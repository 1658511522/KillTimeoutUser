#include <iostream>
#include <time.h>
#include <Windows.h>
#include "WebServer.h"

using namespace std;
TimeoutSqList list;


//��ʱ��鴦����
static void CheckTimeouts(TimeoutSqList &L, time_t t)
{
	int fd, i;
	cout << "��鳬ʱfd.........." << endl;
	for (int i = 0; i < list.length; i++)
	{
		if (list.elems[i].timeout > t)
		{
			continue;
		}
		fd = list.elems[i].fd;

		cout << "����[fd= " << fd << "]�Ѿ���ʱ���ر�����" << endl;

		ListDelete(list, i);
		i--;
	}
}



int main()
{
	time_t now, end, lastTimeout;

	time(&now);
	end = now + 60;		//60s ���˳�ѭ��
	lastTimeout = now;	//���һ�γ�ʱʱ�丳ֵΪnow

	InitList(list);

	//ģ�ⳬʱ����
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
		if (lastTimeout+0.999<now)		//1sѭ��һ��
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