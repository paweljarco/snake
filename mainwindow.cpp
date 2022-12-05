#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "drawing/DrawingHandler.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto drawing = std::make_unique<drawing::DrawingHandler>(parent);
    drawing->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

