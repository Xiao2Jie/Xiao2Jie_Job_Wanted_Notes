```C++
//分治
\#include<iostream>
using namespace std
int MaxSubSum(int A[], int Left, int Right)
{
	int MaxLeftSum, MaxRightSum;
	int MaxLeftBorderSum, MaxRightBorderSum;
	int LeftBorderSum, RightBorderSum;
	int Center;
	if(Left == Right)
	{
		if(A[Left] > 0)
		{
			return A[Left];
		}
		else
		{
			return 0;
		}
	}
	
	Center = (Left + Right)/2;
	MaxLeftSum = MaxSubSum(A, Left, Center);
	MaxRightSum = MaxSubSum(A, Center+1, Right);
	MaxLeftBorderSum = LeftBorderSum = 0;
	for(int i = Center; i >= Left; --i)
	{
		LeftBorderSum += A[i];
		if(LeftBorderSum > MaxLeftBorderSum)
		{
			MaxLeftBorderSum = LeftBorderSum;
		}
	}
	MaxRightBorderSum = RightBorderSum = 0;
	for(int i = Center+1; i <= Right; ++i)
	{
		RightBorderSum += A[i];
		if(RightBorderSum > MaxRightBorderSum)
		{
			MaxRightBorderSum = RightBorderSum;
		}
	}
	if(MaxLeftSum > MaxRightSum)
	{
		if(MaxLeftSum > (MaxLeftBorderSum+MaxRightBorderSum))
			return MaxLeftSum;
		else
			return MaxLeftBorderSum+MaxRightBorderSum;
	}
	else
	{
		return (MaxRightSum > (MaxRightBorderSum+MaxLeftBorderSum))?MaxRightSum:(MaxLeftBorderSum+MaxRightBorderSum);
	}
}
int main()
{
	int A[] = {4, -3, 5, -2, -1, 2, 6, -2};
	cout<<MaxSubSum(A, 0, 7);
}

```