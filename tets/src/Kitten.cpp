#include "Kitten.h"

Kitten::Kitten(int x, int y):Creature(x, y){
}

Kitten::~Kitten(){
}

HDC Kitten::getImage(){
    return image;
}

HDC Kitten::image = NULL;
