#ifndef ANGRYCAT_H
#define ANGRYCAT_H

#include <Creature.h>


class AngryCat : public Creature
{
    public:
        AngryCat(int x, int y, int spd);
        virtual ~AngryCat();
        static void setImage(HDC img){image = img;};
        void moveTowards(Creature *other);
    protected:
        virtual HDC getImage();
    private:
        int speed;
        static HDC image;
};

#endif // ANGRYCAT_H
