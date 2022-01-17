#include "tile.hpp"

tile::tile(bool is_free, bool is_path, int x, int y, int size, bool is_end)
    : size_(size),is_path_(is_path), is_free_(is_free), x_(x), y_(y), is_end_(is_end)
{

}

void tile::reserve(){
    is_free_=false;
}

bool tile::is_free(){
    return is_free_;
}
bool tile::is_path(){
    return is_path_;
}
int tile::get_x(){
    return x_;
}

int tile::get_y(){
    return y_;
}

int tile::get_size(){
    return size_;
}

bool tile::is_end() {
    return is_end_;
}
