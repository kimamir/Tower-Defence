#ifndef _Tower_
#define _Tower_

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QObject>
#include "Enemy.hpp"

class Tower :public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Tower(float price, int range, float fire_rate, QString type, QString file, int range_size=10, int damage=1, bool ap=false, QGraphicsItem * parent=0);
    ~Tower();

    float Get_price()const;

    QGraphicsEllipseItem * Get_range()const;
    void setRangePos();
    void setupRange(int x, int y);
    double distanceTo(QGraphicsItem *item);
    QString Get_type() const;
    void fire();
    int Get_x()const;
    bool is_tower();
    int Get_y()const;
    QList<QGraphicsItem *> colliding_items;

private slots:
    void attack_target(QVector<Enemy*> enemiesOnPath);
    void acquire_target();

private:
    QGraphicsEllipseItem * range_;
    float price_;
    QString type_;
    bool ap_;
    int x_;
    int y_;
    double fire_rate_;
    QPointF attack_point_;
    bool has_target_;
    int range_size_;
    int damage_;

};

#endif
