#include "List_Queue.h"
#include <stdio.h>
#include <stdlib.h>
List_Queue init_linkqueue()
{
	LIST_QUEUE* queue = malloc(sizeof(LIST_QUEUE));
	if (queue==NULL)
	{
		return NULL;
	}
	queue->head = malloc(sizeof(NODE));
	queue->tail = malloc(sizeof(NODE));
	queue->head->next = NULL;
	queue->tail = queue->head;
	queue->size = 0;
	return queue;
}

void push_linkqueue(List_Queue queue, void *data)
{
	if (queue==NULL||data==NULL)
	{
		return;
	}
	LIST_QUEUE* my_queue = (LIST_QUEUE*)queue;
	NODE* node = (NODE*)data;
    node->next= NULL;
	my_queue->tail->next = node;
	my_queue->tail = node;
	my_queue->size++;
}

void pop_linkqueue(List_Queue queue)
{
	if (queue == NULL)
	{
		return;
	}
	LIST_QUEUE* my_queue = (LIST_QUEUE*)queue;
	if (my_queue->size<=0)
	{
		return;
	}
	my_queue->head->next = my_queue->head->next->next;
	my_queue->size--;
	if (my_queue->size == 0)
		my_queue->tail = my_queue->head;
}

void* front_linkqueue(List_Queue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	LIST_QUEUE* my_queue = (LIST_QUEUE*)queue;
	return my_queue->head->next;
}

void* back_linkqueue(List_Queue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	LIST_QUEUE* my_queue = (LIST_QUEUE*)queue;
	return my_queue->tail;
}

int size_linkqueue(List_Queue queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	LIST_QUEUE* my_queue = (LIST_QUEUE*)queue;
	return my_queue->size;
}

int is_empty_linkqueue(List_Queue queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	LIST_QUEUE* my_queue = (LIST_QUEUE*)queue;
	if (my_queue->size==0)
	{
		return 1;
	}
	return 0;
}

void destroy_linkqueue(List_Queue queue)
{
	LIST_QUEUE* my_queue = (LIST_QUEUE*)queue;
	
	if (my_queue->head!=my_queue->tail)
	{
		free(my_queue->head);
		free(my_queue->tail);
	}
	else
	{
		free(my_queue->head);
	}
	free(my_queue);
}
