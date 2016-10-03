#include "display.h"

int determine_direction(int direction, char new_dir){

    if(new_dir == 'a'){
        switch(direction){
            case NORTH: return WEST;
            case WEST: return SOUTH;
            case SOUTH: return EAST;
            case EAST: return NORTH;
        }
    }
    if(new_dir == 's'){
        switch(direction){
            case NORTH: return SOUTH;
            case SOUTH: return NORTH;
            case WEST: return EAST;
            case EAST: return WEST;
        }
    }
    if(new_dir == 'd'){
        switch(direction){
            case NORTH: return EAST;
            case EAST: return SOUTH;
            case SOUTH: return WEST;
            case WEST: return NORTH;
        }
    }
    return direction;
}

int move_direction(int direction, int *x, int *y){
    if( direction == NORTH && *y < 15){
        return (*y)++;
    }
    else if( direction == SOUTH && *y > 0){
        return (*y)--;
    }
    else if(direction == EAST && *x < 15){
        return (*x)++;
    }
    else if(direction == WEST && *x > 0){
        return (*x)--;
    }       

}

