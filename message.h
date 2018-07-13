/** @file   message.c
    @author John He & Michelle Xie
    @date   3 October 2016
    @brief  display paper, scissor, rock, start & game over 
   
*/
#include "system.h"
#include "pio.h"
#include "pacer.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include <stdio.h>

#define PACER_RATE 500
#define MESSAGE_RATE 10


void display_character(char character);
    /*Display character*/


