#ifndef BULLET_HPP
#define BULLET_HPP
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>


class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(QGraphicsItem *parent=0);
    ~Bullet();
public slots:
    void move();
private:
};

#endif // BULLET_HPP
