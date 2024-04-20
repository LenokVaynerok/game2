#include "Light.h"

Light::Light(int x, int y, int spd):Creature(x, y), speed(spd){
}

Light::~Light(){
}

HDC Light::getImage(){
    return image;
}void Light::moveTowards(int x, int y, int spd){
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

HDC Light::image = NULL;

