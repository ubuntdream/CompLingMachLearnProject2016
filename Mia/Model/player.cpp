#include "player.h"

Player::Player()
{
 mLifes = 10;
 mWins = 0;
}

Player::~Player()
{

}

int Player::getLife() const{
    return mLifes;
}
void Player::setLife(int l){
    mLifes = l;
}
void Player::looLife(int l){
    mLifes -= l;
}

int Player::getWin() const{
    return mWins;
}
void Player::resetWin(){
    mWins = 0;
}
void Player::addWin(){
    mWins++;
}
