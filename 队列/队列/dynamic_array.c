#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "dynamic_array.h"


void Init_DynamicArray(void **array1, int capacity1)
{
	DY_ARR *array_tmp = malloc(sizeof(DY_ARR));
	array_tmp->array_ = malloc(sizeof(void *)*capacity1);
	array_tmp->capacity = capacity1;
	array_tmp->size = 0;
	*array1 = array_tmp;
}

void DelBypos_DynamicArray(void *myarr1, int pos)
{
	DY_ARR* array1 = (DY_ARR*)myarr1;
	if (myarr1==NULL)
	{
		return;
	}
	if (pos>array1->size-1||pos<0)
	{
		return;
	}
	for (int i=pos;i<array1->size-1;i++)
	{
		array1->array_[i] = array1->array_[i+1];
	}
	array1->size--;
}

void DelByData_DynamicArray(void *myarr1, void *data, int(*mycompare)(void *d1, void *d2))
{
	DY_ARR *array1 = (DY_ARR *)myarr1;
	if (array1 == NULL || data == NULL)
		return;
	for (int i=0;i< array1->size-1;i++)
	{
		if (mycompare(array1->array_[i],data))
		{
			DelBypos_DynamicArray(myarr1, i);
		}
	}
}

void InsetBypos_DynamicArray(void *myarr1, int pos, void *data)
{
	DY_ARR* array1 = (DY_ARR*)myarr1;
	if (myarr1==NULL||data==NULL)
	{
		return;
	}
	if (pos<0||pos>array1->size)
	{
		pos = array1->size;
	}
	if (array1->size>=array1->capacity)
	{
		void** new_array = (void**)malloc(sizeof(void *) * 2 * array1->capacity);
		memcpy(new_array, array1->array_, sizeof(void *)*array1->capacity);
		free(array1->array_);
		array1->capacity = 2 * array1->capacity;
		array1->array_ = new_array;
	}
	for (int i=array1->size-1;i>=pos;i--)
	{
		array1->array_[i + 1] = array1->array_[i];
	}
	array1->array_[pos] = data;
	array1->size++;
}

void InsetByHeader_DynamicArray(void *myarr, void *data)
{
	InsetBypos_DynamicArray(myarr, 0, data);
}

void InsetByTail_DynamicArray(void *myarr1, void *data)
{
	DY_ARR* array1 = (DY_ARR*)myarr1;
	InsetBypos_DynamicArray(array1, array1->size, data);
}

void Print_DynamicArray(void *myarr1, void(*myprint)(void *data))
{
	DY_ARR* array1 = (DY_ARR*)myarr1;
	for (int i=0;i<array1->size;i++)
	{
		myprint(array1->array_[i]);
	}
	printf("\n");
}

int GetSize_DynamicArra(void *myarr1)
{
	DY_ARR* array1 = (DY_ARR*)myarr1;
	return array1->size;
}

int GetCapacity_DynamicArra(void *myarr1)
{
	DY_ARR* array1 = (DY_ARR*)myarr1;
	return array1->capacity;
}

void Destroy_DynamicArray(void **myarr1)
{
	DY_ARR* array1 = *myarr1;
	if (array1==NULL)
	{
		return;
	}
	free(array1->array_);
	array1->array_ = NULL;
	free(array1);
	array1 = NULL;
}

