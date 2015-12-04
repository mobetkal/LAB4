#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include "task.h"
#include <queue>
#include "graph.h"
using namespace std;

void file_stats(const string& file_name);
void tasks(const std::string& file_name);

void main()
{
	//zadanie 1
	const string test = "test.txt";
	file_stats(test);
	// zadanie 2
	const string f_name = "task.txt";
	tasks(f_name);
	// zadanie 3
	string f_name_graph = "graph.txt";
	Graph graf(f_name_graph);
	graf.print();
	system("PAUSE");
}

struct select
{
	bool operator()(Task &t1, Task &t2)
	{
		if (t1.priorytet != t2.priorytet)
		{
			return t1.priorytet > t2.priorytet;
		}
		else
		{
			return t1.czas_wykonania > t2.czas_wykonania;
		}
	}

};

struct compare
{
	bool operator()(pair<int, int> &koszt1, pair<int, int> &koszt2)
	{
		return koszt1.second > koszt2.second;
	}
};

void tasks(const std::string& file_name)
{
	ifstream file;
	file.open(file_name, ios::in);
	string line;
	priority_queue<Task, vector<Task>, select> kolejka;
	if (file.good())
	{
		while (!file.eof())
		{
			string nazwa;
			int czas, priorytet;
			file >> nazwa;
			file >> priorytet;
			file >> czas;
			Task tmp(nazwa, priorytet, czas);
			kolejka.push(tmp);
		}
	}
	else
	{
		cout << "Plik nie został otwarty prawidłowo." << endl;
		return;
	}
	while (!kolejka.empty())
	{
		Task tmp = kolejka.top();
		cout << tmp.nazwa << " " << tmp.priorytet << " " << tmp.czas_wykonania << endl;
		kolejka.pop();
	}
	cout << endl;
	file.close();
}

void file_stats(const string& file_name)
{
	string text;
	ifstream file;
	file.open(file_name, ios::in);
	map<char, int> histogram;
	if (file.good())
	{
		while (getline(file, text))
		{
			for (auto elem = text.begin(); elem < text.end(); ++elem)
			{
				if (!isspace(*elem))
				{
					histogram[*elem] += 1;
				}
			}
		}
	}
	else
	{
		cout << "Plik nie został otwarty prawidłowo." << endl;
		return;
	}

	for (auto elem = histogram.begin(); elem != histogram.end(); ++elem)
	{
		cout << elem->first << " " << elem->second << endl;
	}
	cout << endl;
	file.close();
}