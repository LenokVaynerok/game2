#ifndef CREATURE_H
#define CREATURE_H

#include "TXLib.h"

class Creature
{
    private:
        static int maxX;
        static int maxY;
        static HDC canvas;
    protected:
        virtual HDC getImage() = 0;
    public:
        ~Creature();
        Creature(int x, int y);
        int posX;
        int posY;
        void draw();
        void moveX(int step);
        void moveY(int step);
        void move(int stepX, int stepY);
        void setPosition(int x, int y);
        bool intersects(Creature *other);
        static void initialize(HDC cnvs, int max_x, int max_y){
            canvas = cnvs;
            maxX = max_x;
            maxY = max_y;
        };
};

#endif // CREATURE_H
