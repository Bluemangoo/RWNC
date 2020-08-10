#include<windows.h>
#include<pthread.h>
#include<string>
#include<iostream>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
using namespace std;
string command;
void* con(void* arg)
{
	bool onshow=1;
	HWND hwnd;
	hwnd=FindWindow("ConsoleWindowClass",NULL);
	while(1)
	{
		if(KEY_DOWN(123))
			{
				ShowWindow(hwnd,SW_HIDE);
			}
		if(KEY_DOWN(19))
			{
				ShowWindow(hwnd,SW_SHOW);
			}
		_sleep(10);
	}
} 
int main(int argc,char *argv[])
{
	char aa[1000];
	int n=0;
	while(1)
	{
		aa[n]=*(argv[1]+n);
		if(!aa[n])
			break;
		n++;
	}
	const char *abc = aa;
	pthread_t tid;
	pthread_create(&tid, NULL, con, NULL);
	system(abc);
	return 0;
}
