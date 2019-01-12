#include "secondwindow.h"
#include "mainwindow.h"
#include "uicontroler.h"
#include "iostream"
#include "mknodespec.h"

#include <QtWidgets>
#include <mkdialog.h>

#undef DEBUG

secondwindow::secondwindow(QWidget *parent)
    : QFrame(parent)
{
    setMinimumSize(400, 400);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);
}

void secondwindow::mousePressEvent(QMouseEvent *event)
{
    QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
    if(!child)
        return;
    if(UIControler::phase==normal){
        if(QApplication::mouseButtons() & Qt::LeftButton){
            currentlyDraggedNode=UIControler::getNode(child);

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
            auto node=UIControler::getNode(child);
            //std::cout<<"graph node type: "<<node->type<<std::endl;

    #ifdef DEBUG
            if(node==nullptr){
                std::cout<<"null"<<std::endl;
            }else{
                std::cout<<node<<std::endl;
            }
    #endif
            MKDialog dialog;
            dialog.node=node;
            dialog.setModal(true);
            dialog.exec();
        }
    }else{
        if(UIControler::connectionSource==nullptr){
            std::cout<<"something went wrong, connection source not set"<<std::endl;
            return;
        }
        auto mkIn=UIControler::getNode(child)->getFirstFreeInput();

        if(mkIn!=nullptr){
            std::cout<<"connected: "<<UIControler::connectionSource->parent->type<<"<->"<<mkIn->parent->type<<std::endl;
            UIControler::connectionSource->establishConnection(*mkIn);
            UIControler::connectionSource=nullptr;
            UIControler::phase=normal;
        }else{
            std::cout<<"target node has no free inputs"<<std::endl;
        }

    }
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

        if(currentlyDraggedNode==nullptr){
            auto node=new MKTestNode1_1();
            node->type=MainWindow::draggedNodeType;
            UIControler::addNode(newIcon, node);
        }else{
            UIControler::amendNode(newIcon,currentlyDraggedNode);
        }
        currentlyDraggedNode=nullptr;


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





















