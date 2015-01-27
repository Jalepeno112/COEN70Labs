
/*
 Name   Alberto D. and Giovanni B
 Date:  2/10/14
 Class: T 2:15
 Lab:   06
 */
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <stdlib.h>

using namespace std;
class Player{
public:
    Player()
        {};
    virtual ~Player()
        {};
    virtual int getGuess()
    {return 0;}
    // Returns the players next guess, an integer between
    // 0 and 99 (inclusive)
    virtual void lastWasTooHigh(bool tooHigh)
        {};
    // Called to inform the player that their last guess
    // was too high (if the tooHigh argument is true) or
    // too low (if the tooHigh argument is false)
    virtual void opponentsGuess(int guess, bool tooHigh)
        {};
    // Called to tell the player what the opponent's last
    // guess was, and whether it was too high or too low.
    virtual void reset()
        {};
    // Called to reset the player at the end //of the game.
    // Any stored state about the last guess //should be cleared.
};//end class player

class HumanPlayer : public Player {
public:
    HumanPlayer() {}
    ~HumanPlayer() {};
    int getGuess();
    void lastWasTooHigh(bool tooHigh);
    void opponentsGuess(int guess, bool tooHigh) {};
    void reset(){};
};
/*ak user for guess*/
int HumanPlayer::getGuess() {
    cout<< "Enter guess: ";
    int g;
    cin >> g;
    return g;
}
/*tell user if their guess was too high or too low*/
void HumanPlayer::lastWasTooHigh(bool tooHigh) {
    if (tooHigh) {
        cout << "Last guess was too high" <<endl;
    }
    else
        cout <<"Last guess was too low" <<endl;
}

class ComputerPlayer : public Player {
public:
    ComputerPlayer();
    ~ComputerPlayer(){};
    int getGuess();
    void lastWasTooHigh(bool tooHigh);
    void opponentsGuess(int guess, bool tooHigh);
    void reset();
private:
    int highBound;
    int lowBound;
    int our_guess;
};
/*create a new computer player with a high bound at 100, low bound 0 and a guess of 0*/
ComputerPlayer::ComputerPlayer() {
    highBound = 100;
    lowBound = 0;
    our_guess = 0;
}
/*randomly generate guess based on high and low bounds*/
int ComputerPlayer::getGuess() {
    srand(time(NULL));
    /*highbound+1 - low bound sets the highest guess that the computer can make and assures that it never does rand%0.  Adding lowbound at the end sets the lowest value for guess*/
    our_guess = (rand()%((highBound+1) - lowBound))+lowBound;
    return our_guess;
}
/*output if computer guess was to high or too low and adjust bounds*/
void ComputerPlayer::lastWasTooHigh(bool tooHigh) {
    if(tooHigh) {
        cout << "Computer's guess " << our_guess<<" was too high!"<<endl;
        highBound = our_guess-1;
    }
    else {
        cout << "Computer's guess " << our_guess<<" was too low!"<<endl;
        lowBound = our_guess+1;
    }
}

/*check the opponnets guess and adjust guessing bounds*/
void ComputerPlayer::opponentsGuess(int guess, bool tooHigh) {
    if(tooHigh) {
        if(guess < highBound) {
            highBound = guess;
        }
    }//end if
    else{
        if(guess > lowBound) {
            lowBound = guess;
        }
    }
}

/*reset data*/
void ComputerPlayer::reset() {
    highBound = 100;
    lowBound = 0;
    our_guess = 0;
}
#endif