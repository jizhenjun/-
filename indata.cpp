#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cstring>
#include <Windows.h>
#include "dictate.cpp"
#include "hangup.cpp"
#include "data.h"
using namespace std;

char* U2G(const char* utf8)
{
int len = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
wchar_t* wstr = new wchar_t[len+1];
memset(wstr, 0, len+1);
MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, len);
len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
char* str = new char[len+1];
memset(str, 0, len+1);
WideCharToMultiByte(CP_ACP, 0, wstr, -1, str, len, NULL, NULL);
if(wstr) delete[] wstr;
return str;
}

void indata(int mode)
{
	system("CLS");
	cout << "���뱳���ĵ����ļ���" << endl;
	string name;
	getline(cin,name);//�����ļ��� 
	name += ".txt";
	inFile.open(name.c_str());
	while (!inFile)
	{
		cout << "���ļ������ڣ�����������:" << endl;
		inFile.clear();
		getline(cin,name);//�����ļ��� 
		name += ".txt";
		inFile.open(name.c_str());
	}
	content word[MAX];
	if (mode == 1) {
		cout << "��ѡ���д���ķ�ʽ��" << endl;
	} else if (mode == 0) {
		cout << "��ѡ���е��ʵķ�ʽ��" << endl;
	}
	char ch;
	if (mode == 0 || mode == 1) {
		cout << "1.�����ģ�ĬдӢ��" << endl;
		cout << "2.��Ӣ�ģ�Ĭд����" << endl;
		ch = getch();
		while (ch != '1' && ch != '2') ch = getch();
	}
	int n = 0;
//	if (ch == '1') 
//	while (getline(inFile,word[n].chi) && getline(inFile,word[n].eng)) n++;
//	if (ch == '2') 
	while (getline(inFile, word[n].eng) && getline(inFile, word[n].chi)) {
		word[n].eng = U2G(word[n].eng.c_str());
		word[n].chi = U2G(word[n].chi.c_str());
		for (int i = word[n].eng.length() - 1; i >= 0; i--) {
			if (isalpha(word[n].eng[i])) {
				word[n].eng = word[n].eng.substr(0, i + 1);
				break;
			}
		}
		n++;	
	}
	if (mode == 2) {
		HangUp(word, n);
	} else {
		dictate(mode, ch - '0', word, n);
	}
	
	inFile.close();
}
