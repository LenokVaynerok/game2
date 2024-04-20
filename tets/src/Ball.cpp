#include "Ball.h"

Ball::Ball(int x, int y, int spd):Creature(x, y), speed(spd){
}

Ball::~Ball(){
}

HDC Ball::getImage(){
    return image;
}void Ball::moveTowards(int x, int y, int spd){
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

HDC Ball::image = NULL;
