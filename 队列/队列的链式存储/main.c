#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "List_Queue.h"
typedef struct person
{
	void *data;
	char name[64];
	int age;

}PERSON;

int main()
{
	//��ʼ������
	List_Queue queue = init_linkqueue();
	PERSON p1 = { NULL,"С���",10 };
	PERSON p2 = { NULL, "äɮ",20 };
	PERSON p3 = { NULL,"��",30 };
	PERSON p4 = { NULL,"����",40 };
	PERSON p5 = { NULL,"ѹ��",100 };

	push_linkqueue(queue, &p1);
	push_linkqueue(queue, &p2);
	push_linkqueue(queue, &p3);
	push_linkqueue(queue, &p4);
	push_linkqueue(queue, &p5);
	while (is_empty_linkqueue(queue) == 0)
	{
		PERSON *front = (PERSON *)front_linkqueue(queue);
		PERSON *back = (PERSON *)back_linkqueue(queue);
		printf("%s %d\n", front->name, front->age);
		printf("%s %d\n", back->name, back->age);
		printf("\n");
		pop_linkqueue(queue);
	}
	printf("001\n");
	printf("%d\n", size_linkqueue(queue));
	destroy_linkqueue(queue);

	system("pause");
	return 0;
}
