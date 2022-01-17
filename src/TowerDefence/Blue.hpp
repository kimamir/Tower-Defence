#ifndef BLUE_HPP
#define BLUE_HPP

#include "Enemy.hpp"

class Blue : public Enemy {
public:
    Blue(QVector<QVector<int>> path) : Enemy(2, 5, "blue", path, 60) {}
};

#endif // BLUE_HPP
