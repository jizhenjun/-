#include <iostream>
#include <conio.h>
#include "menu_engword.cpp"
using namespace std;
void menu()
{
	cout << "1.古文背诵神器(目前尚未开放)" << endl;
	cout << "2.英语单词/词组背诵神器" << endl;
	cout << "3.政史地背诵神器(目前尚未开放)" << endl;
	cout << "4.退出程序" << endl;
	char ch;
	ch = getch();
	while (ch != '2' && ch != '4') ch = getch();
	if (ch == '2')
	{
		menu_engword();
		menu();
	}
}
