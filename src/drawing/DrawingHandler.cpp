#include "drawing/DrawingHandler.hpp"

namespace drawing
{
DrawingHandler::DrawingHandler(QWidget *parent)
    : QWidget(parent)
{}

void DrawingHandler::start()
{
    canvas_ = QImage(200,200,QImage::Format_RGB888);
    canvas_.fill(QColor(Qt::blue));
}

} // namespace drawinge
