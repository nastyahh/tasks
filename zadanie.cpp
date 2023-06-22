/* 1.Напишите функцию, которая
•	называется IsPalindrom
•	возвращает bool
•	принимает параметр типа string и возвращает, является ли переданная строка палиндромом
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

		cout << "enter a word (to exit enter '1'):" << endl;
		cin >> word;
		while (word != "1") {

			if (IsPalindrom(word)) 
				cout << "the word is a palindrome" << endl;
			else 
				cout << "the word isn't a palindrome" << endl;

			cout << "enter a word (to exit enter '1'): ";
			cin >> word;
		}

	return 0;
}
