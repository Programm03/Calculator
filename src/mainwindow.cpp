#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::onButtonExpressionClicked()
{
    QPushButton* sender_ = qobject_cast<QPushButton*>(sender());

    if (!sender_) {
        return;
    }

    QString text = sender_->text();
    QString label = ui->label->text();

    label = label + text;

    ui->label->setText(label);
}

void MainWindow::onButtonDeletePressed()
{
    QString label = ui->label->text();

    if (label.isEmpty()) {
        return;
    }

    //label.resize(label.size() - 1);
    label.chop(1);

    ui->label->setText(label);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->buttonOne, &QPushButton::pressed, this, &MainWindow::onButtonExpressionClicked);
    connect(ui->buttonTwo, &QPushButton::pressed, this, &MainWindow::onButtonExpressionClicked);
    connect(ui->buttonThree, &QPushButton::pressed, this, &MainWindow::onButtonExpressionClicked);
    connect(ui->buttonFour, &QPushButton::pressed, this, &MainWindow::onButtonExpressionClicked);
    connect(ui->buttonFive, &QPushButton::pressed, this, &MainWindow::onButtonExpressionClicked);
    connect(ui->buttonSix, &QPushButton::pressed, this, &MainWindow::onButtonExpressionClicked);
    connect(ui->buttonSeven, &QPushButton::pressed, this, &MainWindow::onButtonExpressionClicked);
    connect(ui->buttonEight, &QPushButton::pressed, this, &MainWindow::onButtonExpressionClicked);
    connect(ui->buttonNine, &QPushButton::pressed, this, &MainWindow::onButtonExpressionClicked);
    connect(ui->buttonZero, &QPushButton::pressed, this, &MainWindow::onButtonExpressionClicked);
    connect(ui->buttonPlus, &QPushButton::pressed, this, &MainWindow::onButtonExpressionClicked);
    connect(ui->buttonMinus, &QPushButton::pressed, this, &MainWindow::onButtonExpressionClicked);
    connect(ui->buttonMulti, &QPushButton::pressed, this, &MainWindow::onButtonExpressionClicked);
    connect(ui->buttonDivision, &QPushButton::pressed, this, &MainWindow::onButtonExpressionClicked);
    connect(ui->buttonBrackedOpen, &QPushButton::pressed, this, &MainWindow::onButtonExpressionClicked);
    connect(ui->buttonBrackedClose, &QPushButton::pressed, this, &MainWindow::onButtonExpressionClicked);
    connect(ui->buttonDelete, &QPushButton::pressed, this, &MainWindow::onButtonDeletePressed);
    //connect(ui->buttonEqual, &QPushButton::pressed, this, &MainWindow::onButtonExpressionClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

