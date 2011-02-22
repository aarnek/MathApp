#include <QtGui>
#include "mainwindow.h"
#include "graphics.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    graphics = new Graphics;
    QWidget *widget = new QWidget(this);
    QVBoxLayout *main = new QVBoxLayout;
    main->addWidget(graphics);

    QHBoxLayout *functionlayout = new QHBoxLayout;
    functionedit = new QLineEdit("x^3");
    functionlayout->addWidget(functionedit);
    submit = new QPushButton("Draw");
    connect(submit,SIGNAL(clicked()), this,SLOT(pass_function()));
    functionlayout->addWidget(submit);

    QWidget *area = new QWidget(this);
    area->setLayout(functionlayout);

    main->addWidget(area);

    widget->setLayout(main);
    setCentralWidget(widget);
}
void MainWindow::pass_function()
{
    qDebug() << "pass_functionissa";
    graphics->drawGraph(functionedit->text());
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Return){
        qDebug() << "helloo";
        pass_function();
    }
    qDebug() << event;
}

MainWindow::~MainWindow()
{
    delete graphics;
}
