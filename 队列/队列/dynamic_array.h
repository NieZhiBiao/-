#pragma once

typedef struct dynamic_array
{
	void **array_;
	int size;
	int capacity;
}DY_ARR;

//初始化动态数组
void  Init_DynamicArray(void **array1, int capacity);
//删除指定位置的元素
void DelBypos_DynamicArray(void *myarr1, int pos);
//根据比较数据是否相同,删除元素
void DelByData_DynamicArray(void *myarr1, void *data, int(*mycompare)(void *d1, void *d2));
//插入元素
void InsetBypos_DynamicArray(void *myarr1, int pos, void *data);
//头插
void InsetByHeader_DynamicArray(void *myarr, void *data);
//尾插
void InsetByTail_DynamicArray(void *myarr1, void *data);
void  Print_DynamicArray(void *myarr1, void(*myprint)(void *data));
//获取数组有效元素的个数
int GetSize_DynamicArra(void  *myarr1);
//获取数组容量的大小
int GetCapacity_DynamicArra(void *myarr1);
void Destroy_DynamicArray(void **myarr1);