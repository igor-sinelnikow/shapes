#include "shapespainter.h"

#include <QPainter>

ShapesPainter::ShapesPainter(QWidget *parent): QWidget(parent) {
    m_shape = Circle;

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

QSize ShapesPainter::sizeHint() const {
    return QSize(320, 320);
}

QSize ShapesPainter::minimumSizeHint() const {
    return QSize(100, 100);
}

void ShapesPainter::setShape(Shape shape) {
    m_shape = shape;
    update();
}

void ShapesPainter::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event)

    QPainter painter(this);
    QBrush brush = painter.brush();
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.setRenderHint(QPainter::Antialiasing, true);

    const QPoint center(width()/2, height()/2);

    QRect square(0, 0, 160, 160);
    square.moveCenter(center);

    QRect rect(0, 0, 160, 120);
    rect.moveCenter(center);

    QPolygon triangle;
    triangle << square.bottomLeft() << square.bottomRight()
             << QPoint(center.x(), square.top());

    switch (m_shape) {
    case Circle:
        painter.drawEllipse(square);
        break;
    case Square:
        painter.drawRect(square);
        break;
    case Triangle:
        painter.drawPolygon(triangle);
        break;
    case Rectangle:
        painter.drawRect(rect);
        break;
    default:
        break;
    }
}
