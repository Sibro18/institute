#include <iostream>



void PrintAboutProgram()
{
	std::cout << "Вариант 11\nНаписать программу, которая содержит Указатели на функции.\n";
	std::cout << "Задание В: Посчитать сумму i = 1 -> 100 от суммы j = 1 -> 100 (j - i + 1)/(i+j);\n";
	std::cout << "Задание Г: Посчитать сумму i = 1 -> 100 от суммы j = 1 -> i 1/(2j+i);\n";
	std::cout << "Автор программы : Бровцын А.В.Версия 0.9 Beta с защитой от некоректного ввода.\n";
}


double foo1(double a)
{
	double temp = 0;

	for (int i = 1; i <= 100; i++)
	{
		temp = 0;
		for (int j = 1; j <= 100; j++)
		{
			double v = j - i + 1;
			double c = i + j;
			temp += v/c;
		}
		a += temp;
	}
	return a;
}

double foo2(double a)
{
	double temp = 0;

	for (int i = 1; i <= 100; i++)
	{
		temp = 0;
		for (int j = 1; j <= i; j++)
		{
			double v = 1;
			double c = 2 * j + i;
			temp += v / c;
		}
		a += temp;
	}
	return a;
}

double fooPointer(double (*foo)(double))
{
	double a = 0;
	return foo(a);
}

int main()
{
	setlocale(LC_ALL, "RUS");
	system("cls");
	PrintAboutProgram();
	system("Pause");
	system("cls");
	
	std::string a;
	for (int i = 0; i < a.length(); i++)
	{
		if (!isdigit(a[i]))
		{
			MessageBox::Show("Ошибка");
		}
	}
	double sum1 = fooPointer(&foo1);
	double sum2 = fooPointer(&foo2);

	std::cout << "Сумма1 = " << sum1 << "\n";
	std::cout << "Сумма2 = " << sum2 << "\n";
	return 0;

}