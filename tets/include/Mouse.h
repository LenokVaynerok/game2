#ifndef MOUSE_H#define MOUSE_H

#include <Creature.h>


class Mouse : public Creature
{
    public:
        Mouse(int x, int y);
        virtual ~Mouse();
        static void setImage(HDC img){image = img;};
    protected:
        virtual HDC getImage();
    private:
        static HDC image;
};

#endif // MOUSE_H
