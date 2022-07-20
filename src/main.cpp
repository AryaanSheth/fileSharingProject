// #include <experimental/filesystem> // this works if your on an older version
#include "../include/easyFiles.h"
#include "../include/easyScreens.h"
#include <string>
#include <vector>
#include <ncurses.h>
#include <iostream>

using namespace std;


void host(int, int);
void receive();




int main()
{
    initscr();
    cbreak();
    noecho();
    curs_set(0);


    int yMax, xMax;

    getmaxyx(stdscr, yMax, xMax);

    easyScreen firstWindow(10, 20, 3, 5);

    
    if (firstWindow.displayMenu({"Host", "Receive"}) == 0){
        firstWindow.hideWindow();
        host(yMax, xMax);
    }
    else{
        firstWindow.hideWindow();
        receive();
    }
    

    // getch();
    endwin();

    return 0;
}



void host(int y, int x){

    easyScreen secondWindow(y-2, x/2, 1, 1, true);
    easyFiles currentPath;

    std::vector<std::string> temp = currentPath.getCurrentPaths();
    // int pathInt = secondWindow.displayMenu(temp);
    int pathInt;


    secondWindow.topDirectoryBarDraw(currentPath.returnCurrentPath());
    while (true){

        temp = currentPath.getCurrentPaths();
        

        


        pathInt = secondWindow.displayMenu(temp);


        if (pathInt == 0){
            currentPath.moveDownDir();
            secondWindow.topDirectoryBarDraw(currentPath.returnCurrentPath());
        } else{
            currentPath.moveUpDir(temp.at(pathInt)); // TODO: get moving between files work
        }

        

    }

    // secondWindow.hideWindow();


}

void receive(){

}