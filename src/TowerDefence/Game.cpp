#include "game.h"
#include "TileGraphicsItem.hpp"
#include "tile.hpp"
#include <QVector>
#include <QGraphicsScene>
#include "Map.hpp"
#include <QString>
#include <QFile>
#include "Blue.hpp"
#include "Red.hpp"
#include "Green.hpp"
#include "white.hpp"
#include "Boss.hpp"
#include "basic.h"
#include "quicky.h"
#include "sniper.h"
#include "piercer.h"
#include <QPushButton>
#include "bullet.hpp"
#include "Enemy.hpp"
#include <QTimer>




void Game::handleClick(QString price) {
    sellbutton_clicked_=false;
    int towerprice=price.toInt();
    if ( towerprice>Money_){
        infolbl_->setPlainText("Not enough money!");
        infolbl_->show();
    }
    else{
        towerbutton_clicked_=true;
        if (towerprice ==400){
            chosentower_=400;
        }
        if (towerprice ==600){
            chosentower_=600;
        }
        if (towerprice ==1300){
            chosentower_=1300;
        }
        if (towerprice ==1000){
            chosentower_=1000;
        }
        infolbl_->setPlainText("Click tile to add tower!");
        infolbl_->show();

    }
}

void Game::sell_tower(){
    sellbutton_clicked_=true;
    towerbutton_clicked_=false;
    infolbl_->setPlainText("Click the tower you want to sell!");
}


