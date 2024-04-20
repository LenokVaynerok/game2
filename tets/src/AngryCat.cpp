#include "AngryCat.h"

AngryCat::AngryCat(int x, int y, int spd):Creature(x, y), speed(spd){
}

AngryCat::~AngryCat(){
}

HDC AngryCat::getImage(){
    return image;
}

HDC AngryCat::image = NULL;

void AngryCat::moveTowards(Creature *other){
    if (other == NULL)
        return;

    int stepX = min(speed, abs(posX - other->posX));
    if (posX < other->posX)
        moveX(stepX);
    else
        moveX(-stepX);

    int stepY = min(speed, abs(posY - other->posY));
    if (posY < other->posY)
        moveY(stepY);
    else
        moveY(-stepY);
}
