/* environment : c version >= 99, doesn't support c++ */

#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

void AssignLData(LData *lhs, LData rhs)
{
	*lhs = rhs;
}

LinkedList *CreateList(void)
{
	LinkedList *tempList = calloc(1, sizeof(LinkedList));

	if (tempList == NULL)
	{
		perror("list allocation failed! : ");
	}

	return tempList;
}

// free all nodes and the list
void DestoryList(LinkedList *list)
{
	if (list->numOfNodes != 0)
	{
		LNode *prevNode, *currentNode = list->head;
      
      prevNode = currentNode;

		while (currentNode->next != NULL)
		{
			currentNode = currentNode->next;

			free(prevNode);

			prevNode = currentNode;
		}
	}

	free(list);
}

// insert at the rightmost(act like push)
void LInsert(LinkedList *list, LData data)
{
	LNode *newNode = malloc(sizeof(LNode));

	AssignLData(&(newNode->data), data);
	newNode->next = NULL;

	if (list->head == NULL)
	{
		list->head = newNode;
	}
	else
	{
		LNode *currentNode = list->head;

		while (currentNode->next != NULL)
		{
			currentNode = currentNode->next;
		}

		currentNode->next = newNode;
	}

	list->numOfNodes++;
}

// delete the rightmost node and return deleted node's data(act like pop)
LData LDelete(LinkedList *list)
{
	LNode *toBedelNode, *prevNode;
	LData returnLData;

	if (list->numOfNodes == 1) // if there's only head
	{
      toBedelNode = list->head;
		returnLData = list->head->data;

      list->head = NULL;
	}
	else
	{
		LNode *currentNode = list->head;

		prevNode = currentNode;

		while (currentNode->next != NULL)
		{
			prevNode = currentNode;
			currentNode = currentNode->next;
		}

		toBedelNode = currentNode;

		prevNode->next = NULL;
	}

	returnLData = toBedelNode->data;

	free(toBedelNode);

	list->numOfNodes--;

	return returnLData;
}
