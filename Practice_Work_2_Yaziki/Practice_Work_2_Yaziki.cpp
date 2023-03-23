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
	std::cout << "������� 11\n�������� ���������, ������� �������� ���������� � ������� ��������� � ���������� �����.\n����� ���������: ������� �.�. ������ 0.9 Beta � ������� �� ������������ �����.\n";
}

void TaskText()
{
	std::cout << "\n" << "1.)��������� ���������, ������� �������� ���������� � ������� ��������� � ���������� �����.\n�������� � ������ �������� ��������:\n	����� ��������;\n	";
	std::cout << "������� � �������� ��������;\n	����� ��������.\n2.)��������� ������ ������������:\n	�������� ������ ��� ���� ��������� � ����� � ���� ������������ ������(�������);\n	";
	std::cout << "���������� ������ �� ��������� � ������ ��� ������ ������� �������� � ����; \n	�������� ������ �� �������� �� ������ ��� ������ �� �����, ������� �������� �������� ������� ";
	std::cout << "� ����������;\n	����� ���������� ��� ���� ���������, ����������� � �����; \n	�� ������� ��������� ���������� ��� ���� ���������, ���������� �� ��������, ";
	std::cout << "����� �������� ����� � ����������." << "\n" << "\n";
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
		std::cout << "������� �����:";
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
		std::cout << "������� �����: ";
		return false;
	}
}

int vvod(const char* strokesize)
{
	std::cout << "������� ���-�� ��������� � �����: ";
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
		std::cout << "������� ����� ��� �������� " << i + 1 << ": ";

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
		std::cout << "������� ������� � �������� �������� �� ���������� ����� � ��� ��������,\n��������:(Ivanov.I.I), ��� �������� " << i + 1 << ": ";

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
		std::cout << "������� ����� �������� ��� �������� " << i + 1 << ": ";

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
	std::cout << "������� ����� ��������:";
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
			std::cout << "������ ������� ������ �� ��������." << std::endl << std::endl;
			std::cout << "����� ��������: " << arr[i].bus_num << std::endl;
			std::cout << "�������, �������� ��������: " << arr[i].vodila_name << std::endl;
			std::cout << "����� ��������: " << arr[i].route_num << std::endl << std::endl;
			k++;
		}
	}
	if (k == 0)
	{
		std::cout << "��������� ���������� �� ����� �������� ������ � ����� ���" << std::endl;
	}
}

int menu()
{
	printAboutProgramm();

	std::cout << "����" << "\n";
	std::cout << "1. ���� ���-�� ��������� � ����� � ���� ���������� ��� ������������ ����" << "\n";
	std::cout << "2. ���������� ���-�� ��������� � ��� ��� ������ ���� � �����." << "\n";
	std::cout << "3. ����� ���������� ��� ���� ��������� ������� ���� � �����." << "\n";
	std::cout << "4. ����� ��������� �� ����������� ��������(����� ����� ������ ����� ��������)" << "\n";
	std::cout << "5. �������� �� ������ ���������� �� ������ � ��������� ��������." << "\n";
	std::cout << "6. ����� �������" << "\n";
	std::cout << "7. ����� �� ���������" << "\n";

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
			size = vvod("������� ���-�� ��������� � �����:");
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
			std::cout << "��������� ���������" << std::endl;
			delete[]arr;
			return 0;
		default:
			std::cout << "������� ����� ����!" << std::endl;
		}
	} while (true);
}