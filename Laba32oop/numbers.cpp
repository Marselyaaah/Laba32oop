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

    if (b < a)
        b = a;
}

void Numbers::setB(int value)
{
    if (value < 0)
        value = 0;
    if (value > 100)
        value = 100;

    if (value < a)
        value = a;
    if (value > c)
        value = c;

    b = value;
}

void Numbers::setC(int value)
{
    if (value < 0)
        value = 0;
    if (value > 100)
        value = 100;

    c = value;

    if (b > c)
        b = c;
}