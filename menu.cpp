#include <iostream>
#include <conio.h>
#include "menu_engword.cpp"
using namespace std;
void menu()
{
	cout << "1.���ı�������(Ŀǰ��δ����)" << endl;
	cout << "2.Ӣ�ﵥ��/���鱳������" << endl;
	cout << "3.��ʷ�ر�������(Ŀǰ��δ����)" << endl;
	cout << "4.�˳�����" << endl;
	char ch;
	ch = getch();
	while (ch != '2' && ch != '4') ch = getch();
	if (ch == '2')
	{
		menu_engword();
		menu();
	}
}
