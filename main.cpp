#include <iostream>
#include <vector>
#include "check.h"
#include "employee.h"

using namespace std;

int main()
{
    int num_employees = 0;
    int new_num_employees;
    int chois;
    vector<Employee> employees;
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
            if (employees.empty())
            {
                Employee emp;
                emp.GetEmploy();
                employees.push_back(emp);
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
            employees.reserve(employees.size() + new_num_employees);
            for (int i = 0; i < new_num_employees; i++)
            {
                Employee emp;
                emp.GetEmploy();
                employees.push_back(emp);
                cout << "\nСотрудник создан\n";
            }
            num_employees = new_num_employees;
            break;
        case 3:
            if (employees.empty())
            {
                cout << "\nСписок сотрудников пуст!\n";
                break;
            }

            cout << "\n=== ИНФОРМАЦИЯ О СОТРУДНИКАХ ===\n";

            for (int i = 0; i < employees.size(); i++)
            {
                employees[i].PutEmploy();
                cout << "------------------------\n";
            }
            break;
        case 4:
            return 0;
        default:
            cout << "\nОшибка\n";
            system("pause");
            return 0;
        }
    }
}