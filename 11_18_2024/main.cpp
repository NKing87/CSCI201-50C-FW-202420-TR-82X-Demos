#include <iostream>
#include <random>
#include "clock.h"

template <class comparableType>
comparableType larger(comparableType num1, comparableType num2);

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
    int x, y;
    double z, a;
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    std::uniform_int_distribution<int> distributionInt(1, 100);
    z = distribution(generator);
    a = distribution(generator);
    x = distributionInt(generator);
    y = distributionInt(generator);

    clockType c1(6, 30, 00, "PM", TWELVE), c2(18, 31, 00);

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
