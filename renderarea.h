#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>
#include "dummyinterval.h"

//! [0]
class RenderArea : public QWidget
{
    Q_OBJECT

public:

    RenderArea(dummyInterval *ia, int size, QWidget *parent = nullptr);

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

public slots:
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);
    void UpdateIntervals(dummyInterval *ia);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QPen pen;
    QBrush brush;
    dummyInterval *intervalArray;
    void drawLines(QPainter &p);
    int size = 0;

};
//! [0]

#endif // RENDERAREA_H
