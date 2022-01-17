#include "basic.h"


Basic::Basic()
    :Tower(400,2,1,"Basic", ":/red.png"),fireRate_(1){}

Basic::~Basic() {}

float Basic:: Get_fireRate() const{
    return fireRate_;
}


