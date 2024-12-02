#include "person.h"

void employee::setSalary(double sal)
{
    if (sal >= 60000)
    {
        salary = sal;
    }
    else
    {
        salary = 60000;
    }
}

void employee::setPosition(std::string pos)
{
    position = pos;
}

void employee::setHourly(bool hr)
{
    hourly = hr;
}

std::string employee::tostring()
{
    std::string out;
    out = person::tostring();
    out += "Salary: " + std::to_string(salary) + "\n";

    return out;
}

void person::setHeight(double h)
{
    if (h >= 1)
    {
        height = h;
    }
    else
    {
        height = 1;
    }
}

void person::setWeight(double w)
{
    if (w >= 1)
    {
        weight = w;
    }
    else
    {
        weight = 1;
    }
}

void person::setHairColor(std::string hair)
{
    hairColor = hair;
}

std::string person::tostring()
{
    std::string out;
    out = "Name: " + getName() + "\n";
    out += "Race: " + getRace() + "\n";

    return out;
}

person::person(std::string first_name, std::string last_name, int a, raceType r, double h, double w, std::string hair, std::string eye, char middle)
{
    setName(first_name, last_name, middle);
    if (a >= 0 && a <= 120)
    {
        age = a;
    }
    else
    {
        age = 20;
    }
    race = r;
    setHeight(h);
    setWeight(w);
    setHairColor(hair);
    eyeColor = eye;
}

std::string person::getName()
{
    std::string name = fname;
    if (mi != '\0')
    {
        name += " " + mi;
    }
    name += " " + lname;

    return name;
}

employee::employee(std::string first_name, std::string last_name, int a, raceType r, double h, double w, std::string hair, std::string eye, std::string hire, double sal, unsigned int id, std::string pos, bool hour, char middle) : person(first_name, last_name, a, r, h, w, hair, eye, middle)
{
    hireDate = hire;
    setSalary(sal);
    empID = id;
    setPosition(pos);
    setHourly(hour);

    /* if (empID >= 1)
    {
        empID = id;
    }
    else
    {
        empID = 1;
    } */
}

void person::setName(std::string fn, std::string ln, char m)
{
    fname = fn;
    lname = ln;
    mi = m;
}

std::string person::getRace()
{
    return raceToStr[race];
}

employee *employee::makeCopy()
{
    return new employee(*this);
}

course::course(std::string dept, int num, std::string section, int semester, int creditHr)
{
    this->dept = dept;
    if (num > 100)
    {
        this->courseNum = num;
    }
    this->section = section;
    if (semester > 202310)
    {
        this->semester = semester;
    }
    if (creditHr > 0)
    {
        this->creditHours = creditHr;
    }
}
bool course::operator<(const course &rightHandCourse) const
{
    return this->dept <= rightHandCourse.dept && this->courseNum <= rightHandCourse.courseNum && this->section < rightHandCourse.section;
}

void student::addToSchedule(const course &c)
{
    auto ret = schedule.insert(c);
    if (ret.second)
    {
        // course was added
    }
}
