#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream> 
using namespace std;


int main (void){
    string opcion;
    int IA, Heroe;
    string strInput;
    string cadena;
    stringstream ss;


    srand ((unsigned) time (NULL));
    cout << "Selecciona el valor de jugada del usuario." << endl;
    cout << "\t1.- Piedra" << endl;
    cout << "\t2.- Papel" << endl;
    cout << "\t3.- Tijera" << endl;
    cout << "\t: ";

    do {
        cin >> Heroe;
        cin.get();
        if (Heroe<1||Heroe>3)
        {
            cout << "Valor incorrecto. Ingr\202salo nuevamente.: ";
        }
    } while (Heroe<1||Heroe>3);

    IA=1+rand()%3;

    if(IA==1)
        cout << "La jugada del ordenador es Piedra" << endl;
    if(IA==2)
        cout << "La jugada del ordenador es Papel" << endl;
    if(IA==3)
        cout << "La jugada del ordenador es Tijera" << endl;

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
        cout << "Gana usuario" << endl;
        if (Heroe==1&&IA==3){
            opcion = "1piedra_tijeras.txt";
        }
        else if (Heroe==2&&IA==1){
            opcion = "1papel_piedra.txt";
        }
        else{
            opcion = "1tijeras_papel.txt";
        }
    }

    if((Heroe==3&&IA==1)||(Heroe==1&&IA==2)||(Heroe==2&&IA==3)){
            cout << "Gana ordenador" << endl;
            if (Heroe==3&&IA==1){
            opcion = "1tijeras_piedra.txt";
            }
            else if (Heroe==1&&IA==2){
                opcion = "1piedra_papel.txt";
            }
            else{
                opcion = "1papel_tijeras.txt";
            }
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

    system ("pause");
    return EXIT_SUCCESS;
}