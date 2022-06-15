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
        system("cls");
        cout << "\t::::MENU::::" << endl;
        cout << "[1] Combatir." << endl;
        cout << "[2] Salir." << endl;
        cout <<  "Que quieres hacer: ";
        cin >> eleccion;
        if(eleccion == 1){
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
        system("clear");
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
            system("clear");
            cout << "--- AHORCADO ---" << endl;
            DibujarCuerpo();
            cout << "Palabra: " << palabras[nA] << endl;
            cout << "Ganaste!!!" << endl;
            system("pause");
            return;

        }
    }
    system("clear");
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