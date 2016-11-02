```C++
\#include<iostream>
using namespace std;
int MaxSubSum(int A[], int N)
{
	int ThisSum = 0;
	int MaxSum = 0;
	for(int i = 0; i< N; ++i)
	{
		ThisSum += A[i];
		if(ThisSum > MaxSum)
			MaxSum = ThisSum;
		else if(ThisSum < 0)
			ThisSum = 0;
	}
	return MaxSum;
}
int main()
{
	int A[] = {4, -3, 5, -2, -1, 2, 6, -2};
	cout<<MaxSubSum(A, 8);
}
```