Game::Game( int number){

    scene_=new QGraphicsScene(this);
    setScene(scene_);
    scene_->setSceneRect(0,0,900,600);
    setFixedSize(900,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    Money_=1000;
    Lives_= 20;
    towerbutton_clicked_=false;
    sellbutton_clicked_=false;
    chosentower_=0;
    infolbl_ = new QGraphicsTextItem;
    scene_->addItem(infolbl_);
    infolbl_->setPos(550,350);
    QString money = QString::number(Money_);
    QString Lives = QString::number(Lives_);
    io = new QGraphicsTextItem;
    io->setPos(0,400);
    io->setPlainText("Lives: "+Lives);
    scene_->addItem(io);

    QVBoxLayout *vbox= new QVBoxLayout(this);
    QPushButton *b3= new QPushButton("Piercer\n600");
    QPushButton *b2= new QPushButton("Quicky\n1300");
    QPushButton *b1= new QPushButton("Basic\n400");
    QPushButton *b4= new QPushButton("Sniper\n1000");
    QPushButton *b5= new QPushButton("Sell");
    QPushButton *start= new QPushButton("Start next wave");
    QPalette pal = b3->palette();



    connect(b1, &QPushButton::clicked, [this](){handleClick("400");});
    connect(b2, &QPushButton::clicked, [this](){handleClick("1300");});
    connect(b3, &QPushButton::clicked, [this](){handleClick("600");});
    connect(b4, &QPushButton::clicked, [this](){handleClick("1000");});
    connect(b5, &QPushButton::clicked, [this](){sell_tower();});
    connect(start, &QPushButton::clicked, [this](){createEnemies();});

    QFont serif("Georgia",14,QFont::Bold);

    b5->setFont(serif);
    b4->setFont(serif);
    b3->setFont(serif);
    b2->setFont(serif);
    b1->setFont(serif);
    start ->setFont(serif);


    start->setStyleSheet("color: white");
    b1->setStyleSheet(" color: white ");
    b3->setStyleSheet("color: white");
    b4->setStyleSheet("color: white");
    b2->setStyleSheet("color: white");
    b5->setStyleSheet("color: white");

    vbox->addWidget(b1);
    vbox->addWidget(b2);
    vbox->addWidget(b3);
    vbox->addWidget(b4);
    vbox->addWidget(b5);
    vbox->addWidget(start);

    vbox->setAlignment(Qt::AlignRight);
    vbox->setSpacing(60);

    io2 = new QGraphicsTextItem;
    io2->setPos(100,400);
    io2->setPlainText("Money: "+money);
    this->setStyleSheet("background-color: green;");
    scene_->addItem(io2);


}

bool Game::StartGame(QString filename, int diff, int maplevel){
    QString difficulty = ":/" + QString::number(diff) + ".txt" ;
    QString mapFile = "";
    if (maplevel==0){
         mapFile =":/" + filename + ".txt";
    }
    else if(maplevel==1){
         mapFile =":/map1.txt";
    }
    else if(maplevel==2){
         mapFile =":/map2.txt";
    }
    else{
        mapFile =":/map3.txt";
    }
    Map map=  Map();
    int ret= map.readMap(mapFile);
    if (ret!=1){
        return false;
    }
    else{
   addItems(map.getMap());
   if (!readWaves(difficulty)) {
       return false;
    }
   path_ = map.getPath();
   QString wave = QString::number(waves_.length());
   io3 = new QGraphicsTextItem;
   io3->setPos(200,400);
   io3->setPlainText("Waves left: "+wave);
   scene_->addItem(io3);

   return true;
}
}


bool Game::readWaves(const QString filename) {

    QFile file(filename);
    if (!file.exists()) {
        qCritical() << "Wave file not found!";
        return false;
    }
    if (!file.open(QIODevice::ReadOnly)) {
        qCritical() << "Could not open wave file!";
        qCritical() << file.errorString();
        return false;
    }

    file.seek(0);
    QString waves = file.readAll();
    file.close();
    QVector<QString> wave;

    for (auto it = waves.begin(); *it != '\r'; it++) {

         if (*it == '*') {
            waves_.append(wave);
            wave.clear();
        }
         else{
         wave.append(*it);
         }
    }
    waves_.append(wave);


    return true;
}

QVector<Enemy*> Game::getEnemiesOnPath() {
    return enemiesOnPath_;
}


void Game:: createEnemies(){

  if (enemiesOnPath_.isEmpty()&& !waves_.isEmpty()){
     createTimer= new QTimer(this);
    enemies = waves_.takeFirst();
    QString wave = QString::number(waves_.length());
    io3->setPlainText("Waves left: "+wave);

    connect(createTimer,SIGNAL(timeout()),this,SLOT(spawn()));
    createTimer->start(500);
    }

}
void Game:: spawn(){
    if (enemies.isEmpty()){
       createTimer->disconnect();
    }
    else{
        QString it= enemies.takeFirst();
            if (it == 'R') {
                Red * enemy = new Red(path_);
                enemiesOnPath_.append(enemy);
                scene_->addItem(enemy);

            }
            else if (it == 'B') {
                Blue *enemy = new Blue(path_);
                enemiesOnPath_.append(enemy);
                scene_->addItem(enemy);

            }
            else if (it == 'W') {
                White *enemy = new White(path_);
                enemiesOnPath_.append(enemy);
                scene_->addItem(enemy);

            }
            else if (it == 'G') {
                Green *enemy = new Green(path_);
                enemiesOnPath_.append(enemy);
                scene_->addItem(enemy);

            }
            else if (it == 'P') {
                Boss *enemy = new Boss(path_);
                enemiesOnPath_.append(enemy);
                scene_->addItem(enemy);

            }
       }
}

void Game::addItems(QVector<QVector<tile>> map) {

      for (auto row : map) {
        for (auto tile : row) {
        TileGraphicsItem *tilegraphic = new TileGraphicsItem(tile.get_x(), tile.get_y(), tile.is_path(), tile.get_size(), tile);
        scene_->addItem(tilegraphic);
        if (tile.is_end()) {
            tilegraphic->setBrush(QColor(0,0,0));
        }
        }
    }
}

void Game::mousePressEvent(QMouseEvent *event){
    QGraphicsView::mousePressEvent(event);
     double x=event->scenePosition().x();
     double y = event->scenePosition().y();
     handle_screen_click(x, y);
}


void Game::handle_screen_click(double x, double y){
    QGraphicsItem *item= scene_->itemAt(QPoint(int(x),int(y)), QTransform());
    if(item != nullptr){
    if (item->type()==7){
        if( item->scale()!=0.2 ){

            Tower *tower = (Tower*)scene_->itemAt(QPoint(int(x),int(y)), QTransform());
            if (tower != nullptr && sellbutton_clicked_==false && towerbutton_clicked_==false && tower->type()==7){
                tower->Get_range()->show();
            }
            if (tower != nullptr && sellbutton_clicked_==true && tower->type()==7){
                if (tower->is_tower()==true){
                   Money_=Money_+0.8*tower->Get_price();
                   io2->setPlainText("Money: "+ QString::number(Money_));
                   scene_->removeItem(tower->Get_range());
                   scene_->removeItem(tower);
                   sellbutton_clicked_=false;
                }

            }
        }

    }
    if (item->type()==4){
        Tower *tower = (Tower*)scene_->itemAt(QPoint(int(x),int(y)), QTransform());
        if (tower != nullptr && sellbutton_clicked_==false && towerbutton_clicked_==false && tower->type()==4){
            tower->hide();
        }
    }
    if (item->type()==3){
    TileGraphicsItem * tile = (TileGraphicsItem*)scene_->itemAt(QPoint(int(x),int(y)), QTransform());
    if (tile != nullptr && towerbutton_clicked_==true && tile->type() == 3){
        tile->is_clicked_=true;
        if (tile->get_tile().is_path()==false){
            Tower *tower;
            if (chosentower_==400){
                tower = new Basic;
            }
            if (chosentower_==1300 ){
                tower = new Quicky;
                tower->setScale(0.067);

            }
            if (chosentower_==1000 ){
                tower = new Sniper;
                tower->setScale(0.017);
            }
            if (chosentower_==600 ){
                tower = new Piercer;
                tower->setScale(0.072);
            }
            scene_->addItem(tower);
            tower->show();
            tower->setPos(tile->get_x()*35,tile->get_y()*35);


            tower->setupRange(0,0);
            tower->Get_range()->setPos(tile->get_x()*35 - 52.5, tile->get_y()*35 - 52.5);
            scene_->addItem(tower->Get_range());



            Money_=Money_-int(chosentower_);
            QString money = QString::number(Money_);
            io2->setPlainText("Money: "+ money);
            towerbutton_clicked_=false;
            chosentower_=0;
            tile->get_tile().reserve();
            tile->is_clicked_=false;
            infolbl_->hide();
        }
        else{
            infolbl_->setPlainText("You can't place a tower on the path");
        }
    }

    }
    }

}

void Game::reduceLives(int livesToReduce) {

    if (Lives_ > livesToReduce) {
        Lives_= Lives_ - livesToReduce;
        QString Lives = QString::number(Lives_);
        io -> setPlainText("Lives: " + Lives);
    }
    else {
        Lives_=0;
        QString Lives = QString::number(Lives_);
        io -> setPlainText("Lives: " + Lives);
        QMessageBox *msg = new QMessageBox;
           msg->setWindowTitle("Game over!");
           msg->setIcon(QMessageBox::Information);
           msg->setText("You ran out of lives. GAME OVER!");
           msg->exec();
           close();




    }
}


int Game:: getLives(){
    return Lives_;
}

void Game::addMoney(int money) {
    Money_ += money;
    io2->setPlainText("Money: "+ QString::number(Money_));

}


void Game::killEnemy(Enemy *enemy) {
    int i;
    i=enemiesOnPath_.indexOf(enemy);
    enemiesOnPath_.remove(i);
    addMoney(enemy->getWorth());
    delete enemy;
    if (enemiesOnPath_.isEmpty() && waves_.isEmpty()){
        winningmessage();
    }


}

void Game::winningmessage(){
     //QMessageBox::information(this,"Message", "You won the game!", QMessageBox::Ok);
       QMessageBox *msg2 = new QMessageBox;
       msg2->setIcon(QMessageBox::Information);
       msg2->setText("You won the game!");
       msg2->exec();
       close();

}

Game::~Game()
{

}
