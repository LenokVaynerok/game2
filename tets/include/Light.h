#ifndef LIGHT_H
#define LIGHT_H

#include <Creature.h>


class Light : public Creature
{
    public:
        Light(int x, int y, int spd);
        virtual ~Light();
        static void setImage(HDC img){image = img;};
        void moveTowards(int x, int y, int spd);
    protected:
        virtual HDC getImage();
    private:
        int speed;
        static HDC image;
};

#endif // Light_H

