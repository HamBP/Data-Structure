#include "linkedList.h"

void ListInit(List * plist)
{
	plist->head = (Node*)malloc(sizeof(Node));				// 더미 노드
	plist->head->next = plist->head;
	plist->head->prev = plist->head;
	plist->cur = NULL;
	plist->dataCnt = 0;
}

BOOL isEmpty(List * plist)
{
	if (plist->dataCnt == 0)
		return TRUE;
	else
		return FALSE;
}

int Count(List * plist)
{
	return plist->dataCnt;
}

BOOL First(List * plist, Data * pdata)
{
	if (isEmpty(plist) == TRUE)
		return FALSE;

	plist->cur = plist->head->next;
	*pdata = plist->cur->data;

	return TRUE;
}

BOOL Next(List * plist, Data * pdata)
{
	if (plist->cur->next == plist->head)
		return FALSE;
	
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	
	return TRUE;
}

BOOL Previous(List * plist, Data * pdata)
{
	if (plist->cur->prev == plist->head)
		return FALSE;

	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;
}

BOOL Insert(List * plist, int idx, Data data)			// cur 위치 변화
{
	int i;
	Data temp;
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	if (idx > plist->dataCnt)
		return FALSE;

	plist->cur = plist->head;		
	
	for (i = 0; i < idx; i++)
		Next(plist, &temp);

	newNode->prev = plist->cur;
	plist->cur->next->prev = newNode;
	newNode->next = plist->cur->next;
	plist->cur->next = newNode;

	plist->dataCnt++;
}

Data Delete(List * plist, int idx)						// cur 위치 변화
{
	int i;
	Data temp;
	Node * delNode;

	if (idx >= plist->dataCnt)							// 예외 처리
		return plist->head->data; 

	First(plist, &temp);

	for (i = 0; i < idx; i++)
		Next(plist, &temp);
	
	delNode = plist->cur;
	delNode->prev->next = delNode->next;
	delNode->next->prev = delNode->prev;
	free(delNode);
	
	plist->dataCnt--;
}

void Clear(List * plist)
{
	Data temp;

	if (isEmpty(plist))
		return;
	
	First(plist, &temp);
	Delete(plist, 0);
	
	while (plist->dataCnt != 0)
		Delete(plist, 0);
}