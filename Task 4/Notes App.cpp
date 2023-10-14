#include <iostream>
#include <fstream>
#include <conio.h>
#include <chrono>
using namespace std;


#define CLEAR       "\033[H\033[J"

void menu();
void add();
void del(int num=-2);
void done(int num=-2);
void view();

int added;

int main(){
    ifstream add("Notes.txt");
    add >> added;
    add.close();
    menu();
    return 0;
}

void menu(){
    int choice = -1;
    while(choice != 5){
        cout <<CLEAR;//system("cls");
        cout<<"Enter your choice 1 - 5:\n"
            <<"1.Add a New Note\n"
            <<"2.View all Notes\n"
            <<"3.Delete a Note By Number\n"
            <<"4.Mark as Copmleted\n"
            <<"5.Exit\n";
        cin >> choice;
        if(choice < 1 || choice > 5){
            cout << "Invalid Input Press Enter to try again\n";
            choice = -1;
            _getch();
        }
        else if(choice==1){
            add();
        }
        else if(choice==2){
            view();
        }
        else if(choice==3){
            del();
        }
        else if(choice==4){
            done();
        }
        else{
            cout <<CLEAR;//system("cls");
            cout << "Good Bye :)\n";
            exit(0);
        }
    }
}

void add(){
    ofstream add("Notes.txt", ios::out | ios::app);
    cout << "Enter Your Note in one line:\n";
    string note;
    cin.ignore();
    getline(cin, note);
    add << note <<"\n"<<0<<"\n";
    add.close();
    added++;
    del(0);
}

void del(int num){
    while(num==-2){
        cout << "(Press view to get number)\n";
        cout << "Enter Note number To Delete [1 - "<<added<<"] or -1 to cancle: ";
        cin >> num;
        if(num == -1 ) return;
        if(num < 1 || num > added){
            cout << "Invalid Input Press Enter again...";
            num = -2;
            continue;
        }
    }

    //CLearing Temp.txt file
    fstream temp("Temp.txt", ios::out | ios::trunc);
    temp << "";
    temp.close();

    auto status = ios::in | ios::out | ios::app;
    temp.open("Temp.txt", status);
    fstream notes("Notes.txt", status);
    string note;
    int i = 1;
    getline(notes, note);
    while (getline(notes, note)){
        if(i++ == num*2-1){
            getline(notes, note);
            continue;
        }
        temp << note << "\n";
    }
    temp.close();
    notes.close();

    //CLearing Notes.txt file
    notes.open("Notes.txt", ios::out | ios::trunc);
    notes << "";
    notes.close();

    added = added - 1 + (num==0);
    temp.open("Temp.txt", status);
    notes.open("Notes.txt", status);
    notes << added <<"\n";
    while (getline(temp, note)){
        notes << note <<"\n";
    }
    cout << (num?"Deleted!":"Added!")<<"\n"
         << "Press Enter to Continue...";
         _getch();
    

}

void view(){
    ifstream view("Notes.txt");
    string note;
    bool completed;
    int i = 0;
    getline(view, note);
    while (getline(view, note)){
        view >> completed;
        cout << ++i << " " << note <<"\n"<< (completed?"Completed":"Not Completed")<<"\n";
        view.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Press Enter To Continue...";
    _getch();
}

void done(int num){
    while(num==-2){
        cout << "(Press view to get number)\n";
        cout << "Enter Note number To Mark as Completed [1 - "<<added<<"] or -1 to cancle: ";
        cin >> num;
        if(num == -1 ) return;
        if(num < 1 || num > added){
            cout << "Invalid Input Press Enter again...";
            num = -2;
            continue;
        }
    }

    //CLearing Temp.txt file
    fstream temp("Temp.txt", ios::out | ios::trunc);
    temp << "";
    temp.close();

    auto status = ios::in | ios::out | ios::app;
    temp.open("Temp.txt", status);
    fstream notes("Notes.txt", status);
    string note;
    int i = 1;
    getline(notes, note);
    while (getline(notes, note)){
        if(i++ == num*2-1){
            temp << note << "\n1\n";
            getline(notes, note);
            continue;
        }
        temp << note << "\n";
    }
    temp.close();
    notes.close();

    //CLearing Notes.txt file
    notes.open("Notes.txt", ios::out | ios::trunc);
    notes << "";
    notes.close();

    temp.open("Temp.txt", status);
    notes.open("Notes.txt", status);
    notes << added <<"\n";
    while (getline(temp, note)){
        notes << note <<"\n";
    }
    cout << "Done!\n"
         << "Press Enter to Continue...";
         _getch();
}