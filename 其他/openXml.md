[toc]
# OpenXml简介
OpenXml是微软office2007及之后版本里，对Office信息内容（Word、Excel和PowerPoint）的一种组织方式，当你创建一个Word2007文档：XXX.docx后，它实际上是一组符合一定规范的格式化xml文件，如果你把后缀名更改为XXX.zip，或者，直接用7-zip类似的解压软件解压后，你会得到一系列的xml文件。这些xml文件有用来描述类容的，有用来描述形式的，还有用来自我描述。这样的一系列xml文件来实现一个Word文档不管对于信息内容、表现形式的管理，还是对于文档的扩展性，都提供了比较大的便利。
 
# 编程操作OpenXml文件
##准备环境

下载并安装OpenXMLSDKv2.msi和OpenXMLSDKTool.msi，下载地址为：`http://www.microsoft.com/en-us/download/details.aspx?displaylang=en&id=5124，`          
OpenXmlSDK为我们提供了一系列的API，通过这些API，我们可以直接去描述我们想要生成的东西：文档、段落、表格、样式等等。这些API根据OpenXml的标准，去生成对应的xml文件，并组织对应的xml文件，最终生成以OpenXml的形式组织内容的Word文档。
OpenXMLSDKTool可以查看一个word文档的Xml组织形式和内容，并且可以将这些转换为C#代码。
 
## 创建工程

使用vs创建一个C#控制台应用程序，并添加引用，在“添加引用”对话框中选择“浏览”，找到以下两个路径的文件添加引用：
`C:\Program Files\Reference Assemblies\Microsoft\Framework\v3.0\WindowsBase.dll，
C:\Program Files (x86)\Open XML SDK\V2.0\lib\DocumentFormat.OpenXml.dll.`
得到工程文件如下图：
图2‑1
 
## 创建文档

###主要类的关系

本文所使用OpenXml中主要类的从属关系，也是xml节点的从属关系，如图所示：
图2‑2
图2‑3
图2‑4

### 工程主体函数
```
在Program.cs中添加如下代码：
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using DocumentFormat.OpenXml;
using DocumentFormat.OpenXml.Wordprocessing;
using DocumentFormat.OpenXml.Packaging;
 
//插入图片所需引入的命名空间
using System.IO;
using A = DocumentFormat.OpenXml.Drawing;
using DW = DocumentFormat.OpenXml.Drawing.Wordprocessing;
using PIC = DocumentFormat.OpenXml.Drawing.Pictures;
 
 
namespace OpenXmlTest
{
    class Program
    {
        static void Main(string[] args)
        {
            // 创建一个文件，命名为Text.docx.
using(WordprocessingDocument doc = WordprocessingDocument.Create (@"Test.docx",WordprocessingDocumentType.Document))
            {
                //为doc添加MainDocumentPart部分
                MainDocumentPart mainPart = doc.AddMainDocumentPart();
 
                // 为mainpart添加Document,对应word里的文档部分内容
                mainPart.Document = new Document();
 
                //为Document添加Body,对应文档的主体内容
                Body body = new Body();
                mainPart.Document.AppendChild(body);
 
                setSectionProprities(body);//设置文档页面属性
 
                CreateParagraphStyle(doc);//为文档创建样式
               
                //创建一个段落，并添加文字“标题1”
                Paragraph p1 = body.AppendChild(new Paragraph(new Run(new Text("标题1"))));
 
                //将之前创建的样式应用到此段落上，使之成为标题
                ApplyStyleToParagraph(p1, "1");
 
                string str = "苏州abcde";
                CreateText(body, str);//为文档添加正文
         
                List<String> list = new List<String> (new string[] { "武汉", "100", "北京", "99", "上海", "98", "苏州", "97", "南京", "96" });
                CreateTable(body,8000, 5, 2, list);//创建一个表格并写入数据
 
                Paragraph p3 = new Paragraph();//添加一个空行
                body.AppendChild(p3);
 
                string fileName = @"kop.jpg";
                InsertAPicture(doc, fileName);//添加一张图片            
            }
        }
```
 
 
 
 
###设置页面属性

