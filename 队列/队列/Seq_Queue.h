#pragma once
#include "dynamic_array.h"
#define MAXSIZE 1024


void * init_seqQueue();
// ��Ӳ���
void  push_seqQueue(void *queue, void *data);
//����
void pop_seqQueue(void *queue);
//��ȡ��ͷԪ��
void *get_front_seqQueue(void *queue);
//��ȡ��βԪ��
void *get_back_seqQueue(void *queue);
//��ȡ������size
int get_size_seqQueue(void *queue);
//�ж϶����Ƿ�Ϊ��
int  is_empty_seqQueue(void *queue);
//���ٶ���
void destroy_seqQueue(void *queue);