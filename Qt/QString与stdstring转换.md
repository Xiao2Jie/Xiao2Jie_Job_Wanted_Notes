```
QString转string :  toStdString()
string转QString : c_str()

std::string cstr;
QString qstring;

//****从std::string 到QString
qstring = QString(QString::fromLocal8Bit(cstr.c_str()));

//****从QString 到 std::string
cstr = string((const char *)qstring.toLocal8Bit());
```