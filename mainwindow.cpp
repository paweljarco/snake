#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "board/ConstBoardValues.hpp"
#include "game/Game.hpp"
#include "game_objects/Fruit.hpp"
#include "game_objects/Snake.hpp"
#include "game_objects/Tail.hpp"
#include <QPaintEngine>
#include <QTimer>
#include <QKeyEvent>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(QSize(board::BOARD_WIDTH, board::BOARD_HEIGHT));
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
    QPainter painter(this);
    painter.end();
    if (!gameOn) return;
    painter.begin(this);

    auto& snakePos = game_->getSnakePosition();
    painter.drawRect(QRect(snakePos.x_, snakePos.y_, board::BOX_SIZE, board::BOX_SIZE));

    auto& tailsList = game_->getTails();
    for (auto& tail : tailsList){
        painter.drawRect(QRect(tail->getPosition().x_, tail->getPosition().y_, board::BOX_SIZE, board::BOX_SIZE));
    }

    if (game_->getFruitPosition())
    {
        auto pos = game_->getFruitPosition().value();
        painter.drawRect(QRect(pos.x_, pos.y_, board::BOX_SIZE, board::BOX_SIZE));
    }
}


void MainWindow::on_actionNew_game_triggered()
{
    game_->newGame();
    gameOn = true;
    timerId = startTimer(500);
    update();
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    game_->move();

    if (!game_->isRunning())
    {
        killTimer(timerId);
        gameOn = false;
        return;
    }
    update();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Up:
        game_->turn(board::Direction::UP);
        break;
    case Qt::Key_Down:
        game_->turn(board::Direction::DOWN);
        break;
    case Qt::Key_Left:
        game_->turn(board::Direction::LEFT);
        break;
    case Qt::Key_Right:
        game_->turn(board::Direction::RIGHT);
        break;
    default:
        return;
    }
}


