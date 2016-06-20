#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Control/control.h"

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
    void on_rolldice_clicked();

    void on_callButton_clicked();

private:
    Ui::MainWindow *ui;
    Control mControl;
};

#endif // MAINWINDOW_H
