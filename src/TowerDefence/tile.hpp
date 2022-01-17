#ifndef TILE_HPP
#define TILE_HPP


class tile
{
public:
    tile(bool is_free=true, bool is_path=false, int x=0, int y=0, int size=0, bool is_end=false );
    void reserve();
    bool is_free();
    bool is_path();
    int get_x();
    int get_y();
    int get_size();
    bool is_end();



private:
    bool is_path_;
    int x_;
    int y_;
    int size_;
    bool is_free_;
    bool is_end_;
};

#endif // TILE_HPP