设置页面属性对应的函数为setSectionProprities(Body)，函数定义为：
```
public static void setSectionProprities(Body body)
{
     //向内容主体中添加页面设置的类
     SectionProperties sectionProperties = new SectionProperties();
     body.AppendChild(sectionProperties);
 
     //设置页面宽和高
     PageSize pageSize = new PageSize() { Width = 11906U, Height = 16838U };
 
     //设置页面边距
     PageMargin pageMargin = new PageMargin()
      {
           Top = 1440,        //顶部边距
           Right = 1800U,     //右侧边距 
           Bottom = 1440,    // 底部边距
           Left = 1800U,       //左侧边距
           Header = 851U,     //页眉与边界的距离  
           Footer = 992U,     //页脚与边界的距离
           Gutter = 0U,       //装订线
       };
 
       //文档网格， 此处只指定行网格
       DocGrid docGrid1 = new DocGrid() { Type = DocGridValues.Lines, LinePitch = 312 };
 
        //将这些属性添加到设置属性类中
        sectionProperties.Append(pageSize);
        sectionProperties.Append(pageMargin);
        sectionProperties.Append(docGrid1);
}
``` 
 
###插入标题

插入标题所对应的代码为：
```
CreateParagraphStyle(doc);
Paragraph p1 = body.AppendChild(new Paragraph(new Run(new Text("标题1"))));
ApplyStyleToParagraph(p1, "1");
其中CreateParagraphStyle(doc)的定义为：
public static void CreateParagraphStyle(WordprocessingDocument doc)
 {
      //进入文档控制样式部分
      StyleDefinitionsPart styleDefinitionsPart;
      styleDefinitionsPart = doc.MainDocumentPart.AddNewPart<StyleDefinitionsPart>();
      Styles root = new Styles();
      root.Save(styleDefinitionsPart);
           
      //创建一个样式表
      Styles styles = styleDefinitionsPart.Styles;
      if (styles == null)
      {
            styleDefinitionsPart.Styles = new Styles();
            styleDefinitionsPart.Styles.Save();
       }
 
       //创建样式，此处创建了4种样式
       Style style1 = CreateTitleStyle(1);
       Style style2 = CreateTitleStyle(2);
       Style style3 = CreateTitleStyle(3);
       Style style4 = CreateTitleStyle(4);
 
       //将创建的样式添加到样式表中
       styles.Append(style1);
       styles.Append(style2);
       styles.Append(style3);
       styles.Append(style4);
}
 
CreateTitleStyle(int)的定义：
private static Style CreateTitleStyle(int titleIndex)
{
string titleID = titleIndex.ToString();
    string before = string.Empty;
    string after = string.Empty;
    string line = string.Empty;
    string val = string.Empty;
    int outline = titleIndex - 1;
           
    switch (titleIndex)
    {
        case 1:
        {
             before = "340"; //上文间距
             after = "330";  //下文间距
             line = "578";   //段落间的行间距
             val = "44";    //字体大小
         }
         break;
          case 2:
          {
               before = "260";
               after = "260";
               line = "416";
               val = "32";
           }
           break;
           case 3:
           { 
                before = "130";
                after = "0";
                line = "286";
                val = "32";
            }
            break;
            case 4:
            {
                 before = "88";
                 after = "0";
                 line = "288";
                 val = "28";
             }
              break;
    }
 
    //设置样式的整体属性
     Style style2 = new Style() { Type = StyleValues.Paragraph, StyleId = titleID };
 
//样式名称
     StyleName styleName2 = new StyleName() { Val = "heading " + titleID };
 
//父样式id
     BasedOn basedOn1 = new BasedOn() { Val = "a" };
 
     //  下段样式
     NextParagraphStyle nextParagraphStyle1 = new NextParagraphStyle() { Val = "a" };    
 
//链接样式参考
        LinkedStyle linkedStyle1 = new LinkedStyle() { Val = titleID + "Char" };  
           
//用户界面排序顺序
UIPriority uIPriority1 = new UIPriority() { Val = 9 };
 
//基本样式
       PrimaryStyle primaryStyle2 = new PrimaryStyle();  
         
       style2.Append(styleName2);
       style2.Append(basedOn1);
       style2.Append(nextParagraphStyle1);
       style2.Append(linkedStyle1);
       style2.Append(uIPriority1);
       style2.Append(primaryStyle2);
 
       //设置样式的段落属性
       StyleParagraphProperties styleParagraphProperties2 = new StyleParagraphProperties();
       KeepNext keepNext1 = new KeepNext();
       KeepLines keepLines1 = new KeepLines();
       SpacingBetweenLines spacingBetweenLines1 = new SpacingBetweenLines() { Before = before, After = after, Line = line, LineRule = LineSpacingRuleValues.Auto };//行间距
       OutlineLevel outlineLevel1 = new OutlineLevel() { Val = outline };
 
       styleParagraphProperties2.Append(keepNext1);
       styleParagraphProperties2.Append(keepLines1);
       styleParagraphProperties2.Append(spacingBetweenLines1);
       styleParagraphProperties2.Append(outlineLevel1);
       style2.Append(styleParagraphProperties2);
                
       //设置文字属性
       StyleRunProperties styleRunProperties1 = new StyleRunProperties();           
Bold bold1 = new Bold();//设置粗体
       BoldComplexScript boldComplexScript1 = new BoldComplexScript();//复杂脚本粗体
       FontSize fontSize2 = new FontSize() { Val = val };//字体大小
       FontSizeComplexScript fontSizeComplexScript2 = new FontSizeComplexScript() { Val = val };//复杂脚本字体大小
       styleRunProperties1.Append(bold1);
       styleRunProperties1.Append(boldComplexScript1);
    
       styleRunProperties1.Append(fontSize2);
       styleRunProperties1.Append(fontSizeComplexScript2);
       style2.Append(styleRunProperties1);
       return style2;
}
```
插入标题后效果如图:
图2‑5
 
