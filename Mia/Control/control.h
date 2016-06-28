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
    Value mlastValue;
    Value mRandomValue;
    Value mNewValue;
    bool mStartGame;
    std::vector<Player> mPlayers;
    Ui::MainWindow *mGUI;
    int mActivPlayerID;
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
