#include <iostream>
using namespace std;

double My_Power(double x, int y){
    if(y == 0)
        return 1;
    if(y == 1)
        return x;
    if(y%2)
        return My_Power(x, y/2+1) * My_Power(x, y/2);
    else
        return My_Power(x, y/2) * My_Power(x, y/2);
}

int main() {
    int choice = -1;
    while(choice != 6){
        cout<<"Enter your choice 1 - 4:\n"
            <<"1.Addition (+)\n"
            <<"2.Subtraction (-)\n"
            <<"3.Multiplication (*)\n"
            <<"4.Division (/)\n"
            <<"5.Power (^)\n"
            <<"6.Exit\n";
        cin >> choice;
        if(choice < 1 || choice > 6){
            cout << "Invalid Input Press Enter to try again\n";
            choice = -1;
            continue;
        }
        if(choice == 6){
            cout << "Good Bye!\n";
            break;
        }
        double x, y;
        cout << "input 1st number...";
        cin >> x;
        cout << "input 2nd number...";
        cin >> y;
        if(choice==1){
            cout << x <<" + " << y << " = " << (x + y) << endl;
        }
        else if(choice==2){
            cout << x <<" - " << y << " = " << (x - y) << endl;
        }
        else if(choice==3){
            cout << x <<" * " << y << " = " << (x * y) << endl;
        }
        else if(choice==4){
            cout << x <<" / " << y << " = " << (x / y) << endl;
        }
        else{
            if(y > -1)
                cout << x <<" ^ " << int(y) << " = " << My_Power(x, y) << endl;
            else
                cout << x <<" ^ " << int(y) << " = " << 1/My_Power(x, y) << endl;
        }
    }
    cout << "see you later :)\n";
    return 0;
}