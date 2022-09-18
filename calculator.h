#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "mainwindow.h"

class MainWindow;
class Calculator
{
public:
    Calculator();
    friend MainWindow;
private:
    int nmb = 0;
    int cur_res = 0;
    char sign;
    bool is_first_calculation =true;
    int PermitOperation();
    bool await_right_operand = false;
    int Plus();
    int Minus();
    int Cdot();
    int Divide();
};

#endif // CALCULATOR_H
