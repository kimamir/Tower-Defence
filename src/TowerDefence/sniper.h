#ifndef SNIPER_H
#define SNIPER_H
#include "tower.hpp"

class Sniper: public Tower
{
public:
    Sniper();
    ~Sniper();
    float Get_fireRate() const;

private:
    float fireRate_;
};

#endif // SNIPER_H
