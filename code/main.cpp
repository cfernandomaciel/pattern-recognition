#include <iostream>
#include "headers/Output.h"
#include <curses.h>

using namespace std;
using namespace dynengines;


int main(int argc, char* argv[])
{    
    int ch;

    initscr();

    raw();
    keypad(stdscr, TRUE);
    noecho();

    if(argc < 2) {
        printw("{ result: \"error\", message: \"no parameters provided. please, input image src and image dst\" };");
        return 0;
    }

    ch = getch();

    /*
    if(ch == KEY_F(1))
        printw("F1 Key pressed");

   else {
       printw("The pressed key is ");
       attron(A_BOLD);
       printw("%c", ch);
       attroff(A_BOLD);
   }*/

    Output output;
    //output.renderVideo();
    output.transformImage(argv[0], argv[1]);
    //output.renderImage();

    refresh();
    getch();
    endwin();




    return 0;
}

