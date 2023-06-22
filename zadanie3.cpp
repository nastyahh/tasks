/*
3.Реализуйте функцию void Reverse(vector& v), 
которая переставляет элементы вектора в обратном порядке.*/

#include <iostream>
#include <vector>
using namespace std;

void Print(const vector<int>& v)
{
	for (int n : v)
	{
		cout << n << " ";
	}
	cout << endl;
}
void Reverse(vector<int>& v)
{
	int length = v.size();
	for (int i = 0; i < length / 2; i++)
	{
		int element = v[i];
		v[i] = v[length - i - 1];
		v[length - i - 1] = element;
	}
	Print(v);
}

int main()
{
	vector<int> v = { 8,5,2,3,1,7 };
	cout << "Posledovatelnost: " << endl;
	Print(v);
	cout << "Izmenennaya Posledovatelnost: " << endl;
	Reverse(v);
	return 0;
}