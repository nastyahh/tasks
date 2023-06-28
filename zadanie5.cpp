#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char, int> BuildCharCounters(const string& word)
{
	map<char, int> Counter;
	for (auto n : word)
	{
		Counter[n]++;
	}
	return Counter;
}

bool Anagrams(string& word_1, string& word_2)
{
	map<char, int> Counter1 = BuildCharCounters(word_1);
	map<char, int> Counter2 = BuildCharCounters(word_2);
	return Counter1 == Counter2;
}

int main()
{
	int N;
	cout << "enter the number of pairs of words" << endl;
	cin >> N;
	cout << "enter pairs:" << endl;
	for (int i = 0; i < N; i++)
	{
	string word_1, word_2;
	cin >> word_1;
	cin >> word_2;

	if (Anagrams(word_1, word_2))
		cout << "YES"<< endl;
	else
		cout << "NO" << endl;
	}

	return 0;
}

