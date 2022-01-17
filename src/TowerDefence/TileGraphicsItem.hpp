#ifndef TILEGRAPHICSITEM_H
#define TILEGRAPHICSITEM_H
#include "game.h"
#include "tile.hpp"
#include <QtWidgets>
#include <QtGui>
#include <QGraphicsRectItem>

class TileGraphicsItem : public QGraphicsRectItem {
public:
    TileGraphicsItem(int x, int y, bool is_path, int size, tile tile1, bool is_clicked=false);
    ~TileGraphicsItem();

    void set_selected();
    bool is_path(){return is_path_;};
    bool is_clicked(){return is_clicked_;};
    tile get_tile(){return tile_;};
    int get_x(){return x_;};
    int get_y(){return y_;};
    int get_size(){return size_;};
    bool is_clicked_;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event)
        {

             set_selected();
        }
   private:
    int x_;
    int y_;
    bool is_path_;
    int size_;
    tile tile_;


};

#endif // TILEGRAPHICSITEM_H
