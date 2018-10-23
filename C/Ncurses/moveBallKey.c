#include <ncurses.h>
#include <unistd.h>

#define DELAY 30000

int main(int argc, char *argv[]) {
  // x y cordinates and max avlues
  int ch;
  int x = 0, y = 0;
  int max_y = 0, max_x = 0;
  int next_x = 0;
  int direction = 1;
  //Initialize window
  initscr();
  // Don't echo any keypresses
  noecho();
  // Don't display a cursor
  curs_set(FALSE);
  raw();                  // Do not buffer inputs, but pass them immediately to be read. Do not react to signal inputs
  keypad(stdscr, TRUE);   // Allow reading special keys from the keyboard (Fx, and arrows)

  printw("Welcome - Press # to Exit\n");
  while((ch = getch()) != '#') {
    // function to gets the max dimensions of terminal
    getmaxyx(stdscr, max_y, max_x);
    //clear the window
    clear();
    switch(ch){
      case KEY_UP:
        y--;
        break;
      case KEY_DOWN:
        y++;
        break;
      case KEY_LEFT:
        x--;
        break;
      case KEY_RIGHT:
        x++;
        break;
      default:
        printw("\nThe pressed key is ");
        attron(A_BOLD);             // Activate the attribute to when displaying characters
        printw("%c", ch);
        attroff(A_BOLD);
        break;
    }
    //print the curser in x and y
    mvprintw(y, x, "o");
    //print object
    refresh();
  }
  // Restore normal terminal behavior
  endwin();
}
