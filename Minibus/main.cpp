#include"Bus_depot.h"
#include"BusStop.h"
//#include<ctime>
//#include <windows.h>
//#include <conio.h>
#include<iostream>
using namespace std;


void gotoxy(int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string* MenuItems();

	ChangeCursorStatus(false);
	typedef void (*TMenuOption)();

	int ItemCount = 5;
	int MenuChoice = 1;
	char key;

	TMenuOption* MenuOption = new TMenuOption[ItemCount];
	MenuOption[0] = MenuFun1;
	MenuOption[1] = MenuFun2;
	MenuOption[2] = MenuFun3;
	MenuOption[3] = MenuFun4;
	MenuOption[4] = ExitOption;

	while (1)
	{
		for (int i = 0; i < ItemCount; i++)
		{
			gotoxy(25, 7 + i);
			MenuChoice == i + 1 ? cout << " -> " : cout << "    ";


			cout << MenuItems()[i] << endl;
		}

		key = _getch();

		switch (key)
		{
		case '\r':
			try
			{
				(*MenuOption[MenuChoice - 1])();

			}
			catch (...)
			{
			}


			break;

		case 'P':
			MenuChoice++;
			if (MenuChoice > ItemCount)
				MenuChoice = 1;
			break;

		case 'H':
			MenuChoice--;
			if (MenuChoice < 1)
				MenuChoice = ItemCount;
			break;

		case 27:
			try { (*MenuOption[ItemCount - 1])(); }


			catch (...) {}
			break;
		default:
			if (key >= '1' && key <= char(ItemCount + '0'))

			{
				try { (*MenuOption[int(key) - '0' - 1])(); }

				catch (...) {}
			}
		}
	}

	delete[] MenuOption;
	return 0;




	system("pause");
}


BusStop bs("Советская стрит");
BusDepot bd("Рога и Копыта");

string cat[] = { "Ветеран АТО", "Пенсионер", "Ученик", "Инвалид", "Другие" };

//string stopname;
//cout << "Введите название остановки: ";
//getline(cin, stopname);

//string compname;
//cout << "Введите название компании: ";
//getline(cin, compname);

//BusStop bs(stopname);
//BusDepot bd(compname);

string* MenuItems()
{
	string* item = new string[5];
	item[0] = "1. Добавить автобус на маршрут.";
	item[1] = "2. Снять автобус с маршрута (первый в очереди).";
	item[2] = "3. Показать Остановку и движение автобусов.";
	item[3] = "4. Показать автобусы на маршруте.";
	item[4] = "5. Выход из программы";

	return item;
}


void MenuFun1()
{
	system("cls");

	int timebus = 0;


	int id;
	int number;
	int seats;
	gotoxy(25, 7);
	cout << "---------- Добавление автобуса на маршрут. -----------\n";
	gotoxy(36, 8);
	cout << "ID: ";
	cin >> id;
	gotoxy(36, 9);
	cout << "Номер маршрута: ";
	cin >> number;
	gotoxy(36, 10);
	cout << "Кол-во пассажирских мест: ";
	cin >> seats;

	Bus a(id, number, seats);

	bd.push_back(a);

	_getch();
	system("cls");
}
//-----------------------------------------------------------------------------------------------
void MenuFun2()
{
	system("cls");
	gotoxy(25, 7);
	bd.peek_first();

	if (bd.getSize())
		bd.pop();

	_getch();
	system("cls");
}
//-----------------------------------------------------------------------------------------------
void MenuFun3()
{
	system("cls");

	int t = 0;
	char Stop = '1';

	do {

		int m = rand() % 1 + 2;

		if (t % m == 0)

			bs.addPeople(People(cat[rand() % 5], 0));

		bs.start();

		if (t != 0 && t % 30 == 0)
		{
			if (bd.getSize())
			{
				int freeseats = bd.getseats() - rand() % 7;

				bd.print_first();

				gotoxy(40, 4);
				cout << "Кол-во свободных мест: " << freeseats << endl << endl;

				if (bs.getSize() > freeseats)
				{
					bs.popPeople(freeseats);
				}

				else
				{
					bs.popPeople(bs.getSize());
				}

				bd.pop_queue();
			}

			else
			{
				gotoxy(40, 4);
				cout << "На маршруте нет автобусов!" << endl << endl;
			}
			gotoxy(40, 6);
			cout << "Любая буква -> Продолжить / 0 возврат к Меню (очередь сохраняется): ";
			cin >> Stop;
		}

		t++;
		Sleep(1000);

	} while (Stop != '0');

	_getch();
	system("cls"); \
}
//-----------------------------------------------------------------------------------------------
void MenuFun4()
{
	system("cls");
	bd.print();
	_getch();
	system("cls");
}
//-----------------------------------------------------------------------------------------------
void ExitOption()
{
	gotoxy(35, 15);

	cout << "Exitting..." << endl;
	_getch();
	exit(0);
}
//-----------------------------------------------------------------------------------------------
void ChangeCursorStatus(bool Visible)
{
	CONSOLE_CURSOR_INFO* c = new CONSOLE_CURSOR_INFO;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	if (Visible)
	{
		c->bVisible = TRUE;
		c->dwSize = 0;
	}
	else
	{
		c->bVisible = FALSE;
		c->dwSize = 1;
	}

	SetConsoleCursorInfo(h, c);
}


