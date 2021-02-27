#pragma once
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<ctype.h>
using namespace std;
#include "masFun.h";
#include "funciones.h";
//********************
int combinacionesG(int v[], int tam, int lanza); 
/// Desarrollo de funciones / Definiciones
int combinacionesG(int v[], int tam, int lanza) {
    int gene,full,esca=0,acu;
    bool solo = true;
    gene = contarNumerosRepetidos(v, v[0], tam);
    full = contarNumerosRepetidos(v, v[3], tam);
    acu=bfull(v, tam);
    esca = creciente(v, tam);
        if (acu==3)
        {
            gotoxy(55, 12);
            cout << "PIERNA";
            return 20;
        }
        if (gene == 5 && lanza==1 )
        {
            gotoxy(55, 12);
            cout<< "GENERALA SERVIDA GANA EL JUEGO";
            return 55;

        }else if (gene == 5)
        {
            gotoxy(55, 12);
            cout << "GENERALA + 50 PUNTOS";
            return 50;
        }
        if ((gene == 4||full==4) && lanza == 1 || (v[1] != v[0] && gene == 4 && lanza==1)) 
        {

            gotoxy(55, 12);
            cout << "POKER SERVIDO 40 + 5 PUNTOS EXTRAS";
            return 45;
        }
        else if ((gene == 4 || full == 4) || (v[1] != v[0] && gene == 4))
        {
            gotoxy(55, 12);
            cout << "POKER 40 PUNTOS";
            return 40;
        }
        if (acu==5 && lanza == 1)
        {
            gotoxy(55, 12);
            cout << "FULL SERVIDO 30 + 5 PUNTOS EXTRAS";
            return 35;
        }
        else if (acu==5)
        {
            gotoxy(55, 12);
            cout << "FULL 30 PUNTOS";
            return 30;
        }
        if (esca==5&&lanza==1)
        {
            gotoxy(55, 12);
            cout << "ESCALERA SERVIDA 25 + 5 PUNTOS EXTRAS";
            return 30;
        }
        else if (esca==5)
        {
            gotoxy(55, 12);
            cout << "ESCALERA 25 PUNTOS";
            return 25;
        }
        else if (solo==true)
        {
            return individual(v,tam+1);

        }    
            return 0;
        
}