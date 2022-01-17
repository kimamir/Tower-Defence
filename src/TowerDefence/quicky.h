#ifndef QUICKY_H
#define QUICKY_H
#include "tower.hpp"

class Quicky :public Tower
{
public:
    Quicky();
    ~Quicky();
    float Get_fireRate() const;

private:
    float fireRate_;

};

#endif // QUICKY_H