//int main()
//{
//	srand(time(0));
//
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	std::cout.setf(std::ios_base::boolalpha);
//
//	locale loc(cout.getloc(), new ::numpunct);
//	cout.imbue(loc);
//
//	string cat[] = { "Ветеран АТО", "Пенсионер", "Ученик", "Инвалид", "Другие" };
//
//	int timebus = 0;
//	
//	string stopname;
//	cout << "Введите название остановки: ";
//    getline(cin, stopname);
//
//	string compname;
//	cout << "Введите название компании: ";
//	getline(cin, compname);
//
//	BusStop bs(stopname);
//	BusDepot bd(compname);
//
//	while (true)
//	{
//		system("cls");
//
//		cout << "Остановка: " << stopname << "\nОбслуживающая компания: " << compname << endl;
//		cout << "1. Добавить автобус на маршрут.\n";
//		cout << "2. Снять автобус с маршрута (первый в очереди).\n";
//		cout << "3. Показать Остановку и движение автобусов.\n";
//		cout << "4. Показать автобусы на маршруте.\n";
//		cout << "5. Выход.\n\n";
//
//		int n;
//
//		cout << "Введите номер Меню: ";
//		cin >> n;
//
//		switch (n)
//		{
//
//		case 1:
//		{
//			system("cls");
//			int id;
//			int number;
//			int seats;
//
//			cout << "Добавление автобуса на маршрут.\n";
//			cout << "ID: ";
//			cin >> id;
//			cout << "Номер маршрута: ";
//			cin >> number;
//			cout << "Кол-во пассажирских мест: ";
//			cin >> seats;
//
//			Bus a(id, number, seats);
//
//			bd.push_back(a);
//
//
//			break;
//		}
//		case 2:
//		{
//			bd.pop();
//			break;
//		}
//
//		case 3:
//		{			
//			system("cls");					
//			
//			int t = 0;
//			char Stop = '1';
//
//			do {
//
//				int m = rand() % 1 + 2;
//
//				if (t % m == 0)
//
//					bs.addPeople(People(cat[rand() % 5], 0));
//
//				bs.start();
//
//				if (t != 0 && t % 30 == 0)
//				{
//
//					int freeseats = bd.getseats() - rand() % 7;
//
//					bd.print_first();
//
//					gotoxy(40, 4);
//					cout << "Кол-во свободных мест: " << freeseats << endl << endl;
//
//					if (bs.getSize() > freeseats)
//					{
//						bs.popPeople(freeseats);
//					}
//
//					else
//					{
//						bs.popPeople(bs.getSize());
//					}
//
//					bd.pop_queue();
//					gotoxy(40, 6);
//					cout << "Укажите 0 для возврата к меню: ";
//					cin >> Stop;
//				}
//
//				t++;
//				Sleep(1000);				
//
//			} while (Stop != '0');		
//
//			break;
//		}
//
//		case 4:
//		{
//			bd.print();
//			system("pause");
//			break;
//		}
//
//		case 5:
//			exit(0);
//
//		default:
//			break;
//		}
//	}
//
//	cout << endl;
//	system("pause");
//}