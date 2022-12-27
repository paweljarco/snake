#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "board/ConstBoardValues.hpp"
#include "drawing/DrawingHandler.hpp"
#include "game/Game.hpp"
#include "game_objects/Snake.hpp"
#include "game_objects/IObject.hpp"
#include <QPaintEngine>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    painter_ = std::make_unique<QPainter>(this);
    game_ = std::make_unique<game::Game>();
    gameOn = false;

}

MainWindow::~MainWindow()
{
    delete ui;
    killTimer(timerId);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    if (!gameOn) return;
    QPainter painter(this);
    painter.end();
    painter.begin(this);

    auto& snakePos = game_->getSnakePosition();
    painter.drawRect(QRect(snakePos.x_, snakePos.y_, board::BOX_SIZE, board::BOX_SIZE));

    auto& tailsList = game_->getTails();
    qDebug() << tailsList.size();
    for (auto& tail : tailsList){
        painter.drawRect(QRect(tail->getPosition().x_, tail->getPosition().y_, board::BOX_SIZE, board::BOX_SIZE));
    }
}


void MainWindow::on_actionNew_game_triggered()
{
    game_->newGame();
    gameOn = true;
    timerId = startTimer(1000);
    update();
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    game_->move();
    update();
}


