#pragma once
#ifndef NUMBERS_H
#define NUMBERS_H

#include <QObject>

class Numbers : public QObject
{
    Q_OBJECT

public:
    explicit Numbers(QObject* parent = nullptr);
    ~Numbers();

    int getA() const;
    int getB() const;
    int getC() const;

    void setA(int value);
    void setB(int value);
    void setC(int value);

signals:
    void dataChanged(); 

private:
    int a;
    int b;
    int c;

    void loadFromFile();
    void saveToFile() const;
};

#endif // NUMBERS_H