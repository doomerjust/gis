#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //QWidget*w =new QWidget(this);
    //QVBoxLayout* layout=new QVBoxLayout(this);
    // map1 =new QPixmap(":/new/prefix1/pic/iss_21953_03290.jpg!ww7006");
    // pix =new QGraphicsPixmapItem(*map1);
    // s.addItem(pix);
    map1=new QPixmap(":/new/prefix1/pic/osm_100-l-3-1-0-0.png");
    map2=new QPixmap(":/new/prefix1/pic/osm_100-l-3-1-0-1.png");
    map3=new QPixmap(":/new/prefix1/pic/osm_100-l-3-1-1-0.png");
    map4=new QPixmap(":/new/prefix1/pic/osm_100-l-3-1-1-1.png");
    item1=new QGraphicsPixmapItem(*map1);
    item2=new QGraphicsPixmapItem(*map2);
    item3=new QGraphicsPixmapItem(*map3);
    item4=new QGraphicsPixmapItem(*map4);
    item2->setPos(0,map1->height());
    item3->setPos(map1->width(),0);
    item4->setPos(map3->width(),map2->height());
    s.addItem(item1);
    s.addItem(item2);
    s.addItem(item3);
    s.addItem(item4);

    path.moveTo(0,0);
    path.lineTo(20,20);
    path.lineTo(0,40);
    path.lineTo(map1->width(),map1->height());
    pitem=new QGraphicsPathItem(path);
    pen.setWidth(3);
    pen.setColor(color.green());
    pitem->setPen(pen);
    s.addItem(pitem);

    v=new customGraphicsView(this);
    v->setScene(&s);
    v->show();


    //layout->addWidget(v);
    //layout->setStretchFactor(this,1);
    this->resize(500,500);
}

MainWindow::~MainWindow() {}
