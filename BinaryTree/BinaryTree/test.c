#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"


void HeapSort(int* a, int n)
{
	//建堆
	//降序建小堆
	//升序建大堆

	//向上调整建堆，时间复杂度为O(N*logN)
	/*for (int i = 1; i < n; i++)
	{
		AdjustUp(a, i); 
	}*/

	//向下调整建堆，时间复杂度为O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}


	//这里的时间复杂度为O(N*logN)
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0); //向下调整算法
		--end;
	}
}


void TestHeap1()
{
	int a[] = { 4,2,8,1,5,6,9,7 };
	HP hp;
	HPInit(&hp);
	for (size_t i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		HPPush(&hp, a[i]);
	}

	while (!HPEmpty(&hp))
	{
		printf("%d", HPTop(&hp));
		HPPop(&hp);
	}
	HPDestroy(&hp);
}


void TestHeap2()
{
	int a[] = { 4,5,6,34,4,8,9 ,7,1};
	HeapSort(a, sizeof(a) / sizeof(int));
}

void CreateNDate()
{
	//造数据
	int n = 100000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}
	for (int i = 0; i < n; ++i)
	{
		int x = (rand() + i) % 1000000;
		fprintf(fin, "%d\n", x);
	}
	fclose(fin);
}


//Top-K问题
void TestHeap3()
{
	int k;
	printf("请输入k的值:");
	scanf("%d", &k);
	int* kminheap = (int *)malloc(sizeof(int) * k);
	if (kminheap==NULL)
	{
		perror("malloc failed");
		return;
	}

	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen failed");
		return;
	}

	for (int i = 0; i < k; i++)
	{
		fscanf(fout,"%d", &kminheap[i]);
	}

	//向下调整建堆
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(kminheap, k, i);
	}
	
	//读取剩下的N-K个数
	int x = 0;
	while (fscanf(fout, "%d", &x)>0)
	{
		if (x > kminheap[0])
		{
			kminheap[0] = x;
			AdjustDown(kminheap, k, 0);
		}
	}

	printf("最大的前%d个数：\n", k);
	for (int i = 0; i < k; i++)
	{
		printf("%d\n", kminheap[i]);
	}
}


void main()
{
	CreateNDate();
	TestHeap3();
	return 0;
}