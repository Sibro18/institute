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
	std::cout << "������� ���-�� ���������:";
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
			std::cout << "������� �����!" << "\n";
		}
	} while (!flag);



	MARCH* arr = new MARCH[size];

	for (int i = 0; i < size; i++)
	{
		std::cout << "����� ��������:" << i << std::endl;
		arr[i].num = i;
		std::cout << "������� �������� ���������� ������: ";
		std::getline(std::cin, arr[i].start);
		std::cout << "������� �������� ��������� ������: ";
		std::getline(std::cin, arr[i].finish);
		std::cout << std::endl;
	}

	std::string name;
	std::cout << "������� �������� ������: ";
	std::getline(std::cin, name);

	int k=0;

	for (int i = 0; i < size; i++)
	{
		if ((arr[i].start == name) || (arr[i].finish == name))
		{
			std::cout << "������� �����:  " << arr[i].num << "\n";
			std::cout << "�������� ���������� ������ ��������: " << arr[i].start << "\n";
			std::cout << "��������� ������: " << arr[i].finish << "\n";
			k++;
		}
	}
	if (k == 0) std::cout << "����� ��������� ���\n";
	
	delete[]arr;

}