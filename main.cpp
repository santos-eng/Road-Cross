#include <iostream>
#include "game.h"
#include "player.h"
#include "lane.h"  



int main() {
    srand(time(0));
    Game game(30,5);
    game.run();

    // Game over functionality
    mvaddstr(game.getNumLanes() + 3, 0, "Game Over! Press any key to exit");
    nodelay(stdscr,FALSE); //getch is blocking now
    getch();
    endwin();
    return 0;

}