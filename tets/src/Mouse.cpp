#include "Mouse.h"

Mouse::Mouse(int x, int y):Creature(x, y){

}

Mouse::~Mouse(){
}

HDC Mouse::getImage(){
    return image;
}

HDC Mouse::image = NULL;
