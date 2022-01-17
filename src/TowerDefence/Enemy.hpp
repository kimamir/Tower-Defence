
#ifndef _Enemy_
#define _Enemy_

#include <QString>
#include <QObject>
#include <QPointF>
#include <QList>
#include <QGraphicsPixmapItem>

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(int hp, int speed, QString colour, QVector<QVector<int>> path, int worth, bool armour=false, QGraphicsItem *parent =0);
    ~Enemy();
    int getSpeed();
    int getHp();
    QString getColour();
    QPointF getNextPoint();
    void rotateToPoint(QPointF p);
    QTimer *timer;
    QPointF getPos();
    void takeDamage(int dmg);
    int getWorth();
    bool is_tower();
    bool getArmour();

public slots:
   void Move();

private:
    int hp_;
    int speed_;
    QString colour_;
    bool armour_;
    int x_;
    int y_;
    QVector<QPointF> path_;
    QPointF destination_;
    int point_index_;
    int worth_;
};

#endif
