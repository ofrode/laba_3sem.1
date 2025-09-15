#include "employee.h"
#include <iostream>
#include "check.h"

using namespace std;

void Employee::GetEmploy()
{
    cout << "Введите номер сотрудника: ";
    number = CheckRange(1, 1000000);

    cout << "Введите оклад сотрудника: ";
    salary = CheckRange(0.0f, 1000000.0f);

    cout << "Введите дату приема на работу (день месяц год): ";
    hire_date.day = CheckRange(1, 31);
    hire_date.month = CheckRange(1, 12);
    hire_date.year = CheckRange(1900, 2011);

    char employee_type;
    cout << "Введите тип сотрудника (l - лаборант, s - секретарь, m - менеджер, d - директор): ";
    while (true)
    {
        cin >> employee_type;
        if (employee_type == 'l' || employee_type == 's' || employee_type == 'm' || employee_type == 'd')
            break;
        cout << "Ошибка. Попробуйте еще раз.\n";
    }

    switch (employee_type)
    {
    case 'l':
        type = LABORANT;
        break;
    case 's':
        type = SECRETARY;
        break;
    case 'm':
        type = MANAGER;
        break;
    case 'd':
        type = DIRECTOR;
        break;
    default:
        type = LABORANT;
        break;
    }
}

void Employee::PutEmploy()
{
    cout << "\nИнформация о сотруднике:" << endl;
    cout << "Номер: " << number << endl;
    cout << "Оклад: " << salary << endl;
    cout << "Дата приема на работу: " << hire_date.day << "." << hire_date.month << "." << hire_date.year << endl;
    cout << "Должность: ";

    switch (type)
    {
    case LABORANT:
        cout << "лаборант";
        break;
    case SECRETARY:
        cout << "секретарь";
        break;
    case MANAGER:
        cout << "менеджер";
        break;
    case DIRECTOR:
        cout << "директор";
        break;
    }
    cout << endl;
}