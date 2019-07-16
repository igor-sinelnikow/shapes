#ifndef SHAPESPAINTER_H
#define SHAPESPAINTER_H

#include <QWidget>

class ShapesPainter: public QWidget {
    Q_OBJECT

public:
    enum Shape { Circle, Square, Triangle, Rectangle };

    explicit ShapesPainter(QWidget *parent = nullptr);

    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

protected:
    void paintEvent(QPaintEvent *event) override;

public slots:
    void setShape(Shape shape);

private:
    Shape m_shape;
};

#endif // SHAPESPAINTER_H
