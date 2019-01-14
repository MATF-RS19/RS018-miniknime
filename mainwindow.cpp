#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "uicontroler.h"
#include "mknodespec.h"
#include <iostream>
#include <QtWidgets>
#include <mkdialog.h>

std::string MainWindow::draggedNodeType="";

MainWindow::MainWindow(QWidget *parent)
    : QFrame (parent)
{
    setMinimumSize(400, 400);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);

    QLabel *KNN = new QLabel(this);
    KNN->setPixmap(QPixmap(":/pattern.png"));
    KNN->move(10, 10);
    KNN->show();
    KNN->setAttribute(Qt::WA_DeleteOnClose);
    UIControler::addOriginNode(KNN, "knn");

    QLabel *neuralNetwork = new QLabel(this);
    neuralNetwork->setPixmap(QPixmap(":/neural.png"));
    neuralNetwork->move(10, 40);
    neuralNetwork->show();
    neuralNetwork->setAttribute(Qt::WA_DeleteOnClose);
    UIControler::addOriginNode(neuralNetwork, "nn");

    QLabel *partitionNode = new QLabel(this);
    partitionNode->setPixmap(QPixmap(":/partition.png"));
    partitionNode->move(10, 70);
    partitionNode->show();
    partitionNode->setAttribute(Qt::WA_DeleteOnClose);
    UIControler::addOriginNode(partitionNode,"pn");

    QLabel *normalization = new QLabel(this);
    normalization->setPixmap(QPixmap(":/norm.png"));
    normalization->move(10, 100);
    normalization->show();
    normalization->setAttribute(Qt::WA_DeleteOnClose);
    UIControler::addOriginNode(normalization, "norm");

    QLabel *csvReader = new QLabel(this);
    csvReader->setPixmap(QPixmap(":/csv.png"));
    csvReader->move(10, 130);
    csvReader->show();
    csvReader->setAttribute(Qt::WA_DeleteOnClose);
    UIControler::addOriginNode(csvReader, "csvr");

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{


    QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
    if(!child)
        return;
    if(QApplication::mouseButtons() & Qt::LeftButton){
        //std::cout<<"origin node type: "<<UIControler::getTypeFromOrigin(child)<<std::endl;
        draggedNodeType=UIControler::getTypeFromOrigin(child);

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
    }
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
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

void MainWindow::dragMoveEvent(QDragMoveEvent *event)
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

void MainWindow::dropEvent(QDropEvent *event)
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
        UIControler::amendOriginNode(newIcon,draggedNodeType);
        draggedNodeType="";

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





