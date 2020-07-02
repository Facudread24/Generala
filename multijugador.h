#pragma once
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<ctype.h>
using namespace std;
#include "masFun.h";
#include "funciones.h";
//******************************

void nombres(char[],int tam,int num);
void ubi(int punt);
void ubi_2(char v[], int rondas);
void ubi_3(char vec[], char v[], int tam, int pts1, int pts2, int rondas, bool band);

//**********************************

void nombres(char v[], int tam,int num) {
	cout << "NOMBRE DEL JUGADOR" <<num<< ": ";
	//cin.ignore();
	cin.getline(v, 24);
	mayus(v);
}
void ubi(int punt) {
	gotoxy(60, 1);
	cout << "PUNTAJE TOTAL: " << punt << " PUNTOS";
}
void ubi_2(char v[], int rondas) {
	gotoxy(5, 1);
	cout << "TURNO DE " << v;
	gotoxy(34, 1);
	cout << "RONDA N " << (char)248 << " " << rondas;
}
void ubi_3(char vec[], char v[], int tam, int pts1, int pts2, int rondas, bool band) {

	recuadro(40, 8, 45, 15, 12, 14);
	gotoxy(58, 9);
	cout << "RONDA N " << (char)248 << " " << rondas;
	if (band == true)
	{
		gotoxy(52, 11);
		cout << "PROXIMO TURNO: " << vec;
	}
	else
	{
		gotoxy(52, 11);
		cout << "PROXIMO TURNO: " << v;
	}
	gotoxy(45, 15);
	cout << "PUNTAJE DE " << vec << ": " << pts1;
	gotoxy(45, 18);
	cout << "PUNTAJE DE " << v << ": " << pts2;
	gotoxy(45, 22);
	system("pause");
}