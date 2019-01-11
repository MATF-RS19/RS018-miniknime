#ifndef MKDROPDOWN_H
#define MKDROPDOWN_H

#include <QDialog>

namespace Ui {
class MKDropDown;
}

class MKDropDown : public QDialog
{
    Q_OBJECT

public:
    explicit MKDropDown(QWidget *parent = nullptr);
    ~MKDropDown();

private:
    Ui::MKDropDown *ui;
};

#endif // MKDROPDOWN_H
