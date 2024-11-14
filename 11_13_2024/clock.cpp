#include "clock.h"

/* clockType::clockType()
{
    hr = 0;
    min = 0;
    sec = 0;
} */
clockType::clockType(int h, int m, int s, std::string am, clockFormatType f)
{
    this->format = f;

    std::transform(am.begin(), am.end(), am.begin(), ::toupper);
    bool set = false;
    for (int i = 0; i < 2; i++)
    {
        if (amPmToStr[i] == am)
        {
            timeOfDay = times[i];
            set = true;
        }
    }
    if (!set)
    {
        timeOfDay = times[1];
    }
    setTime(h, m, s);
    count++;
}
void clockType::getTime(int &h, int &m, int &s) const
{
    h = hr;
    m = min;
    s = sec;
}
int clockType::getHour() const
{
    return hr;
}
void clockType::setHour(int h)
{
    hr = h % 23;
}
void clockType::incrementHours()
{
    hr++;
    if (format == TWENTYFOUR)
    {
        hr = hr % 24;
    }
    else
    {
        if (hr == 12)
        {
            if (timeOfDay == PM)
                timeOfDay = AM;
            else
                timeOfDay = PM;
        }
    }
}
int clockType::count = 0;
/* clockType::clockType(int h, int m)
{
    setTime(h, m, 0);
} */
void clockType::setTime(int h, int m, int s, std::string a)
{
    std::transform(a.begin(), a.end(), a.begin(), ::toupper);
    bool set = false;
    for (int i = 0; i < 2; i++)
    {
        if (amPmToStr[i] == a)
        {
            timeOfDay = times[i];
            set = true;
        }
    }
    if (!set)
    {
        timeOfDay = times[1];
    }

    if (format == TWENTYFOUR)
        hr = h % 24;
    else
    {
        if (h > 12 || h < 1)
            hr = h % 12 + 1;
        else
            hr = h;
    }
    min = m % 60;
    sec = s % 60;
}

std::string clockType::tostring() const
{

    std::ostringstream outStr;
    outStr << std::setfill('0') << std::setw(2) << hr << ":" << std::setw(2) << min << ":" << std::setw(2) << sec;
    if (this->format == TWELVE)
    {
        outStr << " " << amPmToStr[timeOfDay];
    }
    return outStr.str();
}

void clockType::incrementSeconds()
{
    sec++;
    if (sec >= 60)
    {
        sec == 0;
        incrementMinutes();
    }
}

void clockType::incrementMinutes()
{
    min++;
    if (min >= 60)
    {
        min == 0;
        incrementHours();
    }
}

bool clockType::equalTime(const clockType &otherClock) const
{
    bool eq;
    int cmpH;
    int cmpOH;
    if (this->format == TWELVE)
    {
        if (this->timeOfDay == AM && hr != 12)
        {
            cmpH = hr;
        }
        else if (this->timeOfDay == AM && hr == 12)
        {
            cmpH = 0;
        }
        else if (hr == 12)
        {
            cmpH = hr;
        }
        else
        {
            cmpH = hr + 12;
        }
    }
    else
    {
        cmpH = hr;
    }
    if (otherClock.format == TWELVE)
    {
        if (otherClock.timeOfDay == AM && otherClock.hr != 12)
        {
            cmpOH = otherClock.hr;
        }
        else if (otherClock.timeOfDay == AM && otherClock.hr == 12)
        {
            cmpOH = 0;
        }
        else if (otherClock.hr == 12)
        {
            cmpOH = otherClock.hr;
        }
        else
        {
            cmpOH = otherClock.hr + 12;
        }
    }
    else
    {
        cmpOH = otherClock.hr;
    }
    eq = cmpH == cmpOH && this->min == otherClock.min && this->sec == otherClock.sec;

    return eq;
}

bool clockType::operator==(const clockType &rightHandClock) const
{
    return this->equalTime(rightHandClock);
}

/* bool operator==(const clockType &leftHandClock, const clockType &rightHandClock)
{
    return leftHandClock.equalTime(rightHandClock);
} */

