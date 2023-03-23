#include <iostream>
#include <string>
#include <fstream>





bool have_2d_num(std::string s)
{
    int counter = 0;
    int size = s.length();
    for (int i = 0; i < size-1;i++)
    {
        if (isdigit(s[i]))
        {
            counter++;
        }
        else {
            if (counter == 2)
            {
                return false;
            }
            else {
                counter = 0;
            }
        }
    }
    return true;
}

int main()
{
    setlocale(LC_ALL, "rus");

    std::string line = "data.txt";
    std::ifstream fin;
    fin.open(line);

    if (!fin.is_open())
    {
        std::cout << "Ошибка открытия файла!" << std::endl;
    }
    else
    {
        std::cout << "Файл открыт!" << std::endl;
        std::cout << "Строки до обработки:" << std::endl;

        std::string str;
        while (!fin.eof())
        {
            str ="";
            getline(fin, str);
            std::cout << str<< std::endl;
        }
        fin.seekg(0);
        std::cout << std::endl;
        std::cout << "Строки после обработки:" << std::endl;
        while (!fin.eof())
        {
            str = "";
            getline(fin, str);
            if (have_2d_num(str))
            {
                std::cout << str << std::endl;
            }
        }
    }
    std::cout << std::endl;
    fin.close();


    return 0;
}