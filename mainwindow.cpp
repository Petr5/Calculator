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
    if (calculator->sign == ' '){
        calculator->sign = '+';
        calculator->cur_res = calculator->nmb;
        calculator->nmb = 0;

        calculator->await_right_operand = true;
        QString str(calculator->sign);
        ui->label->setText(ui->label->text() + str);
    }

}

void MainWindow::on_pushButton_minus_clicked()
{
    initialize_calc();
    if (calculator->sign == ' '){
        calculator->sign = '-';
        calculator->cur_res = calculator->nmb;
        calculator->nmb = 0;

        calculator->await_right_operand = true;
        QString str(calculator->sign);
        ui->label->setText(ui->label->text() + str);
    }

}

void MainWindow::on_pushButton_cdot_clicked()
{
    initialize_calc();
    if (calculator->sign == ' ') {
        calculator->sign = '*';
        calculator->cur_res = calculator->nmb;
        calculator->nmb = 0;

        calculator->await_right_operand = true;
        QString str(calculator->sign);
        ui->label->setText(ui->label->text() + str);
    }

}

void MainWindow::on_pushButton_divide_clicked()
{
    initialize_calc();
    if (calculator->sign == ' '){
        calculator->sign = '/';
        calculator->cur_res = calculator->nmb;
        calculator->nmb = 0;

        calculator->await_right_operand = true;
        QString str(calculator->sign);
        ui->label->setText(ui->label->text() + str);
    }

}

void MainWindow::on_pushButton_equal_to_clicked()
{

    if (ui->label->text()[ui->label->text().size() - 1] != calculator->sign) calculator->await_right_operand = false;
    cout << "equla push button is clicked!" << endl;
    cout << "cur_res " << calculator->cur_res << " nmb " << calculator->nmb << endl;
    if (int handle_error = calculator->PermitOperation()){
        cout << "handle error number " << handle_error << endl;
        if (handle_error == 2) QMessageBox::warning(this, "Error", "calculator doesn't support number greater than 2147483647");
        else if (handle_error == 1) QMessageBox::warning(this, "Error", "Divide by 0 is Impossible!!!");
        else if (handle_error == 3) ;
    }
    else{
         cout << "cur_res " << calculator->cur_res << endl;
        ui->label->setText(QString::number(calculator->cur_res));
        calculator->nmb = calculator->cur_res;
        calculator->is_first_calculation = false;
        calculator->await_right_operand = false;
        calculator->sign = ' ';
    }
}



void MainWindow::on_pushButton_clicked()
{

    initialize_calc();
    int digit = 1;
    if (ui->label->text()[0] == '0' && !calculator->await_right_operand){
        calculator->nmb = digit;
        calculator->is_first_calculation = true;
        QString str = QString::number(digit);
        ui->label->setText(str);
    }
    else{
        if (calculator->nmb <= INT_MAX / 10){
            calculator->nmb = calculator->nmb * 10 + digit;
            QString str = QString::number(digit);
            ui->label->setText(ui->label->text() + str);
        }
        else{
            QMessageBox::warning(this, "Error", "calculator doesn't support number greater than 2147483647");
        }

    }
}

void MainWindow::on_pushButton_2_clicked()
{

    cout << "first adress of calculator " << calculator << endl;
    initialize_calc();
    int digit = 2;
    if (ui->label->text()[0] == '0' && !calculator->await_right_operand){
        calculator->nmb = digit;
        calculator->is_first_calculation = true;
        QString str = QString::number(digit);
        ui->label->setText(str);
    }
    else{
        cout << "adding digit " << digit << " to number" << endl;
        if (calculator->nmb <= INT_MAX / 10){
            calculator->nmb = calculator->nmb * 10 + digit;
            cout << "past adding number is " << calculator->nmb << endl;
            QString str = QString::number(digit);
            ui->label->setText(ui->label->text() + str);
        }
        else{
            QMessageBox::warning(this, "Error", "calculator doesn't support number greater than 2147483647");
        }

    }
}

void MainWindow::on_pushButton_3_clicked()
{

    initialize_calc();

    int digit = 3;
    if (ui->label->text()[0] == '0' && !calculator->await_right_operand){
        calculator->nmb = digit;
        calculator->is_first_calculation = true;
        QString str = QString::number(digit);
        ui->label->setText(str);
    }
    else{
        if (calculator->nmb <= INT_MAX / 10){
            calculator->nmb = calculator->nmb * 10 + digit;
            QString str = QString::number(digit);
            ui->label->setText(ui->label->text() + str);
        }
        else{
            QMessageBox::warning(this, "Error", "calculator doesn't support number greater than 2147483647");
        }

    }

}

void MainWindow::on_pushButton_4_clicked()
{
    initialize_calc();
    int digit = 4;
    if (ui->label->text()[0] == '0' && !calculator->await_right_operand){
        calculator->nmb = digit;
        calculator->is_first_calculation = true;
        QString str = QString::number(digit);
        ui->label->setText(str);
    }
    else{
        if (calculator->nmb <= INT_MAX / 10){
            calculator->nmb = calculator->nmb * 10 + digit;
            QString str = QString::number(digit);
            ui->label->setText(ui->label->text() + str);
        }
        else{
            QMessageBox::warning(this, "Error", "calculator doesn't support number greater than 2147483647");
        }

    }
}

