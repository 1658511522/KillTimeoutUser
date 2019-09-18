#include "WebServer.h"
#include <iostream>


using namespace std;
//˳����ʼ��
bool InitList(TimeoutSqList & L)
{
	L.elems = new ConnTimeout[MAX_SIZE];
	if (!L.elems)
	{
		return false;
	}
	L.length = 0;
	L.size = MAX_SIZE;
	return true;
}
/********************************
* ˳���������					*
* ���������					*
*			L:˳���			*
*			i:Ԥ���Ԫ��ֵ		*
* �������أ�					*
*			ture	��ӳɹ�	*
*			false	���ʧ��	*
********************************/
bool ListAppend(TimeoutSqList & L, ConnTimeout e)
{
	if (L.length == L.size)
	{
		return false;
	}
	L.elems[L.length] = e;
	L.length++;
	return true;
}
/********************************
* ˳����������				*
* ���������					*
*			L:˳���			*
*			i:Ԥ�����λ��		*
*			e:Ԥ�����Ԫ��		*
* �������أ�					*
*			ture	����ɹ�	*
*			false	����ʧ��	*
********************************/
bool ListInsert(TimeoutSqList & L, int i, ConnTimeout e)
{
	if (L.length == L.size || i<1 || i>L.length)
	{
		return false;
	}

	for (int j = L.length; j >= i; j--)
	{
		L.elems[j] = L.elems[j - 1];
	}

	L.elems[i - 1] = e;
	L.length++;

	return true;
}
/********************************
* ˳���ɾ������				*
* ���������					*
*			L:˳���			*
*			i:Ԥɾ��Ԫ��λ��	*
* �������أ�					*
*			ture	ɾ���ɹ�	*
*			false	ɾ��ʧ��	*
********************************/
bool ListDelete(TimeoutSqList & L, int i)
{
	if (i<0 || i>L.length || (!L.length))
	{
		return false;
	}
	for (int j = i; j < L.length; j++)
	{
		L.elems[j - 1] = L.elems[j];
	}
	L.length--;
	return true;
}
//˳�����Ԫ��ֵɾ������(ɾ��һ��)
//bool ListDeleteByValue(TimeoutSqList & L, ConnTimeout e)
//{
//	if (!L.length)
//	{
//		return false;
//	}
//	for (int i = 0; i < L.length; i++)
//	{
//		if (e == L.elems[i])
//		{
//			ListDelete(L, i + 1);
//			return true;
//		}
//	}
//	return false;
//}
//����˳���
void DestroyList(TimeoutSqList & L)
{
	while (!L.elems)
	{
		delete L.elems;
	}
	L.length = 0;
	L.size = 0;
}
//˳����ӡ
void ListPrint(TimeoutSqList & L)
{
	for (int i = 0; i < L.length; i++)
	{
		//cout << "��" << i + 1 << "��Ԫ��Ϊ:" << L.elems[i] << endl;
		cout << "��" << L.elems[i].fd + 1 << "����ʱ����: " << L.elems[i].timeout << endl;
	}
	cout << endl;
}
