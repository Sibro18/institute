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
			std::cout << "Введите число:";
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
		std::cout << "Введите буквы: ";
		return false;
	}
}

void CardInPark::createBnum(CardInPark* a, int bnum)
{
	std::string repBN;
	std::cout << "Введите номер автобуса:";
	bnum = VerifyOnValue(bnum, repBN);
	a->bus_num = bnum;
	a->next = NULL;
}

void CardInPark::createVodila(CardInPark* a, std::string vodila)
{
	std::cout << "Введите фамилию и инициалы водителя:";
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
	std::cout << "Введите номер маршрута:";
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
		std::cout << "Если хотите добавить ещё элемент к списку введите 1:";
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
				std::cout << "Введите либо 1, либо 0:";
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

	std::cout << "Введите какой список нужно вывести\n0 - автобусы в парке\n";
	std::cout << "1 - автобусы на лиинии:";

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
			std::cout << "Введите либо 1, либо 0:";
			k = VerifyOnValue(k, repK);
		}
	} while (twoWay);

	if (k == 0)
	{
		if (*list)
		{
			for (current; current; current = current->next)
			{
				std::cout << "Номер автобуса: " << current->bus_num << "\t" << "Фамилия, инициалы водителя: " << current->vodila;
				std::cout << "\t" << "Номер маршрута: " << current->marsh_num;
				std::cout << "\n";
			}
		}
		else
		{
			std::cout << "Список пустой." << "\n";
		}
	}
	else if (k == 1)
	{
		if (*list2)
		{
			for (currentForL2; currentForL2; currentForL2 = currentForL2->next)
			{
				std::cout << "Номер автобуса: " << currentForL2->bus_num << "\t" << "Фамилия, инициалы водителя: " << currentForL2->vodila;
				std::cout << "\t" << "Номер маршрута: " << currentForL2->marsh_num;
				std::cout << "\n";
			}
		}
		else
		{
			std::cout << "Список пустой." << "\n";
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
	std::cout << "0 - список автобусов которые на стоянке\n1 список атобусов которые на линии\n";
	std::cout << "Введите какой список очистить:";

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
			std::cout << "Введите либо 1, либо 0:";
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
			std::cout << "Введите фамилию и инициалы водителя:";
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
			std::cout << "Список пустой." << "\n";
		}
	}
	else
	{
		if (*list2)
		{
			std::cout << "Введите фамилию и инициалы водителя:";
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
			std::cout << "Список пустой." << "\n";
		}
	}
}

void CardInPark::delAllElems(CardInPark** list, CardInPark** list2)
{
	bool twoWay = true;
	bool flag;
	int k = 0;
	std::string repk = "";
	std::cout << "0 - список автобусов которые на стоянке\n1 список атобусов которые на линии\n";
	std::cout << "Введите какой список очистить:";

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
			std::cout << "Введите либо 1, либо 0:";
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
			std::cout << "Список очищен\n";
		}
		else
		{
			std::cout << "Список пустой.\n";
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
			std::cout << "Список очищен\n";
		}
		else
		{
			std::cout << "Список пустой.\n";
		}
	}
}

void CardInPark::serchBus(CardInPark** list, CardInPark** list2)
{
	bool twoWay = true;
	bool flag;
	int k = 0;
	std::string repk = "";
	std::cout << "0 - список автобусов которые на стоянке\n1 список атобусов которые на линии\n";
	std::cout << "Введите какой список очистить:";

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
			std::cout << "Введите либо 1, либо 0:";
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
			std::cout << "Введите номер маршрута:";
			n = VerifyOnValue(n, nRep);

			for (CardInPark* current = *list; current; current = current->next)
			{
				if (n == current->marsh_num)
				{
					std::cout << "Автобус по таковому маршруту: " << "Номер автобуса:" << current->bus_num << "\t" << "Фамилия инициалы водителя:" << current->vodila << "\t";
					std::cout << "Номер маршрута:" << current->marsh_num << "\n";
				}
			}

		}
		else
		{
			std::cout << "Список пустой.";
		}
	}

	else
	{
		if (*list2 != NULL)
		{
			int num = 0;
			std::string repNum;
			std::cout << "Введите номер маршрута:";
			num = VerifyOnValue(num, repNum);

			for (CardInPark* currentf2 = *list2; currentf2; currentf2 = currentf2->next)
			{
				if (num == currentf2->marsh_num)
				{
					std::cout << "Автобус по таковому маршруту: " << "Номер автобуса:" << currentf2->bus_num << "\t" << "Фамилия инициалы водителя:" << currentf2->vodila << "\t";
					std::cout << "Номер маршрута:" << currentf2->marsh_num << "\n";
				}
			}

		}
		else
		{
			std::cout << "Список пустой.";
		}
	}
}


