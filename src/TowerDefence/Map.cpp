#include "Map.hpp"
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>
#include "tile.hpp"


bool Map::search(const QVector<QVector<int>> path, QVector<int> coord) {
    for (int i = 0; i < path.length(); i++) {
        if (coord[0] == path[i][0] && coord[1] == path[i][1])
            return true;
    }
    return false;
}

int Map::readMap(const QString filename) {
    QFile file(filename);
    if (!file.exists()) {
        qCritical() << "File not found!";
        return -1;
    }
    if (!file.open(QIODevice::ReadOnly)) {
        qCritical() << "Could not open map file!";
        qCritical() << file.errorString();
        return -1;
    }
    file.seek(0);
    QString tiles = file.readAll();
    file.close();
    QVector<QString> row;
    QVector<QVector<QString>> map;

    for (int i = 0; i < tiles.length(); i++) {
        if (tiles[i] == '\n') {
            map.append(row);
            row.clear();
        }
        else if (tiles[i] != '\r') {
            row.append(tiles[i]);
        }
    }

    QVector<QVector<int>> path;
    QVector<int> coord;
    // Find start (S)

    for (int i = 0; i < map.length(); i++) {
        if (map[i][0] == 'S') {
            QVector<int> temp = {i, 0};
            coord.append(temp);
            path.append(coord);
        }
    }

    int y = coord[0];
    int x = coord[1];

    QVector<int> offsetX = {0, 1, 0, -1};
    QVector<int> offsetY = {-1, 0, 1, 0};
    int nextX;
    int nextY;

    while (map[y][x] != 'E') {

        for (int i = 0; i < 4; i++) {
            nextX = x + offsetX[i];
            nextY = y + offsetY[i];
            if (nextX < 0 || nextX > map[0].length() - 1 || nextY < 0 || nextY > map.length() - 1) {
                continue;
            }
            else if (map[nextY][nextX] == '-' || map[nextY][nextX] == 'E') {
                QVector<int> temp = {nextY, nextX};
                 if (search(path, temp)){
                    continue;
                 }
                 else {
                     QVector<int> temp = {nextY, nextX};
                     path.append(temp);
                     x = nextX;
                     y = nextY;
                 }
            }
        }
        if (nextX != x && nextY != y) {
            qInfo() << "Damaged file!!";
            return -1;
        }

}
    QVector<tile> temp_row;

    for (int y = 0; y < map.length(); y++) {
        for (int x = 0; x < map[0].length(); x++) {
            if (map[y][x] == 'E') {
                tile Tile = tile(false, true, x, y, 35, true);
                temp_row.append(Tile);
            }
            else if (map[y][x] != '#') {
                tile Tile = tile(false, true, x, y, 35);
                temp_row.append(Tile);
            }
            else {
                tile Tile = tile(true, false, x, y, 35);
                temp_row.append(Tile);
            }
        }
        map_.append(temp_row);
        temp_row.clear();
    }
    path_ = path;



    return 1;
}

QVector<QVector<tile>> Map::getMap() {
    return map_;
}

QVector<QVector<int>> Map::getPath() {
    return path_;
}

Map::~Map() {
}
