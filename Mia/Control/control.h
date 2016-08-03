#ifndef CONTROL_H
#define CONTROL_H

#include <ctime>
#include <cstdlib>

#include <vector>
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

public:
    Control(int anz);
    ~Control();

    Value getRandomValue();
    bool isNewGame() const;
    void setNewGame();
    Value getLastValue() const;
    Value getNewValue() const;
    Value getOnlyRandomValue()const;
    void setCallValue(int v);
    bool Call_is_correct(int v);
    Player GetPlayer(int i) const;
    int GetActivPlayerID() const;
    int GetLastPlayerID() ;
    void NextPlayer();
    void PreviousPlayer();
    QString look_at_last_Player();
};

#endif // CONTROL_H
