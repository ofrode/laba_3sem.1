#include "employee.h"
#include <iostream>
#include "check.h"

using namespace std;

Employee::Employee() 
    : number(0), salary(0.0f), hire_date{1, 1, 2000}, type(Etype::LABORANT) 
{}

Employee::Employee(const Employee& other) 
    : number(other.number), 
      salary(other.salary), 
      hire_date(other.hire_date), 
      type(other.type) 
{}

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

void Employee::PutEmploy () const
{
    cout << "\nИнформация о сотруднике:" << endl;
    cout << "Номер: " << number << endl;
    cout << "Оклад: " << salary << endl;
    cout << "Дата приема на работу: " << hire_date.day << "." << hire_date.month << "." << hire_date.year << endl;
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