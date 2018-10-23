#include <ncurses.h>
#include <unistd.h>

#define DELAY 30000

int main(int argc, char *argv[]) {
  // x y cordinates and max avlues
  int x = 0, y = 0;
  int max_y = 0, max_x = 0;
  int next_x = 0;
  int direction = 1;
  //Initialize window
  initscr();
  // Don't echo any keypresses in terminal
  noecho();
  // Don't display a cursor
  curs_set(FALSE);


  while(1) {
    // function to gets the max dimensions of terminal
    getmaxyx(stdscr, max_y, max_x);
    //clear the window
    clear();
    //put the object curser in x and y
    mvprintw(y, x, "o");
    //print the object
    refresh();
    //amount on time between movements
    usleep(DELAY);
    //calulate the next x based on the direccion varible
    next_x = x + direction;

    //change direction if the corner is reached
    if (next_x >= max_x || next_x < 0) {
      direction*= -1;
    } else {
      x+= direction;
    }
  }
  // Restore normal terminal behavior
  endwin();
}
