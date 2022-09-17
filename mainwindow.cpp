#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>
using std::cout; using std::endl;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initialize_calc(){
    if (!calculator)
        calculator = new Calculator;
}

void MainWindow::on_pushButton_plus_clicked()
{
//    calculator = new Calculator;
    initialize_calc();
    calculator->sign = '+';
    if (calculator->is_first_calculation) calculator->cur_res = calculator->nmb;
    calculator->nmb = 0;

    QString str(calculator->sign);
    ui->label->setText(ui->label->text() + str);
}

void MainWindow::on_pushButton_minus_clicked()
{
    initialize_calc();
    calculator->sign = '-';
    if (calculator->is_first_calculation) calculator->cur_res = calculator->nmb;
    calculator->nmb = 0;

    QString str(calculator->sign);
    ui->label->setText(ui->label->text() + str);
}

void MainWindow::on_pushButton_cdot_clicked()
{
    initialize_calc();
    calculator->sign = '*';
    if (calculator->is_first_calculation) calculator->cur_res = calculator->nmb;
    calculator->nmb = 0;

    QString str(calculator->sign);
    ui->label->setText(ui->label->text() + str);
}

void MainWindow::on_pushButton_divide_clicked()
{
    initialize_calc();
    calculator->sign = '/';
    if (calculator->is_first_calculation) calculator->cur_res = calculator->nmb;
    calculator->nmb = 0;

    QString str(calculator->sign);
    ui->label->setText(ui->label->text() + str);
}

void MainWindow::on_pushButton_equal_to_clicked()
{
    cout << "equla push button is clicked!" << endl;
    cout << "cur_res " << calculator->cur_res << " nmb " << calculator->nmb << endl;
    if (int handle_error = calculator->PermitOperation()){
        cout << "handle error number " << handle_error << endl;
        if (handle_error == 2) QMessageBox::warning(this, "Error", "calculator doesn't support number greater than 2147483647");
        else if (handle_error == 1) QMessageBox::warning(this, "Error", "Divide by 0 is Impossible!!!");
    }
    else{
         cout << "cur_res " << calculator->cur_res << endl;
        ui->label->setText(QString::number(calculator->cur_res));
        calculator->is_first_calculation = false;
    }
}



void MainWindow::on_pushButton_clicked()
{
    initialize_calc();
    int digit = 1;
    if (calculator->nmb <= INT_MAX / 10){
        calculator->nmb = calculator->nmb * 10 + digit;
    }
    else{
        QMessageBox::warning(this, "Error", "calculator doesn't support number greater than 2147483647");
    }
    QString str = QString::number(digit);
    ui->label->setText(ui->label->text() + str);
}

void MainWindow::on_pushButton_2_clicked()
{
    cout << "first adress of calculator " << calculator << endl;
    initialize_calc();
    int digit = 2;
    cout << "adress of calculator " << calculator << endl;
    cout << "number is " << calculator->nmb << endl;
    if (calculator->nmb <= INT_MAX / 10){
        calculator->nmb = calculator->nmb * 10 + digit;
    }
    else{
        QMessageBox::warning(this, "Error", "calculator doesn't support number greater than 2147483647");
    }
    QString str = QString::number(digit);
    ui->label->setText(ui->label->text() + str);
}

void MainWindow::on_pushButton_3_clicked()
{
    initialize_calc();

    int digit = 3;
//    if (!calculator->await_right_operand){

        if (calculator->nmb <= INT_MAX / 10){
            calculator->nmb = calculator->nmb * 10 + digit;
        }
        else{
            QMessageBox::warning(this, "Error", "calculator doesn't support number greater than 2147483647");
        }
//    }
    QString str = QString::number(digit);
    ui->label->setText(ui->label->text() + str);

}

void MainWindow::on_pushButton_4_clicked()
{
    initialize_calc();
    int digit = 4;
    if (calculator->nmb <= INT_MAX / 10){
        calculator->nmb = calculator->nmb * 10 + digit;
    }
    else{
        QMessageBox::warning(this, "Error", "calculator doesn't support number greater than 2147483647");
    }
    QString str = QString::number(digit);
    ui->label->setText(ui->label->text() + str);
}

void MainWindow::on_pushButton_5_clicked()
{
    initialize_calc();
    int digit = 5;
    if (calculator->nmb <= INT_MAX / 10){
        calculator->nmb = calculator->nmb * 10 + digit;
    }
    else{
        QMessageBox::warning(this, "Error", "calculator doesn't support number greater than 2147483647");
    }
    QString str = QString::number(digit);
    ui->label->setText(ui->label->text() + str);
}

void MainWindow::on_pushButton_6_clicked()
{
    initialize_calc();
    int digit = 6;
    if (calculator->nmb <= INT_MAX / 10){
        calculator->nmb = calculator->nmb * 10 + digit;
    }
    else{
        QMessageBox::warning(this, "Error", "calculator doesn't support number greater than 2147483647");
    }
    QString str = QString::number(digit);
    ui->label->setText(ui->label->text() + str);
}

void MainWindow::on_pushButton_7_clicked()
{
    initialize_calc();
    int digit = 7;
    if (calculator->nmb <= INT_MAX / 10){
        calculator->nmb = calculator->nmb * 10 + digit;
    }
    else{
        QMessageBox::warning(this, "Error", "calculator doesn't support number greater than 2147483647");
    }
    QString str = QString::number(digit);
    ui->label->setText(ui->label->text() + str);

}

void MainWindow::on_pushButton_8_clicked()
{
    initialize_calc();
    int digit = 8;
    if (calculator->nmb < INT_MAX / 10){
        calculator->nmb = calculator->nmb * 10 + digit;
    }
    else{
        QMessageBox::warning(this, "Error", "calculator doesn't support number greater than 2147483647");
    }
    QString str = QString::number(digit);
    ui->label->setText(ui->label->text() + str);
}

void MainWindow::on_pushButton_9_clicked()
{
    initialize_calc();
    int digit = 9;
    if (calculator->nmb < INT_MAX / 10){
        calculator->nmb = calculator->nmb * 10 + digit;
    }
    else{
        QMessageBox::warning(this, "Error", "calculator doesn't support number greater than 2147483647");
    }
    QString str = QString::number(digit);
    ui->label->setText(ui->label->text() + str);
}

