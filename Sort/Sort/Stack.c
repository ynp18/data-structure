#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

//栈的初始化
void STInit(ST *pst)
{
	assert(pst);
	pst->a = NULL;
	//top指向的是栈顶数据的下一个位置
	pst->top = 0;
	//如果top要指向栈顶数据
	//pst->top=-1;
	pst->capacity = 0;
}

void STDestory(ST* pst)
{
	assert(pst->a);
	free(pst->a);
	pst->top = 0;
	pst->capacity = 0;
}

void STPush(ST* pst, STDataType x)
{
	assert(pst);

	if (pst->top == pst->capacity)
	{
		int newcapacity = pst->capacity==0 ? 4: pst->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(pst->a, newcapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc failed");
		}
		pst->a = tmp;
		pst->capacity = newcapacity;

	}

	pst->a[pst->top] = x;
	(pst->top)++;
}

//出栈
void STPop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);
	pst->top--;
}

STDataType STTop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);
	return pst->a[pst->top - 1];
}

//判空
bool STEmpty(ST* pst)
{
	assert(pst);
	return pst->top == 0;
}

//获取数据个数
int STSize(ST* pst)
{
	assert(pst);
	return pst->top;
}