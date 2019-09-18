#include "WebServer.h"
#include <iostream>


using namespace std;
//顺序表初始化
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
* 顺序表添数据					*
* 输入参数：					*
*			L:顺序表			*
*			i:预添加元素值		*
* 函数返回：					*
*			ture	添加成功	*
*			false	添加失败	*
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
* 顺序表插入数据				*
* 输入参数：					*
*			L:顺序表			*
*			i:预插入的位置		*
*			e:预插入的元素		*
* 函数返回：					*
*			ture	插入成功	*
*			false	插入失败	*
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
* 顺序表删除数据				*
* 输入参数：					*
*			L:顺序表			*
*			i:预删除元素位置	*
* 函数返回：					*
*			ture	删除成功	*
*			false	删除失败	*
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
//顺序表按照元素值删除数据(删除一个)
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
//销毁顺序表
void DestroyList(TimeoutSqList & L)
{
	while (!L.elems)
	{
		delete L.elems;
	}
	L.length = 0;
	L.size = 0;
}
//顺序表打印
void ListPrint(TimeoutSqList & L)
{
	for (int i = 0; i < L.length; i++)
	{
		//cout << "第" << i + 1 << "个元素为:" << L.elems[i] << endl;
		cout << "第" << L.elems[i].fd + 1 << "个超时连接: " << L.elems[i].timeout << endl;
	}
	cout << endl;
}
