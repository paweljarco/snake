#pragma once

#include "drawing/IDrawingHandler.hpp"

#include <QImage>
#include <QWidget>

namespace drawing
{
class DrawingHandler : public QWidget, IDrawingHandler
{
public:
    DrawingHandler(QWidget *parent = 0);
    ~DrawingHandler() = default;

    void start() override;

private:
    QImage canvas_;
};

} // namespace drawing
