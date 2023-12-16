#pragma once
#include"Bus.h"
#include"BusStop.h"
#include"QueuePriority.h"
//#include <Windows.h>
//#include<iomanip>
//#include<string>

//void gotoxy(int x, int y)
//{
//	COORD coord;
//	coord.X = x;
//	coord.Y = y;
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}

struct numpunct
	: std::numpunct<char>
{
	std::string do_truename() const { return "правда"; }
	std::string do_falsename() const { return "враньё"; }
};


class BusDepot
{
private:
	string BusDepotName;
	Bus* first = nullptr;
	Bus* last = nullptr;
	int size = 0;


public:
	~BusDepot();
	BusDepot() {}
	BusDepot(string BusDepotName) :BusDepotName(BusDepotName) {}
	void print();
	int getSize();
	void print_first();
	void peek_first();
	void push_back(Bus _a);
	Bus pop();
	Bus pop_queue();
	int getseats();
	Bus operator[](int ind);
	void clear();
};

BusDepot::~BusDepot()
{
	clear();
}

inline void BusDepot::print()
{
	system("cls");

	gotoxy(25, 7);
	cout << "---------- Список автобусов на маршруте ----------\n\n";

	int i = 0;

	if (size > 0)
	{
		Bus* temp = first;
		while (temp)
		{
			gotoxy(25, 8 + i);
			cout << "ID: " << temp->id << " Номер маршрута: " << temp->number << " Кол-во мест: " << temp->seats << endl;
			temp = temp->next;
			i++;
		}
		cout << endl;
	}

	else
	{
		gotoxy(25, 8);
		cout << "На маршруте нет автобусов! Но это легко исправить. Меню -> 1\n\n";
	}

}

inline int BusDepot::getSize()
{
	return size;
}



inline void BusDepot::print_first()
{

	gotoxy(40, 0);
	cout << "-------- Приехал автобус --------\n\n";

	if (size > 0)
	{
		Bus* temp = first;
		while (temp)
		{
			gotoxy(40, 2);
			cout << "ID: " << temp->id << " Номер маршрута: " << temp->number << " Кол-во мест: " << temp->seats << endl;
			temp = nullptr;
		}
		cout << endl;
	}

	else
	{
		gotoxy(40, 0);
		cout << "На маршруте нет автобусов! Но это легко исправить. Меню -> 1\n\n";
	}

}

inline void BusDepot::peek_first()
{
	gotoxy(25, 7);
	cout << "---------- Следующий автобус был снят с маршрута: -----------\n";

	if (size > 0)
	{
		Bus* temp = first;

		gotoxy(25, 8);
		cout << "ID: " << temp->id << " Номер маршрута: " << temp->number << " Кол-во мест: " << temp->seats << endl;
	}

	else
	{
		gotoxy(25, 9);
		cout << "На маршруте нет автобусов! Но это легко исправить. Меню -> 1\n\n";
	}

}

inline void BusDepot::push_back(Bus _a)
{
	if (size == 0)
	{
		first = new Bus;
		first->id = _a.id;
		first->number = _a.number;
		first->seats = _a.seats;
		last = first;
	}

	else
	{
		Bus* temp = new Bus;

		temp->id = _a.id;
		temp->number = _a.number;
		temp->seats = _a.seats;

		last->next = temp;
		last = temp;
	}

	size++;
}

inline Bus BusDepot::pop()
{
	if (size == 0)
	{
		gotoxy(25, 7);
		cout << "Oops!!! На маршруте нет автобусов!";
		cout << endl;
		system("pause");
		exit(1);
	}

	Bus id = first->id;

	if (size == 1)
	{
		delete first;
		first = last = nullptr;
	}

	else
	{
		Bus* temp = first;
		first = first->next;
		delete temp;
	}

	size--;

	return id;
}

inline Bus BusDepot::pop_queue()
{

	if (size == 0)
	{
		gotoxy(25, 7);
		cout << "Oops!!! На маршруте нет автобусов!";
		cout << endl;
		system("pause");
		exit(1);
	}

	Bus id = first->id;

	if (size == 1)
	{
		return id;
	}

	else
	{
		Bus* temp = first;
		first = first->next;
		last->next = temp;
		last = temp;
		temp->next = nullptr;
	}

	return id;
}

inline int BusDepot::getseats()
{
	return first->seats;
}

inline Bus BusDepot::operator[](int ind)
{
	Bus* temp = first;

	for (size_t i = 0; i < ind; i++)
	{
		temp = temp->next;
	}

	return temp->id;
}

inline void BusDepot::clear()
{
	while (size)
		pop();
	first = last = nullptr;
}