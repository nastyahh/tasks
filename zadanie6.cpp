/*ƒва слова называютс€ синонимами друг друга, если они имеют похожие значени€.
–еализуйте следующие операции над словарЄм синонимов:
Х	ADD word1 word2 Ч добавить в словарь пару синонимов (word1, word2).
Х	COUNT word Ч узнать количество синонимов слова word.
Х	CHECK word1 word2 Ч проверить, €вл€ютс€ ли слова word1 и word2 синонимами.
—лова word1 и word2 считаютс€ синонимами, если среди запросов ADD был хот€ бы один запрос ADD word1 word2
или ADD word2 word1.
‘ормат ввода
—начала вводитс€ количество запросов Q, затем Q строк с описани€ми запросов. 
√арантируетс€, что в каждом запросе CHECK и ADD слова word1 и word2 различны.
¬се слова состо€т лишь из латинских букв, цифр и символов подчЄркивани€.
‘ормат вывода
ƒл€ каждого запроса в соответствующей строке выведите ответ на него:
Х	¬ ответ на запрос COUNT word выведите единственное целое число Ч количество синонимов слова word.
Х	¬ ответ на запрос CHECK word1 word2 выведите строку YES, если word1 и word2 €вл€ютс€ синонимами, 
и NO в противном случае.
‘ормат вывода
ƒл€ каждого запроса в соответствующей строке выведите ответ на него:
Х	¬ ответ на запрос COUNT word выведите единственное целое число Ч количество синонимов слова word.
Х	¬ ответ на запрос CHECK word1 word2 выведите строку YES, если word1 и word2 €вл€ютс€ синонимами,
и NO в противном случае.
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