### 插入正文

插入正文所对应的代码为：
```
string str = "苏州abcde";
CreateText(body, str);//创建正文
 
CreateText(Body, string)的定义为：
public static void CreateText(Body body, string str)
{
    //插入一段
    Paragraph p2 = body.AppendChild(new Paragraph());
 
    //设置段落属性
    ParagraphProperties paragraphProperties = new ParagraphProperties();           
    p2.Append(paragraphProperties);
 
    //设置对齐方式，此处设置居中对齐
    Justification justification = new Justification() { Val = JustificationValues.Center };
    paragraphProperties.Append(justification);
 
    //设置段落中的行间距
    SpacingBetweenLines spacingBetweenLines = new SpacingBetweenLines() { Line = "100" };
    paragraphProperties.Append(spacingBetweenLines);
 
    //设置首行缩进，此处设置缩进量为400
    Indentation indentation = new Indentation() { FirstLine = "400" };          
    paragraphProperties.Append(indentation);
 
    //添加文字
    Run run2 = new Run();
    p2.AppendChild(run2);
 
    //添加文字属性
    RunProperties runProperties = new RunProperties();
    run2.Append(runProperties);
 
    //文字设置成粗体
    Bold bold2 = new Bold();
    runProperties.Append(bold2);
 
    // 文字设置成斜体
    Italic italic = new Italic();
    runProperties.Append(italic);
 
    //文字添加下划线，此处添加单下划线，并设置下划线颜色为绿色
    Underline underline = new Underline() { Val = UnderlineValues.Single, Color = "00FF00" };
    runProperties.Append(underline);
 
    //文字不检查拼写错误
    NoProof noProof = new NoProof();
    runProperties.Append(noProof);
 
    //文字颜色设置， 此处设置为红色
    Color color2 = new Color() { Val = "FF0000" };
    runProperties.Append(color2);
 
    //文字字体设置
    RunFonts runFonts = new RunFonts();
    runFonts.EastAsia = "微软雅黑"； //将中文字体设置为微软雅黑
    runFonts.Ascii = "Arial";         //将英文字体设成Arial字体
    runProperties.Append(runFonts);
 
    //字体大小设置，字号为Val的值除以2，此处设置为15号
    FontSize fontSize = new FontSize() { Val = "30" };            
    runProperties.Append(fontSize);
 
    //文字内容设置为str所表示的内容
    Text text = new Text(str);
    run2.AppendChild(text);
}
``` 
添加这些属性后，文字效果如图：
图2‑6
 