void MainWindow::on_pushButton_5_clicked()
{
    initialize_calc();
    int digit = 5;
    if (ui->label->text()[0] == '0' && !calculator->await_right_operand){
        calculator->nmb = digit;
        calculator->is_first_calculation = true;
        QString str = QString::number(digit);
        ui->label->setText(str);
    }
    else{
        if (calculator->nmb <= INT_MAX / 10){
            calculator->nmb = calculator->nmb * 10 + digit;
            QString str = QString::number(digit);
            ui->label->setText(ui->label->text() + str);
        }
        else{
            QMessageBox::warning(this, "Error", "calculator doesn't support number greater than 2147483647");
        }

    }
}

void MainWindow::on_pushButton_6_clicked()
{
    initialize_calc();
    int digit = 6;
    if (ui->label->text()[0] == '0' && !calculator->await_right_operand){
        calculator->nmb = digit;
        calculator->is_first_calculation = true;
        QString str = QString::number(digit);
        ui->label->setText(str);
    }
    else{
        if (calculator->nmb <= INT_MAX / 10){
            calculator->nmb = calculator->nmb * 10 + digit;
            QString str = QString::number(digit);
            ui->label->setText(ui->label->text() + str);
        }
        else{
            QMessageBox::warning(this, "Error", "calculator doesn't support number greater than 2147483647");
        }

    }
}

void MainWindow::on_pushButton_7_clicked()
{
    initialize_calc();
    int digit = 7;
    if (ui->label->text()[0] == '0' && !calculator->await_right_operand){
        calculator->nmb = digit;
        calculator->is_first_calculation = true;
        QString str = QString::number(digit);
        ui->label->setText(str);
    }
    else{
        if (calculator->nmb <= INT_MAX / 10){
            calculator->nmb = calculator->nmb * 10 + digit;
            QString str = QString::number(digit);
            ui->label->setText(ui->label->text() + str);
        }
        else{
            QMessageBox::warning(this, "Error", "calculator doesn't support number greater than 2147483647");
        }

    }


}

void MainWindow::on_pushButton_8_clicked()
{
    initialize_calc();
    int digit = 8;
    if (ui->label->text()[0] == '0' && !calculator->await_right_operand){
        calculator->nmb = digit;
        calculator->is_first_calculation = true;
        QString str = QString::number(digit);
        ui->label->setText(str);
    }
    else{
        if (calculator->nmb < INT_MAX / 10){
            calculator->nmb = calculator->nmb * 10 + digit;
            QString str = QString::number(digit);
            ui->label->setText(ui->label->text() + str);
        }
        else{
            QMessageBox::warning(this, "Error", "calculator doesn't support number greater than 2147483647");
        }

    }
}


void MainWindow::on_pushButton_9_clicked()
{
    initialize_calc();
    int digit = 9;
    if (ui->label->text()[0] == '0' && !calculator->await_right_operand){
        calculator->nmb = digit;
        calculator->is_first_calculation = true;
        QString str = QString::number(digit);
        ui->label->setText(str);
    }
    else{
        if (calculator->nmb < INT_MAX / 10){
            calculator->nmb = calculator->nmb * 10 + digit;
            QString str = QString::number(digit);
            ui->label->setText(ui->label->text() + str);
        }
        else{
            QMessageBox::warning(this, "Error", "calculator doesn't support number greater than 2147483647");
        }

    }

}


void MainWindow::on_pushButton_zero_clicked()
{
    initialize_calc();
    int digit = 0;
    cout << "current lasbel text " << ui->label->text().toStdString() << endl;
    if (ui->label->text()[0] == '0') cout << "first digit is 0" << endl;
    else{
        if (calculator->nmb < INT_MAX / 10){
            calculator->nmb = calculator->nmb * 10 + digit;
            QString str = QString::number(digit);
            ui->label->setText(ui->label->text() + str);
        }
        else{
            QMessageBox::warning(this, "Error", "calculator doesn't support number greater than 2147483647");
        }

    }
}

void MainWindow::on_pushButton_CE_clicked()
{
    if (calculator->sign == '+' || calculator->sign == '-' || calculator->sign == '*' || calculator->sign == '/'){
        calculator->nmb = calculator->cur_res;
        calculator->sign = ' ';
        int size = ui->label->text().size();
        QString leftSide = ui->label->text().left(size - 1);
        cout << leftSide.toStdString() << endl;
        ui->label->setText(leftSide);
    }
    else{

        if (calculator->nmb){
            cout << "try to cut number " << calculator->nmb << endl;
            calculator->nmb = calculator->nmb / 10;
            int size = ui->label->text().size();
            QString leftSide = ui->label->text().left(size - 1);
            cout << leftSide.toStdString() << endl;
            ui->label->setText(leftSide);
        }
        else if(ui->label->text()[ui->label->text().size() - 1] == '+' || ui->label->text()[ui->label->text().size() - 1] == '-'){
            ui->label->setText("");
        }
    }
}
