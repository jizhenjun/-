#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "data.h"
using namespace std;

void guess(string answer)
{
	char word[50],letter[1];
	int length;
	length = answer.length();
	cout << "The length of the word is:" << length << endl;
	for (int i = 0;i<length;i++)
	{
		word[i] = '_';
		cout << word[i] << " ";
	}
    cout << endl;
	int times;
	times = length;//ÅÐ¶ÏÊ£Óà»ú»á
	while (times != 0)
	{
		int p,q,s;
		p = 0;//ÅÐ¶ÏÊÇ·ñ²Â¶Ô
		q = 0;//ÅÐ¶ÏÊÇ·ñ²Â¹ý
		s = 0;//ÅÐ¶ÏÊÇ·ñ»ñÊ¤
		cout << "Please input the letter you guess:";
		cin >> letter[0];
        for (int j = 0;j<length;j++) if (word[j] == letter [0])
        {
            q = 1;
            break;
        }
		if (q == 1) cout << "Please don't input the repeat number." << endl;
		for (int i = 0;i<length;i++) if (answer[i] == letter[0])
		{
			p = 1;
			word[i] = letter[0];
		}
		if (p == 0 and q != 1)
		{
			times--;
			cout << "The letter you guessed is wrong!" << endl;
			for (int i = 0;i<length;i++) cout << word[i] << " ";
            cout << endl;
		}
		if (p != 0 and q == 0)
		{
			cout << "The letter you guessed is true!" << endl;
			for (int i = 0;i<length;i++) cout << word[i] << " ";
            cout << endl;
		}
		for (int i = 0;i<length;i++) if (word[i] == '_') s = 1;
        cout << "You have " << times << " chances." << endl;
		if (s == 0)
		{
			cout << "Congratulations! You win!" << endl;
		}
	}
	cout << "The answer is " << "¡°" << answer << "¡±." << endl;
	cout << "What a shame! You lose!" << endl;
    return;
}

void HangUp(content word[], int word_count) {
	srand ((unsigned)time(NULL));
	while (true) {
		int index = rand() % word_count;
		guess(word[index].eng);
		cout << "ÊÇ·ñ¼ÌÐø(Y/N)" << endl;
		char ch;
		ch = getch();
		while (ch != 'y' && ch != 'n' && ch != 'Y' && ch != 'N') {
			ch = getch();
		}
		system("CLS");
		if (ch == 'n' || ch == 'N') {
			break;
		}
	}
}
