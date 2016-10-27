//快速排序
void Swap(int &a, int &b)
{
	//a ^= b;
	//b ^= a;
	//a ^= b;
	int temp;
	temp = a;
	a= b;
	b = temp;
}
int Median3(int a[], int Left, int Right)
{
	int Center = (Left+Right)/2;
	//将左中右三个值排序
	if(a[Left] > a[Center])
	{
		Swap(a[Left], a[Center]);
	}
	if(a[Left] > a[Right])
	{
		Swap(a[Left], a[Right]);
	}
	if(a[Center] > a[Right])
	{
		Swap(a[Center], a[Right]);
	}
	//将中值放在倒数第二个位置并作为枢纽元返回
	Swap(a[Center], a[Right-1]);
	return a[Right-1];
}
void InsertionSort(int a[], int n)
{
	int temp ;
	for(int i = 1; i < n; ++i)
	{
		int j;
		temp = a[i];
		for(j = i; j >0 && temp < a[j-1]; --j)  //a[j]前的序列都是排好序的,在找到那个比a[j]小的值前,遍历过的值都向后挪1位
		{
				a[j] = a[j-1];
		}
		a[j] = temp;
	}
}
void quickSort(int a[], int Left, int Right)
{
	int i, j, Pivot;
	if(Left +3 <=  Right)    //当元素个数较少时,使用插入排序比快速排序要快,
	{
		Pivot = Median3(a, Left, Right);
		/*	int m = a[0];
		int n = a[7];*/
		i = Left;
		j = Right-1;
		for(;;)   //找到a[i]大于枢纽元的位置和a[j]小于枢纽元的位置并交换两个位置,一直进行直到i大于j退出
		{
			while(a[++i] < Pivot) {}
			while(a[--j] > Pivot) {}
			if(i < j)
				Swap(a[i], a[j]);
			else
				break;
		}
		//退出for循环时,a[i]的值大于枢纽元并且位置在a[j]左边,故a[i]与枢纽元交换, 则此时枢纽元左边的都是较小值,右边都是较大值.
		Swap(a[i], a[Right-1]);  
		quickSort(a, Left, i-1);
		quickSort(a, i+1, Right);
	}
	else
	{
		InsertionSort(a+Left, Right-Left+1);
	}
}
void QuickSort(int a[], int n)
{
	quickSort(a, 0, n-1);
}
