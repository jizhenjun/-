#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "indata.cpp"
using namespace std;
void menu_engword()
{
	system("CLS");
	cout << "1.���е���(Ŀǰ��δ����)" << endl;
	cout << "2.Ĭд����" << endl;
	cout << "3.Ĭд����" << endl;
	cout << "4.���Ĵʿ�(Ŀǰ��δ����)" << endl;
	cout << "5.������һ��" << endl; 
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
