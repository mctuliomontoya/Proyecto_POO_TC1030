#include "Rooms.h"


class Ahorcado : public Rooms{
    private:
        string desc;
        string palabra;
        string fallos;
        string palabras[10] = {"python","aldaco","marco","angel","andre","itc","computadora","programar","tec","cpp"};
        int nA;
        int vidas;
        bool correcta, completa;
    public:
        void play();
        void DibujarCuerpo();
        int mainHd();
};
int Ahorcado::mainHd(){
    vidas = 6;
    palabra = "";
    fallos = "";
    int eleccion;
    while(true){
        cout << "Encuentras una cueva muy misteriosa, se ve que algo brillante al fondo..."<< endl;
        system ("pause");
        system("cls");
        cout << "\tQuieres entrar?" << endl;
        cout << "[1] Entrar a la cueva" << endl;
        cout << "[2] Salir" << endl;
        cout <<  "Que quieres hacer: ";
        cin >> eleccion;
        if(eleccion == 1){
            system("cls");
            cout << "...";
            getch();
            system("cls");
            cout << "  ~ Oh, vaya, hace muchos anios que no me encontraba con alguien...";
            getch();
            cout << "\n    ~ y parece que estoy de suerte! no es nadie mas que el mismisimo heroe!!";
            getch();
            cout << "\n    ~ ya que estas aqui, te dare la oportunidad de tu vida, una gran batalla con el mas poderoso de todos los reyes bajos!";
            getch(); 
            cout << "\n    ~ YO SOY EL MISMISIMO REY CAIDO, INVENCIBLE E INVICTO";
            getch();
            cout << "\n    ~ Esperemos que mi victoria deleite al Gran Rey.";
            getch();
            system("cls");
            cout << "PREPARATE PARA UNA BATALLA INTENSA!!!!";
            getch();
            system("cls");
            cout << "                                  ~~[ El ahorcado ]]~~";
            cout << "\nEn este juego, tienes 6 oportunidades para adivinar una palabra, antes de ser ahorcado";
            cout << " \nPresiona una tecla para poner una letra, y ve si tu palabra la contiene";
            getch();
            system("cls");

            play();
            break;
        }
        else if(eleccion == 2){
            return 0;
            break;
        }
    }
    if(completa == true){
        return 1;
    }
    else{
        return 0;
    }
}

void Ahorcado::play(){
    char eleccion;
    srand((int)time(NULL));
    nA = rand()%10;

    for(int i = 0; i < palabras[nA].size(); i++){
        palabra += "-";
    }

    while(vidas > 0){
        system("cls");
        cout << "--- AHORCADO ---" << endl;
        DibujarCuerpo();
        cout << "Fallos: " << fallos << endl;
        cout << "Progreso: " << palabra << endl;
        cout << "Ingrese una letra: ";
        cin >> eleccion;

        correcta = false;
        for(int i = 0; i < (int)palabras[nA].size(); i++){
            if (palabras[nA][i] == eleccion){
                palabra[i] = eleccion;
                correcta = true;
            }
        }
        if(!correcta){
            vidas--;
            fallos += eleccion;
        }
        completa = true;
        for(int i = 0; i < palabra.size(); i++){
            if(palabra[i] == '-'){
                completa = false;
            }
        }
        if(completa){
            system("cls");
            cout << "--- AHORCADO ---" << endl;
            DibujarCuerpo();
            cout << "Palabra: " << palabras[nA] << endl;
            system("cls");
            cout << "QUE!";
            getch();
            system("cls");
            cout << "  ~ HABIA PLANEADO ESTA ESTRATEGIA POR TANTO TIEMPO!! como perdi?";
            getch();
            cout << "\n  ~ Ya no me quedan fuerzas, supongo que es mi final";
            getch();
            system("cls");
            cout << "Agarras una llave brillante que estaba tirada y entras por un portal";
            getch();
            cout << "\n  ~ Parece que va al incio del laberinto";
            getch();
            cout << "\n ...";
            getch();

            return;

        }
    }
    system("cls");
    cout << "--- AHORCADO ---" << endl;
    DibujarCuerpo();
    cout << "Palabra: " << palabras[nA] << endl;
    cout << "Perdiste :c!!!" << endl;
    system("pause");
    return;

}

void Ahorcado::DibujarCuerpo(){
    
    switch(vidas){
        case 6:
            cout << "------" << endl;
			cout << "|    |" << endl;
			cout << "|" << endl;
			cout << "|" << endl;
			cout << "|" << endl;
			cout << "_________" << endl;
            break;
        case 5:
            cout << "------" << endl;
			cout << "|    |" << endl;
			cout << "|    O" << endl;
			cout << "|" << endl;
			cout << "|" << endl;
			cout << "_________" << endl;
            break;
        case 4:
            cout << "------" << endl;
			cout << "|    |" << endl;
			cout << "|    O" << endl;
			cout << "|    |" << endl;
			cout << "|" << endl;
			cout << "_________" << endl;
            break;
        case 3:
            cout << "------" << endl;
			cout << "|    |" << endl;
			cout << "|    O" << endl;
			cout << "|   /|" << endl;
			cout << "|" << endl;
			cout << "_________" << endl;
            break;
        case 2:
            cout << "------" << endl;
			cout << "|    |" << endl;
			cout << "|    O" << endl;
			cout << "|   /|\ " << endl;
			cout << "|" << endl;
			cout << "_________" << endl;
            break;
        case 1:
            cout << "------" << endl;
			cout << "|    |" << endl;
			cout << "|    O" << endl;
			cout << "|   /|\ " << endl;
			cout << "|   /   " << endl;
			cout << "_________" << endl;
            break;
        case 0:
            cout << "------" << endl;
			cout << "|    |" << endl;
			cout << "|    O" << endl;
			cout << "|   /|\ " << endl;
			cout << "|   / \ " << endl;
			cout << "_________" << endl;
            break;
    }
}