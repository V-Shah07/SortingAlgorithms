#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Header.h"
#include <time.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#pragma warning(disable: 4996)

#define PRINTABLE size < 100

void printList(int* list, long long listSize)
{
	printf("\n");
	for (long long i = 0; i < listSize; ++i)
	{
		printf("%d, ", *(list + i));
	}
	printf("\n\n\n");
}
void generateRandList(int* list, long long listSize)
{
	srand((unsigned int)time(NULL));
	
	for (long long i = 0; i < listSize; ++i)
	{
		*(list + i) = rand() % INT_MAX; 
	}
}
void generateRandSortedList(int* list, long long listSize)
{
	srand((unsigned int)time(NULL));
	int value = rand() % 10;
	for (long long i = 0; i < listSize; ++i)
	{
		if (value == (INT_MAX - 9))
		{
			*(list + i) = value;
		}
		else
		{
			value += rand() % 10;
			*(list + i) = value;
		}
		
	}
}
void checkSorted(int* list, long long listSize)
{
	int smallest = *list;
	for (long long i = 1; i < listSize; ++i)
	{
		if (*(list + i) < smallest)
		{
			printf("This list was not sorted, something went wrong");
			return;
		}
	}
	printf("After making sure through testing, this list was sorted properly");
}
void checkSearch(int* list, long long listSize, int element, int* locationFound)
{
	if (locationFound)
	{
		//was found since not NULL
		if (*locationFound == element)
		{
			printf("Great it really was found!!");
			return;
		}
	}
	else
	{
		//search to make sure it really WASN'T found
		for (long long i = 0; i < listSize; ++i)
		{
			if (*(list + i) == element)
			{
				printf("the binary search did not work! The element IS here!");
				return;
			}
		}
	}
	printf("The binary search worked! The element isn't here!");
}
int compare(const void* p1, const void* p2)

{
	int* element1 = (int*)p1;
	int* element2 = (int*)p2;

	if (*element1 > *element2)
	{
		return 1;
	}
	else if (*element1 == *element2)
	{
		return 0;
	}
	else
	{
		return -1;
	}

}
void delay(int seconds)
{
	#ifdef _WIN32
		Sleep(seconds * 1000);
#else
		usleep(seconds * 1000000);
#endif
}
int main()
{

	printf("1. Insertion sort function - iterative\n");
	printf("2. Insertion sort function - recursive\n");
	printf("3. Binary search built in function\n");
	printf("4. My own quicksort!!\n");
	printf("what would you like to do: ");
	int choice;
	scanf("%d", &choice);
	getchar();
	long long size;
	int* list;
	int searchToken;
	int* searchLocation;

	clock_t start, end;
	double cpu_time_used;
	switch (choice)
	{
	case 1:
		printf("Size of the list: ");
		scanf("%lld", &size);
		list = (int*)malloc(size * sizeof(int));
		generateRandList(list, size);

		if(PRINTABLE)
		{
			printf("Here is the random generated list: \n");
			printList(list, size);
			delay(2);
		}

		printf("Will sort now\n");
		start = clock();
		insertionSortiterative(list, size);
		end = clock();
		printf("Finished sorting in %lf seconds\n\n", ((double)end - start) / CLOCKS_PER_SEC);
		delay(2);
		if(PRINTABLE)
		{
			printf("Here is the sorted list:\n");
			printList(list, size);
			delay(2);
		}
		printf("\n\n");
		checkSorted(list, size);
		printf("\n\n");
		break;
	case 2:
		printf("Size of the list: ");
		scanf("%lld", &size);
		list = (int*)malloc(size * sizeof(int));
		generateRandList(list, size);
		if(PRINTABLE)
		{
			printf("Here is the random generated list: \n");
			printList(list, size);
			delay(2);
		}
		printf("Will sort now\n");
		start = clock();
		insertionSortrecursive(list, size);
		end = clock();
		printf("Finished sorting in %lf seconds\n\n", ((double)end - start) / CLOCKS_PER_SEC);
		delay(2);
		if(PRINTABLE)
		{
			printf("Here is the sorted list:\n");
			printList(list, size);
			delay(2);
		}
		printf("\n\n");
		checkSorted(list, size);
		printf("\n\n");
		break;
	case 3:
		printf("Size of the list: ");
		scanf("%lld", &size);
		list = (int*)malloc(size * sizeof(int));
		generateRandSortedList(list, size);
		printf("Here is the random generated list: \n");
		printList(list, size);
		printf("What item would you like to find?: ");
		scanf("%d", &searchToken);

		searchLocation = (int*)bsearch(&searchToken, list, size, sizeof(int), compare);
		checkSearch(list, size, searchToken, searchLocation);
		break;
	case 4:
		printf("Size of the list: ");
		scanf("%lld", &size);
		list = (int*)malloc(size * sizeof(int));
		generateRandList(list, size);
		printf("Generated random list with %d elements...\n", size);
		delay(2);
		printf("Started sorting\n");
		start = clock();
		quickSort(list, size, sizeof(int), compare);
		end = clock();
		printf("Finished sorting in %lf seconds\n\n", ((double)end - start) / CLOCKS_PER_SEC);
		delay(2);
		checkSorted(list, size);
		printf("\n\n\n");
		break;
	}


}