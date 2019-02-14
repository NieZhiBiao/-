#pragma once

typedef struct dynamic_array
{
	void **array_;
	int size;
	int capacity;
}DY_ARR;

//��ʼ����̬����
void  Init_DynamicArray(void **array1, int capacity);
//ɾ��ָ��λ�õ�Ԫ��
void DelBypos_DynamicArray(void *myarr1, int pos);
//���ݱȽ������Ƿ���ͬ,ɾ��Ԫ��
void DelByData_DynamicArray(void *myarr1, void *data, int(*mycompare)(void *d1, void *d2));
//����Ԫ��
void InsetBypos_DynamicArray(void *myarr1, int pos, void *data);
//ͷ��
void InsetByHeader_DynamicArray(void *myarr, void *data);
//β��
void InsetByTail_DynamicArray(void *myarr1, void *data);
void  Print_DynamicArray(void *myarr1, void(*myprint)(void *data));
//��ȡ������ЧԪ�صĸ���
int GetSize_DynamicArra(void  *myarr1);
//��ȡ���������Ĵ�С
int GetCapacity_DynamicArra(void *myarr1);
void Destroy_DynamicArray(void **myarr1);