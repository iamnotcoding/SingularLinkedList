/* environment : c version >= 99, doesn't support c++ */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include "LinkedList.h"

#define TEST_CASE_NUM 10000
#define TEST_CASE_RANGE 1000

static inline int LDataCmp(LData x, LData y)
{
    if (x > y)
        return -1;
    if (x < y)
        return 1;
    else
        return 0;
}
static inline void LSwap(LNode *x, LNode *y)
{
    assert(x != NULL && y != NULL);

    LData temp;

    AssignLData(&temp, x->data);
    AssignLData(&(x->data), y->data);
    AssignLData(&(y->data), temp);
}

void LBubbleSort(LinkedList *list)
{
    assert(list != NULL);

    if (list->head->next == NULL) // there's nothin to do XD
        return;
    else
    {
        LNode *currentNode = list->head;

        for (size_t i = 0; i < list->numOfNodes; i++)
        {
            for (size_t j = 0; j < list->numOfNodes - i - 1; j++)
            {
                if (LDataCmp(currentNode->data, currentNode->next->data) > 0)
                    LSwap(currentNode, currentNode->next);

                currentNode = currentNode->next;
            }

            currentNode = list->head;
        }
    }
}

int main(void)
{
    clock_t start, end;
    int temp;
    LinkedList *list = CreateList();

    srand((unsigned int)time(NULL));

    for (size_t i = 0; i < TEST_CASE_NUM; i++)
    {
        temp = rand() % TEST_CASE_RANGE;
        LInsert(list, temp);
        printf("%" PFLData " ", temp);
    };

    puts("orignal data");

    start = clock();

    LBubbleSort(list);

    end = clock();
    
     for (size_t i = 0; i < TEST_CASE_NUM; i++)
        printf("%" PFLData " ", LDelete(list));

    puts("sorted data");

    printf("test case : %d\n execution time : %Lfs\n", TEST_CASE_NUM, 
    (long double)(end - start) / CLOCKS_PER_SEC);

    DestoryList(&list);
}
