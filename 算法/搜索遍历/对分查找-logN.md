###给定一个整数X和整数A0,A1...An-1, 后者已经预先排序并且在内存中,求Ai = X的下标i,如果不存在,返回-1.


```C++
\#include<iostream>
using namespace std;
int BinarySearch(int A[],int n, int x)
{
	int Low = 0; 
	int High = n-1;
	int Mid = 0;
	while(Low <= High)
	{
		Mid = (Low + High)/2;
		if(A[Mid] < x)
		{
			Low = Mid+1;
		}
		else if(A[Mid] > x)
		{
			High = Mid-1;
		}
		else
			return Mid;
	}
	return -1;
}
int main()
{
	//int A[] = {4, -3, 5, -2, -1, 2, 6, -2};
	//cout<<BinarySearch(A, 8, -1);
}
```