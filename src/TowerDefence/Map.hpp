#ifndef _Map_
#define _Map_
#include <QString>
#include <QVector>
#include "tile.hpp"

class Map{
public:
    Map() {};
    ~Map();

    bool search(const QVector<QVector<int>> path, QVector<int> coord);
    int readMap(const QString filename);
    QVector<QVector<tile>> getMap();
    QVector<QVector<int>> getPath();



private:
    QVector<QVector<tile>> map_;
    QVector<QVector<int>>  path_;

};

#endif
