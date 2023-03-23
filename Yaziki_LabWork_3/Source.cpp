#include <iostream>
#include <string>

double sum2(double u, double v, int k);

bool IntVerifyOnValue(int c, std::string b)
{
	for (int i = 0; i < b.length(); i++)
	{
		if (b[i] == ',')
		{
			std::cout << "Введите целочисленное значение: ";
			return false;
		}
	}
	try
	{
		c = stoi(b);
		return true;
	}
	catch (...)
	{
		std::cout << "Введите целочисленное значение: ";
	}
	return false;
}

bool DoubleVerifyOnValue(double c, std::string b)
{
	try
	{
		c = stod(b);
		return true;
	}
	catch (...)
	{
		std::cout << "Введите число:";
	}
	return false;
}

void printAboutProgramm()
{
	std::cout << "Вариант 11\nНаписать программу, которая считает сумму заданных элементов до определённого момента.\nАвтор программы: Бровцын А.В. Версия 0.9 Beta с защитой от некоректного ввода.\n";
}

int vvod_n(int n)
{
	std::string rep_n;
	bool flag = false;

	std::cout << "Введите число n:";

	do
	{
		std::getline(std::cin, rep_n);

		if (IntVerifyOnValue(n, rep_n))
		{
			n = stoi(rep_n);
			flag = true;
		}
		else
		{
			flag = false;
		}
	} while (!flag);
	return n;
}

double vvod_u(double u)
{
	std::string rep_u;
	bool flag = false;

	std::cout << "Введите число u:";

	do
	{
		std::getline(std::cin, rep_u);

		if (DoubleVerifyOnValue(u, rep_u))
		{
			u = stod(rep_u);
			flag = true;
		}
		else
		{
			flag = false;
		}
	} while (!flag);
	return u;
}

double vvod_v(double v)
{
	std::string rep_v;
	bool flag = false;

	std::cout << "Введите число v:";

	do
	{
		std::getline(std::cin, rep_v);

		if (DoubleVerifyOnValue(v, rep_v))
		{
			v = stod(rep_v);
			flag = true;
		}
		else
		{
			flag = false;
		}
	} while (!flag);
	return v;
}

double sum1(int n, double u, double v)
{
	double ak = u;
	double bk = v;
	double prevAk = ak;
	double prevBk = bk;
	double fact_k = 2;
	double tmp;

	double sum = (ak * bk) / (fact_k);

	std::cout << "k = 1 tmp = " << sum << std::endl;

	for (int k = 2; k <= n; k++)
	{
		prevAk = ak;
		prevBk = bk;
		ak = (2 * prevBk) + prevAk;
		bk = (2 * pow(prevAk, 2)) + prevBk;
		fact_k *= k + 1;

		tmp = (ak * bk) / (fact_k);
		std::cout << "k = " << k << " tmp = " << tmp << std::endl;
		sum += (ak * bk) / (fact_k);
	}
	return sum;
}

int main(int n,double u,double v)
{

	setlocale(LC_ALL, "rus");
	bool flag = false;

	printAboutProgramm();

	 n = vvod_n(n);
	 u = vvod_u(u);
	 v = vvod_v(v);

	std::cout << "Сумма элементов = " << sum1(n, u, v) << std::endl;
	std::cout << "Сумма элементов = " << sum2(u, v, n) << std::endl;
}

double sum2(double u, double v, int k) {
	static double a;
	static double b;
	static double fact;

	if (k == 1) {
		a = u;
		b = v;
		fact = 1 + k;
		std::cout << "k = " << k << " -> " << a * b / fact << std::endl;
		return a * b / fact;
	}
	else {
		double prevSum = sum2(u, v, k - 1);
		double prevA = a;
		double prevB = b;
		a = 2 * prevB + prevA;
		b = 2 * pow(prevA, 2) + prevB;
		fact *= k + 1;
		std::cout << "\nk = " << k << " -> " << (a * b / fact) << std::endl;
		return a * b / fact + prevSum;
	}
}

