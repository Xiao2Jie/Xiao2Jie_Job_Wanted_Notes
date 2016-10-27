//归并排序
void mergeArray(int a[], int first, int mid, int last, int temp[])        //对两个有序数列合并
{
	int i = first;
	int j = mid + 1;
	int m = mid;
	int n = last;
	int k = 0;
	//每次把两个数列中较小的值存在temp中
	while(i <= m && j <= n)
	{
		if(a[i]<= a[j])
		{
			temp[k++] = a[i++];
		}
		else
		{
			temp[k++] = a[j++];
		}
	}
	//哪一个数列先完成拷贝就把另一个数列的剩余的值存在temp中
	while(i <= m)
	{
		temp[k++] = a[i++];
	}
	while(j <= n)
	{
		temp[k++] = a[j++];
	}
	//把temp中的值拷贝到a中
	for(int i = 0; i < last-first+1; ++i)
	{
		a[first+i] = temp[i];
	}
}
void mergeSort(int a[], int first, int last, int temp[])
{
	if(first < last)
	{
		int mid = (last + first)/2;   //注意用加号,不是减号, 
		//将数组划分成由单个数组成的数列,则就可看成是每个数列都是有序的,可以用mergeArray函数了
		mergeSort(a, first, mid, temp);
		mergeSort(a, mid+1, last, temp);
		mergeArray(a, first, mid, last, temp);
	}
}
bool MergeSort(int a[], int n)
{
	int *p = new int[n];
	if(p == NULL)
	{
		return false;
	}
	else
	{
		mergeSort(a, 0, n-1, p);
		delete[] p;
		return true;
	}
}


