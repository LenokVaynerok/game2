#ifndef KITTEN_H
#define KITTEN_H

#include <Creature.h>


class Kitten : public Creature
{
    public:
        Kitten(int x, int y);
        virtual ~Kitten();
        static void setImage(HDC img){image = img;};
    protected:
        virtual HDC getImage();
    private:
        static HDC image;
};

#endif // KITTEN_H
