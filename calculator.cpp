#include "calculator.h"
#include <QMessageBox>
#include <iostream>
using std::cout; using std::endl;
Calculator::Calculator()
{
    nmb = 0;
}

//Calculator::ChangeNumber(int nmb){
//    this->nmb = nmb;
//}

int Calculator::PermitOperation(){
    int handle_error = 0;

    if (await_right_operand || sign == ' '){
        return 3;
    }
    else if (sign == '+'){

        handle_error = Plus();
    }
    else if (sign == '-'){
        handle_error = Minus();
    }
    else if (sign == '*'){
        handle_error = Cdot();
    }
    else if (sign == '/'){
        handle_error = Divide();
    }
    cout << "Executing operation " << this->cur_res << " " << sign << " " << this->nmb << endl;
    return handle_error;
}

int Calculator::Plus(){
    bool sign = this->nmb > 0 || this->cur_res > 0;
    if (sign){
        if (this->nmb > 0 && this->cur_res > 0 && this->nmb + this->cur_res < 0){
            return 2;
        }
        if (this->nmb < 0 && this->cur_res < 0 && this->nmb + this->cur_res >= 0){
            return 2;
        }
    }
    this->cur_res = this->nmb + this->cur_res;
    this->nmb = 0;
    return 0;
}
int Calculator::Minus(){
    if (this->cur_res  < INT_MIN + this->nmb){

//         QMessageBox::warning(this, "Error", "calculator doesn't support number greater than 2147483647");
        return 2;
    }
    else{
        cout << "QUTPUT FROM MINUS FUNCTION" << endl;
        cout << "cur_res " << this->cur_res << " nmb " << this->nmb << endl;
        this->cur_res = this->cur_res - this->nmb;
        this->nmb = 0;
        return 0;
    }}
int Calculator::Cdot(){
    if (!this->nmb) {
        this->cur_res = 0;
        this->nmb = 0;
        return 0;
    }
    if (abs(this->cur_res) > (INT_MAX / abs(nmb))){ // TODO: This implementation not correct but fast
//         QMessageBox::warning(this, "Error", "calculator doesn't support number greater than 2147483647");
        return 2;
    }
    else{
        this->cur_res = this->nmb * this->cur_res;
        this->nmb = 0;
        return 0;
    }}
int Calculator::Divide(){
    if (!nmb){
        return 1;
//         QMessageBox::warning(this, "Error", "Divide by 0 is Impossible!!!");
    }
    else{
        this->cur_res = this->cur_res / this->nmb;
        this->nmb = 0;
        return 0;
 }}
