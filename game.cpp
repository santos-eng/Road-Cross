#include "game.h"

Game::Game(int w, int h) {
        laneWidth = w;
        numLanes = h;
        quit = false;
        for (int i = 0; i < numLanes; i++)
            carMap.push_back(new Lane(laneWidth));
        player = new Player(laneWidth);
    }

void Game::draw() {
    //Clear the current screen
    clear();
    for (int i = 0; i < numLanes; i++) {
        mvaddch(i,0,'>');
        for (int j = 1; j <= laneWidth; j++) {
            if (carMap[i]->checkPos(j) && i != 0 && i != numLanes - 1)
                mvaddch(i,j,'#');
            else if (player->getX() == j && player->getY() == i)
                mvaddch(i,j,'V');
            else 
                mvaddch(i,j,' ');
        }
        mvaddch(i,laneWidth + 1,'<');
    }
    mvaddstr(numLanes+1,0,"Move with WASD or arrows, q to quit");
    refresh();
}

void Game::input() {
    int c = getch();
    if (c == ERR) return; //No inpurt
    int x = player->getX();
    int y = player->getY();

    switch (c) {
        case 'a':
        case KEY_LEFT:
            if (x > 1) player->setPos(--x,y);
            break;
        case 'd':
        case KEY_RIGHT:
            if (x < laneWidth) player->setPos(++x,y);
            break;
        case 'w':
        case KEY_UP:
            if (y > 0) player->setPos(x,--y);
            break;
        case 's':
        case KEY_DOWN:
            if (y < numLanes - 1) player->setPos(x,++y);
            break;
        case 'q':
            quit = true;
            break;
    }
}

void Game::logic() {
    for (int i = 1; i < numLanes - 1; i++) {
        if (rand() % 10 == 1) {
            carMap[i]->drive();
        } 
        if (carMap[i]->checkPos(player->getX()) && i == player->getY())
            quit = true;
    }
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
        usleep(16667);
    }

}

Game::~Game() {
    endwin();
}

