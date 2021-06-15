/* environment : c version >= 99, doesn't support c++ */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h> //optional

#include "LinkedList.h"

void AssignLData(LData *lhs, LData rhs)
{
   assert(lhs != NULL);

   *lhs = rhs;
}

LinkedList *CreateList(void)
{
   LinkedList *tempList = calloc(1, sizeof(LinkedList));

   return tempList;
}

void DestoryList(LinkedList **list)
{
   assert(*list != NULL);

   if ((*list)->numOfNodes != 0)
   {
      LNode *prevNode, *currentNode = (*list)->head;

      prevNode = currentNode;

      while (currentNode->next != NULL)
      {
         currentNode = currentNode->next;
         prevNode = currentNode;
         free(prevNode);
      }
      free((*list)->head);
   }

   *list = NULL;
}

// insert at the rightmost
void LInsert(LinkedList *list, LData data)
{
   assert(list != NULL);

   LNode *newNode = calloc(1, sizeof(LNode));

   LNode *currentNode = list->head;

   AssignLData(&(newNode->data), data);

   if (list->head == NULL)
      list->head = newNode;
   else
   {
      while (currentNode->next)
         currentNode = currentNode->next;

      currentNode->next = newNode;
   }

   list->numOfNodes++;
}

// delete the rightmost node and returns deleted node's data
LData LDelete(LinkedList *list)
{
   assert(list != NULL);

   LNode *toBedelNode, *prevNode, *currentNode = list->head;
   LData returnLData;

   if (list->numOfNodes == 0)  // if there's no node to delete
      return list->head->data; // there's nothing needs to be done; exit
   else
   {
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