#include "Enemy.hpp"
#include <QString>
#include <QTimer>
#include <QVector>
#include <QPointF>
#include "Map.hpp"
#include <QGraphicsEllipseItem>
#include<QColor>
#include <QtGui>
#include <QtWidgets>
#include "game.h"
extern Game * game;

Enemy::Enemy(int hp, int speed, QString colour, QVector<QVector<int>> path, int worth, bool armour, QGraphicsItem *parent){
    QPixmap enemyPixmap = QPixmap(75,75);
    if (colour == "red") {
        enemyPixmap.fill((Qt::red));
    }
    else if (colour == "blue") {
        enemyPixmap.fill((Qt::blue));
    }
    else if (colour == "green") {
        enemyPixmap.fill((Qt::green));
    }
    else if (colour == "white") {
        enemyPixmap.fill((Qt::white));
    }
    else if (colour == "black") {
        enemyPixmap.fill((Qt::black));
    }

    setPixmap(enemyPixmap);
    setScale(0.2);
    setTransformOriginPoint(QPointF(x(), y()));
    setPos(path[0][1]*35, path[0][0]*35+35/3.8);
    hp_=hp;
    speed_=speed;
    armour_ = armour;
    colour_=colour;
    worth_ = worth;
    point_index_=0;
    for(int i=0 ; i<path.length(); i++ ){
        path_ << QPointF(path[i][1]*35+35/2, path[i][0]*35+35/3.8);
    }

    destination_=path_[0];
    rotateToPoint(destination_);
    timer =new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Move()));
    timer->start(100);
    setShapeMode(BoundingRectShape);
}


int Enemy::getHp() {
    return hp_;
}

void Enemy::rotateToPoint(QPointF p){
    QLineF ln(pos(), p);
    setRotation(-1*ln.angle());
}

void Enemy::Move(){
    if (game->getLives()<=0){
        timer->disconnect();
        (game->get_scene())->removeItem(this);
        delete this;
    }
    else{
    QLineF ln(pos(), destination_);
    if(ln.length() < 5){
        if (point_index_== path_.length()-2){

            (game->get_scene())->removeItem(this);
            timer->disconnect();
            game->reduceLives(hp_);
            if (game->getEnemiesOnPath().isEmpty()==false) {
                game->enemiesOnPath_.takeFirst();
            }
            //delete this;
            if (game->enemiesOnPath_.isEmpty() && game->getWaves().isEmpty()){
                game->winningmessage();
            }


        }
        point_index_=point_index_+1;
        destination_=path_[point_index_];
        rotateToPoint(destination_);

    }

    int stepsize=5;
    double theta=rotation();
    double dy =stepsize*qSin(qDegreesToRadians(theta));
    double dx = stepsize*qCos(qDegreesToRadians(theta));
    setPos( x()+dx, y()+dy);
}}

QPointF Enemy::getPos() {
    return pos();
}

QPointF Enemy::getNextPoint(){
    if (path_.isEmpty()){
    return QPointF(-100000,-100000);
    }
   else{
   return path_.takeFirst();
    }
}

int Enemy::getSpeed() {
    return speed_;
}

QString Enemy::getColour() {
    return colour_;
}

void Enemy::takeDamage(int dmg) {
    hp_ -= dmg;
    if (hp_ <= 0) {
        game->get_scene()->removeItem(this);
        timer->disconnect();
        game->killEnemy(this);
    }

}

int Enemy::getWorth() {
    return worth_;
}
bool Enemy::is_tower() {
    return false;
}

bool Enemy::getArmour() {
    return armour_;
}

Enemy::~Enemy() {

}
