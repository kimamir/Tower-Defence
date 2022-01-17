#include "bullet.hpp"
#include <QPixmap>
#include <QTimer>

Bullet::Bullet(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/arrowbullet.png"));
    setScale(0.01);
    QTimer *move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()), this, SLOT(move()));
    move_timer->start(10);
}

void Bullet::move(){
    int stepsize=8;
    double theta=rotation();
    double dy =stepsize*qSin(qDegreesToRadians(theta));
    double dx = stepsize*qCos(qDegreesToRadians(theta));
    setPos( x()+dx, y()+dy);
}

Bullet::~Bullet() {
}
