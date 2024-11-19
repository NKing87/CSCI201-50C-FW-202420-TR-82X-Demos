#ifndef DONUT_H
#define DONUT_H

#include <string>
#include <sstream>
#include <map>
#include <algorithm>
enum icingType
{
    CHOCOLATEICING,
    CARAMELICING,
    MAPLE,
    VANILLA,
    GLAZE,
    SPECIALICE,
    NOICE
};
enum toppingType
{
    RAINBOWSPR,
    CHOCOLATESPR,
    PEANUTS,
    COCONUT,
    OREO,
    BACON,
    GRAHAM,
    FRUITYPEBBLES,
    REESESPIECES,
    MMS,
    CANDYBAR,
    CHOCOLATECHIPS,
    SEASALT,
    CINSUGAR,
    POWDSUGAR,
    NOTOP
};
enum drizzleType
{
    CARAMELDRIZZLE,
    CHOCOLATEDRIZZLE,
    PEANUTBUTTER,
    RASPBERRY,
    SPECIALDRIZZLE,
    NODRIZZLE
};
class donut
{
public:
    donut();
    donut(std::string icing, std::string topping, std::string drizzle);
    icingType getIcing();
    toppingType getTopping();
    drizzleType getDrizzle();
    void setIcing(std::string);
    void setTopping(std::string);
    void setDrizzle(std::string);
    friend std::ostream &operator<<(std::ostream &, const donut &);
    static std::map<icingType, std::string> icingToStr;
    static std::map<std::string, icingType> strToIcing;
    static std::map<toppingType, std::string> toppingToStr;
    static std::map<std::string, toppingType> strToTopping;
    static std::map<drizzleType, std::string> drizzleToStr;
    static std::map<std::string, drizzleType> strToDrizzle;

private:
    icingType icing;
    toppingType topping;
    drizzleType drizzle;
    static int nextProdNum;
    std::string toString() const;
};

#endif