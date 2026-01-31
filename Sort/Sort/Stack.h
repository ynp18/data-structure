#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void STInit(ST* pst);
void STDestory(ST* pst);

//压栈
void STPush(ST* pst, STDataType x);

//出栈
void STPop(ST* pst);

//获取栈顶的数据
STDataType STTop(ST* pst);

//判断栈是否为空
bool STEmpty(ST* pst);

//判断栈里面有多少数据
int STSize(ST* pst);