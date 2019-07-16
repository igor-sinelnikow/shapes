#include "window.h"

#include <QComboBox>
#include <QLabel>
#include <QVBoxLayout>

#include "shapespainter.h"

Window::Window(QWidget *parent): QWidget(parent) {
    setWindowTitle("Геометрические фигуры");

    m_shapesPainter = new ShapesPainter;

    QLabel *shapeLabel = new QLabel("Фигура:");

    QComboBox *shapeComboBox = new QComboBox;
    shapeComboBox->addItem("Круг", ShapesPainter::Circle);
    shapeComboBox->addItem("Квадрат", ShapesPainter::Square);
    shapeComboBox->addItem("Треугольник", ShapesPainter::Triangle);
    shapeComboBox->addItem("Прямоугольник", ShapesPainter::Rectangle);

    connect(shapeComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(shapeChanged(int)));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(m_shapesPainter);
    layout->addWidget(shapeLabel);
    layout->addWidget(shapeComboBox);
    setLayout(layout);

    shapeChanged(0);
    setFixedSize(400, 400);
}

void Window::shapeChanged(int index) {
    m_shapesPainter->setShape(ShapesPainter::Shape(index));
}
