#include "secondwindow.h"
#include "mainwindow.h"
#include "uicontroler.h"
#include "iostream"
#include "mknodespec.h"
#include "mkcsvreader.h"
#include "mkknndialog.h"
#include "mkknearestneighbor.h"
#include <mkpartition.h>
#include <QtWidgets>
#include <csvreaderdialog.h>
#include <mkdialog.h>
#include <mkneuraldialog.h>
#include <mknormalizationdialog.h>
#include <mkmlpregression.h>
#include <mknormalization.h>


#undef DEBUG

bool secondwindow::paintLine=false;

secondwindow::secondwindow(QWidget *parent)
    : QFrame(parent)
{
    setMinimumSize(400, 400);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);
}


//Function that depending on mouse button clicked either moves node or opens dialog
//for that specific node
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
            }
            else
            {
                auto node=UIControler::getNode(child);
                std::cout<<"graph node type: "<<node->type<<std::endl;
                if(node->type == "csvr")
                {
                    CsvReaderDialog dialog;
                    dialog.node = node;
                    dialog.setModal(true);
                    dialog.exec();

                    MKCSVReader *temp = new MKCSVReader();
                    temp->readFromCSV(dialog.on_browseButton_clicked());
                    temp->m_outputs[0].printData();
                }
                //Depending on type of node opens different dialog
                else if (node->type == "nn")
                {
                    mkneuraldialog dialog;
                    dialog.node = node;
                    dialog.setModal(true);
                    dialog.exec();

                    MKMLPRegression *temp = new MKMLPRegression();
                    std::vector<double> tmp = dialog.on_submitButton_clicked();
                    temp->trainNet(tmp[0], tmp[1], tmp[2], tmp[3], tmp[4], tmp[5]);

                }
                else if(node->type == "pn")
                {
                    MKDialog dialog;
                    dialog.node=node;
                    dialog.setModal(true);
                    dialog.exec();

                    MKPartition *temp = new MKPartition();
                    double tmp = dialog.on_submitButton_clicked();
                    temp->partition(tmp);
                    temp->m_outputs[0].printData();

                }
                else if(node->type == "norm")
                {
                    mknormalizationdialog dialog;
                    dialog.node = node;
                    dialog.setModal(true);
                    dialog.exec();

                    MKNormalization *temp = new MKNormalization();
                    temp->process_data();
                }
                else if(node->type == "knn")
                {
                    mkknndialog dialog;
                    dialog.node = node;
                    dialog.setModal(true);
                    dialog.exec();

                    MKKNearestNeighbor *temp = new MKKNearestNeighbor();
                    std::vector<double> tmp = dialog.on_submitButton_clicked();
                    temp->classify(tmp[0], tmp[1], tmp[2], tmp[3]);
                }
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

//Function that enables draging of node
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
//Function that moves node from one window to another
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

//Function that enables nodes to be dragged into this window and displays text into third window
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


             if(node->type == "knn")
             {
                    UIControler::thirdWin->setPlainText("KNN algorithm. It is algorithm for classifying. An object is classified by a plurality vote of its neighbors, "
                                                        "with the object being assigned "
                                                        "to the class most common among its k nearest neighbors "
                                                        "(k is a positive integer, typically small). If k = 1, then the object is simply assigned to the "
                                                        "class of that single nearest neighbor.");
             }
             else if (node->type == "norm")
             {
                 UIControler::thirdWin->setPlainText("Normalization of values measured on different scales to a notionally common scale, often prior to averaging.");
             }
             else if(node->type == "pn")
             {
                 UIControler::thirdWin->setPlainText("Partioning of the input data onto test and training data in given ratio.");
             }
             else if(node->type == "csvr")
             {
                 UIControler::thirdWin->setPlainText("Reading data values from a csv file.");
             }
             else if (node->type == "nn")
             {
                 UIControler::thirdWin->setPlainText("Multi-layer Perceptron (MLP) is a supervised learning algorithm that learns a function f(): R^m -> R^o by training on a dataset,"
                                                     " where m is the number of dimensions for input and o is the number of dimensions for output. Given a set of features and a target ,"
                                                     " it can learn a non-linear function approximator for either classification or regression");
             }


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

//Drawing line between connected nodes
void secondwindow::changeEvent(QEvent*)
{
    drawLines();
}

//Drawing line between connected nodes
void secondwindow::focusInEvent(QFocusEvent*)
{
    drawLines();
}

//Drawing line between connected nodes
void secondwindow::focusOutEvent(QFocusEvent*)
{
    drawLines();
}
















