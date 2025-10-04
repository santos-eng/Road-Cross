#ifndef PLAYER_H
#define PLAYER_H
#include <utility>

class Player { 
    int x, y;
public:
    Player(int width);
    int getX();
    int getY();
    void setPos(int x, int y);

};


#endif