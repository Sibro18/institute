#include <iostream>
#include <string>

int nod(int, int);

bool IntVerifyonValue(int n, std::string s)
{
	try
	{
		std::getline(std::cin, s);
		n = stoi(s);
		return true;
	}
	catch (...)
	{
		std::cout << "Введите число:";
	}
	return false;
}

void main(std::string* arr)
{
	setlocale(LC_ALL, "RUS");
	const int SIZE = 10;
	int res[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		std::cout << "Введите значение " << i << ": ";
		
		bool flag = false;
		do 
		{
			try 
			{
				std::getline(std::cin, arr[i]);
				res[i] = stoi(arr[i]);
				flag = true;
			}
			catch (...)
			{
				
				std::cout << "Введите корректное число а не символ!" << std::endl;
			} 
		}while(!flag);
	}
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << res[i] << "\n";
	}

	int gcd = nod(res[0], res[1]);
	for (int i = 2; i < SIZE; i++)
	{
		gcd = nod(gcd, res[i]);

	}
	std::cout << std::endl;
	std::cout << "Наибольший общий делитель:" << gcd;
}

int nod(int a, int b)
{
	while (a != b)
	{
		if (a > b)
		{
			int temp = a;
			a = b;
			b = temp;
		}

		b = b - a;

	}
	return a;
}



