#ifndef BALL_H
#define BALL_H

#include <Creature.h>


class Ball : public Creature
{
    public:
        Ball(int x, int y, int spd);
        virtual ~Ball();
        static void setImage(HDC img){image = img;};
        void moveTowards(int x, int y, int spd);
    protected:
        virtual HDC getImage();
    private:
        int speed;
        static HDC image;
};

#endif // Ball_H

