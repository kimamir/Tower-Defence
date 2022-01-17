#include "sniper.h"

Sniper::Sniper()
    :Tower(1000,2,1.5,"Sniper", ":/purple.png", 20, 3, true),fireRate_(1) {}
Sniper::~Sniper() {}

float Sniper:: Get_fireRate() const{
    return fireRate_;
}
