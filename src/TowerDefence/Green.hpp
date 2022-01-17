#ifndef GREEN_H
#define GREEN_H

#include "Enemy.hpp"

class Green : public Enemy {
public:
    Green(QVector<QVector<int>> path) : Enemy(3, 7, "green", path, 70, true) {};

};

#endif // GREEN_H
