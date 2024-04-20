#include "AngryBall.h"

AngryBall::AngryBall(int x, int y, int spd):Creature(x, y), speed(spd){
}

AngryBall::~AngryBall(){
}

HDC AngryBall::getImage(){
    return image;
}void AngryBall::moveTowards(int x, int y, int spd){
    if (x == NULL)
        return;

    int stepX = min(speed, abs(posX - x));
    if (posX< x)
        moveX(stepX);
    else
        moveX(-stepX);

    int stepY = min(speed, abs(posY -  y));
    if (posY< x)
        moveY(stepY);
    else
        moveY(-stepY);
}

HDC AngryBall::image = NULL;

