/* 1.�������� �������, �������
�	���������� IsPalindrom
�	���������� bool
�	��������� �������� ���� string � ����������, �������� �� ���������� ������ �����������
*/
#include <iostream>
#include<string>
using namespace std;

bool IsPalindrom(string& word) {
	int dlina = word.size();
	for (int i = 0; i < dlina / 2; i++) {
		if (!(word[i] == word[dlina - 1 - i])) return false;
	}
	return true;
}

int main()
{
	setlocale(0, "ru");
	string word;

		cout << "������� ����� (��� ������ ������� '1'):" << endl;
		cin >> word;
		while (word != "1") {

			if (IsPalindrom(word)) 
				cout << "����� �������� �����������" << endl;
			else 
				cout << "����� �� �������� �����������" << endl;

			cout << "������� ����� (��� ������ ������� '1'): ";
			cin >> word;
		}

	return 0;
}