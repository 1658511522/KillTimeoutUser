#pragma onec
#ifndef _WEB_SERVER_H_
#define _WEB_SERVER_H_

#include <time.h>

const int MAX_SIZE = 1000;

typedef struct
{
	int fd;
	time_t timeout;			//ʹ�ó�ʱʱ�̵�ʱ�����ʾ
}ConnTimeout;

typedef struct
{
	ConnTimeout *elems;		//��ʱ�ṹ����ΪԪ��
	int size;
	int length;
}TimeoutSqList;

bool InitList(TimeoutSqList & L);
bool ListAppend(TimeoutSqList & L, ConnTimeout e);
bool ListInsert(TimeoutSqList & L, int i, ConnTimeout e);
bool ListDelete(TimeoutSqList & L, int i);
void DestroyList(TimeoutSqList & L);
void ListPrint(TimeoutSqList & L);

#endif // !_WEB_SERVER_H_
