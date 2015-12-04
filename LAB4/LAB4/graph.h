#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <climits>
#include <queue>

class Graph
{
	int nr_wierzcholka;
	int nr_wierzcholka2;
	int koszt;
	int liczba_wierzcholkow;
	std::vector <std::list<std::pair<int, int>>> graf;

public:
	Graph(std::string& file_name)
	{
		std::ifstream file;
		file.open(file_name, std::ios::in);

		if (file.good())
		{
			file >> liczba_wierzcholkow;
			graf.resize(liczba_wierzcholkow);
			while (!file.eof())
			{
				file >> nr_wierzcholka;
				file >> nr_wierzcholka2;
				file >> koszt;
				graf[nr_wierzcholka].push_back(std::make_pair(nr_wierzcholka2, koszt));
				graf[nr_wierzcholka2].push_back(std::make_pair(nr_wierzcholka, koszt));
				//std::cout << nr_wierzcholka << " " << nr_wierzcholka2 << " " << koszt << "\n";
			}
		}
		else
		{
			std::cout << "Plik nie został otwarty prawidłowo." << std::endl;
			return;
		}
	}
	void print()
	{
		for (auto i = 0; i < graf.size(); ++i)
		{
			std::cout << i << ": ";
			for (auto j = graf[i].begin(); j != graf[i].end(); ++j)
			{
				std::cout << j->first << "(" << j->second << ") ";
			}
			std::cout << std::endl;
		}
	}
	void dijkstra(std::vector<int>& costs, int start)
	{
		costs.resize(graf.size());
		for (int i = 0; i < graf.size(); ++i)
		{
			costs[i] = INT_MAX;
		}
		costs[start] = 0;
		//std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, compare> Q;
		//jakimiś dodatkowymi punkcikami nie pogardzę :P 
	}
};