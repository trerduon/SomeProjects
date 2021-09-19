#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <stdio.h>
#include <Windows.h>

using namespace std;

int sign(int x)//Homework 4 case 2
{
    if (x > 0) return 1;
    else if (x = 0) return 0;
    else return -1;
}
int rectangle(int a, int b) { return a * b; } //Площадь прямоугольника
float triangle(float a, float b, float c) //Площадь треугольника
{
    float p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
float circle(int r) { return 3.14 * r * r; } //Площадь круга
long generator(long m, long i, long c) //Псевдогенератор случайных чисел
{
    long s = 0;
    for (int j = 0; j < i; j++)
    {
        long s1 = s;
        s = (m * s1 + i) % c;
    }
    return s;
}

int main()
{
    setlocale(LC_ALL, "");

    bool a = 0;
    while (a != 1)
    {
        cout << "Введите номер домашнего задания: \n";
        int homework;
        cin >> homework;

        switch (homework)
        {
        case 3:
            {
                cout << "Введите номер задания: \n[1] - Заем \n[2] - Ссуда \n[3] - Копирование файла \n[4] - Фильтр \n[5] - Сортировка букв \n";
                int operation;
                cin >> operation;
                switch (operation)
                {
                case 1:
                    {
                        cout << "Введите сумму займа, процент и срок через пробел" << endl;
                        float S;
                        float p;
                        float n;
                        cin >> S >> p >> n;
                        float r;
                        r = p / 100;
                        cout << S * r * pow(1 + r, n) / (12 * (pow(1 + r, n) - 1)) << endl;
                    }
                    break;
                case 2: 
                    {
                        cout << "Введите сумму займа, месяцную выплату и срок через пробел" << endl;
                        float S;
                        float m;
                        float n;
                        cin >> S >> m >> n;
                        float p;
                        float dif = S;
                        int p1;
                        for (p = 1; p < 100; p++)
                        {
                            float r = p / 100;
                            if (abs(m - S * r * pow(1 + r, n) / (12 * (pow(1 + r, n) - 1))) < dif)
                            {
                                dif = m - S * r * pow(1 + r, n) / (12 * (pow(1 + r, n) - 1));
                                p1 = p;
                            }
                        }
                        cout << p1 << endl;
                    }
                    break;
                case 3:
                    {
                        cout << "Введите строку \n";
                        string str;
                        cin >> str;

                        fstream F("file.txt", ios::in | ios::out | ios::app);
                        F << str << endl;
                    }
                    break;
                case 4:
                    {
                        fstream F("E:\\Visual studio\\Repos\\SomeProjects\\HW 3\\HW 3\\file.txt");
                        string str;
                        F >> str;
                        int n = 0;
                        for (char ch : str)
                        {
                            if (isdigit(ch))
                                n = n * 10 + (ch - '0');
                        }
                        cout << n << endl;
                    }
                    break;
                case 5:
                    {
                        cout << "Введите последовательность букв" << endl;
                        string str;
                        cin >> str;

                        for (int i = 0; i < (str.length() - 1); i++)
                        {
                            for (int j = i + 1; j < str.length(); j++)
                            {
                                if (str[j] < str[i])
                                {
                                    char k = str[j];
                                    str[j] = str[i];
                                    str[i] = k;
                                }
                            }
                        }

                        cout << str << endl;
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                cout << "Введите номер задания: \n[1] - Файл \n[2] - Знак числа \n[3] - Геометрические фигуры \n[4] - Былая слава \n[5] - Синусоида \n[6] - Автоматный распознаватель \n[7] - Генератор псевдослучайных чисел \n[8] - Умножение матриц \n[9] - Системы счисления \n";
                int operation;
                cin >> operation;
                switch (operation)
                {
                case 1:
                    {
                        cout << "Введите 10 чисел" << endl;
                        fstream F("newfile.txt", ios::in | ios::out | ios::app);
                        int a[10];
                        cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6] >> a[7] >> a[8] >> a[9];
                        for (int i = 0; i < 10; i++) F << a[i] << endl;
                        F.close();
                        ifstream F2("newfile.txt");
                        int sum = 0;
                        for (int i = 0; i < 10; i++) sum += a[i];
                        cout << sum << endl;
                    }
                    break;
                case 2:
                    {
                        cout << "Введите число x" << endl;
                        int x;
                        cin >> x;
                        cout << sign(x) << endl;
                    }
                    break;
                case 3:
                    {
                        cout << "Введите стороны прямоугольника" << endl;
                        int a, b;
                        cin >> a >> b;
                        cout << rectangle(a, b) << endl;

                        cout << "Введите стороны стороны треугольника" << endl;
                        int a1, b1, c1;
                        cin >> a1 >> b1 >> c1;
                        cout << triangle(a1, b1, c1) << endl;

                        cout << "Введите радиус круга" << endl;
                        int r;
                        cin >> r;
                        cout << circle(r) << endl;
                    }
                    break;
                case 4:
                    {
                        cout << "_________________________________" << endl;
                        for(int i = 0; i < 8; i++)
                        {
                            if(i % 2 == 1) cout << "* * * * * *______________________" << endl;
                            else cout << " * * * * * ______________________" << endl;
                        }
                        cout << "  * * * *  ______________________" << endl;
                        for (int i = 0; i < 4; i++) cout << "_________________________________" << endl;
                    }
                    break;
                case 5:
                    {
                        cout << "Ведутся технические работы" << endl;
                    }
                    break;
                case 6:
                    {
                        cout << "Введите число" << endl;
                        string str;
                        cin >> str;
                        int sum = 0;
                        for (int i = 0; i < str.length(); i++)
                        {
                            if (str[i] == 'I') sum += 1;
                            if (str[i] == 'V') sum += 5;
                            if (str[i] == 'X') sum += 10;
                            if (str[i] == 'L') sum += 50;
                            if (str[i] == 'C') sum += 100;
                            if (str[i] == 'D') sum += 500;
                            if (str[i] == 'M') sum += 1000;
                        }
                        cout << sum << endl;
                    }
                    break;
                case 7:
                    {
                        cout << "Введите числа m, i, c" << endl;
                        long m, i, c;
                        cin >> m >> i >> c;
                        cout << generator(m, i, c) << endl;
                    }
                    break;
                case 8:
                    {
                        float A[3][4] = {{5, 2, 0, 10}, {3, 5, 2, 5}, {20, 0, 0, 0}};
                        float B[4][2] = { {1.2, 0.5}, {2.8, 0.4}, {5.0, 1.0}, {2.0, 1.5} };
                        float C[2][3];
                        for (int i = 0; i < 3; i++)
                            for (int j = 0; j < 2; j++)
                            {
                                    C[i][j] = A[i][0] * B[0][j] + A[i][1] * B[1][j] + A[i][2] * B[2][j] + A[i][3] * B[3][j];
                            }

                        for (int i = 0; i < 3; i++)
                        {
                            for (int j = 0; j < 2; j++)
                            {
                                cout << C[i][j] << "\t";
                            }
                            cout << "\n";
                        }
                        cout << "1) " << endl;
                        if (C[0][0] - C[0][1] > C[1][0] - C[1][1] && C[0][0] - C[0][1] > C[2][0] - C[2][1]) cout << "Первый продавец выручил больше всего денег с продажи" << endl;
                        else
                            if (C[1][0] - C[1][1] > C[0][0] - C[0][1] && C[1][0] - C[1][1] > C[2][0] - C[2][1]) cout << "Второй продавец выручил больше всего денег с продажи" << endl;
                            else cout << "Третий продавец выручил больше всего денег с продажи" << endl;

                        if (C[0][0] - C[0][1] < C[1][0] - C[1][1] && C[0][0] - C[0][1] < C[2][0] - C[2][1]) cout << "Первый продавец выручил меньше всего денег с продажи" << endl;
                        else
                            if (C[1][0] - C[1][1] < C[0][0] - C[0][1] && C[1][0] - C[1][1] < C[2][0] - C[2][1]) cout << "Второй продавец выручил меньше всего денег с продажи" << endl;
                            else cout << "Третий продавец выручил меньше всего денег с продажи" << endl;

                        cout << "2) " << endl;
                        if(C[0][1] > C[1][1] && C[0][1] > C[2][1]) cout << "Первый продавец наибольшие комиссионные" << endl;
                        else 
                            if (C[1][1] > C[0][1] && C[1][1] > C[2][1]) cout << "Второй продавец наибольшие комиссионные" << endl;
                            else cout << "Третий продавец наибольшие комиссионные" << endl;
                        if (C[0][1] < C[1][1] && C[0][1] < C[2][1]) cout << "Первый продавец наименьшие комиссионные" << endl;
                        else
                            if (C[1][1] < C[0][1] && C[1][1] < C[2][1]) cout << "Второй продавец наименьшие комиссионные" << endl;
                            else cout << "Третий продавец наименьшие комиссионные" << endl;

                        cout << "3) " << endl;
                        cout << C[0][0] + C[1][0] + C[2][0] - C[0][1] - C[1][1] - C[2][1] << endl;

                        cout << "4) " << endl;
                        cout << C[0][1] + C[1][1] + C[2][1] << endl;

                        cout << "5) " << endl;
                        cout << C[0][0] + C[1][0] + C[2][0] << endl;
                    }
                    break;
                case 9:
                    {
                        
                    }
                    break;
                }
            }
            break;
        }
        cout << "Нажмите 1, чтобы завершить программу" << endl;
        cin >> a;
    }
}


