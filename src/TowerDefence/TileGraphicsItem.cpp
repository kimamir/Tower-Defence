#include "TileGraphicsItem.hpp"
#include "game.h"
#include "tile.hpp"
#include <QtGui>
#include <QtWidgets>

TileGraphicsItem::TileGraphicsItem(int x, int y, bool is_path, int size,tile tile1, bool is_clicked) {
    x_ = x;
    y_ = y;
    is_path_ = is_path;
    size_ = size;
    is_clicked_ =is_clicked;
    tile_=tile1;


    this->setRect(x * size, y * size, size, size);
    if (is_path) {
        this->setBrush(QColor(128,128,128));
    }
    else {
        this->setBrush(QColor(3,160,198));
    }



}

void TileGraphicsItem::set_selected(){

    if (is_path_ != true && tile_.is_path() != true){
        is_clicked_=true;
    }



}

TileGraphicsItem::~TileGraphicsItem() {

}
