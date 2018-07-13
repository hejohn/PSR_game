/** 
    @file   message.c
    @author John He (44056699) & Michelle Xie (22378644)
    @date   9 Oct 2016
    @brief  This module creates a single charcter buffer to display letters which will represents the display of paper, scissor and rock
*/

#include "tinygl.h"
 
void display_character(char character)
{
    char buffer[2]; // creates space for an single letter
    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text(buffer);
}
