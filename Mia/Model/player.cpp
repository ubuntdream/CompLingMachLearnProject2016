#include "player.h"

// Defauld Startwert
Player::Player()
{
 mLifes = 10;
 mWins = 0;
}

Player::~Player()
{

}
// Gibt die Aktuellen Leben unverändert zurück
int Player::getLife() const{
    return mLifes;
}
// Setzt die Leben auf den Wert l
void Player::setLife(int l){
    mLifes = l;
}
// Die akltuellen Leben des Spielers werden um l verringert
void Player::looLife(int l){
    mLifes -= l;
}

// Gibt die Aktuellen anzahl der Siege unverändert zurück
int Player::getWin() const{
    return mWins;
}
// Setzt die Anzahl der Siege auf Null
void Player::resetWin(){
    mWins = 0;
}
// Erhöht die Anzahl der Siege um Eins
void Player::addWin(){
    mWins++;
}
