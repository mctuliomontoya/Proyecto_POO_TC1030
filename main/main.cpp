#include <iostream>
#include <time.h>
#include <vector>
#include <conio.h>
#include <string>
#include <Windows.h>
#include <ctime>
#include <io.h>
#include <fcntl.h>
#include <cstdlib>
#include <fstream>
#include <sstream> 

using namespace std;
#include "dialogue.h"
#include "ElGato.h"
#include "Ahorcado.h"
#include "PPT.h"
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




void mnerv(){
Ahorcado hangedMan;
A2048 _A2048;
ElGato gatoGame;
PPT _PPT;
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
    if (keys[1]  == 0|| keys[2] == 0 || keys[3] == 0)
    {
        cout << "Hay una puerta gigante en frente de ti, parece muy rigida" << endl;
        getch();
        cout << "Sera mejor dar media vuelta e irte" << endl;
        cout << "Presiona cualquier tecla para continuar...";
        getch();
        system("cls");
        mnerv();
    }
    else if (keys[1]  == 1 && keys[2] == 1 && keys[3] == 1)
    {
        if (_PPT.mainS() == 1){
            keys[0] = true;
            getch();
            system("cls");
            cout << "El altavoz suena de fondo:";
            getch();
            cout << "\n   * Asi que lo hiciste, heroe, venciste a los 4 reyes*";
            getch();
            cout << "\n   *Crei que este dia jamas llegaria, SOMOS LIBRES!";
            getch();
            cout << "\n\n Se escuchan gritos de alegria por todo el laberinto, gente agradecida por tus logros";
            getch();
            system("cls");
            system("Color 0A");
            cout << "\n-----------------------------------------------";
            cout <<"\n[      FELICIDADES, HAS COMPLETADO EL JUEGO!   ]";
            cout << "\n-----------------------------------------------";
            

        }
        else{
            keys[0] = false;
            cout << "Has perdido, pero no te rindas, aun tienes otra oportunidad.";
            getch();
            mnerv();
        }
    }
    
}
else if (playerPosX == 6 && playerPosY == 0)
{
    if (keys[1] == 0){
        if (hangedMan.mainHd() == 1){
            keys[1] = true;
            mnerv();
        }
        else{
            keys[1] = false;
            mnerv();
        }
    }
    else if(keys[1] == 1)
    {
        cout << "La cueva que antes estaba en esta area se ha derrumbado, parece que no hay paso."<<endl<<endl;
        cout << "Presiona cualquier tecla para continuar...";
        getch();
        system("cls");
    }
}
else if (playerPosX == 14 && playerPosY == 0)
{
    if (keys[2] == 0){
        if (_A2048.mainB() == 1){
            keys[2] = true;
            system("pause");
            dialogue();
            mnerv();
        }
        else{
            keys[2] = false;
            mnerv();
        }
    }
    else if(keys[2] == 1)
    {
        cout << "El laboratorio esta totalmente destruido!"<<endl<<endl;
        cout << "Presiona cualquier tecla para continuar...";
        getch();
        system("cls");
        mnerv();
    }
}
else if (playerPosX == 0 && playerPosY == 15)
{
if (keys[3] == 0){
    if (gatoGame.mainY() == 1){
        keys[3] = true;
        getch();
        system("cls");
        cout<<"QUEE!???"<<endl;
        getch();
        cout<<"\n...";
        getch();
        system("cls");
        cout<<"\n ~ No puede ser cierto, yo? perder?";
        getch();
        cout << "\n ~ Agh!!, supongo que el dia iba a llegar, pero no crei que tan pronto";
        getch();
        cout <<"\n ~ Esta bien! te la mereces...";
        getch();
        system("cls");
        cout << "El gran y robusto caballero te entrega una llave de plata, con detalles rojos";
        getch();
        cout << "\n Agarras la llave que estiraba el Caballero y entras por un portal";
        getch();
        cout << "\n  ~ Parece que va al incio del laberinto";
        getch();
        cout << "\n ...";
        getch(); 
        mnerv();
    }
    else{
        keys[3] = false;
        cout<<"Has perdido!, necesitas volver a intentarlo!"<<endl;
        getch();
        mnerv();
    }
    }
    else if(keys[3] == 1)
    {
        cout << "Donde estaba el gran castillo no quedan mas que ruinas..."<<endl<<endl;
        cout << "Presiona cualquier tecla para continuar...";
        getch();
        system("cls");
        mnerv();
    }
}
 


}
int main(){

setmode(_fileno(stdout), _O_U16TEXT);

system("cls");
/*
    Dialogo principal
*/

wcout << L"Te despiertas, lo primero ves es un cielo azulado";
getch();
system("cls");
wcout << L"Te llega a la mente un pensamiento ¿cómo llegue aqui?";
getch();
system("cls");
wcout << L"Te levantas y ves unas paredes enormes con varios caminos,";
getch();
wcout << L"\n ~ Oh, ¿qué es esto? un laberinto?" <<endl;
getch();
wcout << L" ~ Lo último que recuerdo es estar cayendo desde un edificio..."<<endl;
getch();
system("cls");
wcout << L"De pronto se esucha estática de fondo," << endl;
getch();
wcout << L"No, no era simple estática.";
getch();
system("cls");
wcout << L"desde un altavoz lejano se esucha:";
getch();
wcout << L"\n  ~ Bienvenido, héroe, pasaron muchos a\u00F1os desde que un extranjero piso las tierras de DOur";
getch();
wcout << L"\n  ~En estas tierras hace años que se dejó de pelear con armas convencionales, desde que el gran rey se encerró en su mazmorra";
getch(); 
wcout << L"\n ...";
getch();
wcout << L"\n  ~Se que es extra\u00F1o, pero necesitas salvarnos, solo asi podras regresar a tu hogar";
getch();
system("cls");
wcout << L"...";
getch();
system("cls");
wcout << L"  ~ Te explico, hay 4 reyes malignos que desean llevarnos a la ruina, para que puedas ser libre necesitas derrotarlos a todos";
getch();
wcout << L"\n  ~ Hay uno en la cueva al norte de aquí, dicen que es muy hábil con las palabras, pero tambien le gusta torturar a sus víctimas";
getch();
wcout << L"\n  ~ Cerca de el, al noreste, se encuentra el segundo de ellos, un hábil matemático que después de encerrarse en su laboratorio, se volvió loco";
getch();
wcout << L"\n  ~ El tercero, al suroeste de aqui, es un antiguo caballero, muy fuerte pero tambien un poco tonto, por lo que será pan comido";
getch();
wcout << L"\n  ~ Por último, el mas fuerte de ellos, el gran rey, desconozco su estilo de batalla ya que hace años que se encerró, pero de seguro es muy duro";
getch();
system("cls");
wcout << L" ~ Por favor, ayudanos";
getch();
system("cls");
wcout << L"¿Aceptar misión?   -   [Y/n] ";
_setmode(_fileno(stdout),_O_TEXT);

string opc;
cin >> opc;

if (opc == "Y" || opc == "y")
{
    setmode(_fileno(stdout), _O_U16TEXT);
    wcout << L" \n  ~ Muchas gracias, héroe, que la bendición de los 4 grandes te acompañe";
    getch();
    system("cls");
    wcout << L" !La gran aventura comienza! ";
    getch();
    _setmode(_fileno(stdout),_O_TEXT);
    mnerv();
}
else if (opc == "N" || opc == "n")
{
    setmode(_fileno(stdout), _O_U16TEXT);
    wcout << L"\n !Muchas Gracias por su atención!";
    getch();
    wcout << L"\n Código hecho por: ";
    wcout << L"\n Ángel Marín - A00835132";
    wcout << L"\n Marco Montoya - A01254155";
    getch();
    setmode(_fileno(stdout), _O_TEXT);
    system ("cls");
    system("Color 0A");
    cout << "\n-----------------------------------------------";
    cout <<"\n[      FELICIDADES, HAS COMPLETADO EL JUEGO!   ]";
    cout << "\n-----------------------------------------------";
    

}


}
