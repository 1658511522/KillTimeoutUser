#include <iostream>
#include <time.h>
#include <Windows.h>
#include "WebServer.h"

using namespace std;
TimeoutSqList list;


//超时检查处理函数
static void CheckTimeouts(TimeoutSqList &L, time_t t)
{
	int fd, i;
	cout << "检查超时fd.........." << endl;
	for (int i = 0; i < list.length; i++)
	{
		if (list.elems[i].timeout > t)
		{
			continue;
		}
		fd = list.elems[i].fd;

		cout << "连接[fd= " << fd << "]已经超时，关闭连接" << endl;

		ListDelete(list, i);
		i--;
	}
}



int main()
{
	time_t now, end, lastTimeout;

	time(&now);
	end = now + 60;		//60s 后退出循环
	lastTimeout = now;	//最近一次超时时间赋值为now

	InitList(list);

	//模拟超时连接
	for (int i = 0; i < 10; i++)
	{
		ConnTimeout e;
		e.fd = i;
		e.timeout = now + 5 + 2 * i;
		ListAppend(list,e);
	}

	ListPrint(list);

	do
	{
		if (lastTimeout+0.999<now)		//1s循环一次
		{
			CheckTimeouts(list, now);
			lastTimeout = now;
		}
		Sleep(10);
		time(&now);

	} while (now<end);


	system("pause");
	return 0;
}