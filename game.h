#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "lane.h"
#include <vector>
#include <iostream>
#include <ncurses.h>
#include <unistd.h>

class Game {
    bool quit;
    int numLanes;
    int laneWidth;
    int score;
    Player* player;
    std::vector<Lane*> carMap;
public:
    Game(int w = 20, int h = 5);
    void draw();
    void input();
    void logic();
    void run();
    ~Game();
};

#endif