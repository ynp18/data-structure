#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"

void TestInsertSort()
{
	int a[] = { 2,3,4,5,1,4,5,8,9,8 };
	InsertSort(a, 8);
	PrintArray(a, sizeof(a) / sizeof(int));
}

int main(void)
{
	TestInsertSort();
	return 0;
}