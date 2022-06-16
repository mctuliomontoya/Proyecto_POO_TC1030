#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream> 
using namespace std;


int main (void){
    string opcion;
    int IA = 0;
    int Heroe = 0;
    string strInput;
    string cadena;
    stringstream ss;
    int ganadas = 0;
    int perdidas = 0;

    while(true){
        srand ((unsigned) time (NULL));
        cout << "Aventurero, elige sabiamente." << endl;
        cout << "\t1.- Piedra" << endl;
        cout << "\t2.- Papel" << endl;
        cout << "\t3.- Tijera" << endl;
        cout << "\t: ";

        do {
            cin >> Heroe;
            if (Heroe<1||Heroe>3)
            {
                cout << "Valor incorrecto. Intenta de nuevo: ";
            }
        } while (Heroe<1||Heroe>3);

        IA=1+rand()%3;

        if(IA==1)
            cout << "El Gran Rey utilizo Piedra" << endl;
        if(IA==2)
            cout << "El Gran Rey utilizo Papel" << endl;
        if(IA==3)
            cout << "El Gran Rey utilizo Tijera" << endl;

        if(Heroe==IA){
            cout << "Empate" << endl;
            if(Heroe = 1){
                opcion = "1piedra_piedra.txt";
            }
            else if (Heroe = 2){
                opcion = "1papel_papel.txt";
            }
            else{
                opcion = "1tijeras_tijeras.txt";
            }
        }

        if((Heroe==1&&IA==3)||(Heroe==2&&IA==1)||(Heroe==3&&IA==2)){
            cout << "Gana el Heroe" << endl;
            if (Heroe==1&&IA==3){
                opcion = "1piedra_tijeras.txt";
            }
            else if (Heroe==2&&IA==1){
                opcion = "1papel_piedra.txt";
            }
            else if(Heroe==3&&IA==2){
                opcion = "1tijeras_papel.txt";
            }

            ganadas += 1;
        }

        if((Heroe==3&&IA==1)||(Heroe==1&&IA==2)||(Heroe==2&&IA==3)){
            cout << "Gana El Gran Rey" << endl;
            if (Heroe==3&&IA==1){
                opcion = "1tijeras_piedra.txt";
            }
            else if (Heroe==1&&IA==2){
                opcion = "1piedra_papel.txt";
            }
            else if(Heroe==2&&IA==3){
                opcion = "1papel_tijeras.txt";
            }

            perdidas += 1;
        }

        ifstream archivo(opcion);
        getline(archivo, strInput);
        if (!archivo){ 
            cerr << "valio m, no jalo T-T" << endl;

        }
        while(true){
            if (archivo.eof()){
                break;
            } 
            getline(archivo, strInput);
            stringstream ss(strInput);
            getline(ss, cadena,'\n');
            cout << cadena << endl;
        }
        archivo.close();

        cout << "\n";
        cout << "\n";

        if(perdidas == 3){
            cout << "El Gran Rey Gano, y sigue gobernando tiranicamente, fallaste en tu mision." << endl;
            break;
        }
        if (ganadas == 3){
            cout << "El heroe al fin le gano al Gran rey, la gente fue liberada." << endl;
            break;
        }

        Heroe = 0;
        IA = 0;
        cin.clear();
    }

    if (ganadas == 3){
        return 1;
        }
    if(perdidas == 3){
        return 0;
        }


}