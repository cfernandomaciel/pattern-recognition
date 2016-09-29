#include <iostream>
#include "headers/Output.h"
#include <curses.h>
#include <string.h>

using namespace std;
using namespace dynengines;


int main(int argc, char* argv[])
{    
    /*int ch;

    initscr();

    raw();
    keypad(stdscr, TRUE);
    noecho();*/

    if(argc < 2)
    {
        printw("{ result: \"error\", message: \"no parameters provided. please, input image src and image dst\" };");
    }



    //ch = getch();

    Output output;
    //output.renderVideo();
    output.transformImage(argv[1], argv[2]);
    //output.renderImage();

    /*refresh();
    getch();
    endwin();*/




    return 0;
}

