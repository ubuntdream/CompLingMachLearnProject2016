#ifndef CONTROL_H
#define CONTROL_H

#include <ctime>
#include <cstdlib>

#include <vector>
#include <ui_mainwindow.h>
#include <QDebug>

#include "Model/value.h"
#include "Model/player.h"

class Control
{
private:
    int rollDice();

    // Speicherung der letzten Ansage
    Value mlastValue;
    //Speicherung des aktuel gewürfelte Wert
    Value mRandomValue;
    // Speichung der atuellen Ansage
    Value mNewValue;
    // Gibt an, ob die Spielrunde neu gestartet wurde
    bool mStartGame;
    //Speichung aller Spieler
    std::vector<Player> mPlayers;
    // Speicherung der ID, welcher Spieler aktuell an der Reihe ist
    int mActivPlayerID;
    // Verknüpfung zur GUI
    Ui::MainWindow *mGUI;

public:
    Control(int anz);
    ~Control();

    Value getRandomValue();
    bool isNewGame() const;
    Value getLastValue() const;
    void setCallValue(int v);
    bool Call_is_correct(int v);
    Player GetPlayer(int i) const;
    int GetActivPlayerID() const;
    void NextPlayer();
};

#endif // CONTROL_H
