#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap(void* v1, void* v2, int size)
{
	
	char *buffer = (char*)malloc(size);


	memcpy(buffer, v1, size);
	memcpy(v1, v2, size);
	memcpy(v2, buffer, size);
}

void quickSort(void* list, long long size, int sizeElement, int (*compare)(const void*, const void*))
{
	void *temp;
	if (size == 2)
	{
		if (compare(list, (char*)list + sizeElement) > 0)
		{
			swap(list, (char*)list + sizeElement, sizeElement);
		}
		return;
	}
	if (size <= 1)
	{
		return;
	}

	bool hi = true;
	bool lo = false;
	bool curMove = hi;
	void* pivot = (char*)list;
	void* low = (char*)list;
	void* high = (char*)list + (size * sizeElement) - (1 * sizeElement);

	while (low != high)
	{

		if (curMove == hi)
		{
			while ((compare(high, pivot) >= 0) && (high > low))
			{
				high = (char*)high - sizeElement;
			}
			if (compare(high, pivot) < 0)
			{


				//printf("Switching the pivot(%d) which is at index %d with the value(%d) which is at index %d\n",
					//*(int*)pivot, (int*)pivot - list, *(int*)high, (int*)high - list);
				swap(low, high, sizeElement);
				pivot = high; //change the pivot to the right one
			}
			curMove = !curMove;
		}
		else
		{
			while ((compare(low, pivot) <= 0) && (low < high))
			{
				low = (char*)low + sizeElement;
			}
			if (compare(low, pivot) > 0)
			{
				swap(low, high, sizeElement);
				pivot = low;
				//printf("Switching the pivot(%d) which is at index %d with the value(%d) which is at index %d\n",
					//*(int*)pivot, (int*)pivot - list, *(int*)low, (int*)low - list);
			}
			curMove = !curMove;
		}
		//now low and high are the same, so both pointing to pivot element

		
		
	}
	int lowerSize = ((char*)low - (char*)list)/sizeElement;
	quickSort(list, lowerSize, sizeElement, compare); //go into lower half
	quickSort((char*)high + sizeElement, size - lowerSize - 1, sizeElement, compare); //go into higher half
}