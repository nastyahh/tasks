/* 1.Ќапишите функцию, котора€
Х	называетс€ IsPalindrom
Х	возвращает bool
Х	принимает параметр типа string и возвращает, €вл€етс€ ли переданна€ строка палиндромом
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

		cout << "введите слово (дл€ выхода введите '1'):" << endl;
		cin >> word;
		while (word != "1") {

			if (IsPalindrom(word)) 
				cout << "слово €вл€етс€ палиндромом" << endl;
			else 
				cout << "слово не €вл€етс€ палиндромом" << endl;

			cout << "введите слово (дл€ выхода введите '1'): ";
			cin >> word;
		}

	return 0;
}