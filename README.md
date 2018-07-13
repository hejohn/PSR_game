/** @file   README.md
    @author John He & Michelle Xie(TEAM4)
    @date   11 October 2016
    @brief  game instructions
*/
Instructions for paper, scissors, rock (PSR) game : 


1 Using the north and south key to to change between paper (P), scissors (S) and rock (R).

2) To confirm selection of the shape, press the joystick and wait for opponent.

3) A result of win or lost will then appear to each player.


Modules Description

game.c 
This contains the main (PSR)game function.

control. c 
This module is the result decider module that determines if the game who 
won, loss or drew.  Takes in  2 parameters, my_symbol and player2_symbol
 representing the 2 symbol selected from the two players and compares them
 and returns a value which corresponds to either drew, win or lose.
 
message. c
This module just creates an character buffer used to represent then symbols.
