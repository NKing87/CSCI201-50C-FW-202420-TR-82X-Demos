#include "clock.h"
#include <iostream>

clockFormatType getFormat();
std::string getTimeOfDay();
int getHour(clockFormatType f);
int getMinOrSec();

int main()
{
    int hr = 0;
    int min = 0;
    int sec = 0;
    clockFormatType format;
    std::string tod;
    clockType *clock;
    try
    {
        format = getFormat();
        hr = getHour(format);
        min = getMinOrSec();
        sec = getMinOrSec();
        if (format == TWELVE)
        {
            tod = getTimeOfDay();
            clock = new clockType(hr, min, sec, tod, format);
        }
        else
        {
            clock = new clockType(hr, min, sec);
        }
    }
    catch (clockType errorClock)
    {
        std::cout << "caught clock " << errorClock << std::endl;
        return 0;
    }
    catch (std::string error)
    {
        std::cout << error << std::endl;
        return 0;
    }
    catch (...)
    {
        std::cout << "An error has occured. Program will exit." << std::endl;
        return 0;
    }

    return 0;
}

clockFormatType getFormat()
{
    return TWELVE;
}

std::string getTimeOfDay()
{
    return "CM";
}

int getHour(clockFormatType f)
{
    return 12;
}

int getMinOrSec()
{
    return 23;
}
