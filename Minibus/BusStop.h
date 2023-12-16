#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include"MyData.h"
#include"Bus_depot.h"
#include"QueuePriority.h"
#include<iomanip>
#include <Windows.h>
#include <string.h>
#include <conio.h>
#include<ctime>
#include <iostream>

using namespace std;

class People
{
	string category;
	int wait = 0;

public:
	People() {}
	People(string c, int t) :category(c), wait(t) {}
	int getTimeWait();
	void setTimeWait(int t);
	int timeWait = 0;
	//PRIORITY getPrioryty() const; //если нужно с приориетом

	friend ostream& operator <<(ostream& out, const People& obj);
};

inline int People::getTimeWait()
{
	return wait;
}

void People::setTimeWait(int t)
{
	wait = t;
}

ostream& operator<<(ostream& out, const People& obj)
{

	out << left << setw(15) << obj.category << setw(5) << obj.timeWait;// << setw(5) << obj.wait;
	return out;
}

////если нужно с приориетом
//inline PRIORITY People::getPrioryty() const
//{
//
//	if (category == "Пенсионер" || category == "Инвалид")
//		return MEGAHIGH;
//
//	if (category == "Другие")
//		return HIGH;
//
//	if (category == "Ветеран АТО")
//		return MEDIUM;
//	
//	return LOW;
//}

class BusStop
{
	string stopname;
	Queue<People> qpl;
	People currWait;

public:

	BusStop() {}
	BusStop(string stopname) : stopname(stopname) {}
	void addPeople(const People& pl);
	void popPeople(int s);
	void PeopleWait(int t);
	int getSize();
	void start();
};

inline void BusStop::addPeople(const People& pl)
{
	qpl.push(pl);
}

inline void BusStop::popPeople(int s)
{
	for (size_t i = 0; i < s; i++)
	{
		qpl.pop();
	}
}

inline int BusStop::getSize()
{
	return qpl.getSize();
}

void BusStop::start()
{
	system("cls");

	static int timer = 0;

	if (qpl.getSize())
	{
		currWait = qpl.peek();
		cout << "Остановка: " << stopname << endl << endl;
		cout << left << setw(15) << "Пассажир: " << setw(5) << "Время ожидания:" << endl;
		qpl.print();
		cout << "Кол-во людей в очереди: " << qpl.getSize();
		cout << endl;
		cout << "Максимальное время ожидания первого пассажира в очереди: " << currWait.timeWait << " минут" << endl << endl;
		cout << "Общее время движения автобусов: " << timer << " минут" << endl;
		timer++;
		qpl.superMethod();
	}

	else
	{
		cout << "Очередь пустая! На остановке нет пассажиров. Все уехали\n";
	}
}

template<>
inline void Queue<People>::superMethod()
{
	MyData<People>* temp = first;
	while (temp)
	{
		temp->value.timeWait++;
		temp = temp->next;
	}
}

//-----------------------------------------------------------------------------------------------

void gotoxy(int, int);

void ChangeCursorStatus(bool);
void MenuFun1();
void MenuFun2();
void MenuFun3();
void MenuFun4();
void ExitOption();
//-----------------------------------------------------------------------------------------------