clockType operator+(const int minutesToAdd, const clockType &clock)
{
    clockType newClock(clock);
    for (int i = 0; i < minutesToAdd; i++)
    {
        newClock.incrementMinutes();
    }
    return newClock;
}

clockType clockType::operator+(const int minutesToAdd)
{
    return minutesToAdd + *this;
}

std::ostream &operator<<(std::ostream &outputStream, const clockType &clockToPrint)
{
    outputStream << clockToPrint.tostring();
    return outputStream;
}

std::istream &operator>>(std::istream &inputStream, clockType &clockToInput)
{
    int hr, min, sec;
    inputStream >> hr >> min >> sec;

    clockToInput.setTime(hr, min, sec);
    return inputStream;
}

const clockType &clockType::operator=(const clockType &rightHandClock)
{
    this->hr = rightHandClock.hr;
    this->min = rightHandClock.min;
    this->sec = rightHandClock.sec;
    this->format = rightHandClock.format;
    this->timeOfDay = rightHandClock.timeOfDay;
    return *this;
}

clockType clockType::operator++()
{
    this->incrementSeconds();
    return *this;
}
clockType clockType::operator++(int)
{
    clockType temp = *this;
    this->incrementSeconds();
    return temp;
}

bool clockType::operator!=(const clockType &rightHandClock) const
{
    return !(*this == rightHandClock);
}
bool clockType::operator>(const clockType &rightHandClock) const
{

    int cmpH;
    int cmpOH;
    if (this->format == TWELVE)
    {
        if (this->timeOfDay == AM && hr != 12)
        {
            cmpH = hr;
        }
        else if (this->timeOfDay == AM && hr == 12)
        {
            cmpH = 0;
        }
        else if (hr == 12)
        {
            cmpH = hr;
        }
        else
        {
            cmpH = hr + 12;
        }
    }
    else
    {
        cmpH = hr;
    }
    if (rightHandClock.format == TWELVE)
    {
        if (rightHandClock.timeOfDay == AM && rightHandClock.hr != 12)
        {
            cmpOH = rightHandClock.hr;
        }
        else if (rightHandClock.timeOfDay == AM && rightHandClock.hr == 12)
        {
            cmpOH = 0;
        }
        else if (rightHandClock.hr == 12)
        {
            cmpOH = rightHandClock.hr;
        }
        else
        {
            cmpOH = rightHandClock.hr + 12;
        }
    }
    else
    {
        cmpOH = rightHandClock.hr;
    }
    if (cmpH > cmpOH)
    {
        return true;
    }
    else if (cmpH == cmpOH)
    {
        if (this->min > rightHandClock.min)
        {
            return true;
        }
        else if (this->min == rightHandClock.min)
        {
            if (this->sec > rightHandClock.sec)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool clockType::operator<(const clockType &rightHandClock) const
{
    int cmpH, cmpOH;
    if (this->format == TWELVE)
    {
        cmpH = (this->timeOfDay == AM && hr != 12) ? hr : ((this->timeOfDay == AM && hr == 12) ? 0 : ((hr == 12) ? hr : hr + 12));
    }
    else
    {
        cmpH = hr;
    }
    if (rightHandClock.format == TWELVE)
    {
        cmpOH = (rightHandClock.timeOfDay == AM && rightHandClock.hr != 12) ? rightHandClock.hr : ((rightHandClock.timeOfDay == AM && rightHandClock.hr == 12) ? 0 : ((rightHandClock.hr == 12) ? rightHandClock.hr : rightHandClock.hr + 12));
    }
    else
    {
        cmpOH = rightHandClock.hr;
    }

    if (cmpH < cmpOH)
    {
        return true;
    }
    else if (cmpH == cmpOH)
    {
        if (this->min < rightHandClock.min)
        {
            return true;
        }
        else if (this->min == rightHandClock.min)
        {
            return this->sec < rightHandClock.sec;
        }
    }
    return false;
}

bool clockType::operator>=(const clockType &rightHandClock) const
{
    return (*this > rightHandClock) || (*this == rightHandClock);
}

bool clockType::operator<=(const clockType &rightHandClock) const
{
    return (*this < rightHandClock) || (*this == rightHandClock);
}
