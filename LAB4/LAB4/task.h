#pragma once
#include <iostream>
#include <string>


class Task
{
public:
	int priorytet;
	int czas_wykonania;
	std::string nazwa;
	Task(std::string nazwa, int priorytet, int czas_wykonania) : priorytet(priorytet), czas_wykonania(czas_wykonania), nazwa(nazwa){}
};