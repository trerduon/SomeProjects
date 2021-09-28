#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <stdio.h>
#include <Windows.h>
#include <vector>

using namespace std;

int sign(int x)//Homework 4 case 2
{
    if (x > 0) return 1;
    else if (x = 0) return 0;
    else return -1;
}
int rectangle(int a, int b) { return a * b; } //Ïëîùàäü ïðÿìîóãîëüíèêà
float triangle(float a, float b, float c) //Ïëîùàäü òðåóãîëüíèêà
{
    float p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
float circle(int r) { return 3.14 * r * r; } //Ïëîùàäü êðóãà
long generator(long m, long i, long c) //Ïñåâäîãåíåðàòîð ñëó÷àéíûõ ÷èñåë
{
    long s = 0;
    for (int j = 0; j < i; j++)
    {
        long s1 = s;
        s = (m * s1 + i) % c;
    }
    return s;
}

int NODab(int a, int b)
{
    if (b == 0)
        return a;
    else
        return NODab(b, a % b);
}

/*int complete(string num, int s)
{
    int len = num.length();
    int arr[100];
    int newnum = 0;
    for (int i = 0; i < num.length(); i++)
    {
        if (num[len - i] == 'A') arr[i] = 10;
        else if (num[len - i - 1] == 'B') arr[i] = 11;
        else if (num[len - i - 1] == 'C') arr[i] = 12;
        else if (num[len - i - 1] == 'D') arr[i] = 13;
        else if (num[len - i - 1] == 'E') arr[i] = 14;
        else if (num[len - i - 1] == 'F') arr[i] = 15;
        else arr[i] = num[len - i] - '0';
    }
    for (int i = 0; i < num.length(); i++)
        newnum += pow(s, (len - 1 - i)) * arr[i];
    return newnum;
}
*/

int convert(char num[10], int sold)
{
    int i, s, k, p;
    s = 0;
    p = strlen(num) - 1;
    for (i = 0; num[i] != '\0'; i++)
    {
        switch (toupper(num[i]))
        {
        case 'A': k = 10; break;
        case 'B': k = 11; break;
        case 'C': k = 12; break;
        case 'D': k = 13; break;
        case 'E': k = 14; break;
        case 'F': k = 15; break;
        case '1': k = 1; break;
        case '2': k = 2; break;
        case '3': k = 3; break;
        case '4': k = 4; break;
        case '5': k = 5; break;
        case '6': k = 6; break;
        case '7': k = 7; break;
        case '8': k = 8; break;
        case '9': k = 9; break;
        case '0': k = 0; break;
        }
        s = s + k * pow(sold, p);
        p--;
    }
    return s;
}

int main()
{
    setlocale(LC_ALL, "");

    bool a = 0;
    while (a != 1)
    {
        cout << "Ââåäèòå íîìåð äîìàøíåãî çàäàíèÿ: \n";
        int homework;
        cin >> homework;

        switch (homework)
        {
        case 3:
            {
                cout << "Ââåäèòå íîìåð çàäàíèÿ: \n[1] - Çàåì \n[2] - Ññóäà \n[3] - Êîïèðîâàíèå ôàéëà \n[4] - Ôèëüòð \n[5] - Ñîðòèðîâêà áóêâ \n";
                int operation;
                cin >> operation;
                switch (operation)
                {
                case 1:
                    {
                        cout << "Ââåäèòå ñóììó çàéìà, ïðîöåíò è ñðîê ÷åðåç ïðîáåë" << endl;
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
                        cout << "Ââåäèòå ñóììó çàéìà, ìåñÿöíóþ âûïëàòó è ñðîê ÷åðåç ïðîáåë" << endl;
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
                        cout << "Ââåäèòå ñòðîêó \n";
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
                        cout << "Ââåäèòå ïîñëåäîâàòåëüíîñòü áóêâ" << endl;
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
                cout << "Ââåäèòå íîìåð çàäàíèÿ: \n[1] - Ôàéë \n[2] - Çíàê ÷èñëà \n[3] - Ãåîìåòðè÷åñêèå ôèãóðû \n[4] - Áûëàÿ ñëàâà \n[5] - Ñèíóñîèäà \n[6] - Àâòîìàòíûé ðàñïîçíàâàòåëü \n[7] - Ãåíåðàòîð ïñåâäîñëó÷àéíûõ ÷èñåë \n[8] - Óìíîæåíèå ìàòðèö \n[9] - Ñèñòåìû ñ÷èñëåíèÿ \n";
                int operation;
                cin >> operation;
                switch (operation)
                {
                case 1:
                    {
                        cout << "Ââåäèòå 10 ÷èñåë" << endl;
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
                        cout << "Ââåäèòå ÷èñëî x" << endl;
                        int x;
                        cin >> x;
                        cout << sign(x) << endl;
                    }
                    break;
                case 3:
                    {
                        cout << "Ââåäèòå ñòîðîíû ïðÿìîóãîëüíèêà" << endl;
                        int a, b;
                        cin >> a >> b;
                        cout << rectangle(a, b) << endl;

                        cout << "Ââåäèòå ñòîðîíû ñòîðîíû òðåóãîëüíèêà" << endl;
                        int a1, b1, c1;
                        cin >> a1 >> b1 >> c1;
                        cout << triangle(a1, b1, c1) << endl;

                        cout << "Ââåäèòå ðàäèóñ êðóãà" << endl;
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
                        vector<vector<char>> graph(21);
                        for (int i = 0; i < 21; i++)
                        {
                            graph.push_back(vector<char>(41));
                            for (int j = 0; j < 41; j++)
                            {
                                if (j == 20 and i == 10)
                                    graph[i].push_back('+');
                                else if (i == 10)
                                {
                                    graph[i].push_back('-');
                                }
                                else if (j == 20)
                                    graph[i].push_back('|');
                                else
                                {
                                    graph[i].push_back(' ');
                                }
                            }
                        }

                        for (int i = 0; i < 300; i += 15) // x > 0
                        {
                            int y = 10 - round(sinf(i * 3.1415 / 180) * 10.f);
                            int x = 21 + (i / 15);
                            graph[y][x] = '+';
                        }

                        for (int i = 0; i > -300; i -= 15) // x < 0
                        {
                            int y = 10 - round(sinf(i * 3.1415 / 180) * 10.f);
                            int x = 21 + (i / 15);
                            graph[y][x] = '+';
                        }

                        for (int i = 0; i < 21; i++) // âûâîä ìàññèâà
                        {
                            for (int j = 0; j < 41; j++)
                            {
                                cout << ("%c", graph[i][j]);
                            }
                            cout << endl;
                        }
                    }
                    break;
                case 6:
                    {
                        cout << "Ââåäèòå ÷èñëî" << endl;
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
                        cout << "Ââåäèòå ÷èñëà m, i, c" << endl;
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
                        if (C[0][0] - C[0][1] > C[1][0] - C[1][1] && C[0][0] - C[0][1] > C[2][0] - C[2][1]) cout << "Ïåðâûé ïðîäàâåö âûðó÷èë áîëüøå âñåãî äåíåã ñ ïðîäàæè" << endl;
                        else
                            if (C[1][0] - C[1][1] > C[0][0] - C[0][1] && C[1][0] - C[1][1] > C[2][0] - C[2][1]) cout << "Âòîðîé ïðîäàâåö âûðó÷èë áîëüøå âñåãî äåíåã ñ ïðîäàæè" << endl;
                            else cout << "Òðåòèé ïðîäàâåö âûðó÷èë áîëüøå âñåãî äåíåã ñ ïðîäàæè" << endl;

                        if (C[0][0] - C[0][1] < C[1][0] - C[1][1] && C[0][0] - C[0][1] < C[2][0] - C[2][1]) cout << "Ïåðâûé ïðîäàâåö âûðó÷èë ìåíüøå âñåãî äåíåã ñ ïðîäàæè" << endl;
                        else
                            if (C[1][0] - C[1][1] < C[0][0] - C[0][1] && C[1][0] - C[1][1] < C[2][0] - C[2][1]) cout << "Âòîðîé ïðîäàâåö âûðó÷èë ìåíüøå âñåãî äåíåã ñ ïðîäàæè" << endl;
                            else cout << "Òðåòèé ïðîäàâåö âûðó÷èë ìåíüøå âñåãî äåíåã ñ ïðîäàæè" << endl;

                        cout << "2) " << endl;
                        if(C[0][1] > C[1][1] && C[0][1] > C[2][1]) cout << "Ïåðâûé ïðîäàâåö íàèáîëüøèå êîìèññèîííûå" << endl;
                        else 
                            if (C[1][1] > C[0][1] && C[1][1] > C[2][1]) cout << "Âòîðîé ïðîäàâåö íàèáîëüøèå êîìèññèîííûå" << endl;
                            else cout << "Òðåòèé ïðîäàâåö íàèáîëüøèå êîìèññèîííûå" << endl;
                        if (C[0][1] < C[1][1] && C[0][1] < C[2][1]) cout << "Ïåðâûé ïðîäàâåö íàèìåíüøèå êîìèññèîííûå" << endl;
                        else
                            if (C[1][1] < C[0][1] && C[1][1] < C[2][1]) cout << "Âòîðîé ïðîäàâåö íàèìåíüøèå êîìèññèîííûå" << endl;
                            else cout << "Òðåòèé ïðîäàâåö íàèìåíüøèå êîìèññèîííûå" << endl;

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
                        cout << "Ââåäèòå ÷èñëî" << endl;
                        char num[10];
                        cin >> num;
                        cout << "Ââåäèòå ñèñòåìó ñ÷èñëåíèÿ ââåä¸ííîãî ÷èñëà" << endl;
                        int sold;
                        cin >> sold;
                        cout << "Ââåäèòå ñèñòåìó ñ÷èñëåíèÿ, â êîòîðóþ íàäî ïåðåâåñòè ÷èñëî" << endl;
                        int snew;
                        cin >> snew;

                        int Tnum;

                        if (sold > 10) Tnum = convert(num, sold);
                        else int Tnum = stoi(num);
                        
                        int k = 1, newnum = 0;
                        while (Tnum != 0) 
                        {
                            newnum += Tnum % snew * k; 
                            Tnum /= snew; 
                            k *= 10; 
                        }
                        cout << newnum << endl;
                    }
                    break;
                }
            }
            break;
            case 5:
            {
                cout << "Ââåäèòå íîìåð çàäàíèÿ: \n[1] - Àëãîðèòì Åâêëèäà \n[2] - Ðåøåòî Ýðàòîñôåíà \n[3] - Îáðàáîòêà òåêñòîâûõ ôàéëîâ \n[4] - Ðÿäû \n[5] - Ôàéëû \n";
                int operation;
                cin >> operation;
                switch (operation)
                {
                case 1:
                    {
                        cout << "Ââåäèòå 2 ÷èñëà" << endl;
                        int a, b;
                        cin >> a >> b;
                        cout << "Àëãîðèòì Åâêëèäà(äåëåíèå) - " << NODab(a, b) << endl; // Àëãîðèòì Åâêëèäà(äåëåíèå)

                        while (a != b)
                        {
                            if (a > b) a = a - b;
                            else b = b - a;
                        }
                        cout << "Âû÷èòàíèå - " << a << endl; // Íàõîæäåíèå ÍÎÄ âû÷èòàíèåì

                    }
                    break;
                case 2:
                    {
                        int n;
                        cout << "Ââåäèòå ÷èñëî \n";
                        cin >> n;
                        int* a = new int[n + 1];
                        for (int i = 0; i < n + 1; i++) a[i] = i;
                        for (int i = 2; i < n + 1; i++)
                        {
                            if (a[i] != 0)
                            {
                                cout << a[i] << endl;
                                for (int j = i * i; j < n + 1; j += i) a[j] = 0;
                            }
                        }
                    }
                    break;
                case 3:
                    {
                        cout << "Çàäàíèå 1. \nÂâåäèòå ñèìâîë, íà êîòîðûé íàäî çàìåíèòü ïðîáåë" << endl;

                        char n;
                        cin >> n;
                        string str = "hello world";
                        fstream file("SomeFile.txt");
                        getline(file, str);
                        file.close();

                        ofstream ofs;
                        ofs.open("SomeFile.txt", ofstream::out | ofstream::trunc);
                        ofs.close();

                        for (int i = 0; i < size(str); i++)
                            if (str[i] == ' ') str[i] = n;

                        fstream F("SomeFile.txt", ios::in | ios::out | ios::app);
                        F << str << endl;


                        cout << "Çàäàíèå 2. \n" << endl;

                        string line;
                        ifstream in("File_5_3_2.txt"); 
                        if (in.is_open())
                        {
                            getline(in, line);
                        }
                        in.close();     

                        int count = 0;
                        int m = 0;
                        for (int i = 0; i < size(line); i++)
                        {
                            if (line[i] != ' ') count += 1;
                            else
                            {
                                if (m < count) m = count;
                                count = 0;
                            }
                        }
                        cout << "Íàèáîëüøàÿ äëèíà ñëîâà - " << m << endl;
                    }
                    break;
                case 4:
                    {
                        cout << "Çàäàíèå 1. \nÂâåäèòå n" << endl;
                        float n;
                        cin >> n;
                        float y = 0, siny = 0;
                        for (int i = 0; i < n; i++)
                        {
                            siny += sin(n);
                            y += (1 / siny);
                        }
                        cout << y << endl;
                        
                        cout << "Çàäàíèå 3. \nÂâåäèòå n" << endl;
                        cin >> n;
                        y = 1;
                        siny = 0;
                        float y1 = 1;
                        for (int i = 1; i < n + 1; i++)
                        {
                            y1 *= i;
                            siny += sin(2 * i);
                            y *= (y1 / siny);
                        }
                        cout << y << endl;
                    }
                    break;
                case 5:
                    {
                        cout << "Задание 9 \nВведите целые числа файла А" << endl;
                        int a[10];
                        cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6] >> a[7] >> a[8] >> a[9];

                        
                        
                        //  A
                        for (int i = 0; i < 10; i++)
                        {
                            for (int j = i + 1; j < 10; j++)
                            {
                                if (a[j] < a[i])
                                {
                                    int k = a[j];
                                    a[j] = a[i];
                                    a[i] = k;
                                }
                            }
                        }

                        fstream A("File_A.txt", ios::in | ios::out | ios::app);
                        cout << "Сортировка файла А: ";
                        for (int i = 0; i < 10; i++)
                        {
                            cout << a[i] << " ";
                            A << a[i] << " ";
                        }
                        cout << "\n" << endl;

                        //  B
                        cout << "Введите целые числа файла В" << endl;
                        int b[10];
                        cin >> b[0] >> b[1] >> b[2] >> b[3] >> b[4] >> b[5] >> b[6] >> b[7] >> b[8] >> b[9];

                        for (int i = 0; i < 10; i++)
                        {
                            for (int j = i + 1; j < 10; j++)
                            {
                                if (b[j] < b[i])
                                {
                                    int k = b[j];
                                    b[j] = b[i];
                                    b[i] = k;
                                }
                            }
                        }

                        fstream B("File_B.txt", ios::in | ios::out | ios::app);
                        cout << "Сортировка файла B: ";
                        for (int i = 0; i < 10; i++)
                        {
                            cout << b[i] << " ";
                            B << b[i] << " ";
                        }
                        cout << "\n" << endl;

                        //  C
                        int c[20];
                        for (int i = 0; i < 20; i++)
                            if (i < 10) c[i] = a[i];
                            else c[i] = b[i-10];

                        for (int i = 0; i < 20; i++)
                        {
                            for (int j = i + 1; j < 20; j++)
                            {
                                if (c[j] < c[i])
                                {
                                    int k = c[j];
                                    c[j] = c[i];
                                    c[i] = k;
                                }
                            }
                        }

                        fstream C("File_C.txt", ios::in | ios::out | ios::app);
                        cout << "Сортировка файла С: ";
                        for (int i = 0; i < 20; i++)
                        {
                            cout << c[i] << " ";
                            C << c[i] << " ";
                        }
                        cout << endl;
                    }
                    break;
                }
            }
            break;
        }
        cout << "Íàæìèòå 1, ÷òîáû çàâåðøèòü ïðîãðàììó" << endl;
        cin >> a;
    }
}


