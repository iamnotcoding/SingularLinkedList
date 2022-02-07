#include <stdio.h>

/* environment : c version >= 99, doesn't support c++ */

// include gaurd
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define PFLData "d"

/* if you want to change LData, 
you have to change AssignLData() and PFLData too(if it's printable)*/
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
	size_t numOfNodes;
} LinkedList;

LinkedList *CreateList(void);
void DestoryList(LinkedList *list);

void LInsert(LinkedList *list, LData data);
LData LDelete(LinkedList *list);

void AssignLData(LData *lhs, LData rhs);

#endif