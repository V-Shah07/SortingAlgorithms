#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void insertionSortiterative(int* list, long long listSize)
{	
	int temp;
	for (int i = 1; i < listSize; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (*(list + i) < *(list + j))
			{
				temp = *(list + i);
				memmove(list+ j +1 , list + j, (sizeof(int)) * ((size_t)i - j));
				*(list + j) = temp;
				break;
			}
		}

	}
}