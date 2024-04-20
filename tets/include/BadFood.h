#ifndef BADFOOD_H
#define BADFOOD_H

#include <Creature.h>


class BadFood : public Creature
{
    public:
        BadFood(int x, int y);
        virtual ~BadFood();
        static void setImage(HDC img){image = img;};
    protected:
        virtual HDC getImage();
    private:
        static HDC image;
};

#endif // BADFOOD_H
