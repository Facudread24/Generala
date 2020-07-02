#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
using namespace std;
#include "funciones.h";
#include "masFun.h";
#include "combinaciones.h";
#include "multijugador.h";
int main() {
	const int Tam = 5;
	int Dados[Tam];
	bool Tirar = true;
	//variables de preguntas
	char decidir;//si o no
	char jugador1[25], jugador2[25];
	int eleccion, dadoDecidido;
	//contadores/acumuladores
	int puntos2 = 0, puntos = 0, rondas = 1, lanzamientos = 1;

	///MENU PRINCIPAL
	int opcion;
	textcolor(1, 14);
	recuadro(45, 10, 25, 12, 12, 14);
	opcion = Menu_principal();
	system("cls");
	if (opcion == 1)
	{
		recuadro(40, 5, 35, 5, 12, 14);
		gotoxy(41,7);
		cin.ignore();
		nombres(jugador1, 24,1);

		while (rondas <= 10)
		{
			///Hacer un recuadro que diga el numero de ronda tirador y puntos
			system("cls");
			recuadro(1, 0, 118, 29, 12, 14);///recuadro en turno
			// ubicacion de rayas verticales Y horizontales
			gotoxy(25, 1);
			cout << (char)186;
			gotoxy(55, 1);
			cout << (char)186;
			for (int x = 2;x < 118;x++) {
				gotoxy(x, 2);
				cout << (char)205;
			}
			for (int x = 2;x < 118;x++) {
				gotoxy(x, 4);
				cout << (char)205;
			}
			//ubicacion de QUIEN ES EL TURNO
			gotoxy(4, 1);
			cout << "TURNO DE " << jugador1;///AGREGAR NOMBRES
			gotoxy(34, 1);
			cout << "RONDA N " << (char)248 << " " << rondas;///AGREGAR RONDA CONTADOR
		//PANTALLA DE JUEGO
			int point = 0, aux = 0;
			bool band = true;
			//.......................................
			decidir = 'S';
			while (lanzamientos <= 3 && (decidir == 'S' || decidir == 's'))
			{
				if (band == true) {

					tirarDados(Dados, Tam, Tirar);
					ordenarVector(Dados, Tam);
					
				}
				mostrarDados(Dados, Tam);
				point = combinacionesG(Dados, Tam, lanzamientos);
				if (aux != point) {
					puntos += point;
					aux = point;
				}
				if (point == 55) {
					system("pause");
					system("cls");
					ganador(jugador1, 24, puntos);
					gotoxy(45, 18);
					cout << "FELICIDADES SACO GENERALA SERVIDA USTED GANA";
					gotoxy(43, 13);
					system("pause");
					return 0;
				}
				gotoxy(60, 1);
				cout << "PUNTAJE TOTAL: " << puntos << " PUNTOS";
				gotoxy(50, 3);
				cout << "LANZAMIENTO N " << (char)248 << " " << lanzamientos << endl;
				if (lanzamientos < 3)
				{
					gotoxy(3, 12);
					cout << "¿CONTINUAR LANZANDO? S/N \t ";
					cin >> decidir;
					if (decidir == 'S' || decidir == 's') {
						gotoxy(3, 14);
						cout << "¿CUANTOS DADOS VOLVES A TIRAR?\t";
						cin >> eleccion;
						for (int EL = 1; EL <= eleccion; EL++)
						{
							gotoxy(3, 16);
							cout << "INGRESA LA POSICION DE LOS DADOS (UNO A LA VEZ): " << EL << (char)248 << " \t";
							cin >> dadoDecidido;
							modificar(Dados, dadoDecidido);
							band = false;
						}
						lanzamientos++;
					}
				}
				else {
					gotoxy(50, 15);
					system("pause");
					break;
				}
				borrarZona(3, 12, 50, 10);
				borrarZona(50, 12, 50, 5);
			}
			lanzamientos = 1;
			rondas++;
			decidir = 'S';
		}
		system("cls");
		ganador(jugador1, 25, puntos);
		gotoxy(12, 16);
		cout << "El exito no es definitivo y el fracaso no es fatal, Lo que importa es el coraje para continuar.";
		gotoxy(43, 18);
		system("pause");

	}
	else if (opcion == 2) {///IMPORTANTE: FALTA RECUADRO DE ACA Y UN JUGADOR
		recuadro(40, 5, 35, 8, 12, 14);
		gotoxy(41, 7);
		cin.ignore();
		nombres(jugador1, 24,1);
		gotoxy(41, 10);
		nombres(jugador2, 24,2);
		
		while (rondas <= 10)
		{
			
			//PANTALLA DE JUEGO
			int point = 0, aux = 0;
			bool band = true;
			bool bandJ = true;
			bool bandJ2= false;
			//.......................................
			for (int vue = 1; vue <= 2; vue++)
			{ ///un recuadro que dice el numero de ronda tirador y puntos
				system("cls");
				ubi_3(jugador1, jugador2, 24, puntos, puntos2, rondas, bandJ);
			///********************************************************************
				system("cls");
				recuadro(1, 0, 118, 29, 12, 14);///recuadro en turno

				// ubicacion de rayas verticales Y horizontales
				gotoxy(26, 1);
				cout << (char)186;
				gotoxy(56, 1);
				cout << (char)186;
				for (int x = 2;x < 118;x++) {
					gotoxy(x, 2);
					cout << (char)205;
				}
				for (int x = 2;x < 118;x++) {
					gotoxy(x, 4);
					cout << (char)205;
				}
			//**********************************************************************
				lanzamientos = 1;
				bool band = true;
				decidir = 'S';

				while (lanzamientos <= 3 && (decidir == 'S' || decidir == 's'))
				{
					
					if (bandJ == true) {
						ubi_2(jugador1, rondas);
					}
					else if (bandJ2 == true)
					{
						ubi_2(jugador2, rondas);
					}
					if (band == true) {
						tirarDados(Dados, Tam, Tirar);
						
					}
					gotoxy(50, 3);
					cout << "LANZAMIENTO N " << (char)248 << " " << lanzamientos << endl;
					mostrarDados(Dados, Tam);
					point = combinacionesG(Dados, Tam, lanzamientos);
					switch (bandJ)
					{
					case true:
						if (aux != point) {
							puntos += point;
							aux = point;
							ubi(puntos);

						}
						if (point == 55) {
							system("pause");
							system("cls");
							ganador(jugador1, 24, puntos);
							
							gotoxy(45, 18);
							cout << "FELICIDADES SACO GENERALA SERVIDA USTED GANA";
							gotoxy(43, 13);
							system("pause");
							return 0;
						}
						else
							break;
					case false:
						if (aux != point) {
							puntos2 += point;
							aux = point;
							ubi(puntos2);
						}
						if (point == 55) {
							system("pause");
							system("cls");
							ganador(jugador2, 24, puntos);
							gotoxy(50, 18);
							cout << "FELICIDADES SACO GENERALA SERVIDA USTED GANA";
							gotoxy(43, 13);
							system("pause");
							return 0;
						}
						else
							break;
					}
					if (lanzamientos < 3)
					{
						gotoxy(3, 12);
						cout << "¿CONTINUAR LANZANDO? S/N \t ";
						cin >> decidir;
						if (decidir == 'S' || decidir == 's') {
							gotoxy(3, 14);
							cout << "¿CUANTOS DADOS VOLVES A TIRAR?\t";
							cin >> eleccion;
							for (int EL = 1; EL <= eleccion; EL++)
							{
								gotoxy(3, 16);
								cout << "INGRESA LA POSICION DE LOS DADOS (UNO A LA VEZ): " << EL << (char)248 << " \t";
								cin >> dadoDecidido;
								modificar(Dados, dadoDecidido);
								band = false;
							}
							lanzamientos++;
						}
						else
						{
							gotoxy(50, 15);
							system("pause");
							bandJ = false;
							bandJ2 = true;
							lanzamientos = 1;
							
							break;
						}
					}
					else {
						gotoxy(50, 15);
						system("pause");
						lanzamientos = 1;
						bandJ = false;
						bandJ2 = true;
						system("cls");
						break;
					}
					borrarZona(3, 12, 50, 10);
					borrarZona(50, 12, 50, 5);

				}
			}
			rondas++;
		}
		system("cls");
		//Resultado
		if (puntos>puntos2)
		{
			ganador(jugador1, 24, puntos);
			gotoxy(12, 16);
			cout << "El exito no es definitivo y el fracaso no es fatal, Lo que importa es el coraje para continuar.";
			gotoxy(43, 18);
			system("pause");
		}
		else if (puntos<puntos2)
		{
			ganador(jugador2, 24, puntos2);
			gotoxy(12, 16);
			cout << "El exito no es definitivo y el fracaso no es fatal, Lo que importa es el coraje para continuar.";
			gotoxy(43, 18);
			system("pause");
		}
		else {
			gotoxy(55, 9);
			cout << "EMPATARON";
			gotoxy(45, 18);
			system("pause");
		}
	}
	else {
		return 0;
	}
	return 0; 
}