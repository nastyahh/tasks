/*��� ����� ���������� ���������� ���� �����, ���� ��� ����� ������� ��������.
���������� ��������� �������� ��� ������� ���������:
�	ADD word1 word2 � �������� � ������� ���� ��������� (word1, word2).
�	COUNT word � ������ ���������� ��������� ����� word.
�	CHECK word1 word2 � ���������, �������� �� ����� word1 � word2 ����������.
����� word1 � word2 ��������� ����������, ���� ����� �������� ADD ��� ���� �� ���� ������ ADD word1 word2
��� ADD word2 word1.
������ �����
������� �������� ���������� �������� Q, ����� Q ����� � ���������� ��������. 
�������������, ��� � ������ ������� CHECK � ADD ����� word1 � word2 ��������.
��� ����� ������� ���� �� ��������� ����, ���� � �������� �������������.
������ ������
��� ������� ������� � ��������������� ������ �������� ����� �� ����:
�	� ����� �� ������ COUNT word �������� ������������ ����� ����� � ���������� ��������� ����� word.
�	� ����� �� ������ CHECK word1 word2 �������� ������ YES, ���� word1 � word2 �������� ����������, 
� NO � ��������� ������.
������ ������
��� ������� ������� � ��������������� ������ �������� ����� �� ����:
�	� ����� �� ������ COUNT word �������� ������������ ����� ����� � ���������� ��������� ����� word.
�	� ����� �� ������ CHECK word1 word2 �������� ������ YES, ���� word1 � word2 �������� ����������,
� NO � ��������� ������.
*/

#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

void Add(const string& word1, const string& word2, map<string,set<string>>& synonyms)
{
	synonyms[word1].insert(word2);
	synonyms[word2].insert(word1);
}

int main()
{
	int Q;
	string operation;
	map<string, set<string>> synonyms;
	cout << "enter the number of requests" << endl;
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		cout << "enter operation name" << endl;
		cin >> operation;
		if (operation == "ADD")
		{
			string word1, word2;
			cin >> word1 >> word2;
			Add(word1, word2, synonyms);
		}
		else if (operation == "COUNT")
		{
			string word;
			cout << "enter a word:" << endl;
			cin >> word;
			if (synonyms.count(word) > 0)
			{
				cout << synonyms[word].size() << endl;
			}
			else
				cout << "there are no synonyms for this word" << endl;
		}
		else if (operation == "CHECK")
		{
			string word1, word2;
			cout << "enter the words:" << endl;
			cin >> word1 >> word2;
			if (synonyms.count(word1) > 0 && synonyms.count(word2) > 0)
			{
				cout << "Yes" << endl;
			}
			else
				cout << "No" << endl;
		}
	}
	return 0;
}

