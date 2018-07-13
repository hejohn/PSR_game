/** @file   control.h
    @author John He & Michelle Xie
    @date   3 October 2016
    @brief  display paper, scissor, rock, start & game over 
   
*/
#include "system.h"
#include "pio.h"
#include "pacer.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "message.h"
#include <stdio.h>
#include "navswitch.h"
#include "ir_uart.h"


int get_winner(char my_symbol, char player2_symbol);
  //return an integer representing the winner
