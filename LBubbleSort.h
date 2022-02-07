#ifndef LBUUBLESORT_H
#define LBUBBLESORT_H

#include "LinkedList.h"

int LDataCmp(LData x, LData y);
void LSwap(LNode *x, LNode *y);
void LBubbleSort(LinkedList *list);

#endif