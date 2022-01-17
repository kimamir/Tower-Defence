#ifndef RED_HPP
#define RED_HPP

#include "Enemy.hpp"
#include <QPainter>

class Red : public Enemy {
public:
    Red(QVector<QVector<int>> path) : Enemy(1, 2, "red", path, 40) {};
};


#endif // RED_HPP
