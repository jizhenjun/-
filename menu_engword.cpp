#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "indata.cpp"
using namespace std;
void menu_engword()
{
	system("CLS");
	cout << "1.背诵单词(目前尚未开放)" << endl;
	cout << "2.默写单词" << endl;
	cout << "3.默写词组" << endl;
	cout << "4.更改词库(目前尚未开放)" << endl;
	cout << "5.返回上一级" << endl; 
	char ch;
	ch = getch();
	while (ch != '2' && ch != '3' && ch != '5')
	{
		ch = getch();
	}
	if (ch == '5')
	{
		system("CLS");
		return;
	}
	if(ch == '2' || ch == '3') indata(ch - '2');
}
