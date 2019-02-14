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
//���
void push_linkqueue(List_Queue queue, void *data);

//����
void pop_linkqueue(List_Queue queue);

//��ȡ��ͷ
void* front_linkqueue(List_Queue queue);

//��ȡ��β
void* back_linkqueue(List_Queue queue);
//��ȡ����Ԫ�صĸ���
int  size_linkqueue(List_Queue queue);

//�ж϶����Ƿ�Ϊ��
int  is_empty_linkqueue(List_Queue queue);
//���ٶ���
void destroy_linkqueue(List_Queue queue);