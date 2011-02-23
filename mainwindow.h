#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include "graphics.h"
class Graphics;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Graphics *graphics;
    QLineEdit *functionedit;
    QPushButton *submit;
private slots:
    void pass_function();
protected:
    virtual void keyPressEvent(QKeyEvent *);
};

#endif // MAINWINDOW_H
