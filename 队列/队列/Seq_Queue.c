#include "Seq_Queue.h"
#include <stdio.h>
void * init_seqQueue()
{
	void * Seq_Queue = NULL;
	Init_DynamicArray(&Seq_Queue, MAXSIZE);
	return Seq_Queue;
}

void push_seqQueue(void *queue, void *data)
{
	if (queue==NULL||data==NULL)
	{
		return;
	}
	//DY_ARR *arr = (DY_ARR*)data;
	int size = GetSize_DynamicArra(queue);
	if (size>MAXSIZE)
	{
		return;
	}
	InsetBypos_DynamicArray(queue, 0, data);
}

void pop_seqQueue(void *queue)
{
	if (queue == NULL)
	{
		return;
	}
	int size = GetSize_DynamicArra(queue);
	if (size <= 0)
	{
		return;
	}
	DelBypos_DynamicArray(queue, 0);
}

void * get_front_seqQueue(void *queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	DY_ARR *arr = (DY_ARR*)queue;
	if (arr->size<=0)
	{
		return NULL;
	}
	return arr->array_[0];
}

void * get_back_seqQueue(void *queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	DY_ARR *arr = (DY_ARR*)queue;
	if (arr->size <= 0)
	{
		return NULL;
	}
	return arr->array_[arr->size-1];
}

int get_size_seqQueue(void *queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	DY_ARR *arr = (DY_ARR*)queue;
	return arr->size;
}

int is_empty_seqQueue(void *queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	DY_ARR *arr = (DY_ARR*)queue;
	if (arr->size == 0)
	{
		return 1;
	}
	return 0;
}

void destroy_seqQueue(void *queue)
{
	Destroy_DynamicArray(queue);
}

