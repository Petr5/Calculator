#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <calculator.h>
class Calculator;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//    friend Calculator;
private slots:


    void on_pushButton_plus_clicked();

    void on_pushButton_minus_clicked();

    void on_pushButton_cdot_clicked();


    void on_pushButton_equal_to_clicked();

    void on_pushButton_divide_clicked();

    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

//    void on_label_windowIconTextChanged(const QString &iconText);
    void initialize_calc();

private:
    Ui::MainWindow *ui;
    Calculator* calculator = nullptr;
};

#endif // MAINWINDOW_H
