#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QtGui>
#include <QList>
#include "tile.hpp"
#include "TileGraphicsItem.hpp"
#include <QGraphicsView>
#include "Enemy.hpp"



class Game : public QGraphicsView {
    Q_OBJECT
public:
    Game(int number);
    ~Game();
    void addItems(QVector<QVector<tile>> map);
    bool readWaves(const QString filename);
    void handle_screen_click(double x, double y);
    //void set_tower(TileGraphicsItem *tileg, double x, double y);
    void sell_tower();
    QGraphicsScene* get_scene(){return scene_;};
    QTimer* createTimer;
    void createEnemies();
    QVector<QString> enemies;
    bool StartGame(QString filename, int difficulty, int map);
    void reduceLives(int livesToReduce);
    void setLives();
    int getLives();
    QVector<Enemy*> getEnemiesOnPath();
    void killEnemy(Enemy * enemy);
    void addMoney(int money);
    QVector<QVector<QString>> getWaves(){return waves_;}
    QVector<Enemy*> enemiesOnPath_;
    void winningmessage();




public slots:
    void handleClick(QString price);
    void spawn();
    //void Move(QTimer * movetimer, Enemy* enemy);


protected:
    void mousePressEvent(QMouseEvent *event);


private:
    int Money_;
    int Lives_;
    QVector<QVector<QString>> waves_;
    QGraphicsScene *scene_;
    bool towerbutton_clicked_;
    QGraphicsTextItem *infolbl_ ;
    int chosentower_;
    QGraphicsTextItem * io2;
    QGraphicsTextItem * io3;
    QGraphicsTextItem * io;
    bool sellbutton_clicked_;
    QVector<QVector<int>> path_;





};

#endif // GAME_H
