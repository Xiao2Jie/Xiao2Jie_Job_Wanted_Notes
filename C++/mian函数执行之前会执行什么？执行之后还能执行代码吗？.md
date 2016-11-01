- 全局对象的构造函数在main之前执行
- 通过atexit()注册函数，在main函数后执行
```C++
	#include <stdlib.h>
	#include <stdio.h>`
	int atexit(void (*function)(void))?
	void fn1( void ), fn2( void ), fn3( void )?
	int main( void )
{
	atexit(fn1)?
		atexit( fn2 )?
		printf( "This is executed first.\n" )?
}
void fn1()
{
	printf( " This is\n" )?
}
void fn2()
{
	printf( " executed next." )?
}
```
结果：
	```This is executed first.
	This is executed next.```
