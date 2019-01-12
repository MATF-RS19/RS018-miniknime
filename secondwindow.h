#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QFrame>

QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE

class MKNode;

class secondwindow : public QFrame
{
public:
    secondwindow(QWidget *parent = nullptr);

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

    MKNode* currentlyDraggedNode=nullptr;

};

#endif // SECONDWINDOW_H
