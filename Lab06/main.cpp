/*
 Name   Alberto D. and Giovanni B
 Date:  2/10/14
 Class: T 2:15
 Lab:   06
 */

#include "player.h"
#include <iostream>
#include <stdlib.h>

using namespace std;
void Play(Player* player1, Player* player2);

/*srand was not having enough delay, so call it earlier than the play function*/
int number;
int main() {
    int run = 1;
    srand(time(NULL));
    number = rand()%100;
    while (run == 1) {
        cout << "How do you want to play" <<endl;
        cout<< "1) Human v Human\n2) Human v Computer\n3) Computer v Computer\n4) Quit\n";
        int option;
        cin >>option;
        Player* player1, *player2;
        if(option == 1) {
            HumanPlayer h1;
            HumanPlayer h2;
            player1 = &h1;
            player2 = &h2;
        }
        else if(option == 2) {
            HumanPlayer h1;
            ComputerPlayer c1;
            player1 = &h1;
            player2 = &c1;
        }
        else if (option == 3) {
            ComputerPlayer c1;
            ComputerPlayer c2;
            player1 = &c1;
            player2 = &c2;
        }
        else {
            run++;
            return 0;
        }//end else
        Play(player1, player2);
    }//end while
    return 0;
}

void Play(Player* player1, Player* player2){
    bool tooHigh = false;
    int guess_1 = 0, guess_2 = 0, guess_count = 0, guess_1_total = 0, guess_2_total=0;
    while (1) {
    if (guess_count%2 == 0){
        if (guess_count!= 0) {
            player1->opponentsGuess(guess_2, tooHigh);
        }
        //player 1's turn
        guess_1 = player1->getGuess();
        guess_count++;
        guess_1_total++;
        if (guess_1 == number) {
            cout << "WINNING NUMBER: " << number<<endl;
            cout << "Player 1 wins after "<<guess_1_total<< " guesses!" <<endl;
            player1->reset();
            player2->reset();
            return;
        }
        tooHigh = (guess_1>number);
        player1->lastWasTooHigh(tooHigh);
    }//end if
    else{
        //player 2s turn
        player2->opponentsGuess(guess_1,tooHigh);
        guess_2 = player2->getGuess();
        guess_count++;
        guess_2_total++;
        if (guess_2 == number) {
            cout << "WINNING NUMBER: " << number<<endl;
            cout <<"Player 2 wins after "<<guess_2_total<< " guesses!" <<endl;
            player1->reset();
            player2->reset();
            return;
        }
        tooHigh = guess_2 > number;
        player2->lastWasTooHigh(tooHigh);
    }//end else
    }
}//end play