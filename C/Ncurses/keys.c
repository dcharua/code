/*
    Example from:
    https://www.linuxquestions.org/questions/programming-9/detecting-arrow-key-presses-in-c-c-166055/
*/

#include<ncurses.h>

int main()
{
    int ch;

    /* Curses Initialisations */
    initscr();
    raw();                  // Do not buffer inputs, but pass them immediately to be read. Do not react to signal inputs
    keypad(stdscr, TRUE);   // Allow reading special keys from the keyboard (Fx, and arrows)
    noecho();               // Do not show on the terminal the keys pressed

    printw("Welcome - Press # to Exit\n");

    while((ch = getch()) != '#')
    {
        switch(ch)
        {
            case KEY_UP:
                printw("\nUp Arrow");
                break;
            case KEY_DOWN:
                printw("\nDown Arrow");
                break;
            case KEY_LEFT:
                printw("\nLeft Arrow");
                break;
            case KEY_RIGHT:
                printw("\nRight Arrow");
                break;
            default:
                printw("\nThe pressed key is ");
                attron(A_BOLD);             // Activate the attribute to when displaying characters
                printw("%c", ch);
                attroff(A_BOLD);
                break;
        }
    }

    printw("\n\nBye Now!\n");

    refresh();          // Show on the terminal anything printed on the window
    getch();            // Wait for a final key press before finishing the program
    endwin();

    return 0;
}
