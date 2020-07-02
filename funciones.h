#pragma once

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<ctype.h>
using namespace std;
#include "masFun.h";
/// DECLARACIÓN/PROTOTIPO DE FUNCIONES

void cargarVector(int v[], int tam);///asigna valores a cada una de las posiciones del vector

void mostrarVector(int v[], int tam);/// muestra lo que contiene cada una de las posiciones del vector

void ponerCero(int v[], int tam);/// pone en 0 todas las posiciones del vector

int posicionNumeroEnVector(int v[], int tam, int numero);/// devuelve la posición que ocupa un número que se //envía como parámetro. Devuelve la primera posición que encuentra el número. Si no lo encuentra devuelve -1

int contarNumerosRepetidos(int v[], int tam, int numero);///cuenta la cantidad de veces que se repite un //número en el vector

int maximoVector(int v[], int tam);///devuelve  la posición (ultima) que ocupa el máximo en el vector

int minimoVector(int v[], int tam);///devuelve  la posición (primera) que ocupa el mínimo en el vector

void cargarAleatorio(int v[], int tam, int limite);///asigna valores aleatorios a cada al vector

void ordenarVector(int v[], int tam);/// ordena de menor a mayor un vector

int sumarVector(int v[], int tam); /// suma los valores contenidos en el vector

void copiarVector(int v[], int v2[], int tam); ///copia el vector v en v2

bool compararVectores(int v[], int v2[], int tam);// compara los dos vectores que recibe. Si son iguales ///devuelve true, si no devuelve false
//****************************************************************************************************
int BuscarMayor(int v[], int tam);// busca el mayor dentro del vector;

void tirarDados(int vecDados[], int otro,bool solo);//tira una canatidad de dados determinado (modificado)

void mostrarDados(int v[], int tam); /// muestra los dados

int Menu_principal(); // menu de opciones

void modificar(int v[], int pos); /// modifica un dado especifico dentro del vector

char* mayus(char *v); //pone en mayuscula un vector de minuscula

void ganador(char v[], int tam, int puntos);// muestra el nombre y puntaje del ganador

int creciente(int v[], int tam); //ordena el vector para ver i hay esclaera 

int individual(int v[], int tam); // busca las combinaciones que se multiplican como maximo * 3

int contarRepetidos(int v[], int n, int tam);/// devuelve la cantidad que se repite determinado numero, fue usado en f()individual.

/// Desarrollo de funciones / Definiciones
int individual(int v[], int tam) {
    int posMax,may,cant,solo;
    int vec[6] = { 0 };
    
    for (int i = 1; i <=6; i++)
    {
        cant = contarRepetidos(v, i, tam);
        vec[i - 1] = cant;
        
    }
        may = BuscarMayor(vec, tam);
        posMax = maximoVector(vec, tam);
        if (may * (posMax + 1) < 6)
        {
            solo = BuscarMayor(v, tam);
            if (solo < may * (posMax + 1))
            {
                gotoxy(55, 12);
                cout << "JUEGO DE " << posMax+1 << " SON " << may * (posMax + 1) << " PUNTOS";
                return may * (posMax + 1);
            }
            else {
                gotoxy(55, 12);
                cout << "JUEGO DE " << solo << " SON " << solo << " PUNTOS";
                return solo;
            }
        }
        else
        {
            gotoxy(55, 12);
            cout << "JUEGO DE " << posMax + 1 << " SON " << may * (posMax + 1) << " PUNTOS";

            return may * (posMax + 1);
        }

 }
