#include <iostream>
#include "headers/Output.h"
#include <curses.h>

using namespace std;
using namespace dynengines;


int main(int, char **)
{    
    Output output;

    int i;
    cout << "Please enter an integer value: ";
    cin >> i;
    cout << "The value you entered is " << i;
    cout << " and its double is " << i*2 << ".\n";


    //output.renderVideo();
    //output.transformImage();
    output.renderImage();


    return 0;
}

