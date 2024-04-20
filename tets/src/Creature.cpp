#include "Creature.h"

Creature::Creature(int x, int y) : posX(x), posY(y){
}

Creature::~Creature(){
}

HDC Creature::canvas;
int Creature::maxX;
int Creature::maxY;

void Creature::draw(){
    txTransparentBlt (canvas, posX, posY, 0, 0, getImage(), 0, 0, TX_WHITE);
}

void Creature::moveX(int step){
    int newPosX = posX + step;
    if (newPosX < 0)
        newPosX = 0;
    if (newPosX > maxX)
        newPosX = maxX;
    posX = newPosX;
}

void Creature::moveY(int step){
    int newPosY = posY + step;
    if (newPosY < 0)
        newPosY = 0;
    if (newPosY > maxY)
        newPosY = maxY;
    posY = newPosY;
}

void Creature::move(int stepX, int stepY){
    moveX(stepX);
    moveY(stepY);
}

void Creature::setPosition(int x, int y){
    posX = x;
    posY = y;
}

bool Creature::intersects(Creature *other){
    return other != NULL && (abs(posX - other->posX) <= 50) && (abs(posY - other->posY) <= 50);
}
