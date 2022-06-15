#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main (void){
    string opcion;
    int IA, Heroe;
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
    if(Heroe==IA)
        cout << "Empate" << endl;
        if(Heroe = 1){
            ifstream archivo(opcion);
        }
    if((Heroe==1&&IA==3)||(Heroe==2&&IA==1)||(Heroe==3&&IA==2))
        cout << "Gana usuario" << endl;
    if((Heroe==3&&IA==1)||(Heroe==1&&IA==2)||(Heroe==2&&IA==3))
        cout << "Gana ordenador" << endl;
    cout << "Valor de jugada del ordenador: " << IA << endl;
    cout << endl;
    system ("pause");
    return EXIT_SUCCESS;
}