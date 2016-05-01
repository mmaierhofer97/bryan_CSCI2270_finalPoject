#include <iostream>
#include <stdlib.h>
#include "BSMap.h"

using namespace std;

int main()
{
    bool start=false;
    string response="";
    int choice=0;
    cout<<"You begin your quest for fame and fortune!"<<endl;
    cout<<"You heard rumor of treasure and glory to be found in the dungeons"<<endl;
    cout<<"You grab your family gear and set out"<<endl;
    cout<<"=============================================="<<endl;
    cout<<"Enter 1 to begin your adventure!"<<endl;

    getline(cin,response);
    if(response=="1")
        start=true;
    else
        cout<<"Game has been quit! No adventure started!"<<endl;

    BSMap *world=new BSMap();//start new character here / set world map / set dungeon layout
    while(start)
    {
        cout<<"You are resting. What would you like to do next?"<<endl;
        cout<<"1. Go to a dungeon"<<endl;
        cout<<"2. Look at map"<<endl;
        cout<<"3. Quit the game"<<endl;

        getline(cin,response);
        choice=atoi(response.c_str());

        switch(choice)
        {
            case 1:
                world->moveChar();
                break;
            case 2:
                world->printMap();
                break;
            case 3:
                start=false;
                cout<<"Game has been turned off! Restart the program if you want to play again!"<<endl;
                break;
            default:
                cout<<"Not a valid selection! Please enter a number from the list provided"<<endl;
                break;
        }
         if(world->player->hp<=0)
         {
            start=false;
            cout<<"You have died! Game Over"<<endl;
         }

    }
    return 0;
}
