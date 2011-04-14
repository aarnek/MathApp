#ifndef GRAPH_H
#define GRAPH_H

#include <QtGui>
#include "graphics.h"
class Graphics;

class Graph : public QWidget
{
public:
    Graph(QString);
    void make_pixels(Graphics *);
    QList<QRectF> getPixels();
    void parse(QString);
    qreal valueAt(qreal);
private:
    qreal RANGE;
    Graphics *graphics;
    qreal miny,minx,maxy,maxx;
    QList<QRectF> pixels;
    QList<QPair <qreal,qreal> > func;
};

#endif // GRAPH_H
