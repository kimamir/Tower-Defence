#ifndef BOSS_HPP
#define BOSS_HPP
#include "Enemy.hpp"

class Boss: public Enemy{
public:
     Boss(QVector<QVector<int>> path) : Enemy(10, 2, "black", path, 200) {};
};

#endif // BOSS_HPP

