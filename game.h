#ifndef GAME_H
#define GAME_H

class Game {
    bool quit;
public:
    void draw();
    void input();
    void logic();
    void run();
};

#endif