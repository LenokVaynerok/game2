#ifndef ANGRYBALL_H
#define ANGRYBALL_H

#include <Creature.h>


class AngryBall : public Creature
{
    public:
        AngryBall(int x, int y, int spd);
        virtual ~AngryBall();
        static void setImage(HDC img){image = img;};
        void moveTowards(int x, int y, int spd);
    protected:
        virtual HDC getImage();
    private:
        int speed;
        static HDC image;
};

#endif


