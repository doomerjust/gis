#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QVBoxLayout>
#include <QWidget>
#include <QResizeEvent>
#include <QPoint>
#include <QScrollBar>
#include <QPainterPath>
#include <QPen>

#include <QPainterPath>
#include <QGraphicsPathItem>


class customGraphicsView:public QGraphicsView
{
    Q_OBJECT
private:
    QPoint point;
    qreal scalefactor;
public:
    customGraphicsView(QWidget* parent=nullptr):QGraphicsView(parent)
    {
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setDragMode(QGraphicsView::ScrollHandDrag);
        scalefactor=1.1;

    }
protected:
    void mousePressEvent(QMouseEvent *event)override
    {
        if(event->button()==Qt::LeftButton)
        {
            point=event->pos();
        }
        QGraphicsView::mousePressEvent(event);
    }
    void mouseMoveEvent(QMouseEvent *event)override
    {
        if(event->button()&Qt::LeftButton)
        {
            QPoint delta=event->pos() -point;
            horizontalScrollBar()->setValue(horizontalScrollBar()->value() - delta.x());
            verticalScrollBar()->setValue(verticalScrollBar()->value() - delta.y());
            point=event->pos();
        }
        QGraphicsView::mouseMoveEvent(event);
    }
    void wheelEvent(QWheelEvent*event)override
    {
        qreal q;
        if(event->angleDelta().y()>0)
        {
            q=scalefactor;
        }else
        {
            q=1.0/scalefactor;
        }
        scale(q,q);
        event->accept();
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    customGraphicsView *v;
    QGraphicsScene s;
    QGraphicsPixmapItem* pix;
    QPixmap* map;
protected:
    void resizeEvent(QResizeEvent *event)override
    {
        v->setGeometry(0,0,event->size().width(),event->size().height());
        QWidget::resizeEvent(event);
    }

};


#endif // MAINWINDOW_H
