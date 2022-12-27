#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qpainter.h"
#include <QMainWindow>

namespace game {
class Game;
}  // game

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void timerEvent(QTimerEvent *event);


private slots:
    void on_actionNew_game_triggered();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<game::Game> game_;
    std::unique_ptr<QPainter> painter_;
    bool gameOn;
    int timerId;
};
#endif // MAINWINDOW_H
