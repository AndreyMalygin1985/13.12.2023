#pragma once

#include<iostream>
using namespace std;

class Bus
{
public:
	int id;
	int number;
	int seats;
	Bus* next = nullptr;

	Bus();
	Bus(int id) : Bus(id, 0, 0) {};
	Bus(int _id, int _number, int _seats);
};

inline Bus::Bus()
{
}

Bus::Bus(int _id, int _number, int _seats)
{
	id = _id;
	number = _number;
	seats = _seats;
}