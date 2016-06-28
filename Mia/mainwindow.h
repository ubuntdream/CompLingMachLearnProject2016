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

    void setPlayerValue();

private slots:
    void on_btn_RollDice_clicked();

    void on_btn_CallValue_clicked();

    void on_btn_ShowResult_clicked();

private:
    // Verknüpfung zur GUI(ui) und Control
    Ui::MainWindow *ui;
    Control *mControl;
    QStringListModel *model;

    void toggleRollCall();
    void setActivPlayer();
};

#endif // MAINWINDOW_H
