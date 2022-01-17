#ifndef BASIC_H
#define BASIC_H
#include "tower.hpp"

class Basic :public Tower
{
public:
    Basic();
    ~Basic();
    float Get_fireRate() const;

private:
    float fireRate_;

};

#endif // BASIC_H
