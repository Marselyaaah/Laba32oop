#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Laba32oop.h"

class Laba32oop : public QMainWindow
{
    Q_OBJECT

public:
    Laba32oop(QWidget *parent = nullptr);
    ~Laba32oop();

private:
    Ui::Laba32oopClass ui;
};
