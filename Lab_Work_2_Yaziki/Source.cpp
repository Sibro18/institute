#include <iostream>
#include <string>

struct MARCH {
	std::string start;
	std::string finish;
	int num;
};

void main()
{
	setlocale(LC_ALL, "RUS");
	system("chcp 1251");
	system("cls");
	bool flag = false;
	int size = 0;
	std::cout << "Введите кол-во маршрутов:";
	do {
		try
		{
			std::string razmer;

			std::getline(std::cin, razmer);

			size = stoi(razmer);

			flag = true;

		}
		catch (...)
		{
			std::cout << "Введите число!" << "\n";
		}
	} while (!flag);



	MARCH* arr = new MARCH[size];

	for (int i = 0; i < size; i++)
	{
		std::cout << "Номер маршрута:" << i << std::endl;
		arr[i].num = i;
		std::cout << "Введите название начального пункта: ";
		std::getline(std::cin, arr[i].start);
		std::cout << "Введите название конечного пункта: ";
		std::getline(std::cin, arr[i].finish);
		std::cout << std::endl;
	}

	std::string name;
	std::cout << "Введите название пункта: ";
	std::getline(std::cin, name);

	int k=0;

	for (int i = 0; i < size; i++)
	{
		if ((arr[i].start == name) || (arr[i].finish == name))
		{
			std::cout << "Маршрут номер:  " << arr[i].num << "\n";
			std::cout << "Название начального пункта маршрута: " << arr[i].start << "\n";
			std::cout << "Конечного пункта: " << arr[i].finish << "\n";
			k++;
		}
	}
	if (k == 0) std::cout << "Таких маршрутов нет\n";
	
	delete[]arr;

}