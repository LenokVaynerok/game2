#include <iostream>
#include <random>
#include "TXLib.h"
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <ctime>
#include <string>
#include "Kitten.h"
#include "Food.h"

#include "AngryCat.h"
#include "Mouse.h"
#include "BadFood.h"
#include "Ball.h"
#include "AngryBall.h"
#include "Heart.h"
#include "Light.h"


#define MAX_X 1250
#define MAX_Y 800
#define KITTEN_SPEED 5
#define ANGRY_CAT_SPEED 2
#define BALL_SPEED 2

using namespace std;
HDC eda = txLoadImage ("food.bmp");
HDC pers = txLoadImage ("cotik.bmp");
HDC fon = txLoadImage ("fon.bmp");
HDC acat = txLoadImage ("acat.bmp");
HDC fon2 = txLoadImage ("fon2.bmp");
HDC fon3 = txLoadImage ("fonthird.bmp");
HDC fon0 = txLoadImage ("fon0.bmp");
HDC mice = txLoadImage ("mouseforcat.bmp");
HDC bfood = txLoadImage ("badfood.bmp");
HDC fon4 = txLoadImage ("fon4.bmp");
HDC ball = txLoadImage ("ball.bmp");
HDC angball = txLoadImage ("angball.bmp");
HDC hearts = txLoadImage ("heart.bmp");
HDC lights = txLoadImage ("light.bmp");

class Button
{
private:
    int x, y;
public:
    char text[255];
    COLORREF color;
    int score;
    bool active, cliked, setTimer;
    Button (int xButton, int yButton, char textButton[255], COLORREF colorButton, bool activeButton, bool clikedButton)
    {
        x = xButton;
        y = yButton;
        strcpy(text, textButton);
        color = colorButton;
        active = activeButton;
        cliked = clikedButton;
    }
    int getX()
    {
        return x;
    }
    void setX(int xButton)
    {
        x = xButton;
    }

