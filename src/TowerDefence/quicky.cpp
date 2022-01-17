#include "quicky.h"

Quicky::Quicky()
    :Tower(1300,2,0.5,"Quicky", ":/black.png"),fireRate_(0.5){}

Quicky::~Quicky() {}

float Quicky:: Get_fireRate() const{
    return fireRate_;
}
