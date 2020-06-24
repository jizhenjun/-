#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <sstream>
#include "data.h"

using namespace std;

int Check(string text_in, string ans_in) {
	if (text_in == "") {
		return 0;
	}
	istringstream tmp(text_in);
	vector<string> text, ans;
	string xx;
	while (tmp >> xx) {
		text.push_back(xx);
	}
	istringstream tmp2(ans_in);
	while (tmp2 >> xx) {
		ans.push_back(xx);
	}
	int mark1 = (text[0] == ans[0]), mark2 = false;
	int score = 0;
	for (int i = 1; i < text.size(); i++) {
		for (int j = 1; j < ans.size(); j++) {
			if (text[i] == ans[j]) {
				score++;
				break;
			}
		}
	}
	if (score == ans.size() || score >= 2) {
		mark2 = true;
	}
	return mark1 * 2 + mark2;
}

void dictate(bool recite_phrase, int first_chi, content word[],int n)
{
	srand((unsigned)time(NULL));
	int word_count;//���еĵ����� 
	cout << "����������ҪĬд�ĵ�����:" << endl;
	cin >> word_count;
	cin.get();//��ȡ���з� 
	int num[MAX];
	int check[MAX] = {0};
	int i,j,k;//ѭ������ 
	string recite;
	int score = 0;
	n = min(n, word_count);
	int round = 1;
	for (k = 0;k<round;k++)
	{
		j = 0;
		while (j < n)
		{
			num[j]=rand()%n;
			if (check[num[j]] == 0)
			{
				system("CLS");
				cout << "round " << k+1 << " of " << round << endl;
				cout << "Word " << j+1 << " of " << n << endl;
				if (first_chi == 1)  {
					cout << word[num[j]].chi << endl;
				} else {
					cout << word[num[j]].eng << endl;
				}
				
				cout << "��������Ĵ�:" << endl;
				getline(cin, recite);
				while (recite == "") {
					 cout << "����Ϊ�գ�����������:" << endl;
					 getline(cin, recite);
				} 
				
				int correct;
				if (first_chi == 2) {
					correct = Check(recite, word[num[j]].chi);
				}
				
				if (first_chi == 1 || recite_phrase == true) {
					if (recite == word[num[j]].eng) {
						cout << "��ϲ�㣬�����!";
						score++;
					} else {
						cout << "���ź���������!" << endl << "��ȷ���ǣ�" \
								<< "\"" << word[num[j]].eng << "\""<< endl;
					}
				} else if (first_chi == 2) {
					string output = "";
					if (correct == 1) {
						output = "���ź������Դ����!\n��ȷ���ǣ�\"" + word[num[j]].chi + "\"\n";
					} else if (correct == 2) {
						output = "���ź������ķ��벻̫��!\n��ȷ���ǣ�\"" + word[num[j]].chi + "\"\n";
					} else if (correct == 3) {
						output = "��ϲ�㣬�����!";
						score++;
					} else {
						output = "���ź���������!\n��ȷ���ǣ�\"" + word[num[j]].chi + "\"\n";
					} 
					cout << output << endl;
				}
				
				getchar();
				check[num[j]] = 1;
			}
			else j = j - 1;
		j = j + 1;
		}
		for (i = 0;i<n;i++)check[i] = 0;
		cout << "�ڵ�" << k+1 << "��" << ",��Ĭд�Ľ����:(��ȷ�ĸ���/����) " \
		<< score << "/" << n << endl;
		cout << fixed << setprecision(2) << "�����ȷ����" << 100.0 * score / n << "\%" << endl; 
		cin.get();
		score = 0;
	}
	system("CLS");
}
