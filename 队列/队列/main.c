#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "Seq_Queue.h"
typedef struct person
{
	char name[64];
	int age;

}PERSON;
int main()
{
	//��ʼ������
	void *queue = init_seqQueue();
	PERSON p1 = { "С���",10 };
	PERSON p2 = { "äɮ",20 };
	PERSON p3 = { "��",30 };
	PERSON p4 = { "����",40 };
	PERSON p5 = { "ѹ��",100 };
	push_seqQueue(queue, &p1);
	push_seqQueue(queue, &p2);
	push_seqQueue(queue, &p3);
	push_seqQueue(queue, &p4);
	push_seqQueue(queue, &p5);
	while (is_empty_seqQueue(queue) == 0)//��Ϊ��
	{
		PERSON *front = get_front_seqQueue(queue);
		PERSON *back = get_back_seqQueue(queue);
		printf("��ͷΪ: %s %d\n", front->name, front->age);
		printf("��βΪ: %s %d\n", back->name, back->age);
		printf("\n");
		pop_seqQueue(queue);

	}
	destroy_seqQueue(&queue);


	system("pause");
	return 0;
}
