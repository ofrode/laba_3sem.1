#pragma once

enum class Etype
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
    Etype type;

public:
    void GetEmploy();
    void PutEmploy () const;
};