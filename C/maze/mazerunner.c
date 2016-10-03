#include <stdio.h>
#include <stdbool.h>
#include "display.h"
#include <curses.h>

int main(){
    int level;
    char action;
    int row, col;
    int dir;
    int *x, *y;

    init_display(0);
    dir = row = col = 0;
    x = &col;
    y = &row;
    show_mouse(dir, *y, *x);
    action =  getchar();
    show_position(*y, *x);
    while(action != 'q'){ 
        dir = determine_direction(dir, action);
        if(action == 'w'){
            move_direction(dir, x, y);
        }
        show_mouse(dir, *y, *x);
        show_position(*y, *x);
        action = getchar();
    }
    clear_screen();
}
