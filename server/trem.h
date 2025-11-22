#ifndef TREM_H
#define TREM_H

#include <QObject>
#include <thread>
#include <QSemaphore>

using namespace std;

struct BinarySemaphoreWrapper
{
    mutable QSemaphore semaphore;

    BinarySemaphoreWrapper() : semaphore(1) {}
};

class Trem : public QObject
{
    Q_OBJECT
public:
    Trem(int, int, int, QVector<BinarySemaphoreWrapper> *);
    ~Trem();
    void start();
    void run();
    void setVelocidade(int);
    void setEnable(bool);

signals:
    void updateGUI(int, int, int);

private:
    std::thread threadTrem;
    int id;
    int x;
    int y;
    int velocidade;
    bool enable;
    QVector<BinarySemaphoreWrapper> *semaphoreVector;

    void moveRight(int step = 10);
    void moveLeft(int step = 10);
    void moveDown(int step = 10);
    void moveUp(int step = 10);
    void acquireSemaphore(int index);
    void releaseSemaphore(int index);
    
    void moveTrem1();
    void moveTrem2();
    void moveTrem3();
    void moveTrem4();
    void moveTrem5();
    void moveTrem6();
    void moveTrem7();
};

#endif // TREM_H
