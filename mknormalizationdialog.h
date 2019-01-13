#ifndef MKNORMALIZATIONDIALOG_H
#define MKNORMALIZATIONDIALOG_H

#include <QDialog>

namespace Ui {
class mknormalizationdialog;
}

class mknormalizationdialog : public QDialog
{
    Q_OBJECT

public:
    explicit mknormalizationdialog(QWidget *parent = nullptr);
    ~mknormalizationdialog();

private:
    Ui::mknormalizationdialog *ui;
};

#endif // MKNORMALIZATIONDIALOG_H
