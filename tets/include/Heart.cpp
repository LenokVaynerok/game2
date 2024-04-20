#ifndef HEART_H
#define HEART_H
#include <Creature.h>
class Heart : public Creature
{
    public:
        Heart(int x, int y);
        virtual ~Heart();
        static void setImage(HDC img){image = img;};
    protected:
        virtual HDC getImage();
    private:
        static HDC image;
};

#endif // HEART_H
