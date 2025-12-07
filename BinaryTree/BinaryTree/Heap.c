#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

void HPInit(HP*php)
{
	assert(php);
	php->a = NULL;
	php->size = php->capacity = 0;
}

void HPDestroy(HP*php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = php->capacity=0;
}

//交换两者的值
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


//向上调整算法
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}   

void HPPush(HP* php, HPDataType x)
{
	assert(php);

	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType *)realloc(php->a,newcapacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc failed");
			return;
		}
		php->a = tmp;
		php->capacity = newcapacity;
	}

	php->a[php->size] = x;
	php->size++;

	AdjustUp(php->a, php->size - 1);
}

//向下调整算法
void AdjustDown(HPDataType *a,int n,int parent)
{
	//先假设左孩子小
	int child = parent * 2 + 1;
	while (child < n)  //child>=n说明孩子不存在，调整到叶子了
	{
		if (child+1<n  && a[child + 1] < a[child])
		{
			++child;
		}

		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//删除堆是删除堆顶的数据，将堆顶的数据跟最后⼀个数据⼀换，然后删除数组最后⼀个数据，再进⾏
//向下调整算法
void HPPop(HP *php)
{
	assert(php);
	assert(php->size > 0);
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;

	AdjustDown(php->a,php->size,0);
}

//取出堆顶的元素
HPDataType HPTop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	return php->a[0];
}

bool HPEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}