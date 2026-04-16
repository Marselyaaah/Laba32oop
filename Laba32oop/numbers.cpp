#include "Numbers.h"

Numbers::Numbers()
{
    a = 0;
    b = 0;
    c = 0;
}

int Numbers::getA() const { return a; }
int Numbers::getB() const { return b; }
int Numbers::getC() const { return c; }

void Numbers::setA(int value)
{
    if (value < 0)
        value = 0;
    if (value > 100)
        value = 100;

    a = value;
}

void Numbers::setB(int value)
{
    if (value < 0)
        value = 0;
    if (value > 100)
        value = 100;

    b = value;
}

void Numbers::setC(int value)
{
    if (value < 0)
        value = 0;
    if (value > 100)
        value = 100;

    c = value;
}