int lis(int A[], int n)
{
	int *d = new int[n];   //存放最长子序列个数的数组
	int len = 1;
	for(int i = 0; i < n; ++i)
	{
//A[i]之前的数的最长子序列都是已经确定了的，所以A[i]的最长子序列就是找到一个他之前的数的最长子序列最大值，并且满足A[i]>A[x]
		d[i] = 1;
		for(int j = 0; j < i; ++j)
		{
			if(A[j] < A[i] && d[j]+1 > d[i])  //某个数比A[i]小,并且它的最长自序列+1比目前的d[i]大,那么就可以把A[j]加到A[i]的子序列上,更新d[i]
			{
				d[i] = d[j]+1;
			}		
		}
        if(d[i]>len)
        {
          len = d[i];
        }
	}
	delete[] d;
   return len;
}
int main()
{
    int A[] = {5, 3, 4, 8, 6, 7};
    cout<<lis(A, 6)<<endl;
}

