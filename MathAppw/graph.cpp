#include <QtGui>
#include <QtCore>
#include <math.h>
#include "graph.h"
#include "graphics.h"

Graph::Graph(QString graph)
{
    qDebug() << "hello";
    maxx = 6;
    maxy = 4;
    miny = -4;
    minx = -6;
    RANGE = 0.024;
    qDebug() << RANGE;
    parse(&graph);
}
void Graph::parse(QString *function)
{
    QStringList particles;
    qDebug() << "jotein" << function->size();
    /*bool is_next_minus = false;
    int i = 0;
    int prevint = 0;
    int stringsize = function->size();
    for(i=0;i<=stringsize;i++)
    {
        if(i == stringsize){
            i++;
            QString string;
            string.append(function->mid(prevint,i-prevint));
            if(string.contains('+')){string.remove(0,1);};
            particles << string;
        }
        else if(function->at(i) == '+')
        {
            QString var;
            if(i != 0)
            {
            var = function->mid(prevint,i-prevint);
        }
            if(is_next_minus && function->at(prevint) != '-')
            {
                var.prepend('-');
            }
            if(var.contains('+')){var.remove(0,1);};
            particles << var;
            prevint = i;
            is_next_minus = false;
        }
        else if(function->at(i) == '-')
        {
            if(i != 0)
            {
                QString part = function->mid(prevint,i-prevint);
                if(is_next_minus == true && function->at(prevint) != '-'){part.prepend('-');}
                if(part.contains('+')){part.remove(0,1);};
                particles << part;
            }
            is_next_minus = true;
            prevint = i;
        }
        else{}
    }
    */
    qDebug() << particles << " QPaireihin jako";
    int j,prevj= 0;
    qreal multi=0;
    qreal pow=0;
    for(i=0;i <= particles.size()-1;i++)
    {
        qreal length = particles.at(i).size()-1;
        prevj = 0;
        for(j=0;j <= length ;j++)
        {
            if(j == length)
            {
                qDebug() << "vika";
                if(particles.at(i).contains('^'))
                {

                int lowerindex = particles.at(i).indexOf('^');
                QString p;
                p = particles.at(i);
                p = p.mid(lowerindex+1, j-lowerindex);
                qDebug() << p.toFloat();
                pow = p.toFloat();
                }
                else
                {
                    qDebug() << prevj << j;
                    QString l;
                    l = particles.at(i);
                    pow = 0;
                    if(l.contains('x')){l.remove(l.indexOf('x'),1); pow = 1;};
                    l.mid(prevj,j);
                    qDebug() << l;
                    multi = l.toFloat();
                }
                func.append(qMakePair(multi,pow));
            }
            else if(particles.at(i).at(j) == 'x')
            {
                QString l = particles.at(i);
                l.truncate(j);
                qDebug() << "xvalue"<< l;
                if(l == ""){multi = 1;}
                else if(l == "-"){multi = -1;}
                else
                {
                multi = l.toFloat();
            }
                prevj = j;
            }
            else{}
            qDebug() << func;
        }
        qDebug() << particles.at(i)<< i << "    multi: "<< multi<<" power:" << pow <<" " << length;
    }
    qDebug() << func;
    return;
}
void Graph::make_pixels(Graphics *graphics)
{
    qreal x,y,pixel = 0;
    int i=0;
    qDebug() << "makepixels-funktiossa";
    for(pixel = graphics->sceneRect().left() ; pixel <= graphics->sceneRect().right(); pixel++ )
    {
        x = minx + (i*RANGE);
        y = (maxy-valueAt(x))/(maxy-miny);
        y =  y*(graphics->sceneRect().bottom() - graphics->sceneRect().top()) + graphics->sceneRect().top();
        pixel = (int)pixel;
        y = (int)y;
        qDebug() << x << y << pixel;
        pixels.append(QRectF(pixel,y,1,1));
        i++;
        qDebug() << i ;
    }
    qDebug() << pixels.at(4);
}
qreal Graph::valueAt(qreal x_value)
{
    qreal sum = 0;
    int i;
    QPair<double,double> pair;
    for(i = 0; i < func.size() ; i++)
    {
        if(i == func.size())
        {
            pair = func.last();
        }
        else{pair = func.at(i);}
        sum += ((pair.first) * pow(x_value, pair.second ));
    }
    qDebug() << "summa: "<< sum;
    return sum;
}
QList<QRectF> Graph::getPixels()
{
    return pixels;
}
