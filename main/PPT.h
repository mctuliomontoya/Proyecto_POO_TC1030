#include "Rooms.h"


class PPT{
    private:
        string desc;
    public:
        int mainS();
        int mainP();
};


int PPT::mainS(){
        cout<<"La gran puerta se ha abierto, se ve un pasillo gigante con una alfombra roja y pilares blancos";
        getch();
        cout<<"\nAun que intentaras volver, no se puede, la presencia que se muestra es demasiado grande para volver";
        getch();
        cout<<"\n\n Entras, sigues el pasillo y al fondo, en un trono lleno de espadas, se ve a un hombre imponente.";
        getch();
        system("cls");
        cout << "\n ~ Hm? hasta que al fin llegas, heroe, aunque tardaste mucho mas de lo que pense";
        getch();
        cout << "\n ~ Mis lacayos no duraron mucho, pero alegrate, yo terminare lo que ellos no";
        getch();
        cout << "\n ~ Estos 100 anios de exilio me ayudaron a crear una tecnica de combate perfecta, no hay chance de que me venzas";
        getch(); 
        cout << "\n ~ Empezemos";
        getch();
        system ("cls");
        system("Color 04");
        cout << "\n EMPIEZA LA BATALLA";
        getch();
        system("Color 07");
        system("cls");
        mainP();

}


int PPT::mainP (void){
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

        cin.clear();

        do {
            cin >> Heroe;
            cin.get();
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
            if(Heroe == 1){
                opcion = "1piedra_piedra.txt";
            }
            else if (Heroe == 2){
                opcion = "1papel_papel.txt";
            }
            else if (Heroe == 3){
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

    }

    if (ganadas == 3){
        return 1;
        }
    if(perdidas == 3){
        return 0;
        }


}