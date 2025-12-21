#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct TreeNode* QDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;


void QueueInit(Queue* pq);

//队尾插入
void QueuePush(Queue* pq, QDataType x);

//队头删除
void QueuePop(Queue* pq);

//求队列的数据个数
int QueueSize(Queue* pq);

//求取队头的数据
QDataType QueueFront(Queue* pq);

//求取队尾的数据
QDataType QueueBack(Queue* pq);

//判断队列是否为空
bool QueueEmpty(Queue* pq);

//队列的销毁
void QueueDestory(Queue* pq);