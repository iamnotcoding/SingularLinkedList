#include <stdio.h>

/* environment : c version >= 99, doesn't support c++ */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define PFLData "d"

typedef int LData;

typedef struct _node
{
    struct _node *next;
    LData data;
}LNode;

typedef struct _linked_list
{
    LNode *head;
    size_t numOfNodes;
}LinkedList;

LinkedList *CreateList(void);
void DestoryList(LinkedList **list);

void LInsert(LinkedList *list, LData data);
LData LDelete(LinkedList *list);

void AssignLData(LData *lhs, LData rhs);

#endif