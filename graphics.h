#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QtGui>
#include "graph.h"

class Graph;
class Graphics : public QGraphicsView
{
    Q_OBJECT
public:
    explicit Graphics(QWidget *parent = 0);
    void draw_y_axis();
    void draw_x_axis();
public slots:
    void drawGraph(QString);

signals:

private:
    QGraphicsScene *scene;
    QRectF content;
    Graph *graph;
};

#endif // GRAPHICS_H
