#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include "clock.h"

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
    std::default_random_engine generator(std::random_device{}());
    std::uniform_int_distribution<int> formatDistribution(1, 2); // 1 for 12-hour, 2 for 24-hour
    std::uniform_int_distribution<int> hourDistribution12(1, 12); // Hours for 12-hour clock
    std::uniform_int_distribution<int> hourDistribution24(0, 23); // Hours for 24-hour clock
    std::uniform_int_distribution<int> minuteSecondDistribution(0, 59);

    for (int i = 0; i < 15; ++i)
    {
        int formatChoice = formatDistribution(generator);
        int hours, minutes, seconds;
        std::string amPm;

        if (formatChoice == 1) // 12-hour clock
        {
            hours = hourDistribution12(generator);
            minutes = minuteSecondDistribution(generator);
            seconds = minuteSecondDistribution(generator);

            std::cout << "For clock #" << i + 1 << ": Is it AM or PM? ";
            std::cin >> amPm;

            // Convert to uppercase for consistency
            std::transform(amPm.begin(), amPm.end(), amPm.begin(), ::toupper);

            while (amPm != "AM" && amPm != "PM")
            {
                std::cout << "Invalid input. Please enter AM or PM: ";
                std::cin >> amPm;
                std::transform(amPm.begin(), amPm.end(), amPm.begin(), ::toupper);
            }

            timeClockIn.emplace_back(hours, minutes, seconds, amPm, clockFormatType::TWELVE);
        }
        else // 24-hour clock
        {
            hours = hourDistribution24(generator);
            minutes = minuteSecondDistribution(generator);
            seconds = minuteSecondDistribution(generator);

            timeClockIn.emplace_back(hours, minutes, seconds, clockFormatType::TWENTY_FOUR);
        }
    }

    // Display all generated clocks
    std::cout << "\nGenerated Clocks:\n";
    for (const auto &clock : timeClockIn)
    {
        std::cout << clock << std::endl;
    }

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
