#include "secondwindow.h"
#include "mainwindow.h"
#include "uicontroler.h"
#include "iostream"
#include "mknodespec.h"
#include "mkcsvreader.h"


#include <QtWidgets>
#include <csvreaderdialog.h>
#include <mkdialog.h>
#include <mkneuraldialog.h>
#include <mknormalizationdialog.h>


#undef DEBUG

bool secondwindow::paintLine=false;

secondwindow::secondwindow(QWidget *parent)
    : QFrame(parent)
{
    setMinimumSize(400, 400);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);
}

void secondwindow::mousePressEvent(QMouseEvent *event)
{
    drawLines();

    if(UIControler::phase==normal){
        QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
        if(!child)
            return;
        if(QApplication::mouseButtons() & Qt::LeftButton){
            currentlyDraggedNode=UIControler::getNode(child);
            currentlyDraggedNode->sendInvalidationPulse();

            for(auto& input:currentlyDraggedNode->m_inputs){
                UIControler::destroyLine(input.connectedLine);
                input.breakConnection();                
            }
            for(auto& output:currentlyDraggedNode->m_outputs){
                UIControler::destroyLine(output.connectedLine);
                output.breakConnection();
            }

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
            std::cout<<"graph node type: "<<node->type<<std::endl;
            if(node->type == "csvr")
            {
                node = new MKCSVReader;
                CsvReaderDialog dialog;
                dialog.node = node;
                dialog.setModal(true);
                dialog.exec();
            }
            else if (node->type == "nn")
            {
                mkneuraldialog dialog;
                dialog.node = node;
                dialog.setModal(true);
                dialog.exec();
            }
            else if(node->type == "pn")
            {
                MKDialog dialog;
                dialog.node=node;
                dialog.setModal(true);
                dialog.exec();
            }
            else if(node->type == "norm")
            {
                mknormalizationdialog dialog;
                dialog.node = node;
                dialog.setModal(true);
                dialog.exec();
            }


    #ifdef DEBUG
            if(node==nullptr){
                std::cout<<"null"<<std::endl;
            }else{
                std::cout<<node<<std::endl;
            }
    #endif

        }
    }else{
        if(QApplication::mouseButtons() & Qt::RightButton){
            std::cout<<"exited connecting mode"<<std::endl;
            UIControler::phase=normal;
            return;
        }

        QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
        if(!child)
            return;

        if(UIControler::connectionSource==nullptr){
            std::cout<<"something went wrong, connection source not set"<<std::endl;
            return;
        }
        auto targetNode=UIControler::getNode(child);
        if(UIControler::connectionSource->parent==targetNode){
            std::cout<<"cannot connect node to self"<<std::endl;
            return;
        }
        auto mkIn=targetNode->getFirstFreeInput();

        if(mkIn!=nullptr){
            auto source=UIControler::getWidget(UIControler::connectionSource->parent);

            appendLine(source,child,UIControler::connectionSource,mkIn);
            UIControler::connectionSource->establishConnection(*mkIn);
            UIControler::connectionSource=nullptr;
            UIControler::phase=normal;
            drawLines();
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
            //ovde treba da se konstruise odgovarajuci node
            auto node=new MKTestNode1_1();

            node->type=MainWindow::draggedNodeType;
            UIControler::addNode(newIcon, node);

            //switch(node->type)
            UIControler::thirdWin->setPlainText("this be node");
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
    drawLines();
}

void secondwindow::changeEvent(QEvent*)
{
    drawLines();
}

void secondwindow::focusInEvent(QFocusEvent*)
{
    drawLines();
}

void secondwindow::focusOutEvent(QFocusEvent*)
{
    drawLines();
}
















