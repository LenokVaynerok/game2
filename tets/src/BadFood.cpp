#include "BadFood.h"

BadFood::BadFood(int x, int y):Creature(x, y){
}

BadFood::~BadFood()
{
    //dtor
}

HDC BadFood::getImage(){
    return image;
}

HDC BadFood::image = NULL;
