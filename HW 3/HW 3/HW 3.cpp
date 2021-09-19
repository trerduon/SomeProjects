#include <iostream>
#include <cmath>
using namespace std;

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
                        
                    }
                    break;
                case 4:
                    break;
                case 5:
                    break;
                }
            }
            break;
        }
        cout << "Нажмите 1, чтобы завершить программу" << endl;
        cin >> a;
    }
}

