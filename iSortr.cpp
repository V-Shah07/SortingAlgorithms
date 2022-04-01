#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void insertionSortrecursive(int* list, long long listSize)
{
	if (listSize == 1)
	{
		return;
	}

	insertionSortrecursive(list, listSize - 1);
	int temp;
	for (long long i = 0; i < listSize-1; ++i)
	{
		if (*(list + listSize - 1) < *(list + i))
		{
			temp = *(list + listSize - 1);
			memmove(list + i + 1, list + i, (sizeof(int)) * ((size_t)listSize - 1 - i));
			*(list + i) = temp;
			break;
		}
	}

}