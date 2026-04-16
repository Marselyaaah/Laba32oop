#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include "Numbers.h"
#include <QSpinBox>
#include <QSlider>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);

private:
    Numbers* numbers;
    QLineEdit* editA;
    QSpinBox* spinA;
    QSlider* sliderA;
    QLineEdit* editB;
    QSpinBox* spinB;
    QSlider* sliderB;
    QLineEdit* editC;
    QSpinBox* spinC;
    QSlider* sliderC;
    void updateA();
    void updateB();
    void updateC();
};

#endif // MAINWINDOW_H