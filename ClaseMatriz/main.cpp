#include <iostream>
#include "Matriz.h"
#include <conio.h>

using namespace std;

int main() {
	int fil, col, opc;
	float prom;
	do {
		cout << "Ingrese el numero de filas: ";
		cin >> fil;
	} while ((fil <= 0) || (fil > MAX));

	do {
		cout << "Ingrese el numero de columnas: ";
		cin >> col;
	} while ((col <= 0) || (col > MAX));

	Matriz arreglo(fil, col);
	//Menu
	do {
		cout << "\t Menu\n";
		cout << "\t ====\n\n";
		cout << "(1) Cargar Matriz\n";
		cout << "(2) Mostrar Matriz\n";
		cout << "(3) Promedio Matriz\n";
		cout << "(4) Mayor Matriz\n";
		cout << "(0) Salir\n";
		cout << "Opcion:";
		cin >> opc;
		switch (opc) {
		case 1: arreglo.cargarmat();
			break;
		case 2: arreglo.mostrarmat();
			break;
		case 3: prom = arreglo.promedio();
			cout << "El valor promedio es: " << prom;
			break;
		case 4: cout << "El mayor es: " << arreglo.mayor();
			break;
		case 0: cout << "Salir\n";
			break;
		default: cout << "Error\n";
			break;
		}
		_getch();
		system("cls"); // Limpie la pantalla y funciona stdlib
	} while (opc != 0);
	return 0;
}
