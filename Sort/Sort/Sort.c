#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"
void Swap(int* a1, int* a2)
{
	int tmp;
	tmp = *a1;
	*a1 = *a2;
}

//直接插入排序
void InsertSort(int* a, int n)
{
	//前[0,end]是有序的
	for (int i = 0; i < n-1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		//这里主要是处理两种情况：1.end=-1,即tmp的值比前面的值都小，2:就是上面的else的break跳出循环
		a[end + 1] = tmp;
	}
}

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
}

//冒泡排序
void BubbleSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		if (a[i - 1] < a[i])
		{
			Swap(&a[i - 1], a[i]);

		}
	}
}

//希尔排序
void ShellSort(int* a, int n)
{
	//循环三次，串行形式，分成gap组，每组完成排序后再排下一组
	/*int gap = 3;
	for (int j = 0; j < gap; j++)
	{
		for (int i = j; i < n - gap; i += gap)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
	}*/
	//并行形式，只需要两层循环
		/*int gap = 3;
		for (int i = 0; i < n - gap; i ++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}*/
	int gap = n;
	while (gap > 1)
	{
		//这里的加一是为了保证最后一次循环时gap的值为1，也就是前面是先跳着排，最后一次是直接插入排序
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
	}
}