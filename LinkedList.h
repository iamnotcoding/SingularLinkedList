#include <stdio.h>

/* environment : c version >= 99, doesn't support c++ */

// include gaurd
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef int LData;

typedef struct _node
{
	struct _node *next;
	LData data;
} LNode;

// singular list only with head
typedef struct _linked_list
{
	LNode *head;
	int nodeCount;
} LinkedList;

LinkedList *CreateList(void);
void DestoryList(LinkedList *list);

void LInsert(LinkedList *list, const LData *data, int index);

void LDeleteByIndex(LinkedList *list, int index);
void LDeleteByData(LinkedList *list, const LData *data);

int LFind(LinkedList *list, const LData *data);
LData *LGetData(LinkedList *list, int index);

#endif
