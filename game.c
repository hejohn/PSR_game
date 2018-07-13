/** @file   game.c
    @author John He & Michelle Xie
    @date   9 October 2016
    @brief  display paper, scissor, rock, start & game over

*/

//Header Files
#include "system.h"
#include "pio.h"
#include "pacer.h"
#include "ir_uart.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "message.h"
#include "navswitch.h"
#include "control.h"
#include "ledmat.h"



#define PACER_RATE 500
#define MESSAGE_RATE 10
#define LOOP_RATE 1000


char player2_symbol = 'A';      // dummy symbol
char my_symbol = 'A';           // dummy symbol


void display_win(void)          //display win 
{
    tinygl_init(LOOP_RATE);
    tinygl_font_set(&font5x7_1);
    tinygl_text_speed_set(MESSAGE_RATE);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);

    tinygl_text("WIN");
    pacer_init(PACER_RATE);

    ir_uart_putc('L');          // send the character L to the other player telling them they lost.

    while (1) {
        pacer_wait();
        tinygl_update();
    }
}

void display_lose(void)         //display lose
{
    tinygl_init(LOOP_RATE);
    tinygl_font_set(&font5x7_1);
    tinygl_text_speed_set(MESSAGE_RATE);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);

    tinygl_text("LOSE");
    pacer_init(PACER_RATE);

    while (1) {
        pacer_wait();
        tinygl_update();
    }
}


void display_draw(void)         //display draw
{
    tinygl_init(LOOP_RATE);
    tinygl_font_set(&font5x7_1);
    tinygl_text_speed_set(MESSAGE_RATE);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);

    tinygl_text("DRAW");
    pacer_init(PACER_RATE);
    ir_uart_putc('D');

    while (1) {
        pacer_wait();
        tinygl_update();

    }
}

int main(void)                  // main program
{
    system_init();
    tinygl_init(LOOP_RATE);
    tinygl_font_set(&font5x7_1);
    tinygl_text_speed_set(MESSAGE_RATE);
    navswitch_init();
    ir_uart_init();
    pacer_init(LOOP_RATE);

    char character[] = { 'P', 'S', 'R' };
    int number = 1;
    int sent = 0;
    int receive = 0;
    int result = 0;

   // connect();

    while (1) {
        pacer_wait();
        tinygl_update();
        navswitch_update();

        if (number > 2) {
            number = 0;
        } else if (number < 0) {
            number = 2;
        }

        if (navswitch_push_event_p(NAVSWITCH_NORTH)) {  //switch to next character
            number++;
        }

        if (navswitch_push_event_p(NAVSWITCH_SOUTH)) {  //switch to last character
            number--;
        }

        display_character(character[number]);

        if (navswitch_push_event_p(NAVSWITCH_PUSH)) { //push to confirm current character 
            ir_uart_putc(character[number]);
            my_symbol = character[number];
            sent = 1;
        }
        if (ir_uart_read_ready_p()) {
            player2_symbol = ir_uart_getc();
            receive = 1;
        }
        if (sent == 1 && receive == 1) { // when both sent and receive signal is received, display result
            result = get_winner(my_symbol, player2_symbol);
            if (result == 0) {
                display_draw();
            } else if (result == 1) {
                display_win();
            } else if (player2_symbol == 'L') {
                display_lose();
            } else if (player2_symbol == 'D') {
                display_draw();
            } else if (my_symbol == 'D') {
                display_draw();
            }
        }
        tinygl_update();
    }
    return 0;
}
