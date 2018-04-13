#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0

typedef int	BOOL;

typedef struct _TODO										// ��� ������ ���� ����ü
{
	int start;
	int period;
	char * schedule;
} TODO;

typedef TODO Data;

typedef struct _node										// ��� ����ü
{
	Data data;
	struct _node * next;
	struct _node * prev;
} Node;

typedef struct _List										// ���� ���Ḯ��Ʈ ����ü
{
	Node * head;
	Node * cur;
	int dataCnt;
} List;

void ListInit(List * plist);
BOOL isEmpty(List * plist);
int Count(List * plist);
BOOL First(List * plist, Data * pdata);
BOOL Next(List * plist, Data * pdata);
BOOL Previous(List * plist, Data * pdata);
BOOL Insert(List * plist, int idx, Data data);
Data Delete(List * plist, int idx);
void Clear(List * plist);

#endif