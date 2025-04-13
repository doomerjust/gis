#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //QWidget*w =new QWidget(this);
    //QVBoxLayout* layout=new QVBoxLayout(this);
    map =new QPixmap(":/new/prefix1/pic/iss_21953_03290.jpg!ww7006");
    pix =new QGraphicsPixmapItem(*map);
    s.addItem(pix);
    v=new customGraphicsView(this);
    v->setScene(&s);
    v->show();


    //layout->addWidget(v);
    //layout->setStretchFactor(this,1);
    this->resize(200,200);
}

MainWindow::~MainWindow() {}
