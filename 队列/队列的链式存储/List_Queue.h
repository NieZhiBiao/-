#pragma once
typedef struct _node
{
	struct _node* next;

}NODE;

typedef struct list_queue
{
	NODE* head;
	NODE* tail;
	int size;
}LIST_QUEUE;

typedef void* List_Queue;

List_Queue init_linkqueue();
//入队
void push_linkqueue(List_Queue queue, void *data);

//出队
void pop_linkqueue(List_Queue queue);

//获取队头
void* front_linkqueue(List_Queue queue);

//获取队尾
void* back_linkqueue(List_Queue queue);
//获取队列元素的个数
int  size_linkqueue(List_Queue queue);

//判断队列是否为空
int  is_empty_linkqueue(List_Queue queue);
//销毁队列
void destroy_linkqueue(List_Queue queue);