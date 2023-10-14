#include <iostream>
#include <unistd.h> /* for sleep */
using namespace std;

//ANSI escape codes for text attributes
#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define UNDERLINE   "\033[4m"
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define BLUE        "\033[34m"
#define WHITE       "\033[97m"
#define CLEAR       "\033[H\033[J"


char arr[9][9];
    int win[2][20];
int n;

void print_board(){
    cout << CLEAR;
    for (int i = 0; i < n; i++){
        cout <<UNDERLINE <<BOLD;
        for (int j = 0; j < n; j++){
            cout <<" ";
            if(arr[i][j]=='x')cout <<RED;
            else if(arr[i][j]=='o')cout << BLUE;
            cout << arr[i][j]<<WHITE  <<" |"; }cout<<"\n";}
    cout <<RESET;
}

int main()
{
    cout << CLEAR;
    cout << "Enter N as The Board Dimensions is N x N: ";
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = '.';

    
    //Starting The Game
    for (int i = 0; i < n*n; i++)
    {
        print_board();
        //Switching Turns
        char player = ((i+1)%2)?'x':'o';
        int win_i = (player=='x')? 0 : 1 ;

        cout << "player "<<player<<" turn, Enter empty location (r, c): ";
        int r,c;
        cin >> r >> c;
        r--;c--;

        //Cheking space validity
        if(arr[r][c]!='.'){
            cout<<"Invalid input try again\n";
            sleep(1);
            i--;continue;
        }

        arr[r][c]=player;

        win[win_i][r]++;
        win[win_i][c+n]++;
        if(r==c)
            win[win_i][18]++;
        if(r+c+1==n)
            win[win_i][19]++;

        
        
        //Cheking Winning
        for (int k = 0; k < 20; k++){
            if(win[win_i][k]==n){
                print_board();
                cout <<"Player "<<player<<" Won!!\n";
                return 0;
            }
        }
    }
    
    cout << "Draw :)";
    return 0;
}