void CardInPark::isNotOnLine(CardInPark** list, CardInPark** list2)
{
	CardInPark* PrevL = NULL;
	CardInPark* NextL = NULL;
	std::string reBnum;
	int bNum = 0;
	std::cout << "Введите номер автобуса который хотите перевести в список - автобусы на линии:";
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
	std::cout << "Введите номер автобуса который хотите перевести в список - автобусы на линии:";
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
	std::cout << "Вариант 11\nНаписать программу, которая содержит информацию о наличии автобусов в автобусном парке.\n";
	std::cout << "Автор программы : Бровцын А.В.Версия 0.9 Beta с защитой от некоректного ввода.\n";
}

void TaskText()
{
	std::cout << "\n" << "1.)Составить программу, которая содержит информацию о наличии автобусов в автобусном парке.\n";
	std::cout << "Сведения о каждом автобусе включают : \nномер автобуса; \n";
	std::cout << "фамилию и инициалы водителя;\nномер маршрута.\n\n2.)Программа должна обеспечивать:\n";
	std::cout << "хранение данных обо всех автобусах в парке в виде односвязного списка(очередь); \n";
	std::cout << "добавление данных об автобусах в список при въезде каждого автобуса в парк; \n";
	std::cout << "удаление данных об автобусе из списка при выезде из парка, фамилия водителя которого введена ";
	std::cout << "с клавиатуры;\nвывод информации обо всех автобусах, находящихся в парке; \n";
	std::cout << "по запросу выводится информация обо всех автобусах, работающих на маршруте, ";
	std::cout << "номер которого введён с клавиатуры." << "\n\n";
	std::cout << "3.)Программа должна обеспечивать диалог с помощью меню.\n\n";
	std::cout << "4.)В программе должны быть созданы два экземпляра класса:\n автобусы ";
	std::cout << "в парке и на линии. При выезде из парка информация о данном автобусе\n(по ";
	std::cout << "введенному номеру автобуса) должна быть автоматически удалена из списка\n";
	std::cout << "автобусов в парке и переведена в список автобусов на линии.\n";
	std::cout << "При въезде автобуса в парк информация о нем должна быть автоматически удалена из.\n";
	std::cout << "списка автобусов на линии и перенесена в список автобусов в парке.\n";
	std::cout << "При выводе информации об автобусах, пользователь должен выбрать какой\n";
	std::cout << "список выводить (автобусы в парке или на линии), либо вывести все\n";
	std::cout << "автобусы из обоих списков.\n\n";
}

int menu()
{
	int p = 0;
	std::string repP;

	std::cout << "Меню" << "\n";
	std::cout << "1. Ввод водительских карт." << "\n";
	std::cout << "2. Вывод информации об автобусах. " << "\n";
	std::cout << "3. Удаление из списка по фамилии и инициалам водителя." << "\n";
	std::cout << "4. Очистить список." << "\n";
	std::cout << "5. Перенос автобуса из списка автобусов в парке, в список автобусов на линии." << "\n";
	std::cout << "6. Перенос автобуса из списка автобусов на линии, в список автобусов в парке." << "\n";
	std::cout << "7. Поиск автобусов по маршруту" << "\n";
	std::cout << "8. Текст задания." << "\n";
	std::cout << "9. Выход из программы" << "\n";

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
			std::cout << "Программа завершенна";
			delete(L);
			return 0;
		default:
			std::cout << "Введите пункт меню:";
			break;
		}
	} while (1);
}