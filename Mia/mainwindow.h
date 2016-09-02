#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Control/control.h"
#include "QStringListModel"
#include "csvwriter.h"

#include "Control/ki.h"
#include "Control/statistic.h"
#include "Control/primitiveki.h"
#include "Control/svmki.h"

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
    CSVWriter* mCSVWriter;
    void toggleRollCall();
    void setActivPlayer();
    void appendToLogView(QString s);
    void learn(Value call, Value rand, Value last, bool startGame);

    //Speicherung der einzelnen KIs
    KI* mKIs[3];
    // Hier werden die verwendeten KIs erstellt, Momentan 3 mal die selbe

    /*
    Statistic KI_1;
    Statistic KI_2;
    Statistic KI_3;
    */

    /*
    PrimitiveKI KI_1;
    PrimitiveKI KI_2;
    PrimitiveKI KI_3;
    */


    SVMKI KI_1;
    SVMKI KI_2;
    SVMKI KI_3;

};

#endif // MAINWINDOW_H
