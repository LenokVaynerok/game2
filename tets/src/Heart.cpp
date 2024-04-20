#include "Heart.h"

Heart::Heart(int x, int y):Creature(x, y){
}

Heart::~Heart(){
}

HDC Heart::getImage(){
    return image;
}

HDC Heart::image = NULL;