    void drawButton()
    {
        if(active == true)
        {
            txSetColor(TX_BLACK);
            txSetFillColor(color);
            txRectangle (x, y, x + 150, y + 50);
            txDrawText(x, y, x + 150, y + 50, text);
            COLORREF tempColor = color;
            if (txMouseX() > x && txMouseX() < x + 150 && txMouseY() > y && txMouseY() < y + 50)
            {
                color = TX_GREEN;
                if (GetAsyncKeyState(VK_LBUTTON))
                {
                    color = TX_RED;
                    cliked = true;
                    score = 1;
                }
            }
            else
            {
                cliked = false;
            }
        }
        else
        {
            color = TX_WHITE;
        }
    }
};
int main ()
{
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(10, MAX_Y - 100);
    std::uniform_int_distribution<> distribution2(10, MAX_X - 100);
    vector <Kitten*> cotiks;
    vector <Food*> foods;
    vector <AngryCat*> angrycats;
    vector <Mouse*> mouses;
    vector <BadFood*> badfoods;
    vector <Ball*> ballss;
    vector <Heart*> heartss;
    vector <Light*> lightss;
    vector <AngryBall*> angryballs;
    txCreateWindow (MAX_X, MAX_Y);
    Creature::initialize(txDC(), MAX_X, MAX_Y);
    Kitten::setImage(pers);
    Food::setImage(eda);
    AngryCat::setImage(acat);
    Mouse::setImage(mice);
    BadFood::setImage(bfood);
    Ball::setImage(ball);
    AngryBall::setImage(angball);
    Heart::setImage(hearts);
    Light::setImage(lights);
    cotiks.push_back(new Kitten(500, 300));
    foods.push_back(new Food(800, 300));
    badfoods.push_back(new BadFood(1000, 500));
    badfoods.push_back(new BadFood(880, 670));
    badfoods.push_back(new BadFood(70, 100));
    badfoods.push_back(new BadFood(290, 300));
    badfoods.push_back(new BadFood(300, 200));
    badfoods.push_back(new BadFood(390, 700));
    badfoods.push_back(new BadFood(500, 50));
    ballss.push_back(new Ball(500, 600, 2));
    angryballs.push_back(new AngryBall(500, 600, 2));
    heartss.push_back(new Heart(800, 40));
    heartss.push_back(new Heart(850, 40));
    heartss.push_back(new Heart(900, 40));
    heartss.push_back(new Heart(950, 40));
    heartss.push_back(new Heart(1000, 40));
    heartss.push_back(new Heart(1050, 40));
    heartss.push_back(new Heart(1100, 40));
    heartss.push_back(new Heart(1150, 40));
    heartss.push_back(new Heart(1200, 40));
    lightss.push_back(new Light(100, 40, 2));
    angrycats.push_back(new AngryCat(100, 100, ANGRY_CAT_SPEED));
    mouses.push_back(new Mouse(100, 100));
    txSetFillColor (TX_WHITE);
    Button b1(1000, 100, "Следующий уровень", TX_WHITE, true, false);
    Button b2 (500, 500, "Начать игру", TX_WHITE, true, false);
    Button b3 (500, 500, "Начать игру заново", TX_WHITE, true, false);
    b1.score = 0;
    b2.score = 0;
    b3.score = 0;
    int heartscount = 9000;
    int i = 0;
    int score = 0;
    int countfood = 0;
    int persx = 150;
    int persy = 600;
    int ballx = 100;
    int bally = 100;
    int angballx = 400;
    int angbally = 400;
    int countballs = 0;
    int h = 0;
    int t = 9;
    int lightx = 100;
    int lighty = 40;
    int itogballs = 5;
    while (!GetAsyncKeyState (VK_ESCAPE))
    {
        txBegin();
        if (b2.score == 0)
        {
            txBitBlt (txDC(), 0, 0, 1250, 800, fon0, 0, 0);
            txSetColor(TX_GREEN);
            b2.drawButton();
            txDrawText (250, 20, 1000, 500, "Эт5о игра о котёнке, которого девочка принесла к себе домой. Но дома уже есть взрослый ");
            txDrawText (250, 120, 1000, 500, "и злой кот, которому не нравится котёнок. Игроку нужно пытаться пройти все испытания,");
            txDrawText (250, 220, 1000, 500,"которые подготовил злой кот.");
            //countfood = 0;
        }
        if (b2.score >= 1)
        {
            countballs = 0;
            b3.score = 0;
            for(int j = 0; j < mouses.size(); j++)
            {
                mouses.erase(mouses.begin()+ j);
            }
            txBitBlt (txDC(), 0, 0, 1250, 800, fon, 0, 0);
            txSetColor(TX_GREEN);
            if (GetAsyncKeyState('A'))
            {
                cotiks[0]->moveX(-KITTEN_SPEED);
            }
            if (GetAsyncKeyState('D'))
            {
                cotiks[0]->moveX(KITTEN_SPEED);
            }
            if (GetAsyncKeyState('W'))
            {
                cotiks[0]->moveY(-KITTEN_SPEED);
            }
            if (GetAsyncKeyState('S'))
            {
                cotiks[0]->moveY(KITTEN_SPEED);
            }
            cotiks[0]->draw();
            foods[0]->draw();
            badfoods[0]->draw();
            badfoods[1]->draw();
            badfoods[2]->draw();
            badfoods[3]->draw();
            badfoods[4]->draw();
            badfoods[5]->draw();
            badfoods [6]->draw();
            angrycats[0]->moveTowards(cotiks[0]);
            angrycats[0]->draw();
            if (cotiks[0]->intersects(angrycats[0]))
            {
                break;
            }

            if (cotiks[0]->intersects(foods[0]))
            {
                int foodx = distribution2(generator);
                int foody = distribution(generator);
                foods[0]->setPosition(foodx, foody);
                countfood = countfood + 10;

                for (int j = 0; j < badfoods.size(); j++)
                {
                    badfoods[j]->setPosition(distribution2(generator), distribution(generator));
                    badfoods[j]->draw();
                }
            }
            boolean ateWrong = false;
            for(int j = 0; j < badfoods.size(); j++)
            {
                if (cotiks[0]->intersects(badfoods[j]))
                {
                    ateWrong = true;
                    break;
                }
            }
            if (ateWrong)
                break;

            if (countfood >= 10)
            {
                b1.drawButton();
            }
            char point[255];
            itoa (countfood, point, 10);
            txSetFillColor(TX_WHITE);
            txDrawText (100, 70, 150, 150, "Очки:");
            txDrawText (200, 70, 250, 150, point);
            txDrawText (400, 20, 700, 70, "Уровень 1");
        }

        if(b1.score >= 1)
        {
            b2.score = 0;
            cotiks.push_back(new Kitten(500, 500));
            if ((i % 5) == 0)
            {
                angrycats[0]->setPosition(distribution2(generator), 60);
                mouses.push_back(new Mouse(angrycats[0]->posX, 100));
            }
            for(int j = 0; j < mouses.size(); j++)
            {
                mouses[j]->moveY(10);
            }
            txBitBlt (txDC(), 0, 0, 1250, 800, fon2, 0, 0);
            txSetColor(TX_GREEN);
            if (GetAsyncKeyState('A'))
            {
                cotiks[1]->moveX(-KITTEN_SPEED);
            }
            if (GetAsyncKeyState('D'))
            {
                cotiks[1]->moveX(KITTEN_SPEED);
            }
            cotiks[1]->draw();
            heartss[0]-> draw ();
            heartss[1]-> draw ();
            heartss[2]-> draw ();
            heartss[3]-> draw ();
            heartss[4]-> draw ();
            heartss[5]-> draw ();
            heartss[6]-> draw ();
            heartss[7]-> draw ();
            heartss[8]-> draw ();
            angrycats[0]->draw();
            boolean catchmouse = false;
            for(int j = 0; j < mouses.size(); j++)
            {
                if ((i%750) == 0)
                {
                    countfood = countfood + 1;
                }
                char point[255];
                itoa (countfood, point, 10);
                txDrawText (100, 70, 150, 150, "Очки:");
                txDrawText (150, 70, 200, 150, point);
                txDrawText (400, 20, 700, 70, "Уровень 2");
                txSetColor(TX_BLACK);
                score = 1;
                if  (j < 70)
                {
                    mouses[j]->draw();
                    if (cotiks[1]->intersects(mouses[j]))
                    {
                        heartscount = heartscount - 1;
                        h = h+10;
                        if (h/1000 == 0)
                        {
                            heartss[h/100]->setPosition (20, 1500);
                        }
                    }
                }
                i++;
            }
            if (heartscount == 0)
            {
                break;
            }
        }
        if(mouses.size() >=70)
        {
            i++;
            b1.score = 0;

            txBitBlt (txDC(), 0, 0, 1250, 800, fon4, 0, 0);
            txDrawText (400, 20, 700, 70, "Уровень 3");
            cotiks[0]->draw();
            ballss[0]->draw();
            lightss[0]->draw();
            angryballs[0]->draw();

            if (i%50 == 0)
            {
                ballx = distribution2(generator);
                bally = distribution(generator);
                angballx = distribution2(generator);
                angbally = distribution(generator);
                lightx = distribution2(generator);
                lighty = distribution(generator);
            }
            ballss[0]->moveTowards(ballx, bally, 4);
            lightss[0]->moveTowards(lightx, lighty, 3);
            angryballs[0]->moveTowards(angballx, angbally, 3);
            txDrawText (750, 40, 1000, 70, "Осталось собрать ");
            char point[255];
            itoa (itogballs, point, 10);
            txDrawText (930, 40, 980, 70, point);
            txDrawText (980, 40, 1090, 70, "шт. клубков");
            char points[255];
            itoa (countfood, points, 10);
            txDrawText (100, 70, 150, 150, "Очки:");
            txDrawText (150, 70, 200, 150, points);

            if (cotiks[0]->intersects(lightss[0]))
            {
                break;
            }
            if (cotiks[0]->intersects(angryballs[0]))
            {
                break;
            }
            if (GetAsyncKeyState('A'))
            {
                cotiks[0]->moveX(-KITTEN_SPEED);
            }
            if (GetAsyncKeyState('D'))
            {
                cotiks[0]->moveX(KITTEN_SPEED);
            }
            if (GetAsyncKeyState('W'))
            {
                cotiks[0]->moveY(-KITTEN_SPEED);
            }
            if (GetAsyncKeyState('S'))
            {
                cotiks[0]->moveY(KITTEN_SPEED);
            }
            if (cotiks[0]->intersects(ballss[0]))
            {
                int ballx = distribution2(generator);
                int bally = distribution(generator);
                ballss[0]->setPosition(bally, ballx);
                countfood = countfood + 10;
                countballs = countballs + 1;
                itogballs = itogballs - 1;

            }
        }

        if(countballs>=5)
        {
            txBitBlt (txDC(), 0, 0, 1250, 800, fon0, 0, 0);
            txDrawText (250, 220, 1000, 500, "Вы прошли все 3 уровня и на этот раз котёнок спасён!");
            txDrawText (450, 330, 700, 500, "В этот раз вы набрали ");
            char point[255];
            itoa (countfood, point, 10);
            txDrawText (650, 330, 680, 500, point);
            txDrawText (690, 330, 750, 500, "очков! ");
            b3.drawButton();

            if (b3.score == 1)
            {
                for(int j = 0; j < cotiks.size(); j++)
                {
                    cotiks.erase(cotiks.begin()+ j);
                }
                for(int j = 0; j < badfoods.size(); j++)
                {
                    badfoods.erase(badfoods.begin()+ j);
                }
                for(int j = 0; j < foods.size(); j++)
                {
                    foods.erase(foods.begin()+ j);
                }
                for(int j = 0; j < angrycats.size(); j++)
                {
                    angrycats.erase(angrycats.begin()+ j);
                }
                for(int j = 0; j < ballss.size(); j++)
                {
                    ballss.erase(ballss.begin()+ j);
                }
                for(int j = 0; j < lightss.size(); j++)
                {
                    lightss.erase(lightss.begin()+ j);
                }
                for(int j = 0; j < angryballs.size(); j++)
                {
                    angryballs.erase(angryballs.begin()+ j);
                }
                heartscount = 9000;
                b2.score = 0;
                i = 0;
                score = 0;
                countfood = 0;
                persx = 150;
                persy = 600;
                ballx = 100;
                bally = 100;
                angballx = 400;
                angbally = 400;
                countballs = 0;
                h = 0;
                t = 9;
                lightx = 100;
                lighty = 40;
                itogballs = 10;
                txBitBlt (txDC(), 0, 0, 1250, 800, fon0, 0, 0);
                txSetColor(TX_GREEN);
                b2.drawButton();
                (250, 20, 1000, 500, "Это игра о котёнке, котороого девочка принесла к себе домой. Но дома уже есть взрослый ");
                txDrawText (250, 120, 1000, 500, "и злой кот, которому не нравится котёнок. Игроку нужно пытаться пройти все испытания,");
                txDrawText (250, 220, 1000, 500,"которые подготовил злой кот.");
            }

        }
        txEnd();
    }
    txDeleteDC (fon);
    txDeleteDC (fon2);
    txDeleteDC (pers);
    txDeleteDC (mice);
    txDeleteDC (eda);
    txDeleteDC (acat);
    txDeleteDC (fon3);
    txDeleteDC (fon0);
    txDeleteDC (bfood);
    txDeleteDC (fon4);
    txDeleteDC (ball);
    txDeleteDC (lights);
    return 0;
}