###插入表格

插入表格所对应的代码为：
```
List<String> list = new List<String>(new string[] { "武汉", "100", "北京", "99", "上海", "98", "苏州", "97", "南京", "96" });
CreateTable(body, 8000, 5, 2, list);
 
CreateTable(Body ,int , int , int , List<String>)的定义为：
/*四个形参分别表示文档内容主体，表格总宽度，表格行数，表格列数，表格文字内容*/
public static void CreateTable(Body body,int width, int rowCount, int colCount, List<String> list)
{
    Table table = new Table();//创建一个表格
    body.AppendChild(table);//添加到内容主题中
 
    //添加表格属性
    TableProperties tblProp = new TableProperties();
    table.Append(tblProp);
 
    //添加表格边框
    TableBorders tblBorder = new TableBorders();
    tblProp.Append(tblBorder);
    
    //设置各个边的边框属性，此处设置边框为单线，粗细为4
    TopBorder topBorder = new TopBorder() { Val = BorderValues.Single, Size = 4 };       
    RightBorder rightBorder = new RightBorder() { Val = BorderValues.Single, Size = 4 };
    LeftBorder leftBorder = new LeftBorder() { Val = BorderValues.Single, Size = 4 };
    BottomBorder bottomBorder = new BottomBorder() { Val = BorderValues.Single, Size = 4 };
    InsideHorizontalBorder insideHorizontalBorder = new InsideHorizontalBorder() { Val = BorderValues.Single, Size = 4 };
    InsideVerticalBorder insideVerticalBorder = new InsideVerticalBorder() { Val = BorderValues.Single, Size = 4 };
 
    tblBorder.Append(topBorder);
    tblBorder.Append(rightBorder);
    tblBorder.Append(leftBorder);
    tblBorder.Append(bottomBorder);
    tblBorder.Append(insideHorizontalBorder);
    tblBorder.Append(insideVerticalBorder);
 
    //设置表格宽度，指的是所有列的宽度和
    tblProp.TableWidth = new TableWidth() {Width = width.ToString()};           
           
    //创建行，列单元格，并且将文字内容写入
    int num = 0;
 
    //创建rowCount行单元格
    for (int i = 0; i < rowCount; ++i)
    {
        //创建一行单元格
        TableRow tblRow = new TableRow();
        table.Append(tblRow);
 
        //创建colCount列单元格
        for (int j = 0; j < colCount; ++j)
        {
            //创建一列单元格
            TableCell tblCell = new TableCell();
            tblRow.Append(tblCell);
 
            //设置单元格属性
            TableCellProperties tblCellProp = new TableCellProperties();               
            tblCell.Append(tblCellProp);
                    
            //设置内容与边框的边距，此处设为100
            TableCellMargin tblCellMargin = new TableCellMargin();                 
            tblCellMargin.LeftMargin = new LeftMargin() { Width = "100" };
            tblCellMargin.RightMargin = new RightMargin() { Width = "100" };
            tblCellProp.Append(tblCellMargin);
                  
            //添加内容
            Paragraph par = new Paragraph();
            Run run = new Run();
            Text text = new Text(list[num]);
            tblCell.Append(par);
            par.Append(run);
            run.Append(text);
            ++num;
        }
    }
}
```
添加的表格效果如图:
图2‑7
 
