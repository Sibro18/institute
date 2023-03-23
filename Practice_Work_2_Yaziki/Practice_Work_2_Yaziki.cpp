#include <iostream>
#include <string>



struct card
{
	int bus_num;
	int route_num;
	std::string vodila_name;
	card* next;
};

struct Queue
{
	card* head = NULL, * tail = NULL;
};

void push(Queue** q, int Bn,int Rn,std::string Vn)
{
	card* e = (card*) malloc(sizeof(card));
	e->bus_num = Bn;
	e->next = NULL;

	if ((*q)->head == NULL)
	{
		(*q)->tail = e;
		(*q)->head = e;
	}
	else
	{
		(*q)->tail->next = e;
		(*q)->tail = e;
	}
}

void printAboutProgramm()
{
	std::cout << "Вариант 11\nНаписать программу, которая содержит информацию о наличии автобусов в автобусном парке.\nАвтор программы: Бровцын А.В. Версия 0.9 Beta с защитой от некоректного ввода.\n";
}

void TaskText()
{
	std::cout << "\n" << "1.)Составить программу, которая содержит информацию о наличии автобусов в автобусном парке.\nСведения о каждом автобусе включают:\n	номер автобуса;\n	";
	std::cout << "фамилию и инициалы водителя;\n	номер маршрута.\n2.)Программа должна обеспечивать:\n	хранение данных обо всех автобусах в парке в виде односвязного списка(очередь);\n	";
	std::cout << "добавление данных об автобусах в список при въезде каждого автобуса в парк; \n	удаление данных об автобусе из списка при выезде из парка, фамилия водителя которого введена ";
	std::cout << "с клавиатуры;\n	вывод информации обо всех автобусах, находящихся в парке; \n	по запросу выводится информация обо всех автобусах, работающих на маршруте, ";
	std::cout << "номер которого введён с клавиатуры." << "\n" << "\n";
}

bool VerifyOnValue(int c, std::string b)
{
	try
	{
		c = stoi(b);
		return true;
	}
	catch (...)
	{
		std::cout << "Введите число:";
	}
	return false;
}

bool VerifyOnBukva(std::string a)
{
	for (int i = 0; i < a.length(); i++)
	{
		if ((!(std::isalpha(a[i]) || a[i] == '.')))
		{
			return false;
		}
	}

	return true;
}

bool twoWayBukva(std::string& a)
{
	if (VerifyOnBukva(a) == true)
	{
		return true;
	}
	else
	{
		std::cout << "Введите буквы: ";
		return false;
	}
}

int vvod(const char* strokesize)
{
	std::cout << "Введите кол-во автобусов в парке: ";
	std::string vsego;

	bool flag = false;
	int size = 0;
	do
	{
		std::getline(std::cin, vsego);

		if (VerifyOnValue(size, vsego))
		{
			size = stoi(vsego);
			flag = true;
		}
		else
		{
			flag = false;
		}
	} while (!flag);

	return size;
}

void AddBusNum(int size, card*& arr)
{
	arr = new card[size];

	for (int i = 0; i < size; i++)
	{
		bool flag = false;
		std::string test_bus;
		std::cout << "Введите номер для автобуса " << i + 1 << ": ";

		do
		{
			std::getline(std::cin, test_bus);

			if (VerifyOnValue(arr[i].bus_num, test_bus))
			{
				arr[i].bus_num = stoi(test_bus);
				flag = true;
			}
			else
			{
				flag = false;
			}
		} while (!flag);
	}
	std::cout << std::endl;
}

void AddNameVodila(int size, card* arr)
{
	for (int i = 0; i < size; i++)
	{
		bool flag = false;
		std::string test_bus;
		std::cout << "Введите Фамилию и инициалы водителя на английском языке и без пробелов,\nнапример:(Ivanov.I.I), для автобуса " << i + 1 << ": ";

		do
		{
			std::getline(std::cin, arr[i].vodila_name);

			if (twoWayBukva(arr[i].vodila_name))
			{
				flag = true;
			}
			else
			{
				flag = false;
			}

		} while (!flag);
	}
	std::cout << std::endl;
}

void AddRouteNum(int size, card* arr)
{
	for (int i = 0; i < size; i++)
	{
		bool flag = false;
		std::string test_route;
		std::cout << "Введите номер маршрута для автобуса " << i + 1 << ": ";

		do
		{
			std::getline(std::cin, test_route);

			if (VerifyOnValue(arr[i].route_num, test_route))
			{
				flag = true;
				arr[i].route_num = stoi(test_route);
			}
			else
			{
				flag = false;
			}
		} while (!flag);
	}
	std::cout << std::endl;
}

void Vyvod(int size, card* arr)
{
	std::string marshrut_num;
	std::cout << "Введите номер маршрута:";
	bool flag = false;
	int rep_marsh = 0;
	int k = 0;

	do
	{
		std::getline(std::cin, marshrut_num);

		if (VerifyOnValue(rep_marsh, marshrut_num))
		{
			rep_marsh = stoi(marshrut_num);
			flag = true;
		}
		else
		{
			flag = false;
		}

	} while (!flag);

	std::cout << std::endl;

	for (int i = 0; i < size; i++)
	{
		if (arr[i].route_num == rep_marsh)
		{
			std::cout << "Данный автобус сейчас на маршруте." << std::endl << std::endl;
			std::cout << "Номер автобуса: " << arr[i].bus_num << std::endl;
			std::cout << "Фамилия, инициалы водителя: " << arr[i].vodila_name << std::endl;
			std::cout << "Номер маршрута: " << arr[i].route_num << std::endl << std::endl;
			k++;
		}
	}
	if (k == 0)
	{
		std::cout << "Автобусов работающих по этому маршруту сейчас в парке нет" << std::endl;
	}
}

int menu()
{
	printAboutProgramm();

	std::cout << "Меню" << "\n";
	std::cout << "1. Ввод кол-ва автобусов в парке и ввод информации для водительских карт" << "\n";
	std::cout << "2. Добавление кол-ва автобусов к тем что сейчас есть в парке." << "\n";
	std::cout << "3. Вывод информации обо всех автобусах которые есть в парке." << "\n";
	std::cout << "4. Поиск автобусов по конкретному маршруту(нужно будет ввести номер маршрута)" << "\n";
	std::cout << "5. Удаление из списка информации по Фамили и инициалам водителя." << "\n";
	std::cout << "6. Текст задания" << "\n";
	std::cout << "7. Выход из программы" << "\n";

	std::string k;
	int i = 0;
	bool flag = false;

	do
	{
		std::getline(std::cin, k);

		if (VerifyOnValue(i, k))
		{
			i = stoi(k);
			flag = true;
		}
		else
		{
			flag = false;
		}
	} while (!flag);
	return i;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int size;
	card* arr = 0;
	int p;
	do
	{
		p = menu();
		switch (p)
		{
		case 1:
			size = vvod("Введите кол-во автобусов в парке:");
			AddBusNum(size, arr);
			AddNameVodila(size, arr);
			AddRouteNum(size, arr);
			std::cout << std::endl;
			break;
		case 2:
			Vyvod(size, arr);
			std::cout << std::endl;
			break;
		case 3:
			TaskText();
			break;
		case 4:
			std::cout << "Программа завершена" << std::endl;
			delete[]arr;
			return 0;
		default:
			std::cout << "Введите пункт меню!" << std::endl;
		}
	} while (true);
}