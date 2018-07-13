/** @file   control.c
    @author John He (44056699) & Michelle Xie (22378644)
    @date   9 Oct 2016
    @brief  decide the winner
   
*/


int get_winner(char my_symbol, char player2_symbol)     //compares two parameters (my symbol and palyer2 symbol) and assigns comparison result number, 0 (draw), 1 (you win), 2 (you lost)
{

    if (my_symbol == player2_symbol) {  // compares the two symbols to see if it is a draw
        return 0;

    } else if ((my_symbol == 'P' && player2_symbol == 'R') || (my_symbol == 'S' && player2_symbol == 'P') || (my_symbol == 'R' && player2_symbol == 'S')) {     // if any of the given is true it mean my_symbol won, therefore returns a value 2
        return 1;

    } else {                    // if you done draw or win, then you lose, return value 2
        return 2;
    }
}
