#include <iostream>
#include "headers/Output.h"
#include <curses.h>

using namespace std;
using namespace dynengines;


int main(int, char **)
{    
    int ch;


//    initscr();

//    raw();
//    keypad(stdscr, TRUE);
//    noecho();


//    printw("Type any character to see it in bold\n");
//    ch = getch();
//    if(ch == KEY_F(1))
//        printw("F1 Key pressed");

//   else {
//       printw("The pressed key is ");
//       attron(A_BOLD);
//       printw("%c", ch);
//       attroff(A_BOLD);
//   }

//    refresh();
//    getch();
//    endwin();


    Output output;


    //output.renderVideo();
    //output.transformImage();
    output.renderImage();


    return 0;
}