###插入图片

插入图片对应的代码为：
```
string fileName = @"kop.jpg"; //图片的路径
InsertAPicture(doc, fileName);
 
InsertAPicture(WordprocessingDocument, string)的定义为：
public static void InsertAPicture(WordprocessingDocument docName, string fileName)
{
    //添加图片部分，并设置了图片格式
    ImagePart imagePart = docName.MainDocumentPart.AddImagePart(ImagePartType.Jpeg);
 
    using (FileStream stream = new FileStream(fileName, FileMode.Open))
    {
        imagePart.FeedData(stream);
    }
    AddImageToBody(docName,docName.MainDocumentPart.GetIdOfPart(imagePart));
}
 
 
AddImageToBody(WordprocessingDocument, string)的定义为：
    //两个形参分别表示文档和关联id，因为图片是由外部引入，所以要设置关联
    private static void AddImageToBody(WordprocessingDocument docName, string relationshipId)
    {
    var element =
        new Drawing(
            new DW.Inline(
                //设置图片宽高
                new DW.Extent() { Cx = 990000*5L, Cy = 792000*5L },
                new DW.EffectExtent() { LeftEdge = 0L, TopEdge = 0L, RightEdge = 0L, BottomEdge = 0L },
                new DW.DocProperties() { Id = 1U, Name = "Picture 1" },
                new DW.NonVisualGraphicFrameDrawingProperties(
                    new A.GraphicFrameLocks() { NoChangeAspect = true }),
                new A.Graphic(
                    new A.GraphicData(
                        new PIC.Picture(
                            new PIC.NonVisualPictureProperties(
                                new PIC.NonVisualDrawingProperties() { Id = 0U, Name = "New Bitmap Image.jpg" },
                                new PIC.NonVisualPictureDrawingProperties()),
                            new PIC.BlipFill(
                                new A.Blip(
                                    new A.BlipExtensionList(
                                        new A.BlipExtension() { Uri = "{28A0092B-C50C-407E-A947-70E740481C1C}" }
                                    )
                                    ) { Embed = relationshipId, CompressionState = A.BlipCompressionValues.Print },
                                    new A.Stretch(
                                        new A.FillRectangle())),
                        new PIC.ShapeProperties(
                            new A.Transform2D(
                                new A.Offset() { X = 0L, Y = 0L },
                                new A.Extents() { Cx = 990000L, Cy = 792000L }),
                            new A.PresetGeometry(
                                new A.AdjustValueList()
                                ) { Preset = A.ShapeTypeValues.Rectangle }))
                        ) { Uri = "http://schemas.openxmlformats.org/drawingml/2006/picture" })
                )
                {
                    DistanceFromTop = 0U,
                    DistanceFromBottom = 0U,
                    DistanceFromLeft = 0U,
                    DistanceFromRight = 0U,
                    EditId = "50D07946"
                });
    docName.MainDocumentPart.Document.Body.AppendChild(new Paragraph(new Run(element)));
    }
```
添加图片后的效果如图：
图2‑8
 
# 参考文档
- [Word processing (Open XML SDK)](https://msdn.microsoft.com/en-us/library/office/cc850833.aspx)
- [利用OpenXml生成Word2007文档](http://blog.csdn.net/francislaw/article/details/7568317)
- [OpenXml操作word的一些总结](http://www.cnblogs.com/zhouxin/p/3174936.html)
- [OpenXml入门-word里面插入图片](http://www.cnblogs.com/FourLeafCloverZc/p/3980437.html)
- [Walkthrough:Word 2007 XML 格式](http://www.cnblogs.com/end/archive/2008/08/06/1261770.html)
 
