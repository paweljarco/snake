#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "drawing/DrawingHandler.hpp"
#include <QPaintEngine>

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

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawRect(QRect(80, 120, 100, 150));
}
