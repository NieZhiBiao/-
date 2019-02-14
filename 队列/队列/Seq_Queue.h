#pragma once
#include "dynamic_array.h"
#define MAXSIZE 1024


void * init_seqQueue();
// 入队操作
void  push_seqQueue(void *queue, void *data);
//出队
void pop_seqQueue(void *queue);
//获取队头元素
void *get_front_seqQueue(void *queue);
//获取队尾元素
void *get_back_seqQueue(void *queue);
//获取队列中size
int get_size_seqQueue(void *queue);
//判断队列是否为空
int  is_empty_seqQueue(void *queue);
//销毁队列
void destroy_seqQueue(void *queue);