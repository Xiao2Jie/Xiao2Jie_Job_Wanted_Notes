封装可以隐藏实现细节，使得代码模块化。

封装就是将抽象得到的数据和行为相结合，形成一个有机的整体。使用者不必了解具体的实现细节，而只要通过外部接口，特定的访问权限来使用类的成员。

public和private的作用就是为了实现封装，private成员只能由**类内成员和友元访问**。

protected的作用是为了实现继承。**protected成员可以被派生类对象访问，不能被类外部代码访问。**

---
###继承中的特点：
先记住：不管是否继承，上面的规则永远适用！

有public, protected, private三种继承方式，它们相应地改变了基类成员的访问属性。

1. public继承：基类public成员，protected成员，private成员的访问属性在派生类中分别变成：public, protected, private
2. protected继承：基类public成员，protected成员，private成员的访问属性在派生类中分别变成：protected, protected, private
3. private继承：基类public成员，protected成员，private成员的访问属性在派生类中分别变成：private, private, private

来源： http://www.jb51.net/article/54224.htm