#include <iostream>
#include "game.h"
#include "player.h"
#include "lane.h"  



int main() {
    srand(time(0));
    Game game(30,10);
    game.run();

    // Game over functionality
    
    for (int i = 1; i < 4; i++)
        move(game.getNumLanes() + i,0);
        clrtoeol();
    mvaddstr(game.getNumLanes() + 1, 0, "Game Over! Press any key to exit");
    mvprintw(game.getNumLanes() + 3, 0, "Final Score: %d", game.getScore());
    refresh();
    usleep(1000000); // Debounce
    nodelay(stdscr,FALSE); //getch is blocking now
    getch();
    endwin();
    return 0;

}