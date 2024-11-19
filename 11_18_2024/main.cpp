#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include "clock.h"

// change the main to loop and push into the clockInVector 15 random clocks
//  use the code provided to randomly determine if it is a 12 or 24 hour clock
// based on the format generate a value for hours, mins, secs
// for 12 hour clocks ask the user if it is am or pm

template <class comparableType>
comparableType larger(comparableType num1, comparableType num2);
bool codeGradeLoopFix(std::string errLocation);
void resetStream();

/* int larger(int num1, int num2);
double larger(double num1, double num2);
 */
/* int larger(int num1, int num2)
{
    if (num1 >= num2)
        return num1;
    else
        return num2;
}

double larger(double num1, double num2)
{
    if (num1 >= num2)
        return num1;
    else
        return num2;
}
 */
int main()
{
    std::vector<clockType> timeClockIn;
    std::vector<clockType> timeClockOut;
    int x, y;
    double z, a;
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    std::uniform_int_distribution<int> distributionInt(1, 100);
    z = distribution(generator);
    a = distribution(generator);
    x = distributionInt(generator);
    y = distributionInt(generator);
    std::uniform_int_distribution<int> distributionFormat(1, 2);

    // goes into the new loop
    int clockFormat = distributionFormat(generator) * 12;
    clockFormatType format = clockType::intToClockFormat[clockFormat];

    clockType c1(6, 30, 00, "PM", TWELVE), c2(18, 31, 00);
    // timeClockIn.insert(timeClockIn.begin(), c1);//works but required the exact iterator position
    // timeClockIn[0] = c1; doesn't work if the vector is empty
    timeClockIn.push_back(c1);
    // timeClockIn.insert(timeClockIn.end(), 15, c2);
    for (int i = 0; i < timeClockIn.size(); i++)
    {
        std::cout << timeClockIn[i] << std::endl;
    }

    int largerInt = larger(x, y);
    std::cout << "The larger value is " << largerInt << " from x = " << x << " and y = " << y << std::endl;

    double largerDouble = larger(z, a);
    std::cout << "The larger value is " << largerDouble << " from z = " << z << " and a = " << a << std::endl;

    clockType largerClock = larger(c1, c2);
    std::cout << "The larger of c1 = " << c1 << " and c2 = " << c2 << " is " << largerClock << std::endl;
    largerDouble = larger<double>(x, a);
    return 0;
}

template <class t>
t larger(t num1, t num2)
{
    if (num1 >= num2)
        return num1;
    else
        return num2;
}

clockType *createClock()
{

    std::string tod;
    int format;
    clockType *newClock;
    std::cout << "What kind of clock do you have? Enter 12 for 12 Hour and 24 for 24 Hour. " << std::endl;

    std::cin >> format;
    while (!std::cin || (format != 12 && format != 24))
    {
        if (codeGradeLoopFix("line 58"))
        {
            return new clockType(0, 0, 0);
        }
        if (!std::cin)
        {
            resetStream();
        }
        else
        {
            std::cout << "Please enter 12 or 24." << std::endl;
        }
        std::cout << "What kind of clock do you have?" << std::endl;

        std::cin >> format;
    }
    if (format == 12)
    {
        std::cout << "Is it AM or PM?" << std::endl;
        std::cin >> std::ws;
        std::getline(std::cin, tod);

        std::transform(tod.begin(), tod.end(), tod.begin(), ::tolower);
        std::cout << tod << std::endl;
        while (clockType::strToAmPmType.count(tod))
        {
            if (codeGradeLoopFix("line 52"))
            {
                return new clockType(0, 0, 0);
            }
            std::cout << "Is it AM or PM?" << std::endl;
            std::cin >> std::ws;
            std::getline(std::cin, tod);

            std::transform(tod.begin(), tod.end(), tod.begin(), ::tolower);
            std::cout << tod << std::endl;
        }
    }

    if (format == 12)
    {
        newClock = new clockType(12, 00, 00, tod, clockType::intToClockFormat[format]);
    }
    else
    {
        newClock = new clockType();
    }
    std::cout << "Enter the hours, minutes and seconds on the clock: ";
    std::cin >> *newClock;
    return newClock;
}

void resetStream()
{
    std::cout << "You entered something that is not a number." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool codeGradeLoopFix(std::string errLocation)
{
    if (std::cin.eof())
    {
        std::cout << "There was a problem and there is no more input! @" + errLocation << std::endl;
        return true;
    }
    return false;
}
