#ifndef FOOD_H
#define FOOD_H

#include <Creature.h>


class Food : public Creature
{
    public:
        Food(int x, int y);
        virtual ~Food();
        static void setImage(HDC img){image = img;};
    protected:
        virtual HDC getImage();
    private:
        static HDC image;
};

#endif // FOOD_H
