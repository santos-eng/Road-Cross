#include "game.h"

void Game::draw() {

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