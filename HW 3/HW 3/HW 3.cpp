#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    bool a = 0;
    while (a != 1)
    {
        cout << "������� ����� ��������� �������: \n";
        int homework;
        cin >> homework;

        switch (homework)
        {
        case 3:
            {
                cout << "������� ����� �������: \n[1] - ���� \n[2] - ����� \n[3] - ����������� ����� \n[4] - ������ \n[5] - ���������� ���� \n";
                int operation;
                cin >> operation;
                switch (operation)
                {
                case 1:
                    {
                        cout << "������� ����� �����, ������� � ���� ����� ������" << endl;
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
                        cout << "������� ����� �����, �������� ������� � ���� ����� ������" << endl;
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
        cout << "������� 1, ����� ��������� ���������" << endl;
        cin >> a;
    }
}

