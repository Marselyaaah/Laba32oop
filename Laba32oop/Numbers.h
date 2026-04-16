#pragma once
#ifndef NUMBERS_H
#define NUMBERS_H

class Numbers
{
public:
    Numbers();

    int getA() const;
    int getB() const;
    int getC() const;

    void setA(int value);
    void setB(int value);
    void setC(int value);

private:
    int a;
    int b;
    int c;
};

#endif // NUMBERS_H