#include <iostream>
#include <string>

void foo(double value)
{
	if (value == -0.125)
	{
		throw value;
	}
}

double vvodB(double B, std::string strB)
{
	bool flag = false;
	do
	{
		std::getline(std::cin, strB);
		try
		{
			B = stod(strB);
			flag = true;
			return B;
		}
		catch (...)
		{
			std::cout << "Введите число:";
		}
	} while (!flag);
}

double vvodA(double A, std::string strA)
{
	bool flag = false;
	do
	{
		std::getline(std::cin, strA);
		try
		{
			A = stod(strA);
			flag = true;
			return A;
		}
		catch (...)
		{
			std::cout << "Введите число:";
		}
	} while (!flag);
}

int main()
{
	setlocale(LC_ALL, "rus");
	
	std::string strB="";
	std::string strA="";
	double B=0;
	double A=0;
	double tmp1 = 0;
	double tmp2 = 0;
	double tmp3 = 0;
	double C = 0;
	bool flag = false;
	bool twoWay = false;

	
	std::cout << "Введите число B = ";
	B = vvodB(B, strB);
	std::cout << "Введите число A = ";
	A = vvodA(A, strA);

	do {
		try
		{
			foo(A);
			twoWay = true;
		}
		catch (const double ex)
		{
			std::cout << "деление на ноль, введите число A больше (-0,125):";
			A = vvodA(A, strA);
		}
	} while (!twoWay);

	std::cout << "\n";

	tmp1 = 2 * pow(-B, (1 / 2));
	tmp2 = 1 + 8 * A;
	tmp3 = tmp1 / tmp2;
	C = atan(tmp3) ;
	
	std::cout <<"Выражение C = arctan(2*sqrt(-B)/(1+8*A)) = " << C << std::endl;
}

