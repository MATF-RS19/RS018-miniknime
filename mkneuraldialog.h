#ifndef MKNEURALDIALOG_H
#define MKNEURALDIALOG_H

#include <QDialog>

namespace Ui {
class mkneuraldialog;
}

class mkneuraldialog : public QDialog
{
    Q_OBJECT

public:
    explicit mkneuraldialog(QWidget *parent = nullptr);
    ~mkneuraldialog();

private:
    Ui::mkneuraldialog *ui;
};

#endif // MKNEURALDIALOG_H
