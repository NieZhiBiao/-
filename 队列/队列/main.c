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
	//初始化队列
	void *queue = init_seqQueue();
	PERSON p1 = { "小鱼儿",10 };
	PERSON p2 = { "盲僧",20 };
	PERSON p3 = { "劫",30 };
	PERSON p4 = { "武器",40 };
	PERSON p5 = { "压缩",100 };
	push_seqQueue(queue, &p1);
	push_seqQueue(queue, &p2);
	push_seqQueue(queue, &p3);
	push_seqQueue(queue, &p4);
	push_seqQueue(queue, &p5);
	while (is_empty_seqQueue(queue) == 0)//不为空
	{
		PERSON *front = get_front_seqQueue(queue);
		PERSON *back = get_back_seqQueue(queue);
		printf("队头为: %s %d\n", front->name, front->age);
		printf("队尾为: %s %d\n", back->name, back->age);
		printf("\n");
		pop_seqQueue(queue);

	}
	destroy_seqQueue(&queue);


	system("pause");
	return 0;
}
