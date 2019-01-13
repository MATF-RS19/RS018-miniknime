#ifndef MKKNN_H
#define MKKNN_H

#include <mknode.h>
#include <QDialog>

namespace Ui {
class MKKnn;
}

class MKKnn : public QDialog
{
    Q_OBJECT

public:
    explicit MKKnn(QWidget *parent = nullptr);
    ~MKKnn();
    MKNode* node=nullptr;


private slots:
    void on_connectButton_clicked();

private:
    Ui::MKKnn *ui;
};

#endif // MKKNN_H
