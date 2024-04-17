#include "mainwindow.h"
#include "model.h"

#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();*/

    Model model;

    std::string test = "1+(2*(3-4))";

    std::cout << model.calculateRPN(model.reverseToRPN(test));

    return 0;
}

