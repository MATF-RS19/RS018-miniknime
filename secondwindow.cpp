#include "secondwindow.h"
#include "uicontroler.h"
#include "iostream"
#include "mknodespec.h"

#include <QtWidgets>
#include <mkdialog.h>


secondwindow::secondwindow(QWidget *parent)
    : QFrame(parent)
{
    setMinimumSize(400, 400);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);
}

void secondwindow::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasFormat("application/x-dnditemdata"))
    {
        if(event->source() == this)
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }
        else
        {
            event->acceptProposedAction();
        }

    }
    else
    {
        event->ignore();
    }
}

void secondwindow::dragMoveEvent(QDragMoveEvent *event)
{
    if(event->mimeData()->hasFormat("application/x-dnditemdata"))
    {
        if(event->source() == this)
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }
        else
        {
            event->acceptProposedAction();
        }
    }
    else
    {
        event->ignore();
    }
}

void secondwindow::dropEvent(QDropEvent *event)
{
    if(event->mimeData()->hasFormat("application/x-dnditemdata"))
    {
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPixmap pixmap;
        QPoint offset;
        dataStream >> pixmap >> offset;

        QLabel *newIcon = new QLabel(this);
        newIcon->setPixmap(pixmap);
        newIcon->move(event->pos() - offset);
        newIcon->show();
        newIcon->setAttribute(Qt::WA_DeleteOnClose);
        UIControler::addNode(newIcon,new MKTestNode1_1());

        if(event->source() == this)
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }
        else
        {
            event->acceptProposedAction();
        }
    }
    else
    {
        event->ignore();
    }
}

void secondwindow::mousePressEvent(QMouseEvent *event)
{
    QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
    if(!child)
        return;
    std::cout<<"1"<<std::endl;
    if(QApplication::mouseButtons() & Qt::LeftButton){
        std::cout<<"lmb"<<std::endl;
        QPixmap pixmap = *child->pixmap();

        QByteArray itemData;
        QDataStream dataStream(&itemData, QIODevice::WriteOnly);
        dataStream << pixmap << QPoint(event->pos() - child->pos());

        QMimeData *mimeData = new QMimeData;
        mimeData->setData("application/x-dnditemdata", itemData);

        QDrag *drag = new QDrag(this);
        drag->setMimeData(mimeData);
        drag->setPixmap(pixmap);
        drag->setHotSpot(event->pos() - child->pos());

        QPixmap tempPixmap = pixmap;
        QPainter painter;
        painter.begin(&tempPixmap);
        painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
        painter.end();

        child->setPixmap(tempPixmap);

        if(drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction)
        {
            child->close();
        }
        else
        {
            child->show();
            child->setPixmap(pixmap);
        }
    }else{
        std::cout<<"rmb"<<std::endl;
        auto node=UIControler::getNode(child);
        if(node==nullptr){
            std::cout<<"null"<<std::endl;
            std::cout<<"ok"<<std::endl;
        }else{
            std::cout<<node<<std::endl;
            std::cout<<"ok2"<<std::endl;
        }
        MKDialog dialog;
        dialog.setModal(true);
        dialog.exec();
    }
}




















