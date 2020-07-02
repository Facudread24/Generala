#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <iostream>
#include <windows.h>
using namespace std;
enum Color{
cNEGRO=0,
cAZUL=1,
cVERDE=2,
cCIAN=3,
cROJO=4,
cMAGENTA=5,
cMARRON=6,
cGRIS_CLARO=7,
cGRIS=8,
cAZUL_CLARO=9,
cVERDE_CLARO=10,
cCIAN_CLARO=11,
cROJO_CLARO=12,
cMAGENTA_CLARO=13,
cAMARILLO=14,
cBLANCO=15
};
///DECLARACIONES
void DibujoNum1(int num,int x, int y);
///DEFINICIONES

void clrscr(void){
    system("cls");
}
void pause(void){
    system("pause >nul");
}
void gotoxy(int x, int y){
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
void textcolor(short colorTexto=15, short colorFondo=0){
    short color = colorTexto + colorFondo * 16;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), color);
}
void recuadro(short iniX, short iniY, short ancho, short alto, short colorLinea=cBLANCO, short colorFondo=cNEGRO){
    int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            gotoxy(i, j);
            textcolor(colorLinea, colorFondo);
            //Arriba izquierda
            if(i==iniX && j==iniY){
                cout << (char) 201;
            }
            //Arriba derecha
            else if(i==iniX+ancho && j==iniY){
                cout << (char) 187;
            }
            //Abajo izquierda
            else if(i==iniX && j==iniY+alto){
                cout << (char) 200;
            }
            //Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto){
                cout << (char) 188;
            }
            //Lineas arriba y abajo
            else if(j==iniY || j==iniY+alto){
                cout << (char) 205;
            }
            //Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho){
                cout << (char) 186;
            }
            //Dentro del recuadro
            else{
                cout << " ";
            }
        }
    }
}
void hacerDado(short iniX, short iniY, short ancho, short alto, short colorLinea = cBLANCO, short colorFondo = cNEGRO) {
    int i, j;
    for (i = iniX; i <= iniX + ancho; i++) {
        for (j = iniY; j <= iniY + alto; j++) {
            gotoxy(i, j);
            textcolor(colorLinea, colorFondo);
            //Arriba izquierda
            if (i == iniX && j == iniY) {
                cout << (char)218;
            }
            //Arriba derecha
            else if (i == iniX + ancho && j == iniY) {
                cout << (char)191;
            }
            //Abajo izquierda
            else if (i == iniX && j == iniY + alto) {
                cout << (char)192;
            }
            //Abajo derecha
            else if (i == iniX + ancho && j == iniY + alto) {
                cout << (char)217;
            }
            //Lineas arriba y abajo
            else if (j == iniY || j == iniY + alto) {
                cout << (char)196;
            }
            //Lineas izquierda y derecha
            else if (i == iniX || i == iniX + ancho) {
                cout << (char)179;
            }
            //Dentro del recuadro
            else {
                cout << " ";
            }
        }
    }
}

void DibujoNum1(int num, int x, int y) {
        
            switch (num)
            {
            case 1:
                gotoxy(x, y);
                cout << (char)254;
                
                break;
            case 2:
                gotoxy(x - 1, y - 1);
                cout << (char)254;
                gotoxy(x + 1, y + 1);
                cout << (char)254;
                break;
            case 3:
                gotoxy(x - 2, y - 1);
                cout << (char)254;
                gotoxy(x, y);
                cout << (char)254;
                gotoxy(x + 2, y + 1);
                cout << (char)254;
                break;
            case 4:
                gotoxy(x - 2, y - 1);
                cout << (char)254;
                gotoxy(x - 2, y + 1);
                cout << (char)254;
                gotoxy(x + 2, y - 1);
                cout << (char)254;
                gotoxy(x + 2, y + 1);
                cout << (char)254;
                break;
            case 5:
                gotoxy(x - 2, y - 1);
                cout << (char)254;
                gotoxy(x - 2, y + 1);
                cout << (char)254;
                gotoxy(x + 2, y - 1);
                cout << (char)254;
                gotoxy(x + 2, y + 1);
                cout << (char)254;
                gotoxy(x, y);
                cout << (char)254;
                break;
            case 6:
                gotoxy(x - 2, y - 1);
                cout << (char)254;
                gotoxy(x - 2, y);
                cout << (char)254;
                gotoxy(x - 2, y + 1);
                cout << (char)254;
                gotoxy(x + 2, y - 1);
                cout << (char)254;
                gotoxy(x + 2, y);
                cout << (char)254;
                gotoxy(x + 2, y + 1);
                cout << (char)254;
                break;

            }
    
}
void borrarZona(int X, int Y, int ancho, int alto) {
    int i, j;
    for (i = X; i <= X + ancho; i++) {
        for (j = Y; j <= Y + alto; j++) {
            gotoxy(i, j);
            //Arriba izquierda
            if (i == X && j == Y) {
                cout << " ";
            }
            //Arriba derecha
            else if (i == X + ancho && j == Y) {
                cout << " ";
            }
            //Abajo izquierda
            else if (i == X && j == Y + alto) {
                cout << " ";
            }
            //Abajo derecha
            else if (i == X + ancho && j == Y + alto) {
                cout << " ";
            }
            //Dentro del recuadro
            else {
                cout << "     ";
            }
        }
    }
}

#endif // FUNCIONES_H_INCLUDED
