#pragma once

enum etype
{
    LABORANT,
    SECRETARY,
    MANAGER,
    DIRECTOR
};

struct date
{
    int day;
    int month;
    int year;
};

class Employee
{
private:
    int number;
    float salary;
    date hire_date;
    etype type;

public:
    void GetEmploy();
    void PutEmploy();
};