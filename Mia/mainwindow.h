#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Control/control.h"
#include "QStringListModel"

#include "Control/statistic.h"

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

    void on_Auto_Start_Button_clicked();

private:
    // Verknüpfung zur GUI(ui) und Control
    Ui::MainWindow *ui;
    Control *mControl;

    void toggleRollCall();
    void setActivPlayer();
    void appendToLogView(QString s);

    //Zugriff auf die Einfache Statistisch basierte KI
    Statistic mStatisticKI;
};

#endif // MAINWINDOW_H
