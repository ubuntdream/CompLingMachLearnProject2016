#ifndef PLAYER_H
#define PLAYER_H


class Player
{
private:
    int mLifes, mWins;
public:
    Player();
    ~Player();
    int getLife() const;
    void looLife(int l);
    void setLife(int l);

    int getWin() const;
    void addWin();
    void resetWin();
};

#endif // PLAYER_H
