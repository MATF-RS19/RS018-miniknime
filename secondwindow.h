#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QFrame>
#include <QtWidgets>
#include <iostream>
#include "mknode.h"
#include "uicontroler.h"
#include "mkline.h"

QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE


class secondwindow : public QFrame
{
public:
    MKLine* line=nullptr;

    secondwindow(QWidget *parent = nullptr);
    static bool paintLine;
    void paintLines(QWidget* origin, QWidget* target, int positionIndex1,int positionIndex2){
        line=new MKLine(origin->pos().x(),origin->pos().y(),
                    target->pos().x(),target->pos().y(),
                    positionIndex1,positionIndex2
                        );
        paintLine=true;
        this->repaint();
    }

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *e) override{
        if(paintLine){
            paintLine=false;
            auto pixmap = new QPixmap(400,400);
            pixmap->fill(Qt::white);
            QPainter PixmapPainter(pixmap);
            QPen pen(Qt::red);
            pen.setWidth(5);
            PixmapPainter.setPen(pen);
            PixmapPainter.drawLine(line->startX, line->startY, line->endX, line->endY);
            QPainter painter(this);
            painter.drawPixmap(0, 0, *pixmap);
        }
    }



    MKNode* currentlyDraggedNode=nullptr;

};

#endif // SECONDWINDOW_H
