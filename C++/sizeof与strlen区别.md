- sizeo操作符的结果是size_t, 她在头文件中的typedef为unsigned int 类型。该类型保证能容纳实现所建立的最大对象的字节大小。


- sizeof是运算符，strlen是函数
 
- sizeof可以用类型做参数还可以用函数做参数， strlen只能用char*做参数，且必须以“\0”结尾。
- 数组做sizeof参数不退化，还是表示数组。strlen就退化成指针。