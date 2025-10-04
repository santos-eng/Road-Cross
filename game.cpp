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
    clear();
    for (int i = 0; i < numLanes; i++) {
        for (int j = 0; j < laneWidth; j++) {
            if (map[i]->checkPos(j) && i != 0 && i != numLanes - 1)
                mvaddch(i,j,'#');
            else if (player->getX() == j && player->getY() == i)
                mvaddch(i,j,'V');
            else 
                mvaddch(i,j,' ');
        }
    }
    mvaddstr(numLanes+1,0,"test");
    refresh();
}

void Game::input() {
    int c = (char)tolower(getch());
    switch (c) {
        case 'a':
        case KEY_LEFT:
            if (player->getX())
            break;
    }

}

void Game::logic() {

}

void Game::run() {
    initscr(); // Start ncurses
    cbreak(); // disable buffer, emptied with enter
    noecho(); // avoid printing to screen
    curs_set(0); // hide cursor
    keypad(stdscr, TRUE); // enable arrow keys
    nodelay(stdscr, TRUE); //avoid getch blocking
    while (!quit) {
        input();
        draw();
        logic();
        napms(50);
    }

}

Game::~Game() {
    endwin();
}

