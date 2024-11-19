#include "donut.h"
donut::donut()
{
    this->icing = NOICE;
    this->topping = NOTOP;
    this->drizzle = NODRIZZLE;
}

donut::donut(std::string icing, std::string topping, std::string drizzle)
{
    std::transform(icing.begin(), icing.end(), icing.begin(), ::tolower);
    this->icing = strToIcing.at(icing);
}

std::string donut::toString() const
{
    std::ostringstream out;

    return out.str();
}

std::map<icingType, std::string> donut::icingToStr = {{CHOCOLATEICING, "Chocolate"},
                                                      {CARAMELICING, "Caramel"},
                                                      {MAPLE, "Maple"},
                                                      {VANILLA, "Vanilla"},
                                                      {GLAZE, "Glaze"},
                                                      {SPECIALICE, "Special"},
                                                      {NOICE, "None"}};
std::map<std::string, icingType> donut::strToIcing = {{"chocolate", CHOCOLATEICING},
                                                      {"caramel", CARAMELICING},
                                                      {"maple", MAPLE},
                                                      {"vanilla", VANILLA},
                                                      {"glaze", GLAZE},
                                                      {"special", SPECIALICE},
                                                      {"none", NOICE}};

std::map<toppingType, std::string> donut::toppingToStr = {{RAINBOWSPR, "Rainbow Sprinkles"},
                                                          {CHOCOLATESPR, "Chocolate Sprinkles"},
                                                          {PEANUTS, "Peanuts"},
                                                          {COCONUT, "Coconut"},
                                                          {OREO, "Oreo"},
                                                          {BACON, "Bacon"},
                                                          {GRAHAM, "Graham Cracker"},
                                                          {FRUITYPEBBLES, "Fruity Pebbles"},
                                                          {REESESPIECES, "Reese's Pieces"},
                                                          {MMS, "M&Ms"},
                                                          {CANDYBAR, "Candy Bar"},
                                                          {CHOCOLATECHIPS, "Chocolate Chips"},
                                                          {SEASALT, "Sea Salt"},
                                                          {CINSUGAR, "Cinnamon Sugar"},
                                                          {POWDSUGAR, "Powdered Sugar"},
                                                          {NOTOP, "None"}};
std::map<std::string, toppingType> donut::strToTopping = {{"rainbow sprinkles", RAINBOWSPR},
                                                          {"chocolate sprinkles", CHOCOLATESPR},
                                                          {"peanuts", PEANUTS},
                                                          {"coconut", COCONUT},
                                                          {"oreo", OREO},
                                                          {"bacon", BACON},
                                                          {"graham cracker", GRAHAM},
                                                          {"fruity pebbles", FRUITYPEBBLES},
                                                          {"m&ms", MMS},
                                                          {"reese's pieces", REESESPIECES},
                                                          {"reeses pieces", REESESPIECES}, // we can have alternate spellings in our map.
                                                          {"candy bar", CANDYBAR},
                                                          {"chocolate chips", CHOCOLATECHIPS},
                                                          {"sea salt", SEASALT},
                                                          {"cinnamon sugar", CINSUGAR},
                                                          {"powdered sugar", POWDSUGAR},
                                                          {"none", NOTOP}};
std::map<drizzleType, std::string> donut::drizzleToStr = {{CARAMELDRIZZLE, "Caramel"},
                                                          {CHOCOLATEDRIZZLE, "Chocolate"},
                                                          {PEANUTBUTTER, "Peanut Butter"},
                                                          {RASPBERRY, "Raspberry"},
                                                          {SPECIALDRIZZLE, "Special"},
                                                          {NODRIZZLE, "None"}};

std::map<std::string, drizzleType> donut::strToDrizzle = {{"caramel", CARAMELDRIZZLE},
                                                          {"chocolate", CHOCOLATEDRIZZLE},
                                                          {"peanut butter", PEANUTBUTTER},
                                                          {"raspberry", RASPBERRY},
                                                          {"special", SPECIALDRIZZLE},
                                                          {"none", NODRIZZLE}};
