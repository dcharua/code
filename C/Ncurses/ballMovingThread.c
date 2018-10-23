#include <ncurses.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#define DELAY 30000
//struct for x and y
typedef struct position{
  int x;
  int y;
} coords_t;
//struct with x and y plus x and y max
typedef struct coords_struct{
  coords_t * pos;
  coords_t * limits;
} data_t;

void initSharedData(data_t ** shared_data);
void bounceBall(data_t * shared_data);
void * moveKeys(void * arg);

int main(int argc, char *argv[]) {
  // x y cordinates and max values
  data_t * shared_data = NULL;
  pthread_t pid;
  initSharedData(&shared_data);
  //Initialize window
  initscr();
  // Don't echo any keypresses
  noecho();
  // Don't display a cursor
  curs_set(FALSE);
  c_break();                  // Do not buffer inputs, but pass them immediately to be read. Do not react to signal inputs
  keypad(stdscr, TRUE);   // Allow reading special keys from the keyboard (Fx, and arrows)
  bounceBall(shared_data);
  pthread_create(&pid, NULL, moveKeys, (void*)shared_data);

  printw("Welcome - Press # to Exit\n");

  // Restore normal terminal behavior
  endwin();
}
void initSharedData(data_t ** shared_data){
  //malloc struct
  * shared_data = malloc(sizeof(data_t));
  //malloc data
  (*shared_data)->pos = malloc(sizeof(coords_t));
  (*shared_data)->limits = malloc(sizeof(coords_t));
  //init position
  (*shared_data)->pos->x=0;
  (*shared_data)->pos->y=0;

}

void bounceBall(data_t * shared_data){
  int next_x = 0;
  int direction = 1;
  while(1) {
    // function to gets the max dimensions of terminal
    getmaxyx(stdscr, shared_data->limits->y,  shared_data->limits->x);
    //clear the window
    clear();
    //print the curser in x and y
    mvprintw(shared_data->pos->y, shared_data->pos->x, "o");
    //print object
    refresh();
    //amount on time between movements
    usleep(DELAY);
    //calulate the next x based on the direccion varible
    next_x = shared_data->pos->x + direction;

    if (next_x >= shared_data->limits->x || next_x < 0) {
      direction*= -1;
    } else {
      shared_data->pos->x+= direction;
    }
  }
}

void * moveKeys(void * arg){
  data_t * shared_data = (data_t *) arg;

  int ch;
  while((ch = getch()) != '#') {
    clear();
    switch(ch){
      case KEY_UP:
        shared_data->pos->y--;
        break;
      case KEY_DOWN:
        shared_data->pos->y++;
        break;
      case KEY_LEFT:
        shared_data->pos->x--;
        break;
      case KEY_RIGHT:
        shared_data->pos->x++;
        break;
      default:
        printw("\nThe pressed key is ");
        attron(A_BOLD);             // Activate the attribute to when displaying characters
        printw("%c", ch);
        attroff(A_BOLD);
        break;
    }
    //print the curser in x and y
    mvprintw(shared_data->pos->y, shared_data->pos->x, "o");
    //print object
    refresh();
  }
  pthread_exit(NULL);
}
