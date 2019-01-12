#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFrame>

QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE

class MainWindow : public QFrame
{
public:
    MainWindow(QWidget *parent = nullptr);
    static std::string draggedNodeType;

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // MAINWINDOW_H
