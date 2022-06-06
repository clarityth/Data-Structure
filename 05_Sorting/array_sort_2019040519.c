#include "array_sort.h"
#include <stdlib.h>
#include <stdbool.h>


void init_array(Array* array)
{
	array->len = 0;
}

bool is_empty(Array* array)
{
	if (array->len == 0)
		return true;
	return false;
}

bool is_full(Array* array)
{
	if (array->len == MAX_ARRAY_SIZE)
		return true;
	return false;
}

void print_array(Array* array)
{
	if (!is_empty(array))
	{
		for (int i = 0; i < array->len; i++)
			printf("%d -> ", array->array[i]);

		printf("\n");
	}
}

/*
* return 0	: success
* return -1	: fail
*/
int insert_array(Array* array, int data)
{
	if (!is_full(array))
	{
		array->array[array->len] = data;
		array->len++;
		return 0;
	}
	return -1;
}


//-----------------------------------------------------------
// If you need a another function, write it here.
void swap(Array* array, int i, int j){
	int temp = array->array[i];
	array->array[i] = array->array[j];
	array->array[j] = temp;
}

int partition(Array* array, int left, int right){
	int key = left;
	int pivot = array->array[key];
	int low = left+1;
	int high = right;
	while (low <= high){
		while (array->array[low]<=pivot && low <= right) low++;
		while (array->array[high]>=pivot && high >= left+1) high--;
		if(low <= high)
			swap(array, low, high);
	}
	swap(array, left, high);
	return high;
}

void q_sort(Array* array, int left, int right){
	if (left >= right)
		return;
		int pivotIndex = partition(array, left, right);
		q_sort(array, left, pivotIndex-1);
		q_sort(array, pivotIndex+1, right);
}
//-----------------------------------------------------------


/*
* -----------------------------------------------------------------------------------
* Sorting Algorithm
* -----------------------------------------------------------------------------------
*/

void sequence_sort(Array* array)
{
	for (int i=0; i<array->len-1; i++){
		for (int j=i+1; j<array->len; j++){
			if (array->array[i] > array->array[j]){
				swap(array, i, j);
			}
		}
	}
}

void selection_sort(Array* array)
{
	int i, j;
	for (i=0; i<array->len-1; i++){
		int min = i;
		for (j=i+1; j<array->len; j++){
			if (array->array[min] > array->array[j]){
				min = j;
			}
		}
		if (i != min){
			swap(array, i, min);
		}
	}
}

void insertion_sort(Array* array)
{
	int i, j, key;
	for (i=1; i<array->len; i++){
		key = array->array[i];
		for (j=i; (j>0) && (array->array[j-1])>key; j--){
			array->array[j] = array->array[j-1];
		}
		array->array[j] = key;
	}
}

void bubble_sort(Array* array)
{
	int i, j;
	for (i=array->len; i>1; i--){
		for (j=1; j<i; j++){
			if (array->array[j-1] > array->array[j])
				swap(array, j-1, j);
		}
	}
}

void quick_sort(Array* array)
{
	q_sort(array, 0, array->len-1);
}