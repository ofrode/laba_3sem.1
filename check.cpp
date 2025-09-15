#include "check.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

int GetInput(int)
{
    int value;
    while (true)
    {
        cin >> value;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Введите целое число." << endl;
        }
        else
        {
            if (cin.peek() != '\n')
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка! Введите только целое число без лишних символов." << endl;
            }
            else
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return value;
            }
        }
    }
}

float GetInput(float)
{
    float value;

    while (true)
    {
        cin >> value;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Введите целое число." << endl;
        }
        else
        {
            if (cin.peek() != '\n')
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка! Введите только целое число без лишних символов." << endl;
            }
            else
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return value;
            }
        }
    }
}

int CheckRange(int min, int max)
{
    int value;
    while (true)
    {
        value = GetInput(0);
        if (value <= max && value >= min)
        {
            return value;
        }
        cout << "Ошибка. Попробуйте еще раз.\n";
    }
}

float CheckRange(float min, float max)
{
    float value;
    while (true)
    {
        value = GetInput(0.0f);
        if (value <= max && value >= min)
        {
            return value;
        }
        cout << "Ошибка. Попробуйте еще раз.\n";
    }
}
