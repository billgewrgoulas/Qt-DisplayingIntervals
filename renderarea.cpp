#include "renderarea.h"
#include "dummyinterval.h"

#include <QPainter>
#include <QPainterPath>
#include<iostream>
#include <string>
#include <iostream>
#include <cstdlib>

RenderArea::RenderArea(dummyInterval *ia, int size, QWidget *parent )
    : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    this->intervalArray = ia;
    this->size = size;
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}

QSize RenderArea::sizeHint() const
{
    return QSize(1024, 1024);
}

void RenderArea::setPen(const QPen &pen)
{
    this->pen = pen;
    update();
}

void RenderArea::setBrush(const QBrush &brush)
{
    this->brush = brush;
    update();
}

void RenderArea::UpdateIntervals(dummyInterval *ia){

    if(this->intervalArray){
        delete [] this->intervalArray;
    }

    this->intervalArray = ia;
    update();
}

void RenderArea::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.setWindow(0, 0, 840, 600);

    for(int i = 0; i < 1024; i+=40){
        painter.drawLine(i,0,i, 1024);
    }

    this->drawLines(painter);
    painter.end();

}

void RenderArea::drawLines(QPainter &p){

    int dy = 30;
    p.setPen(QPen(Qt::black, 1));
    p.setFont(QFont("times", 11));

    for(int i = 0; i<this->size; i++){

        int l = this->intervalArray[i].left();
        int r = this->intervalArray[i].right();

        if(l == r){
            continue;
        }
        QPoint sp, ep;

        sp.setX(l*40);
        sp.setY(dy);

        ep.setX(r*40);
        ep.setY(dy + 10);

        p.drawRect(QRect(sp, ep));
        dy+=50;

        QString sx = QString::number(l);
        QString ex = QString::number(r);
        QString label = QString::fromStdString("(i" + std::to_string(r) + ")");
        p.drawText(sp.x(), sp.y() + 25, sx);
        p.drawText(ep.x() - 5, ep.y() + 15, ex);
        p.drawText(ep.x() - 17, ep.y() - 18, label);

    }
}
