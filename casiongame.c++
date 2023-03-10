#include <iostream>
#include <string> 
#include <cstdlib> 
#include <ctime>
using namespace std;
void drawLine(int n, char symbol);
void rules();
int main()
{
    string name;
    int amt; 
    int bamt;
    int guess;
    int dice; 
    char choice;
    srand(time(0)); 
    drawLine(90,'_');
    cout << "\n\n\t\tCASINO GAME\n\n";
    drawLine(90,'_');
    cout<<"WELCOME TO OUR CASINO"<<endl;
    cout << "Enter Your Name : ";
    getline(cin, name);
    cout << "Enter Deposit amt to play game : Rs ";
    cin >> amt;
    do
    {
        system("cls");
        rules();
        cout << "\nYour current balance is Rs " << amt << "\n"<<endl;
        do
        {
            cout <<name<<", enter money to bet : Rs ";
            cin >> bamt;
            if(bamt > amt)
                cout << "Your betting amt is more than your current balance\n"
                       <<"\nRe-enter data\n ";
        }while(bamt > amt);
        do
        {
            cout << "Guess your number to bet between 1 to 10 :";
            cin >> guess;
            if(guess <= 0 || guess > 10)
                cout << "Please check the number!! should be between 1 to 10\n"
                    <<"\nRe-enter data\n ";
        }while(guess <= 0 || guess > 10);
        dice = rand()%10 + 1; 
        if(dice == guess)
        {
            cout << "\n\nGood Luck!! You won Rs." << bamt * 10;
            amt = amt + bamt * 10;
        }
        else
        {
            cout << "Bad Luck this time !! You lost Rs "<< bamt <<"\n";
            amt = amt - bamt;
        }
        cout << "\nThe winning number was : " << dice <<"\n";
        cout << "\n"<<name<<", You have Rs " << amt << "\n";
        if(amt == 0)
        {
            cout << "You have no money to play "<<endl;;
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
    cout << "\n\n\n";
    drawLine(85,'=');
    cout << "\n\nThanks for playing game. Your balance amt is Rs " << amt << "\n\n";
    drawLine(85,'=');
    cout<<"by:Chandana mn "<<endl;
    cout<<"20030141cse060"<<endl;
    cout<<"sec:B";
    return 0;
}
void drawLine(int n, char symbol)
{
    for(int i=0; i<n; i++)
        cout << symbol;
    cout << "\n" ;
}
void rules()
{
    system("cls");
    cout << "\n\n";
    drawLine(90,'-');
    cout << "\t\tRULES OF THE GAME\n";
    drawLine(90,'-');
    cout << "1. Choose any number between 1 to 10\n";
    cout << "2. If you win you will get 10 times of money you bet\n";
    cout << "3. If you bet on wrong number you will lose your betting amt\n\n";
    drawLine(90,'-');
}
