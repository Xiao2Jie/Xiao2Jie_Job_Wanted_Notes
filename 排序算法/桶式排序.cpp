//桶式排序
void BucketSort(int a[],int n, int b[], int max)
{
	for(int i = 0; i <n; ++i )
		b[a[i]]++;
	for(int i = 0, j = 0; i < max; ++i)
	{
		if(b[i])
		{
			a[j++] = i;
		}
	}
}
int main()
{
	int A[] = {40, 2, 15, 12, 10,1, 6, 8};
	int b[50] ={0};
	BucketSort(A, 8, b, 50);
	for(int i = 0; i <8; ++i )
	{
		cout<<A[i]<<endl;
	}
}
