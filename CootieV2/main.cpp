//
//  main.cpp
//  CootieV2
//
//  Created by Nick Williams on 9/19/14.
//  Copyright (c) 2014 Ninjaneer. All rights reserved.
//
//  Description: This Program automatically generates random dice rolls
//               each time a user presses Enter, in order to build a complete
//               Cootie, based on the old Cootie children's game.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

bool checkComplete(int, int, int, int, int, int);
//Function that checks for Cootie Completion, which stops the build loop.
//Integer values of current piece quantities are sent to the function,
//which compares them against pre-defined ideal quantities.

int main(int argc, const char * argv[])
{
    string play;
    int diceRolls = 0;
    int die;
    int cootieBody = 0;
    int cootieHead = 0;
    int cootieAntenna = 0;
    int cootieWings = 0;
    int cootieStinger = 0;
    int cootieLegs = 0;
    
    srand((unsigned)time(0));
    
    cout << "Play a Game of Cootie!\n";
    play = "y";
    
    //Loop that executes only when the user wants to play.
    while  ((play == "y") || (play == "Y"))
    {
        //Loop that executes until Cootie is complete
        do
        {
            
            cout << "Press Enter to Roll your Die!\n";
            cin.get();
            
            die = (rand() % 6) +1;
            
            cout << "You rolled a " << die << endl;
            
            if (die == 1) //Body
            {
                if (cootieBody == 0)
                {
                    cout << "Great! You got a Body!\n";
                    cootieBody++;
                }
                else
                {
                    cout << "You already have a body!\n";
                }
            }
            
            if (die == 2) //Head
            {
                if (cootieBody != 1)
                {
                    cout << "You first need a Body to add a Head!\n";
                }
                else if (cootieHead == 1)
                {
                    cout << "You already have the Head!\n";
                }
                else
                {
                    cout << "Great! You got a Head!\n";
                    cootieHead++;
                }
            }
            
            if (die == 3) //Antenna
            {
                if (cootieBody != 1)
                {
                    cout << "You first need a Body to add Antennae!\n";
                }
                else if (cootieHead != 1)
                {
                    cout << "You first need a Head!\n";
                }
                else if (cootieAntenna < 2)
                {
                    cout << "Great! You got an Antenna!\n";
                    cootieAntenna++;
                }
                else
                {
                    cout << "You already have both Antennae!\n";
                }
            }
            
            if (die == 4) //Wing
            {
                if (cootieBody != 1)
                {
                    cout << "You first need a Body to add a Wing!\n";
                }
                else if (cootieWings < 4)
                {
                    cout << "Great! You got a Wing!\n";
                    cootieWings++;
                }
                else
                {
                    cout << "You already have all 4 Wings!\n";
                }
                
            }
            
            if (die == 5) //Stinger
            {
                if (cootieBody != 1)
                {
                    cout << "You first need a Body to add a Stinger!\n";
                }
                else if (cootieStinger == 0)
                {
                    cout << "Great! You got a Stinger!\n";
                    cootieStinger++;
                }
                else
                {
                    cout << "You already have a Stinger!\n";
                }
            }
            
            if (die == 6) //Legs
            {
                if (cootieBody != 1)
                {
                    cout << "You first need a Body to add Legs!\n";
                }
                else if (cootieLegs < 2)
                {
                    cout << "Great! You got a Leg!\n";
                    cootieLegs++;
                }
                else
                {
                    cout << "You already have both Legs!\n";
                }
            }
            
            
            diceRolls++; //Dice Roll Accumulator
            
            cout << "Your Cootie now has\n"
                 << cootieBody << " Body,\n"
                 << cootieHead << " Head,\n"
                 << cootieAntenna << " Antennae,\n"
                 << cootieWings << " Wing(s),\n"
                 << cootieStinger << " Stinger, and\n"
                 << cootieLegs << " Leg(s)." << endl;
            
        } while (checkComplete(cootieBody,
                              cootieHead,
                              cootieAntenna,
                              cootieWings,
                              cootieStinger,
                              cootieLegs) == false);
        
        
        cout << "Congratulations!\n";
        cout << "You completed your Cootie in " << diceRolls << " Rolls!\n";
        cout << "Do you want to play again? [y/n]\n";
            
        
            
        cin >> play;
        cin.ignore();
        
        //Resets Cootie Parts to Zero for replay.
        diceRolls = 0;
        cootieBody = 0;
        cootieHead = 0;
        cootieAntenna = 0;
        cootieWings = 0;
        cootieStinger = 0;
        cootieLegs = 0;
        
    }
    cout << "Thank you! Goodbye.\n";
    return 0;
}


bool checkComplete(int cootieBody, int cootieHead, int cootieAntenna,
                   int cootieWings, int cootieStinger, int cootieLegs)
{
    if ((cootieBody == 1) &&
        (cootieHead == 1) &&
        (cootieAntenna == 2) &&
        (cootieWings == 4) &&
        (cootieStinger == 1) &&
        (cootieLegs == 2))
    {
        return true;
    }
    else
        return false;
}



