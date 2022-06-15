#include <iostream>
#include <time.h>
#include <vector>
#include <conio.h>
#include <string>
#include <Windows.h>
#include <ctime>

using namespace std;

#include "ElGato.h"
#include "Ahorcado.h"
#include "A2048.h"
#include "Character.h"

//maze game in console

bool keys[4] = {0,0,0,0};

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

// S: Start
// #: Wall
// .: Space
// F: Finish
// P: Player



const char maze[17][17]={{'#','#','#','#','#','#','n','#','#','#','#','#','#','#','R','#','#'},
                       {'#','#','.','#','#','#','.','#','#','#','.','#','.','#','.','#','#'},
                       {'#','#','.','#','.','.','.','#','.','#','.','#','.','#','.','#','#'},
                       {'#','.','.','.','.','#','#','#','.','.','.','.','.','#','.','.','#'},
                       {'#','#','.','#','.','.','.','#','.','#','.','#','#','#','#','.','#'},
                       {'#','.','.','.','.','#','.','.','.','.','.','.','.','#','.','.','#'},
                       {'#','.','#','.','.','#','#','#','.','#','#','#','#','#','.','#','#'},
                       {'#','.','#','#','.','.','#','.','.','.','#','.','.','.','.','#','#'},
                       {'#','.','.','#','#','.','.','.','.','.','.','.','#','#','#','#','#'},
                       {'#','#','.','.','#','.','#','.','.','.','#','.','.','#','.','#','#'},
                       {'#','.','.','.','#','.','.','#','.','#','.','.','.','.','.','#','#'},
                       {'#','.','#','.','.','.','#','#','.','.','.','#','#','.','.','.','#'},
                       {'#','.','#','#','#','.','.','.','.','#','.','.','.','.','#','.','#'},
                       {'#','#','#','.','.','.','.','#','.','#','.','#','#','.','#','.','#'},
                       {'#','.','.','.','#','#','.','#','.','.','.','#','.','.','.','.','#'},
                       {'C','.','#','.','.','#','.','#','.','#','.','#','#','#','.','#','#'},
                       {'#','#','#','#','#','#','#','#','F','#','#','#','#','#','#','#','#'}};

void Clear(){
    system("CLS");//clear console
}
void InputHandle(int move, int &pX, int &pY){
    switch(move=getch()){
            case KEY_UP:
            if( pY-1 >= 0 ){
                if(maze[pY-1][pX] != '#'){//if it is not the limit or it is not the wall(#) move player 
                pY--;
            }
        }
        break;

        case KEY_DOWN:
        if( pY+1 <= 16 ){
            if(maze[pY+1][pX] != '#'){
                pY++;
            }
        }
        break;

        case KEY_RIGHT:
        if( pX+1 <= 16 ){
            if(maze[pY][pX+1] != '#'){
                pX++;
            }
        }
        break;

        case KEY_LEFT:
            if( pX-1 >= 0 ){
            if(maze[pY][pX-1] != '#'){
                pX--;
            }
        }
}
}
void Display(int &pX, int &pY){
for(int i=0;i<17;i++){
    for(int j=0;j<17;j++){
        if(j==pX && i==pY){//instead of the maze char, put player's 'P' 
            std::cout<<"P ";
            continue;
        }
        std::cout<<maze[i][j]<<" ";
    }
    std::cout<<"\n";
}
}
bool CheckWinCondition(int &pX, int &pY){
if(pX==8 && pY ==16){
    return true;
}
else if (pX == 6 && pY == 0)   
{
    return true;
}
else if (pX == 14 && pY == 0)
{
    return true;
}
else if (pX == 0 && pY == 15)
{
    return true;
}


return false;
}


int main(){



//movement
Ahorcado hangedMan;
A2048 _A2048;
system("cls");
int playerPosX=8;
int playerPosY=8;
int movement;

while(!CheckWinCondition(playerPosX,playerPosY)){//if player is not in the finish, loop 
    Display(playerPosX, playerPosY);//Show current maze
    InputHandle(movement, playerPosX, playerPosY);//take input
    Clear();//Clear the screen
}

if (playerPosX == 8 && playerPosY == 16){
    if (keys[1]  == 0|| keys[2] == 0)
    {
        cout << "Necesitas terminar todos los niveles antes de entrar! >:c" << endl<<endl;
        cout << "Presiona cualquier tecla para continuar...";
        getch();
        system("cls");
        main();
    }
}
else if (playerPosX == 6 && playerPosY == 0)
{
    if (keys[1] == 0){
        if (hangedMan.mainHd() == 1){
            keys[1] = true;
            main();
        }
        else{
            keys[1] = false;
            main();
        }
    }
    else if(keys[1] == 1)
    {
        cout << "Ya has completado este desafio, aun te esperan un par!"<<endl<<endl;
        cout << "Presiona cualquier tecla para continuar...";
        getch();
        system("cls");
        main();
    }
}
else if (playerPosX == 14 && playerPosY == 0)
{
    if (keys[2] == 0){
        if (_A2048.mainA() == 1){
            keys[2] = true;
            system("pause");
            main();
        }
        else{
            keys[2] = false;
            main();
        }
    }
    else if(keys[2] == 1)
    {
        cout << "Ya has completado este desafio, aun te esperan un par!"<<endl<<endl;
        cout << "Presiona cualquier tecla para continuar...";
        getch();
        system("cls");
        main();
    }
}
else if (playerPosX == 0 && playerPosY == 15)
{
    std::cout << "BEMBEÑIDO AU CASTILLO!"<< std::endl;
}
 


}