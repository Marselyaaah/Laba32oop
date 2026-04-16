#include "Numbers.h"
#include <fstream>
Numbers::Numbers(QObject* parent)
    : QObject(parent)
{
    a = 0;
    b = 0;
    c = 0;

    loadFromFile();
}

Numbers::~Numbers()
{
    saveToFile();
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

    int oldA = a;
    int oldB = b;
    int oldC = c;

    a = value;

    if (b < a)
        b = a;

    if (c < b)
        c = b;

    if (a != oldA || b != oldB || c != oldC) {
        emit dataChanged();
    }
}

void Numbers::setB(int value)
{
    if (value < 0)
        value = 0;
    if (value > 100)
        value = 100;

    int oldA = a;
    int oldB = b;
    int oldC = c;

    if (value < a)
        value = a;
    if (value > c)
        value = c;

    b = value;

    if (a != oldA || b != oldB || c != oldC) {
        emit dataChanged();
    }
}

void Numbers::setC(int value)
{
    if (value < 0)
        value = 0;
    if (value > 100)
        value = 100;

    int oldA = a;
    int oldB = b;
    int oldC = c;

    c = value;

    if (b > c)
        b = c;

    if (a > b)
        a = b;

    if (a != oldA || b != oldB || c != oldC) {
        emit dataChanged();
    }
}


void Numbers::loadFromFile()
{
    std::ifstream file("numbers.txt");

    int fileA, fileB, fileC;
    int oldA = a;
    int oldB = b;
    int oldC = c;
    if (!(file >> fileA >> fileB >> fileC))
    {
        a = 0;
        b = 0;
        c = 0;
        return;
    }

    if (fileA < 0) fileA = 0;
    if (fileA > 100) fileA = 100;

    if (fileB < 0) fileB = 0;
    if (fileB > 100) fileB = 100;

    if (fileC < 0) fileC = 0;
    if (fileC > 100) fileC = 100;

    a = fileA;
    b = fileB;
    c = fileC;

    if (b < a)
        b = a;

    if (c < b)
        c = b;

    if (a != oldA || b != oldB || c != oldC)
        emit dataChanged();
}

void Numbers::saveToFile() const
{
    std::ofstream file("numbers.txt");

    if (!file)
        return;

    file << a << ' ' << b << ' ' << c;
}