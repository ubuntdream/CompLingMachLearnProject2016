#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Control/control.h"
#include "QStringListModel"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_RollDice_clicked();

    void on_btn_CallValue_clicked();

private:
    Ui::MainWindow *ui;
    Control *mControl;
    QStringListModel *model;
    void toggleRollCall();
    void setPlayerValue();
    void setActivPlayer();
};

#endif // MAINWINDOW_H
