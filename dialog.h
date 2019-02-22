#ifndef DIALOG_H
#define DIALOG_H
#include"util.h"
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    THREAD_DATA threadData;
    HANDLE Thread_fly;
    HANDLE Thread_down;
    HANDLE Thread_recoil;
    HANDLE Thread_blood;
    HANDLE Thread_bullet;
    ~Dialog();
private slots:
    void on_checkBox_clicked(bool checked);

    void on_checkBox_2_clicked(bool checked);

    void on_checkBox_3_clicked(bool checked);

    void on_checkBox_4_clicked(bool checked);

    void on_checkBox_5_clicked(bool checked);

    void on_checkBox_6_clicked(bool checked);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
