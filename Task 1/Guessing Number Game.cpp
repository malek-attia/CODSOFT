#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    int choice;
    int counter;
    while(choice!=-1){
        srand(time(0));
        counter=0;
        cout << "guess the number from 0 to 100..\n";
        int number = rand() %101;
        cin >> choice;
        counter++;
        while(choice!=number){
            cout << ((choice>number)?"smaller  ":"bigger  ");
            cin >> choice;
            if(choice==-1){break;}
            counter++;
        }
        if(choice==number){
            cout << "That's Right\nyou guessed the right number " << number
                <<" from " << counter << " times"
            << endl << "press 1 to play again\n"
            << "press -1 to exit"<< endl;
            cin >> choice;
        }
    }
    cout << "see you later :)..." << endl;
    return 0;
}