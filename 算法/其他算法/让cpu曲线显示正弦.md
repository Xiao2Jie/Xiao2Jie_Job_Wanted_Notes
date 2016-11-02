```C++
\#include<iostream>
\#include<windows.h>
\#include<math.h>
using namespace std;
int main()
{
	const float PI = 3.1416;
	int count = 180;   //一个周期有多少个点
	int number = 200;
	int idle[180];
	int busy[180];
	float alpha = 0;
	float delta = 2*PI/count;  //每次移动距离
	for(int i = 0; i < count; ++i)
	{
		busy[i] = number*(sin(alpha)+1)/2;   //busy[i]+[idle[i] = number. 而busy[i]又是弦函数
		idle[i] = number-busy[i];
		alpha = alpha+delta;
	}
	int j = 0;
	int st_time;
	while(1)
	{
		j = j%number;
		st_time = GetTickCount();   //记录时间
		while((GetTickCount()-st_time) < busy[j]) ;
		Sleep((idle[j]));
		j++;
	}
	return 0;
}
```