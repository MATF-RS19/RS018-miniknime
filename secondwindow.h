#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QFrame>
#include <QtWidgets>
#include <iostream>
#include "mknode.h"
#include "uicontroler.h"
#include "mkline.h"
#include "mkinput.h"
#include "mkoutput.h"

QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE


class secondwindow : public QFrame
{
public:

    secondwindow(QWidget *parent = nullptr);
    static bool paintLine;
    void appendLine(QWidget* origin, QWidget* target,
                    MKOutput<double>* output,MKInput<double>* input){
        auto line=new MKLine(origin->pos().x(),origin->pos().y(),
                    target->pos().x(),target->pos().y(),
                    input->positionIndex,output->positionIndex
                        );
        input->connectedLine=line;
        output->connectedLine=line;
        UIControler::addLine(line);
    }

    void drawLines(){
        paintLine=true;
        this->repaint();
    }

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

    void changeEvent(QEvent *event) override;
    void focusOutEvent(QFocusEvent* e) override;
    void focusInEvent(QFocusEvent* e) override;

    void paintEvent(QPaintEvent*) override{
        paintLine=false;
        auto pixmap = new QPixmap(400,400);
        pixmap->fill(Qt::white);
        QPainter PixmapPainter(pixmap);
        QPen pen(Qt::red);
        pen.setWidth(5);
        PixmapPainter.setPen(pen);
        for(const auto* line : UIControler::activeLines){
            PixmapPainter.drawLine(line->startX, line->startY, line->endX, line->endY);
        }
        QPainter painter(this);
        painter.drawPixmap(0, 0, *pixmap);
    }

    MKNode* currentlyDraggedNode=nullptr;

};

#endif // SECONDWINDOW_H
