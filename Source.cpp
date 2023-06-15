#include <iostream>
#include <string>

class CardInPark
{
private:
	int bus_num;
	int marsh_num;
	std::string vodila;
	CardInPark* next;


public:
	static void createBnum(CardInPark* a, int bnum);
	static void createMnum(CardInPark* a, int mnum);
	static void createVodila(CardInPark* a, std::string vodila);
	static CardInPark* card_create(int bus_num, int marsh_num, std::string vodila);
	CardInPark* last_elem();
	static void addCard(CardInPark** old, int bus_num, int marsh_num, std::string vodila);
	static void delSpecCard(CardInPark** list, CardInPark** list2);
	static void delAllElems(CardInPark** list, CardInPark** list2);
	static void serchBus(CardInPark** list, CardInPark** list2);
	static void isNotOnLine(CardInPark** list, CardInPark** list2);
	static void OnLine(CardInPark** list, CardInPark** list2);
	void printAllElems(CardInPark** list, CardInPark** list2);
};

void newException(int a)
{
	if (a > 1 || a < 0)
	{
		throw a;
	}
}

int VerifyOnValue(int n, std::string s)
{
	bool flag = false;

	do {
		std::getline(std::cin, s);

		try
		{
			n = stoi(s);
			return n;
		}
		catch (...)
		{
			std::cout << "������� �����:";
		}
	} while (!flag);

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

void CardInPark::createBnum(CardInPark* a, int bnum)
{
	std::string repBN;
	std::cout << "������� ����� ��������:";
	bnum = VerifyOnValue(bnum, repBN);
	a->bus_num = bnum;
	a->next = NULL;
}

void CardInPark::createVodila(CardInPark* a, std::string vodila)
{
	std::cout << "������� ������� � �������� ��������:";
	bool flag = false;

	do
	{

		std::getline(std::cin, vodila);

		if (twoWayBukva(vodila))
		{
			flag = true;
		}
	} while (!flag);

	a->vodila = vodila;
	a->next = NULL;
}

void CardInPark::createMnum(CardInPark* a, int marsh_num)
{
	std::string repBN;
	std::cout << "������� ����� ��������:";
	marsh_num = VerifyOnValue(marsh_num, repBN);

	a->marsh_num = marsh_num;
	a->next = NULL;
}

CardInPark* CardInPark::card_create(int bus_num, int marsh_num, std::string vodila)
{
	CardInPark* a = new CardInPark;
	createBnum(a, bus_num);
	createVodila(a, vodila);
	createMnum(a, marsh_num);
	return a;
}

CardInPark* CardInPark::last_elem()
{
	CardInPark* temp = this;

	if (this == NULL)
	{
		return NULL;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	return temp;
}

void CardInPark::addCard(CardInPark** old, int bus_num, int marsh_num, std::string vodila)
{
	bool flag = true;
	while (flag)
	{
		CardInPark* newBus = card_create(bus_num, marsh_num, vodila);
		CardInPark* lastBus = NULL;

		if (*old)
		{
			lastBus = (*old)->last_elem();
			lastBus->next = newBus;
		}
		else *old = newBus;
		int k = 0;
		std::string repK;
		bool twoWay = true;
		std::cout << "���� ������ �������� ��� ������� � ������ ������� 1:";
		k = VerifyOnValue(k, repK);


		do
		{
			try
			{
				newException(k);
				twoWay = false;
			}
			catch (const int ex)
			{
				std::cout << "������� ���� 1, ���� 0:";
				k = VerifyOnValue(k, repK);
			}
		} while (twoWay);

		if (k == 0)
		{
			flag = false;
		}
		else flag = true;
	}
}

void CardInPark::printAllElems(CardInPark** list, CardInPark** list2)
{
	CardInPark* current = *list;
	CardInPark* currentForL2 = *list2;
	int k = 0;
	std::string repK;

	std::cout << "������� ����� ������ ����� �������\n0 - �������� � �����\n";
	std::cout << "1 - �������� �� ������:";

	bool twoWay = true;
	k = VerifyOnValue(k, repK);


	do
	{
		try
		{
			newException(k);
			twoWay = false;
		}
		catch (const int ex)
		{
			std::cout << "������� ���� 1, ���� 0:";
			k = VerifyOnValue(k, repK);
		}
	} while (twoWay);

	if (k == 0)
	{
		if (*list)
		{
			for (current; current; current = current->next)
			{
				std::cout << "����� ��������: " << current->bus_num << "\t" << "�������, �������� ��������: " << current->vodila;
				std::cout << "\t" << "����� ��������: " << current->marsh_num;
				std::cout << "\n";
			}
		}
		else
		{
			std::cout << "������ ������." << "\n";
		}
	}
	else if (k == 1)
	{
		if (*list2)
		{
			for (currentForL2; currentForL2; currentForL2 = currentForL2->next)
			{
				std::cout << "����� ��������: " << currentForL2->bus_num << "\t" << "�������, �������� ��������: " << currentForL2->vodila;
				std::cout << "\t" << "����� ��������: " << currentForL2->marsh_num;
				std::cout << "\n";
			}
		}
		else
		{
			std::cout << "������ ������." << "\n";
		}
	}


}

void CardInPark::delSpecCard(CardInPark** list, CardInPark** list2)
{
	std::string delVod;
	CardInPark* PrevL = NULL;
	CardInPark* NextL = NULL;
	bool flag = false;
	bool twoWay = true;
	bool secFlag;
	int k = 0;
	std::string repk = "";
	std::cout << "0 - ������ ��������� ������� �� �������\n1 ������ �������� ������� �� �����\n";
	std::cout << "������� ����� ������ ��������:";

	k = VerifyOnValue(k, repk);

	do
	{
		try
		{
			newException(k);
			twoWay = false;
		}
		catch (const int ex)
		{
			std::cout << "������� ���� 1, ���� 0:";
			k = VerifyOnValue(k, repk);
		}
	} while (twoWay);

	if (k == 0)
	{
		secFlag = true;
	}
	else
	{
		secFlag = false;
	}

	if (secFlag)
	{
		if (*list)
		{
			std::cout << "������� ������� � �������� ��������:";
			do
			{
				std::cin >> delVod;
				if (twoWayBukva(delVod))
				{
					flag = true;
				}
			} while (!flag);

			for (CardInPark* current = *list; current;)
			{
				if (delVod == current->vodila)
				{
					if (!PrevL)
					{
						CardInPark* temp = *list;
						*list = (*list)->next;
						delete(temp);
						current = *list;
					}
					else
					{
						NextL = current->next;
						PrevL->next = NextL;
						delete(current);
						current = NextL;
					}
				}
				else
				{
					PrevL = current;
					current = current->next;
				}
			}
		}
		else
		{
			std::cout << "������ ������." << "\n";
		}
	}
	else
	{
		if (*list2)
		{
			std::cout << "������� ������� � �������� ��������:";
			do
			{
				std::cin >> delVod;
				if (twoWayBukva(delVod))
				{
					flag = true;
				}
			} while (!flag);

			for (CardInPark* currentf2 = *list2; currentf2;)
			{
				if (delVod == currentf2->vodila)
				{
					if (!PrevL)
					{
						CardInPark* temp = *list;
						*list2 = (*list2)->next;
						delete(temp);
						currentf2 = *list2;
					}
					else
					{
						NextL = currentf2->next;
						PrevL->next = NextL;
						delete(currentf2);
						currentf2 = NextL;
					}
				}
				else
				{
					PrevL = currentf2;
					currentf2 = currentf2->next;
				}
			}
		}
		else
		{
			std::cout << "������ ������." << "\n";
		}
	}
}

void CardInPark::delAllElems(CardInPark** list, CardInPark** list2)
{
	bool twoWay = true;
	bool flag;
	int k = 0;
	std::string repk = "";
	std::cout << "0 - ������ ��������� ������� �� �������\n1 ������ �������� ������� �� �����\n";
	std::cout << "������� ����� ������ ��������:";

	k = VerifyOnValue(k, repk);

	do
	{
		try
		{
			newException(k);
			twoWay = false;
		}
		catch (const int ex)
		{
			std::cout << "������� ���� 1, ���� 0:";
			k = VerifyOnValue(k, repk);
		}
	} while (twoWay);

	if (k == 0)
	{
		flag = true;
	}
	else
	{
		flag = false;
	}

	if (flag)
	{
		if (*list)
		{
			CardInPark* temp;

			for (CardInPark* current = *list; current;)
			{
				temp = *list;
				*list = (*list)->next;
				delete(temp);
				current = *list;
			}
			std::cout << "������ ������\n";
		}
		else
		{
			std::cout << "������ ������.\n";
		}
	}
	else
	{
		if (*list2)
		{
			CardInPark* temp;

			for (CardInPark* currentf2 = *list2; currentf2;)
			{
				temp = *list2;
				*list2 = (*list2)->next;
				delete(temp);
				currentf2 = *list2;
			}
			std::cout << "������ ������\n";
		}
		else
		{
			std::cout << "������ ������.\n";
		}
	}
}

void CardInPark::serchBus(CardInPark** list, CardInPark** list2)
{
	bool twoWay = true;
	bool flag;
	int k = 0;
	std::string repk = "";
	std::cout << "0 - ������ ��������� ������� �� �������\n1 ������ �������� ������� �� �����\n";
	std::cout << "������� ����� ������ ��������:";

	k = VerifyOnValue(k, repk);

	do
	{
		try
		{
			newException(k);
			twoWay = false;
		}
		catch (const int ex)
		{
			std::cout << "������� ���� 1, ���� 0:";
			k = VerifyOnValue(k, repk);
		}
	} while (twoWay);

	if (k == 0)
	{
		flag = true;
	}
	else
	{
		flag = false;
	}

	if (flag)
	{
		if (*list != NULL)
		{
			int n = 0;
			std::string nRep;
			std::cout << "������� ����� ��������:";
			n = VerifyOnValue(n, nRep);

			for (CardInPark* current = *list; current; current = current->next)
			{
				if (n == current->marsh_num)
				{
					std::cout << "������� �� �������� ��������: " << "����� ��������:" << current->bus_num << "\t" << "������� �������� ��������:" << current->vodila << "\t";
					std::cout << "����� ��������:" << current->marsh_num << "\n";
				}
			}

		}
		else
		{
			std::cout << "������ ������.";
		}
	}

	else
	{
		if (*list2 != NULL)
		{
			int num = 0;
			std::string repNum;
			std::cout << "������� ����� ��������:";
			num = VerifyOnValue(num, repNum);

			for (CardInPark* currentf2 = *list2; currentf2; currentf2 = currentf2->next)
			{
				if (num == currentf2->marsh_num)
				{
					std::cout << "������� �� �������� ��������: " << "����� ��������:" << currentf2->bus_num << "\t" << "������� �������� ��������:" << currentf2->vodila << "\t";
					std::cout << "����� ��������:" << currentf2->marsh_num << "\n";
				}
			}

		}
		else
		{
			std::cout << "������ ������.";
		}
	}
}


void CardInPark::isNotOnLine(CardInPark** list, CardInPark** list2)
{
	CardInPark* PrevL = NULL;
	CardInPark* NextL = NULL;
	std::string reBnum;
	int bNum = 0;
	std::cout << "������� ����� �������� ������� ������ ��������� � ������ - �������� �� �����:";
	bNum = VerifyOnValue(bNum, reBnum);

	for (CardInPark* current = *list; current;)
	{
		if (bNum == current->bus_num)
		{
			if (!PrevL)
			{
				CardInPark* temp = current;
				if (!*list2)
				{

					*list2 = temp;
					*list = temp->next;
					(*list2)->next = NULL;
					break;
				}
				else
				{
					CardInPark* tmp = (*list2)->last_elem();
					tmp->next = temp;
					*list = temp->next;
					temp->next = NULL;
					break;
				}
			}
			else
			{
				NextL = current->next;
				PrevL->next = NextL;
				if (!*list2)
				{

					*list2 = current;
					(*list2)->next = NULL;
					break;
				}
				else
				{
					CardInPark* tmp = (*list2)->last_elem();
					tmp->next = current;
					current->next = NULL;
					break;
				}

			}
		}
		else
		{
			PrevL = current;
			current = current->next;
		}

	}

}

void CardInPark::OnLine(CardInPark** list, CardInPark** list2)
{
	CardInPark* PrevL = NULL;
	CardInPark* NextL = NULL;
	std::string reBnum;
	int bNum = 0;
	std::cout << "������� ����� �������� ������� ������ ��������� � ������ - �������� �� �����:";
	bNum = VerifyOnValue(bNum, reBnum);

	for (CardInPark* current = *list2; current;)
	{
		if (bNum == current->bus_num)
		{
			if (!PrevL)
			{
				CardInPark* temp = current;
				if (!*list)
				{

					*list = temp;
					*list2 = temp->next;
					(*list)->next = NULL;
					break;
				}
				else
				{
					CardInPark* tmp = (*list)->last_elem();
					tmp->next = temp;
					*list2 = temp->next;
					temp->next = NULL;
					break;
				}
			}
			else
			{
				NextL = current->next;
				PrevL->next = NextL;
				if (!*list)
				{

					*list = current;
					(*list)->next = NULL;
					break;
				}
				else
				{
					CardInPark* tmp = (*list)->last_elem();
					tmp->next = current;
					current->next = NULL;
					break;
				}

			}
		}
		else
		{
			PrevL = current;
			current = current->next;
		}

	}
}

void printAboutProgramm()
{
	std::cout << "������� 11\n�������� ���������, ������� �������� ���������� � ������� ��������� � ���������� �����.\n";
	std::cout << "����� ��������� : ������� �.�.������ 0.9 Beta � ������� �� ������������ �����.\n";
}

void TaskText()
{
	std::cout << "\n" << "1.)��������� ���������, ������� �������� ���������� � ������� ��������� � ���������� �����.\n";
	std::cout << "�������� � ������ �������� �������� : \n����� ��������; \n";
	std::cout << "������� � �������� ��������;\n����� ��������.\n\n2.)��������� ������ ������������:\n";
	std::cout << "�������� ������ ��� ���� ��������� � ����� � ���� ������������ ������(�������); \n";
	std::cout << "���������� ������ �� ��������� � ������ ��� ������ ������� �������� � ����; \n";
	std::cout << "�������� ������ �� �������� �� ������ ��� ������ �� �����, ������� �������� �������� ������� ";
	std::cout << "� ����������;\n����� ���������� ��� ���� ���������, ����������� � �����; \n";
	std::cout << "�� ������� ��������� ���������� ��� ���� ���������, ���������� �� ��������, ";
	std::cout << "����� �������� ����� � ����������." << "\n\n";
	std::cout << "3.)��������� ������ ������������ ������ � ������� ����.\n\n";
	std::cout << "4.)� ��������� ������ ���� ������� ��� ���������� ������:\n �������� ";
	std::cout << "� ����� � �� �����. ��� ������ �� ����� ���������� � ������ ��������\n(�� ";
	std::cout << "���������� ������ ��������) ������ ���� ������������� ������� �� ������\n";
	std::cout << "��������� � ����� � ���������� � ������ ��������� �� �����.\n";
	std::cout << "��� ������ �������� � ���� ���������� � ��� ������ ���� ������������� ������� ��.\n";
	std::cout << "������ ��������� �� ����� � ���������� � ������ ��������� � �����.\n";
	std::cout << "��� ������ ���������� �� ���������, ������������ ������ ������� �����\n";
	std::cout << "������ �������� (�������� � ����� ��� �� �����), ���� ������� ���\n";
	std::cout << "�������� �� ����� �������.\n\n";
}

int menu()
{
	int p = 0;
	std::string repP;

	std::cout << "����" << "\n";
	std::cout << "1. ���� ������������ ����." << "\n";
	std::cout << "2. ����� ���������� �� ���������. " << "\n";
	std::cout << "3. �������� �� ������ �� ������� � ��������� ��������." << "\n";
	std::cout << "4. �������� ������." << "\n";
	std::cout << "5. ������� �������� �� ������ ��������� � �����, � ������ ��������� �� �����." << "\n";
	std::cout << "6. ������� �������� �� ������ ��������� �� �����, � ������ ��������� � �����." << "\n";
	std::cout << "7. ����� ��������� �� ��������" << "\n";
	std::cout << "8. ����� �������." << "\n";
	std::cout << "9. ����� �� ���������" << "\n";

	p = VerifyOnValue(p, repP);

	return p;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int Bnum = NULL;
	int Mnum = NULL;
	std::string vodila;
	CardInPark* L = NULL;
	int p = 0;
	CardInPark* L2 = NULL;

	printAboutProgramm();

	do
	{
		p = menu();
		switch (p)
		{
		case 1:
			system("cls");
			L->addCard(&L, Bnum, Mnum, vodila);
			system("cls");
			break;
		case 2:
			system("cls");
			L->printAllElems(&L, &L2);
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			L->delSpecCard(&L, &L2);
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			L->delAllElems(&L, &L2);
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			L->isNotOnLine(&L, &L2);
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			L->OnLine(&L, &L2);
			system("pause");
			system("cls");
		case 7:
			system("cls");
			L->serchBus(&L, &L2);
			system("pause");
			system("cls");
			break;
		case 8:
			system("cls");
			TaskText();
			system("pause");
			system("cls");
			break;
		case 9:
			system("cls");
			std::cout << "��������� ����������";
			delete(L);
			return 0;
		default:
			std::cout << "������� ����� ����:";
			break;
		}
	} while (1);
}