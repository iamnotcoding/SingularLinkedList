/* environment : c version >= 99, doesn't support c++ */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "LBubbleSort.h"
#include "LinkedList.h"

#define TEST_CASE_NUM 10U
#define TEST_CASE_RANGE 1000U

#if 0
int main(void)
{
	clock_t start, end;
	int temp;
	LinkedList *list = CreateList();

	if (list == NULL)
	{
		fprintf(stderr, "CreateList() failed!; exiting...\n");
		return 1;
	}

	// simple example

	puts("insert 3");
	LInsert(list, 3, -1);
	puts("insert 7");
	LInsert(list, 7, -1);

	putchar('\n');

	printf("delete : "
		   "%" "d" " \n",
		   LDelete(list, -1));
	printf("delete : "
		   "%" "d" " \n",
		   LDelete(list, -1));

	putchar('\n');

	srand((unsigned int)time(NULL));

	puts("orignal data : ");

	// fill the list with random data
	for (size_t i = 0; i < TEST_CASE_NUM; i++)
	{
		temp = rand() % TEST_CASE_RANGE;

		LInsert(list, temp);

		printf("%" "d" " ", temp);
	};

	start = clock();

	// sort the list
	LBubbleSort(list);

	end = clock();

	putchar('\n');
	puts("sorted data : ");

	// print the result
	for (size_t i = 0; i < TEST_CASE_NUM; i++)
	{
		printf("%" "d" " ", LDelete(list));
	}

	putchar('\n');
	printf("\ntest case number : %d\nexecution time : %Lfs\n", TEST_CASE_NUM,
		   (long double)(end - start) / CLOCKS_PER_SEC);

	DestoryList(list);
}

#endif

int main(void)
{
	LinkedList *list = CreateList();
	LData data = 1;

	LInsert(list, &data, 0);
	data = 2;
	LInsert(list, &data, -1);

	printf("%d\n", *LGetData(list, 1));
}