#include "../headers/employee.h"
#include <iostream>
#include "../headers/check.h"

using namespace std;

void Employee::getEmploy()
{
    cout << "Введите номер сотрудника: ";
    number = checkRange(1, 1000000);

    cout << "Введите оклад сотрудника: ";
    salary = checkRange(0.0f, 1000000.0f);

    cout << "Введите дату приема на работу (день месяц год): ";
    hireDate.day = checkRange(1, 31);
    hireDate.month = checkRange(1, 12);
    hireDate.year = checkRange(1900, 2011);

    char employeeType;
    cout << "Введите тип сотрудника (l - лаборант, s - секретарь, m - менеджер, d - директор): ";
    while (true)
    {
        cin >> employeeType;
        if (employeeType == 'l' || employeeType == 's' || employeeType == 'm' || employeeType == 'd')
            break;
        cout << "Ошибка. Попробуйте еще раз.\n";
    }

    switch (employeeType)
    {
    case 'l':
        type = Etype::LABORANT;
        break;
    case 's':
        type = Etype::SECRETARY;
        break;
    case 'm':
        type = Etype::MANAGER;
        break;
    case 'd':
        type = Etype::DIRECTOR;
        break;
    default:
        type = Etype::LABORANT;
        break;
    }
}

void Employee::putEmploy() const
{
    cout << "\nИнформация о сотруднике:" << endl;
    cout << "Номер: " << number << endl;
    cout << "Оклад: " << salary << endl;
    cout << "Дата приема на работу: " << hireDate.day << "." << hireDate.month << "." << hireDate.year << endl;
    cout << "Должность: ";

    switch (type)
    {
    case Etype::LABORANT:
        cout << "лаборант";
        break;
    case Etype::SECRETARY:
        cout << "секретарь";
        break;
    case Etype::MANAGER:
        cout << "менеджер";
        break;
    case Etype::DIRECTOR:
        cout << "директор";
        break;
    }
    cout << endl;
}