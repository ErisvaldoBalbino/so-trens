#include "trem.h"
#include <algorithm>

Trem::Trem(int id, int x, int y, QVector<BinarySemaphoreWrapper> *semaphoreVector)
{
    this->id = id;
    this->x = x;
    this->y = y;
    velocidade = 300;
    enable = false;
    this->semaphoreVector = semaphoreVector;
}

Trem::~Trem()
{
    threadTrem.join();
}

void Trem::setVelocidade(int velocidade)
{
    this->velocidade = velocidade;
}

void Trem::setEnable(bool enable)
{
    this->enable = enable;
}

void Trem::start()
{
    threadTrem = std::thread(&Trem::run, this);
}

void Trem::acquireSemaphore(int index)
{
    if (index >= 0 && index < semaphoreVector->size())
    {
        semaphoreVector->at(index).semaphore.acquire(1);
    }
}

void Trem::releaseSemaphore(int index)
{
    if (index >= 0 && index < semaphoreVector->size())
    {
        semaphoreVector->at(index).semaphore.release(1);
    }
}

void Trem::moveRight(int step)
{
    x += step;
}

void Trem::moveLeft(int step)
{
    x -= step;
}

void Trem::moveDown(int step)
{
    y += step;
}

void Trem::moveUp(int step)
{
    y -= step;
}

void Trem::moveTrem1()
{
    if (y == 50 && x < 270)
    {
        if (x == 250) acquireSemaphore(0);
        moveRight();
    }
    else if (x == 270 && y < 150)
    {
        if (y == 130) acquireSemaphore(5);
        moveDown();
    }
    else if (x > 130 && y == 150)
    {
        moveLeft();
        if (x == 250) releaseSemaphore(0);
        if (x == 190) releaseSemaphore(5);
    }
    else
    {
        moveUp();
    }
}

void Trem::moveTrem2()
{
    if (y == 50 && x > 270)
    {
        if (x == 290) acquireSemaphore(0);
        moveLeft();
        if (x == 390) releaseSemaphore(1);
    }
    else if (x == 270 && y < 150)
    {
        if (y == 130) acquireSemaphore(6);
        moveDown();
    }
    else if (x < 410 && y == 150)
    {
        if (x == 390) acquireSemaphore(1);
        moveRight();
        if (x == 290) releaseSemaphore(0);
    }
    else
    {
        moveUp();
        if (y == 120) releaseSemaphore(6);
    }
}

void Trem::moveTrem3()
{
    if (y == 50 && x < 550)
    {
        moveRight();
        if (x == 430) releaseSemaphore(1);
    }
    else if (x == 550 && y < 150)
    {
        moveDown();
    }
    else if (x > 410 && y == 150)
    {
        if (x == 430) acquireSemaphore(1);
        if (x == 500) acquireSemaphore(2);
        moveLeft();
    }
    else
    {
        moveUp();
        if (y == 130) releaseSemaphore(2);
    }
}

void Trem::moveTrem4()
{
    if (y == 150 && x > 200)
    {
        if (x == 290) acquireSemaphore(5);
        if (x == 430) acquireSemaphore(6);
        if (x == 220) acquireSemaphore(9);
        moveLeft();
        if (x == 380) releaseSemaphore(2);
        if (x == 240) releaseSemaphore(6);
        if (x == 460) releaseSemaphore(8);
    }
    else if (x == 200 && y < 250)
    {
        if (y == 230) acquireSemaphore(7);
        moveDown();
        if (y == 170) releaseSemaphore(5);
    }
    else if (x < 480 && y == 250)
    {
        if (x == 320) acquireSemaphore(3);
        if (x == 460) acquireSemaphore(8);
        moveRight();
        if (x == 340) releaseSemaphore(7);
        if (x == 220) releaseSemaphore(9);
    }
    else
    {
        if (y == 170) acquireSemaphore(2);
        moveUp();
        if (y == 240) releaseSemaphore(3);
    }
}

void Trem::moveTrem5()
{
    if (y == 150 && x > 200)
    {
        if (x == 290) acquireSemaphore(5);
        if (x == 430) acquireSemaphore(6);
        if (x == 220) acquireSemaphore(9);
        moveLeft();
        if (x == 380) releaseSemaphore(2);
        if (x == 240) releaseSemaphore(6);
        if (x == 460) releaseSemaphore(8);
    }
    else if (x == 200 && y < 250)
    {
        if (y == 230) acquireSemaphore(7);
        moveDown();
        if (y == 170) releaseSemaphore(5);
    }
    else if (x < 480 && y == 250)
    {
        if (x == 320) acquireSemaphore(3);
        if (x == 460) acquireSemaphore(8);
        moveRight();
        if (x == 340) releaseSemaphore(7);
        if (x == 220) releaseSemaphore(9);
    }
    else
    {
        if (y == 170) acquireSemaphore(2);
        moveUp();
        if (y == 240) releaseSemaphore(3);
    }
}

void Trem::moveTrem6()
{
    if (y == 250 && x < 340)
    {
        if (x == 320) acquireSemaphore(4);
        if (x == 180) acquireSemaphore(7);
        moveRight();
    }
    else if (x == 340 && y < 350)
    {
        moveDown();
        if (y == 280) releaseSemaphore(7);
    }
    else if (x > 130 && y == 350)
    {
        moveLeft();
        if (x == 310) releaseSemaphore(4);
    }
    else
    {
        moveUp();
    }
}

void Trem::moveTrem7()
{
    if (y == 250 && x < 550)
    {
        moveRight();
        if (x == 360) releaseSemaphore(4);
        if (x == 500) releaseSemaphore(3);
    }
    else if (x == 550 && y < 350)
    {
        moveDown();
    }
    else if (x > 340 && y == 350)
    {
        if (x == 360) acquireSemaphore(4);
        moveLeft();
    }
    else
    {
        if (y == 270) acquireSemaphore(3);
        moveUp();
    }
}

void Trem::run()
{
    while (true)
    {
        if (enable)
        {
            emit updateGUI(id, x, y);
            
            switch (id)
            {
            case 1: moveTrem1(); break;
            case 2: moveTrem2(); break;
            case 3: moveTrem3(); break;
            case 4: moveTrem4(); break;
            case 5: moveTrem5(); break;
            case 6: moveTrem6(); break;
            case 7: moveTrem7(); break;
            default: break;
            }
        }
        
        this_thread::sleep_for(chrono::milliseconds(velocidade));
    }
}