int BuscarMayor(int v[], int tam) {
    int mayor = v[0];

    for (int i = 1; i < tam; i++)
    {
        if (v[i] >= mayor) {
            mayor = v[i];
        }
    }
    return mayor;

}
int contarRepetidos(int v[], int numero, int tam) {
    int i, cant = 0;
    for (i = 1;i <= tam;i++) {
        if (v[i - 1] == numero) cant++;
    }
    return cant;
}
int creciente(int v[], int tam) {
    int vec[5];
    for (int x = 0; x < tam; x++)
    {
        vec[x] = v[x];
    }
    ordenarVector(vec, tam);
    
    int cont = 1;
    for (int i = 1; i < tam; i++)
    {
        if (vec[i - 1] < vec[i] && (vec[i - 1] - vec[i]) == -1) {
            cont++;
            
        }

    }
    return cont;

}
void ganador(char v[], int tam, int puntos) {

    recuadro(40, 5, 40, 10, 12, 14);
    gotoxy(45,6);
    cout << "!!!FELICITACIONES AL GANADOR!!!";
    gotoxy(45, 9);
    cout <<"EL GANADOR ES: "<< v;
    gotoxy(45, 11);
    cout <<"PUNTAJE DEL GANADOR:"<< puntos;
}
/*void ganador2(char v[],char vec[], int tam, int puntos) {

    recuadro(40, 5, 40, 10, 12, 14);

    gotoxy(45, 6);
    cout << "!!!FELICITACIONES AL GANADOR!!!";
    gotoxy(45, 9);
    cout << "EL GANADOR ES: " << v;
    gotoxy(45, 11);
    cout << "PUNTAJE DEL GANADOR:" << puntos;
}*/
char* mayus(char*v){
    char* m = v;
    while (*m = toupper(*m))m++;
    return m;
}
void modificar(int v[], int pos) {

    srand(time(NULL));
    v[pos-1] = (rand() % 6) + 1;

}
int Menu_principal() {
    int opciones;
    gotoxy(46, 11);
    cout << "¡BIENVENIDOS A GENERALA!";
    gotoxy(50, 13);
    cout << "1. PLAY";
    gotoxy(50, 16);
    cout << "2. MULTIJUGADOR" << endl << endl;
    /*gotoxy(50, 17);
    cout << "3. REGLAS" << endl << endl;*/
    gotoxy(50, 19);
    cout << "0. EXIT" << endl << endl;
    gotoxy(46, 21);
    cout << "Seleccione una opcion: ";
    cin >> opciones;

    return opciones;
}
void tirarDados(int vecDados[], int otro, bool solo) {
    if (solo == true) {
        srand(time(NULL));
        for (int i = 0;i < otro;i++) {
            vecDados[i] = (rand() % 6) + 1;
        }
    }
    else {
        for (int i = 0;i < otro;i++) {
            gotoxy(50, 12);
            cin >> vecDados[i];
        }
    }
}
void mostrarDados(int v[], int tam) {
    for (int i = 0; i < tam; i++) {
        int x, y;
        if (i == 0) {
            gotoxy(35, 10);
            cout << "|DADO N" << (char)248 << i + 1 << "|";
            hacerDado(35, 5, 8, 4, 12, 14);
            x = 39;
            y = 7;
            DibujoNum1(v[0], x, y);

        }


        else if (i == 1) {
            gotoxy(44, 10);
            cout << "|DADO N" << (char)248 << i + 1 << "|";
            hacerDado(44, 5, 8, 4, 12, 14);
            x = 48;
            y = 7;
            DibujoNum1(v[1], x, y);
        }
        else if (i == 2) {
            gotoxy(53, 10);
            cout << "|DADO N" << (char)248 << i + 1 << "|";
            hacerDado(53, 5, 8, 4, 12, 14);
            x = 57;
            y = 7;
            DibujoNum1(v[2], x, y);

        }

        else if (i == 3) {
            gotoxy(62, 10);
            cout << "|DADO N" << (char)248 << i + 1 << "|";
            hacerDado(62, 5, 8, 4, 12, 14);
            x = 66;
            y = 7;
            DibujoNum1(v[3], x, y);

        }

        else if (i == 4) {
            gotoxy(71, 10);
            cout << "|DADO N" << (char)248 << i + 1 << "|";
            hacerDado(71, 5, 8, 4, 12, 14);
            x = 75;
            y = 7;
            DibujoNum1(v[4], x, y);

        }
        else if (i == 5) {
            hacerDado(80, 5, 8, 4, 12, 14);
            x = 84;
            y = 7;
            DibujoNum1(v[5], x, y);
        }
        cout << endl;
    }
}

    int posicionNumeroEnVector(int v[], int tam, int numero) {
        int i;
        for (i = 0;i < tam;i++) {
            if (v[i] == numero) return i;
        }
        return -1;
    }
    void cargarVector(int v[], int tam) {

        for (int i = 0; i < tam; i++)
        {
            cout << "Ingrese un numero";
            cin >> v[i];
            cout << endl;

        }

    }
    int minimoVector(int v[], int tam) {
        int i, posMin = 0;
        for (i = 1;i < tam;i++) {
            if (v[i] < v[posMin]) {
                posMin = i;
            }
        }
        return posMin;
    }

    void ordenarVector(int v[], int tam) {
        int posmin, aux;
        for (int i = 0;i < tam /*- 1*/;i++) {
            posmin = i;
            for (int j = i + 1;j < tam;j++) {
                if (v[j] < v[posmin]) posmin = j;
            }
            aux = v[i];
            v[i] = v[posmin];
            v[posmin] = aux;
        }
    }

    int maximoVector(int v[], int tam) {
        int i, posMax = 0;
        for (i = 1;i <=tam;i++) {
            if (v[i] >= v[posMax]) {
                posMax = i;
            }
        }
        return posMax;
    }

    void cargarAleatorio(int v[], int tam, int limite) {
        int i;
        srand(time(NULL));
        for (i = 0; i < tam; i++) {
            v[i] = (rand() % limite) + 1;
        }
    }

    void mostrarVector(int v[], int tam) {
        int i;
        for (i = 0;i < tam;i++) {
            cout << v[i] << "\t";
        }
    }

    int contarNumerosRepetidos(int v[], int numero, int tam) {
        int i, cant = 0;
        for (i = 0;i < tam;i++) {
            if (v[i] == numero) cant++;
        }
        return cant;
    }
    void ponerCero(int v[], int tam) {
        int i;
        for (i = 0;i < tam;i++) {
            v[i] = 0;
        }
    }

    int sumarVector(int v[], int tam) {
        int i, suma = 0;
        for (i = 0;i < tam;i++) {
            suma += v[i];
        }
        return suma;
    }

    void copiarVector(int v[], int v2[], int tam) {
        int i;
        for (i = 0;i < tam;i++) {
            v2[i] = v[i];
        }
    }

    bool compararVectores(int v[], int v2[], int tam) {
        int i;
        for (i = 0;i < tam;i++) {
            if (v2[i] != v[i]) return false;
        }
        return true;
    }

