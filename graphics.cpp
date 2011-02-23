#include <QtGui>
#include "graphics.h"
#include "graph.h"

Graphics::Graphics(QWidget *parent) :
    QGraphicsView(parent)
{
    setFixedSize(550,330);
    scene = new QGraphicsScene();
    setScene(scene);
    content.setRect(-250,-150,500,300);
    qDebug() << content;
    setSceneRect(content);
    qDebug() << "this";
    draw_y_axis();
    draw_x_axis();

    show();
}
void Graphics::draw_x_axis()
{
    scene->addLine(content.left(), 0, content.right(),0,Qt::DashDotLine);
}
void Graphics::draw_y_axis()
{
    scene->addLine(0, content.top(),0,content.bottom(),Qt::DashDotLine);
}
void Graphics::drawGraph(QString function)
{
    graph = new Graph(function);
    graph->make_pixels(this);
    int i;
    scene->clear();
    draw_x_axis();
    draw_y_axis();
    QList<QRectF> pix = graph->getPixels();
    qDebug() << "ohio";
    for(i= 0; i <= pix.size()-1;i++)
    {
        if(i == pix.size())
        {
            scene->addRect(pix.at(i), QPen(Qt::blue), QBrush(Qt::blue));
            i++;
        }
        else
        {
        scene->addRect(pix.at(i), QPen(Qt::blue), QBrush(Qt::blue));
    }
    }
}
