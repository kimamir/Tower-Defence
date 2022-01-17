#include "tower.hpp"
#include <QPixmap>
#include <QBrush>
#include "bullet.hpp"
#include "game.h"
#include <QGraphicsEllipseItem>

extern Game * game;

Tower::Tower(float price, int range, float fire_rate, QString type, QString file,int range_size, int damage, bool ap, QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent) {
    setPixmap(QPixmap(file));
    setScale(0.016); //joku järkevä tapa saada kaikki towerit saman kokosiksi
    //setTransformOriginPoint(boundingRect().center()); //ei toimi

    price_=price;
    type_=type;
    fire_rate_=fire_rate;
    has_target_ = false;
    range_size_=range_size;
    damage_=damage;
    ap_ = ap;

    QTimer * timer = new QTimer();
    connect( timer, &QTimer::timeout, [this](){attack_target(game->getEnemiesOnPath());});
    timer->start(1000*fire_rate_);
}

Tower::~Tower() {
}

void Tower::setupRange(int x, int y) {
    if (range_size_==10){
        range_ = new QGraphicsEllipseItem(x,y,140,140);
    }
    if (range_size_==20){
        range_ = new QGraphicsEllipseItem(x-30,y-30,200,200);
    }
    range_->setBrush(QColor(128,128,128));
    range_->setOpacity(0.3);
    range_->hide();

}

void Tower::setRangePos() {
    range_->setPos(pos());
}

float Tower:: Get_price()const{
    return price_;
}

QGraphicsEllipseItem * Tower::Get_range()const{
    return range_;
}


int Tower::Get_x()const{
    return x_;
}

int Tower::Get_y()const{
    return y_;
}


QString Tower:: Get_type() const{
    return type_;
}

void Tower::attack_target(QVector<Enemy*> enemiesOnPath){
    acquire_target();
}

double Tower::distanceTo(QGraphicsItem *item){
    QLineF ln(pos(),item->pos());
    return ln.length();
}


void Tower::acquire_target(){

    colliding_items = range_->collidingItems();


    Enemy * target;
    double closest_dist = range_size_ * 10;
    QPointF closest_pt = QPointF(0,0);

    for (size_t i = 0, n = colliding_items.size(); i < n; i++){
        Enemy * enemy = dynamic_cast<Enemy *>(colliding_items[i]);
        if (enemy){
            double this_dist = distanceTo(enemy);
            if (this_dist < closest_dist){
                closest_dist = this_dist;
                closest_pt = colliding_items[i]->pos();
                has_target_ = true;
                target = enemy;
            }
        }
    }
    if (has_target_) {
        attack_point_ = closest_pt;
        fire();
        if (!(target->getArmour() && !ap_)) {
            target->takeDamage(damage_);
        }
        has_target_ = false;

    }
}
bool Tower::is_tower() {
    return true;
}
void Tower::fire() {

    Bullet * bullet = new Bullet();
    bullet->setPos(x()+32/2, y()+32/2);

    QLineF ln(QPoint(x()+32/2, y()+32/2), attack_point_);
    int angle =-1*ln.angle();
    bullet->setRotation(angle);
    game->get_scene()->addItem(bullet);

}
