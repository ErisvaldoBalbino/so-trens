#include "trem.h"

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

void Trem::run()
{
    while (true)
    {
        switch (id)
        {
        case 1:
            if (enable)
            {
                emit updateGUI(id, x, y);
                if (y == 50 && x < 270)
                {
                    if (x == 250)
                    {
                        semaphoreVector->at(0).semaphore.acquire(1);
                    }
                    x += 10;
                }
                else if (x == 270 && y < 150)
                {
                    if (y == 130)
                    {
                        semaphoreVector->at(5).semaphore.acquire(1);
                    }
                    y += 10;
                }
                else if (x > 130 && y == 150)
                {
                    x -= 10;
                    if (x == 250)
                    {
                        semaphoreVector->at(0).semaphore.release(1);
                    }
                    if (x == 190)
                    {
                        semaphoreVector->at(5).semaphore.release(1);
                    }
                }
                else
                {
                    y -= 10;
                }
            }
            break;
        case 2:
            if (enable)
            {
                emit updateGUI(id, x, y);
                if (y == 50 && x > 270)
                {
                    if (x == 290)
                    {
                        semaphoreVector->at(0).semaphore.acquire(1);
                    }
                    x -= 10;
                    if (x == 390)
                    {
                        semaphoreVector->at(1).semaphore.release(1);
                    }
                }
                else if (x == 270 && y < 150)
                {
                    if (y == 130)
                    {
                        semaphoreVector->at(6).semaphore.acquire(1);
                    }
                    y += 10;
                }
                else if (x < 410 && y == 150)
                {
                    if (x == 390)
                    {
                        semaphoreVector->at(1).semaphore.acquire(1);
                    }
                    x += 10;
                    if (x == 290)
                    {
                        semaphoreVector->at(0).semaphore.release(1);
                    }
                }
                else
                {
                    y -= 10;
                    if (y == 120)
                    {
                        semaphoreVector->at(6).semaphore.release(1);
                    }
                }
            }
            break;
        case 3:
            if (enable)
            {
                emit updateGUI(id, x, y);
                if (y == 50 && x < 550)
                {
                    x += 10;
                    if (x == 430)
                    {
                        semaphoreVector->at(1).semaphore.release(1);
                    }
                }
                else if (x == 550 && y < 150)
                {
                    y += 10;
                }
                else if (x > 410 && y == 150)
                {
                    if (x == 430)
                    {
                        semaphoreVector->at(1).semaphore.acquire(1);
                    }
                    if (x == 500)
                    {
                        semaphoreVector->at(2).semaphore.acquire(1);
                    }
                    x -= 10;
                }
                else
                {
                    y -= 10;
                    if (y == 130)
                    {
                        semaphoreVector->at(2).semaphore.release(1);
                    }
                }
            }
            break;
        case 4:
            if (enable)
            {
                emit updateGUI(id, x, y);
                if (y == 150 && x > 200)
                {
                    if (x == 290)
                    {
                        semaphoreVector->at(5).semaphore.acquire(1);
                    }
                    if (x == 430)
                    {
                        semaphoreVector->at(6).semaphore.acquire(1);
                    }
                    if (x == 220)
                    {
                        semaphoreVector->at(9).semaphore.acquire(1);
                    }
                    x -= 10;
                    if (x == 380)
                    {
                        semaphoreVector->at(2).semaphore.release(1);
                    }
                    if (x == 240)
                    {
                        semaphoreVector->at(6).semaphore.release(1);
                    }
                    if (x == 460)
                    {
                        semaphoreVector->at(8).semaphore.release(1);
                    }
                }
                else if (x == 200 && y < 250)
                {
                    if (y == 230)
                    {
                        semaphoreVector->at(7).semaphore.acquire(1);
                    }
                    y += 10;
                    if (y == 170)
                    {
                        semaphoreVector->at(5).semaphore.release(1);
                    }
                }
                else if (x < 480 && y == 250)
                {
                    if (x == 320)
                    {
                        semaphoreVector->at(3).semaphore.acquire(1);
                    }
                    if (x == 460)
                    {
                        semaphoreVector->at(8).semaphore.acquire(1);
                    }
                    x += 10;
                    if (x == 340)
                    {
                        semaphoreVector->at(7).semaphore.release(1);
                    }
                    if (x == 220)
                    {
                        semaphoreVector->at(9).semaphore.release(1);
                    }
                }
                else
                {
                    if (y == 170)
                    {
                        semaphoreVector->at(2).semaphore.acquire(1);
                    }
                    y -= 10;
                    if (y == 240)
                    {
                        semaphoreVector->at(3).semaphore.release(1);
                    }
                }
            }
            break;
        case 5:
            if (enable)
            {
                emit updateGUI(id, x, y);
                if (y == 150 && x > 200)
                {
                    if (x == 290)
                    {
                        semaphoreVector->at(5).semaphore.acquire(1);
                    }
                    if (x == 430)
                    {
                        semaphoreVector->at(6).semaphore.acquire(1);
                    }
                    if (x == 220)
                    {
                        semaphoreVector->at(9).semaphore.acquire(1);
                    }
                    x -= 10;
                    if (x == 380)
                    {
                        semaphoreVector->at(2).semaphore.release(1);
                    }
                    if (x == 240)
                    {
                        semaphoreVector->at(6).semaphore.release(1);
                    }
                    if (x == 460)
                    {
                        semaphoreVector->at(8).semaphore.release(1);
                    }
                }
                else if (x == 200 && y < 250)
                {
                    if (y == 230)
                    {
                        semaphoreVector->at(7).semaphore.acquire(1);
                    }
                    y += 10;
                    if (y == 170)
                    {
                        semaphoreVector->at(5).semaphore.release(1);
                    }
                }
                else if (x < 480 && y == 250)
                {
                    if (x == 320)
                    {
                        semaphoreVector->at(3).semaphore.acquire(1);
                    }
                    if (x == 460)
                    {
                        semaphoreVector->at(8).semaphore.acquire(1);
                    }
                    x += 10;
                    if (x == 340)
                    {
                        semaphoreVector->at(7).semaphore.release(1);
                    }
                    if (x == 220)
                    {
                        semaphoreVector->at(9).semaphore.release(1);
                    }
                }
                else
                {
                    if (y == 170)
                    {
                        semaphoreVector->at(2).semaphore.acquire(1);
                    }
                    y -= 10;
                    if (y == 240)
                    {
                        semaphoreVector->at(3).semaphore.release(1);
                    }
                }
            }
            break;
        case 6:
            if (enable)
            {
                emit updateGUI(id, x, y);
                if (y == 250 && x < 340)
                {
                    if (x == 320)
                    {
                        semaphoreVector->at(4).semaphore.acquire(1);
                    }
                    if (x == 180)
                    {
                        semaphoreVector->at(7).semaphore.acquire(1);
                    }
                    x += 10;
                }
                else if (x == 340 && y < 350)
                {
                    y += 10;
                    if (y == 280)
                    {
                        semaphoreVector->at(7).semaphore.release(1);
                    }
                }
                else if (x > 130 && y == 350)
                {
                    x -= 10;
                    if (x == 310)
                    {
                        semaphoreVector->at(4).semaphore.release(1);
                    }
                }
                else
                {
                    y -= 10;
                }
            }
            break;
        case 7:
            if (enable)
            {
                emit updateGUI(id, x, y);
                if (y == 250 && x < 550)
                {
                    x += 10;
                    if (x == 360)
                    {
                        semaphoreVector->at(4).semaphore.release(1);
                    }
                    if (x == 500)
                    {
                        semaphoreVector->at(3).semaphore.release(1);
                    }
                }
                else if (x == 550 && y < 350)
                {
                    y += 10;
                }
                else if (x > 340 && y == 350)
                {
                    if (x == 360)
                    {
                        semaphoreVector->at(4).semaphore.acquire(1);
                    }
                    x -= 10;
                }
                else
                {
                    if (y == 270)
                    {
                        semaphoreVector->at(3).semaphore.acquire(1);
                    }
                    y -= 10;
                }
            }
            break;
        default:
            break;
        }
        this_thread::sleep_for(chrono::milliseconds(velocidade));
    }
}
