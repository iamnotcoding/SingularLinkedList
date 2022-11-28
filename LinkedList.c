/* environment : c version >= 99, doesn't support c++ */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "LinkedList.h"

void CopyLData(LData *dest, const LData *src)
{
	*dest = *src;
}

bool CmpLData(const LData *x, const LData *y)
{
	return *x == *y;
}

LinkedList *CreateList(void)
{
	LinkedList *tempList = calloc(1, sizeof(LinkedList));

	if (tempList == NULL)
	{
		perror("CreateList() : list allocation failed! : ");
	}

	return tempList;
}

// free all nodes and the list
void DestoryList(LinkedList *list)
{
	if (list->nodeCount != 0)
	{
		LNode *prevNode, *curNode = list->head;

		prevNode = curNode;

		while (curNode->next != NULL)
		{
			curNode = curNode->next;

			free(prevNode);

			prevNode = curNode;
		}
	}

	free(list);
}

// insert at the rightmost(act like push)
void LInsert(LinkedList *list, const LData *data, int index)
{
	LNode *newNode = malloc(sizeof *newNode);

	CopyLData(&(newNode->data), data);

	newNode->next = NULL;

	if (index == 0)
	{
		newNode->next = list->head;
		list->head = newNode;
	}
	else
	{
		LNode *curNode = list->head;
		LNode *prevNode;

		if (index == -1)
		{
			while(curNode != NULL)
			{
				prevNode = curNode;
				curNode = curNode->next;
			}
		}
		else
		{
			for (int i = 0; i < index; i++)
			{
				prevNode = curNode;
				curNode = curNode->next;

				if (curNode == NULL)
				{
					fprintf(stderr, "LInsert() : out of bounds!\n");
					exit(1);
				}
			}
		}

		prevNode->next = newNode;
		newNode->next = curNode;
	}

	list->nodeCount++;
}

// delete the rightmost node and return deleted node's data(act like pop)
void LDeleteByIndex(LinkedList *list, int index)
{
	LNode *toBedelNode, *prevNode;

	if (index == 0) // if there's only head
	{
		if (list->head == NULL)
		{
			fprintf(stderr, "LDeleteByIndex() : the list is empty!\n");
			exit(1);
		}

		toBedelNode = list->head;

		list->head = NULL;
	}
	else
	{
		LNode *curNode = list->head;
		
		prevNode = curNode;

		if (index == -1)
		{
			while (curNode->next != NULL)
			{
				prevNode = curNode;
				curNode = curNode->next;
			}
		}
		else
		{
			for (int i = 0; i < index; i++)
			{
				prevNode = curNode;
				curNode = curNode->next;

				if (curNode == NULL)
				{
					fprintf(stderr, "LDeleteByIndex() : out of bounds!\n");
					exit(1);
				}
			}

		}

		toBedelNode = curNode;

		prevNode->next = NULL;
	}

	free(toBedelNode);

	list->nodeCount--;
}

void LDeleteByData(LinkedList *list, const LData *data)
{
	LNode *curNode = list->head;
	LNode *prevNode;

	if (curNode == NULL)
	{
		fprintf(stderr, "LDeleteByIndex() : the list is empty!\n");
		exit(1);
	}

	while (curNode != NULL && CmpLData(&(curNode->data), data) == true)
	{
		prevNode = curNode;
		curNode = curNode->next;
	}

	if (curNode == NULL)
	{
		fprintf(stderr, "LDeleteByIndex() : out of bounds!\n");
		exit(1);
	}

	prevNode->next = curNode->next;

	free(curNode);
}

int LFind(LinkedList *list, const LData *data)
{
	LNode *curNode = list->head;
	int index;

	if (curNode == NULL)
	{
		return -1;
	}

	for (index = 0; curNode != NULL && CmpLData(&(curNode->data), data) == true; index++)
	{
		curNode = curNode->next;
	}

	if (curNode == NULL)
	{
		return -1;
	}

	return index;
}

LData *LGetData(LinkedList *list, int index)
{
	LNode *curNode = list->head;

	if (curNode == NULL)
	{
		fprintf(stderr, "LGetData() : the list is empty!\n");
		exit(1);
	}

	for (int i = 0; i < index && curNode != NULL; i++)
	{
		curNode = curNode->next;
	}

	if (curNode == NULL)
	{
		fprintf(stderr, "LGetData() : out of bounds!\n");
		exit(1);
	}

	return &(curNode->data);
}
