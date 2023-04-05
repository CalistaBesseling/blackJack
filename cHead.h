#include <iomanip>
#include <cmath>
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;
void run();
bool checkInput(int);
void printState(int, int);
int dealerLogic();
int playerLogic();
int draw();
void menu();
void howToPlay();

int draw()
{
    srand(time(NULL));

    int randDraw;

    std::array<std::array<int, 13>, 4> arr = { {
        {1,2,3,4,5,6,7,8,9,10,11,12,13},
        {14,15,16,17,18,19,20,21,22,23,24,25,26},
        {27,28,29,30,31,32,33,34,35,36,37,38,39},
        {40,41,42,43,44,45,46,47,48,49,50,51,52}
    }};

    std::array<int, 13> arr2 = {{1,2,3,4,5,6,7,8,9,10,11,12,13}};

    const int ROWS = 4;
    string suits[ROWS] =
    {
        "Diamonds", "Clubs", "Hearts", "Spades"
    };

    const int COLS = 13;
    string faces[COLS] =
    {
            "Ace", "Deuce", "Three", "Four", "Five", "Six",
        "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"
    };

    int deck[ROWS][COLS] =
    {
        {1,2,3,4,5,6,7,8,9,10,11,12,13},
        {14,15,16,17,18,19,20,21,22,23,24,25,26},
        {27,28,29,30,31,32,33,34,35,36,37,38,39},
        {40,41,42,43,44,45,46,47,48,49,50,51,52}
    };

    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int array2[12];


    randDraw = (rand() % 13) + 1;

    for (int i = randDraw-1; i < 12; ++i)
        array[i] = array[i + 1];

    std::cout << randDraw << endl;

    for (int i = 0; i < 12; i++) {
        array2[i] = array[i];
    }

    for (int i = 0; i < 12; i++) {
        cout << array2[i] << endl;
    }
}

int dealerLogic()
{
    bool hard = false;
    bool dealerGo = true;
    int total;
    while (dealerGo == true)
    {
        if (total == 17)
        {
            if (hard == false)
            {
                total += draw();
            }
            else
            {
                dealerGo = false;
            }
        }
        else if (total <= 16)
        {
            total += draw();
        }else{
            dealerGo = false;    
        }
    }
    return total;
}

int playerLogic()
{
    bool firstTurn = true;
    bool hard = false;
    int total;
    if (firstTurn == true)
    {
        total = draw() + draw();
    }
    else if (checkInput(total) == true)
    {
        total += draw();
    }

    return total;
}

void run()
{
    bool deal = true;
    // shuffle();
    int dealt = dealerLogic();
    int playHand = playerLogic();

    while (deal)
    {
        printState(dealt, playHand);
        deal = checkInput(playHand);
    }

    // checkWinner();
    printState(dealt, playHand);
}

void printState(int dealer, int player)
{
    cout << "\n";
    cout << "DEALER" << left << setw(7) << right << "YOU" << endl;
    cout << dealer << left << setw(10) << right << player << endl;
    cout << "\n";
}

bool checkInput(int player)
{
    char hit;

    if (player < 21)
    {
        cout << "Hit? (y/n): ";
        cin >> hit;
        while (hit != 'y' && hit != 'n')
        {
            cout << "You stupid, try again (y/n)";
            cin >> hit;
        }

        if (hit == 'y')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

void checkWinner(int dealer, int player)
{
    if (dealer > player)
    {
        cout << "Dealer won!";
    }
    else
    {
        cout << "You won!!";
    }
}

void menu() {
    int choice;
    cout<<"Welcome to BlackJack!\nSelect your option: 1, 2, 3"<<endl;
    cout<<"1)How to Play\n"<<"2)Start Game\n"<<"3)Exit"<<endl;
    cin>>choice;
    if (choice ==1) {
        cout << "play ";
        //howToPlay();
    } else if (choice ==2) {
        cout << "Not how to play";
        //run();
    } else {
        return;
    }
}

void howToPlay() {
    string choice2;
    cout<<"The goal of black jack is to get as close to 21 as possible without going over, while still having a greater hand than the dealer.\n\n";
    cout<<"The program will deal you and itself 2 cards, you may choose to 'Hit' or 'Stand'\nHitting will deal you another card, while stand will allow you to maintain your current amount.\n\n";
    cout<<"The amount is calculated based on the sum of the value of each of the cards. Cards 2-10 are simply their face values, an Ace is 1 or 11, and Jack, Queen, and King are 10."<<endl;
    cout<<"Would you like to start playing now? (y/n)";
    cin>>choice2;
    if (choice2 == "Y" || choice2 == "y") {
        run();
    } else {
        cout<<"Ok! You will be returned to the menu."<<endl;
        menu();
    }
}