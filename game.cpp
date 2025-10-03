#include "game.h"

Game::Game(int w, int h) {
        laneWidth = w;
        numLanes = h;
        quit = false;
        for (int i = 0; i < numLanes; i++)
            map.push_back(new Lane(laneWidth));
        player = new Player(laneWidth);
    }

void Game::draw() {
    //Clear the current screen
    system("clear");
    for (int i = 0; i < numLanes; i++) {
        for (int j = 0; j < laneWidth; j++) {
            if (map[i]->checkPos(j) && i != 0 && i != numLanes - 1)
                std::cout << "#";
            else if (player->x == j && player->y == i)
                std::cout << "V";
            else 
                std::cout << " ";
        }
        std::cout << std::endl;
    }
}

void Game::input() {

}

void Game::logic() {

}

void Game::run() {
    while (!quit) {
        input();
        draw();
        logic();
    }

}