#include <iostream>
#include "./headers/check.h"
#include "./headers/employee.h"

using namespace std;

int main()
{
    int numEmployees = 0;
    int newNumEmployees;
    int chois;
    Employee *employees;
    Employee *newEmployees;
    while (true)
    {
        cout << "Лабораторная работа №1\n\n";
        cout << "1 - Создать первого сотрудника\n";
        cout << "2 - Добавить еще сотрудников\n";
        cout << "3 - Просмотреть список сотрудников\n";
        cout << "4 - Выйти из программы\n";
        cout << "Ваш выбор: ";
        chois = checkRange(1, 4);
        switch (chois)
        {
        case 1:
            if (numEmployees == 0)
            {
                numEmployees = 1;
                employees = new Employee[numEmployees];
                employees[numEmployees - 1].getEmploy();
                cout << "\nСотрудник создан\n";
            }
            else
            {
                cout << "\nПервый сотрудник был уже добавлен, если нужны еще сотрудники то выберете в меню цифру 2\n";
            }
            break;
        case 2:
            cout << "\nВведите количество сотрудников которых хотите добавить: ";
            newNumEmployees = checkRange(1, 1000000);
            newEmployees = new Employee[numEmployees + newNumEmployees];
            for (int i = 0; i < numEmployees; i++)
            {
                newEmployees[i] = Employee(employees[i]);
            }
            delete[] employees;
            employees = newEmployees;
            for (int i = numEmployees; i < newNumEmployees + numEmployees; i++)
            {
                employees[i].getEmploy();
                cout << "\nСотрудник создан\n";
            }
            numEmployees += newNumEmployees;
            break;
        case 3:
            cout << "\n=== ИНФОРМАЦИЯ О СОТРУДНИКАХ ===\n";
            if (numEmployees == 0)
            {
                cout << "Нет сотрудников\n";
                break;
            }
            for (int i = 0; i < numEmployees; i++)
            {
                employees[i].putEmploy();
                cout << "------------------------\n";
            }
            break;
        case 4:
            if (numEmployees != 0)
            {
                delete[] employees;
            }
            return 0;
        default:
            delete[] employees;
            cout << "\nОшибка\n";
            system("pause");
            return 0;
        }
    }
}