#include <stdio.h>

#if 0

#include "LinkedList.h"
#include "LBubbleSort.h"

int LDataCmp(LData x, LData y)
{
	if (x > y)
	{
		return -1;
	}
	if (x < y)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void LSwap(LNode *x, LNode *y)
{
	LData temp;

	AssignLData(&temp, x->data);
	AssignLData(&(x->data), y->data);
	AssignLData(&(y->data), temp);
}

void LBubbleSort(LinkedList *list)
{
	if (list->head->next == NULL) // there's nothin to do
	{
		return;
	}
	else
	{
		LNode *currentNode = list->head;

		for (size_t i = 0; i < list->numOfNodes; i++)
		{
			for (size_t j = 0; j < list->numOfNodes - i - 1; j++)
			{
				if (LDataCmp(currentNode->data, currentNode->next->data) > 0)
				{
					LSwap(currentNode, currentNode->next);
				}

				currentNode = currentNode->next;
			}

			currentNode = list->head;
		}
	}
}
#endif