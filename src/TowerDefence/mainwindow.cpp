#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QString>
#include "Map.hpp"
#include "TileGraphicsItem.hpp"
#include "game.h"

extern Game * game;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startButton_clicked()
{   game = new Game(2);
    bool value=game->StartGame(ui->mapFileLine->text(),ui->spinBox->value(), ui->spinBox_2->value());
    if (value== true){

        game->show();
    }

    else{
        delete game;
        QMessageBox::critical(this,"Message", "Invalid map file!", QMessageBox::Ok);

    }

    }





