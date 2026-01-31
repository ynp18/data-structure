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
			Swap(&a[i - 1], &a[i]);

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
}

#include "Stack.h"

//快排非递归
void QuickSortNonR(int* a, int left, int right)
{
	ST st;
	STInit(&st);
	STPush(&st, right);
	STPush(&st, left);
	while (STEmpty(&st)!=0)
	{
		int begin=STTop(&st);
		STPop(&st);
		int end = STTop(&st);
		STPop(&st);

		//用双指针法来实现单趟排序
		int prev = begin;
		int cur = begin + 1;
		int keyi = begin;
		while (cur <= end)
		{
			if (a[cur] < a[keyi] &&++prev!=cur)
			{
				Swap(&a[cur], a[prev]);
			}
			cur++;
		}
		Swap(&a[keyi], &a[prev]);
		keyi = prev;

		//[begin,keyi-1] keyi [keyi+1,end]
		if (keyi + 1 < end)
		{
			STPush(&st,end);
			STPush(&st,keyi + 1);
		}
		if (keyi - 1 > begin)
		{
			STPush(&st, keyi - 1);
			STPush(&st, begin);
		}
	}
	STDestory(&st);
}

//时间复杂度为O(N*logN)
//空间复杂度为O(N)
void _MergeSort(int* a, int* tmp, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	int mid = (begin + end) / 2;
	//[begin mid] [mid+1,end]
	//如果[begin,mid] [mid+1,end]有序就可以进行归并了
	_MergeSort(a, tmp, begin, mid);
	_MergeSort(a, tmp, mid + 1, end);

	//归并
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;
	while (begin1<=end1 && begin2<=end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2) 
	{
		tmp[i++] = a[begin2++];
	}
	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}

//归并排序非递归
void MergeSortNonR(int* a, int n)
{
	int* tmp =(int *)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc failed");
		return;
	}
	int gap=1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2*gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			//第二组越界不存在，这一组就不需要归并
			if (begin2 >= n)
			{
				break;
			}
			//第二组的begin2没越界，end2越界了，需要修正一下，继续归并
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			int j = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}
			memcpy(a+i, tmp+i, sizeof(int) * (end2 - i+1));
		}
		gap *= 2;
	}
	free(tmp);
	tmp = NULL;
}

void MergeSort(int* a, int n)
{
	int* tmp = (int *)malloc(n * sizeof(int));
	if (tmp == NULL)
	{
		perror("malloc failed");
		return;
	}
	_MergeSort(a, tmp, 0, n - 1);
	free(tmp);
	tmp = NULL;
}