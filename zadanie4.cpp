/*
Люди стоят в очереди, но никогда не уходят из её начала, зато могут приходить в конец и уходить оттуда. 
Более того, иногда некоторые люди могут прекращать и начинать беспокоиться из-за того, что очередь не продвигается.
Реализуйте обработку следующих операций над очередью:
•	WORRY i: пометить i-го человека с начала очереди (в нумерации с 0) как беспокоящегося;
•	QUIET i: пометить i-го человека как успокоившегося;
•	COME k: добавить k спокойных человек в конец очереди;
•	COME -k: убрать k человек из конца очереди;
•	WORRY_COUNT: узнать количество беспокоящихся людей в очереди.
Изначально очередь пуста.
Формат ввода
Количество операций Q, затем описания операций.
Для каждой операции WORRY i и QUIET i гарантируется, что человек с номером i существует в очереди на момент операции.
Для каждой операции COME -k гарантируется, что k не больше текущего размера очереди.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Worry(vector<bool>& queue,int human)
{
	if(human >= 0 && human < queue.size())
	queue[human] = true;
}
void Quiet(vector<bool>& queue, int human)
{
	if (human >= 0 && human < queue.size())
	queue[human] = false;
}
void Come(vector<bool>& queue, int k)
{
	if (k < 0 )
	{ 

		for (int i = 0; i < -k; i++)
		{
			queue.pop_back();
		}
	
	}
	if (k > 0)
	{
		for (int i = 0; i < k; i++)
		{
			queue.push_back(false);
		}

	}
	else if (k == 0)
	{
		
	}
	
}
int Worry_Count(vector<bool>& queue)
{
	int count = 0;
	for (int i = 0; i < queue.size(); i++)
	{
		if (queue[i])
			count++;
	}
	return count;
}


int main()
{
	int Q; 
	
		cout << "Enter the number of transactions - " << endl;
		cin >> Q;
		vector<bool> queue;
		for (int i = 0; i < Q; i++)
		{
			string operation;
			cout << "Enter the name of the operation: " << endl;
			cin >> operation;
			if (operation == "WORRY")
			{
				int human;
				cout << "Which person in the queue should be flagged as worried?" << endl;
				cin >> human;
				Worry(queue, human);
			}
			else if (operation == "QUIET")
			{
				int human;
				cout << "Which person in the queue should be flagged as calm down?" << endl;
				cin >> human;
				Quiet(queue, human);
			}
			else if (operation == "COME")
			{
				int k;
				cout << "how many calm people to add to the end of the queue?" << endl;
				cin >> k;
				Come(queue, k);
			}
			else if (operation == "WORRY_COUNT")
			{
				cout << "Number of worried people in queue:" << endl;
				cout<< Worry_Count(queue) << endl;
				
			}
		}
	

	return 0;
}



