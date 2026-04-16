#include "laba32oop.h"

#include <QWidget>
#include <QLabel>
#include <QString>
#include <QSlider>
#include <QFont>
#include <QLineEdit>
#include <QSpinBox>

MainWindow::MainWindow(Numbers* numbers_, QWidget* parent)
    : QMainWindow(parent), numbers(numbers_)
{
    QFont bigFont;
    bigFont.setPointSize(28);

    // ===== Большие надписи =====
    QLabel* titleA = new QLabel("A", this);
    titleA->setFont(bigFont);
    titleA->resize(60, 60);
    titleA->move(80, 20);

    QLabel* betweenAB = new QLabel("<=", this);
    betweenAB->setFont(bigFont);
    betweenAB->resize(80, 60);
    betweenAB->move(165, 20);

    QLabel* titleB = new QLabel("B", this);
    titleB->setFont(bigFont);
    titleB->resize(60, 60);
    titleB->move(260, 20);

    QLabel* betweenBC = new QLabel("<=", this);
    betweenBC->setFont(bigFont);
    betweenBC->resize(80, 60);
    betweenBC->move(345, 20);

    QLabel* titleC = new QLabel("C", this);
    titleC->setFont(bigFont);
    titleC->resize(60, 60);
    titleC->move(440, 20);

    // ===== A =====
    editA = new QLineEdit(this);
    editA->resize(120, 28);
    editA->move(40, 95);

    spinA = new QSpinBox(this);
    spinA->setRange(numbers->getMin(), numbers->getMax());
    spinA->resize(120, 28);
    spinA->move(40, 130);

    sliderA = new QSlider(Qt::Horizontal, this);
    sliderA->setRange(numbers->getMin(), numbers->getMax());
    sliderA->resize(120, 24);
    sliderA->move(40, 170);

    // ===== B =====
    editB = new QLineEdit(this);
    editB->resize(120, 28);
    editB->move(220, 95);

    spinB = new QSpinBox(this);
    spinB->setRange(numbers->getMin(), numbers->getMax());
    spinB->resize(120, 28);
    spinB->move(220, 130);

    sliderB = new QSlider(Qt::Horizontal, this);
    sliderB->setRange(numbers->getMin(), numbers->getMax());
    sliderB->resize(120, 24);
    sliderB->move(220, 170);

    // ===== C =====
    editC = new QLineEdit(this);
    editC->resize(120, 28);
    editC->move(400, 95);

    spinC = new QSpinBox(this);
    spinC->setRange(numbers->getMin(), numbers->getMax());
    spinC->resize(120, 28);
    spinC->move(400, 130);

    sliderC = new QSlider(Qt::Horizontal, this);
    sliderC->setRange(numbers->getMin(), numbers->getMax());
    sliderC->resize(120, 24);
    sliderC->move(400, 170);

    setWindowTitle("Step QLineEdit");
    resize(580, 260);

    connect(spinA, QOverload<int>::of(&QSpinBox::valueChanged),//меняем cпин бокс и меняется везде
        this, [this](int value)
        {
            numbers->setA(value);
        });

    connect(sliderA, &QSlider::valueChanged, //меняем слайдер и меняется везде
        this, [this](int value)
        {
            numbers->setA(value);
        });

    connect(editA, &QLineEdit::editingFinished,//меняем текст и меняется везде
        this, [this]()
        {
            numbers->setA(editA->text().toInt());
        });

    connect(spinB, QOverload<int>::of(&QSpinBox::valueChanged),//меняем cпин бокс и меняется везде
        this, [this](int value)
        {
            numbers->setB(value);
            updateView();
        });

    connect(sliderB, &QSlider::valueChanged, //меняем слайдер и меняется везде
        this, [this](int value)
        {
            numbers->setB(value);
            updateView();
        });

    connect(editB, &QLineEdit::editingFinished,//меняем текст и меняется везде
        this, [this]()
        {
            numbers->setB(editB->text().toInt());
            updateView();
        });

    connect(spinC, QOverload<int>::of(&QSpinBox::valueChanged),//меняем cпин бокс и меняется везде
        this, [this](int value)
        {
            numbers->setC(value);
        });

    connect(sliderC, &QSlider::valueChanged, //меняем слайдер и меняется везде
        this, [this](int value)
        {
            numbers->setC(value);
        });

    connect(editC, &QLineEdit::editingFinished,//меняем текст и меняется везде
        this, [this]()
        {
            numbers->setC(editC->text().toInt());
        });

    connect(numbers, &Numbers::dataChanged,
        this, [this]()
        {
            updateView();
        });

    updateView();
}

void MainWindow::updateView()
{
    updateCount++;
    qDebug() << "updateView called =" << updateCount;

    editA->setText(QString::number(numbers->getA()));
    editB->setText(QString::number(numbers->getB()));
    editC->setText(QString::number(numbers->getC()));

    spinA->setValue(numbers->getA());
    spinB->setValue(numbers->getB());
    spinC->setValue(numbers->getC());

    sliderA->setValue(numbers->getA());
    sliderB->setValue(numbers->getB());
    sliderC->setValue(numbers->getC());

}