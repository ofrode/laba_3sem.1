#include <iostream>
#include "check.h"
#include "employee.h"

using namespace std;

int main()
{
    int num_employees = 0;
    int new_num_employees;
    int chois;
    Employee *employees;
    while (true)
    {
        cout << "Лабораторная работа №1\n\n";
        cout << "1 - Создать первого сотрудника\n";
        cout << "2 - Добавить еще сотрудников\n";
        cout << "3 - Просмотреть список сотрудников\n";
        cout << "4 - Выйти из программы\n";
        cout << "Ваш выбор: ";
        chois = CheckRange(1, 4);
        switch (chois)
        {
        case 1:
            if (num_employees == 0)
            {
                num_employees = 1;
                employees = new Employee[num_employees];
                employees[num_employees - 1].GetEmploy();
                cout << "\nСотрудник создан\n";
            }
            else
            {
                cout << "\nПервый сотрудник был уже добавлен, если нужны еще сотрудники то выберете в меню цифру 2\n";
            }
            break;
        case 2:
            cout << "\nВведите количество сотрудников которых хотите добавить: ";
            new_num_employees = CheckRange(1, 1000000);
            employees = new Employee[num_employees + new_num_employees];
            for (int i = num_employees; i < new_num_employees + num_employees; i++)
            {
                employees[i].GetEmploy();
                cout << "\nСотрудник создан\n";
            }
            num_employees += new_num_employees;
            break;
        case 3:
            cout << "\n=== ИНФОРМАЦИЯ О СОТРУДНИКАХ ===\n";
            for (int i = 0; i < num_employees; i++)
            {
                employees[i].PutEmploy();
                cout << "------------------------\n";
            }
            break;
        case 4:
            delete[] employees;
            return 0;
            break;
        default:
            cout << "\nОшибка\n";
            delete[] employees;
            system("pause");
            return 0;
            break;
        }
    }
}