#include "Food.h"

Food::Food(int x, int y):Creature(x, y){
}

Food::~Food(){
}

HDC Food::getImage(){
    return image;
}

HDC Food::image = NULL;
