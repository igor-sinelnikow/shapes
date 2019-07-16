#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QComboBox;
class QLabel;

class ShapesPainter;

class Window: public QWidget {
    Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);

private slots:
    void shapeChanged(int index);

private:
    ShapesPainter *m_shapesPainter;
};

#endif // WINDOW_H
