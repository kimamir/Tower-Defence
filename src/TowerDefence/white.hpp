#ifndef WHITE_HPP
#define WHITE_HPP
#include "Enemy.hpp"

class White: public Enemy{
public:
    White(QVector<QVector<int>> path) : Enemy(4, 6, "white",path, 80) {};

};
#endif // WHITE_HPP
