#ifndef MKKNN_H
#define MKKNN_H

#include <QDialog>

namespace Ui {
class mkknn;
}

class mkknn : public QDialog
{
    Q_OBJECT

public:
    explicit mkknn(QWidget *parent = nullptr);
    ~mkknn();

private:
    Ui::mkknn *ui;
};

#endif // MKKNN_H
