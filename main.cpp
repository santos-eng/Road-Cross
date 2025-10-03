#include <iostream>

class Player {
    int x, y;
    
public:
    Player(int width) {
        //Player begins in the top middle of the map
        x = width / 2;
        y = 0;
    }
};

class Lane {
    
};

class Game {
    bool quit;
public:
    void Draw() {

    }

    void Input() {

    }

    void Logic() {

    }

    void Run() {
        while (!quit) {
            Input();
            Draw();
            Logic();
        }

    }
};
