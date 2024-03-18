#include "Matriz.h"
#include <iostream>

using namespace std;

Matriz::Matriz(int filas, int columnas) {
	this->filas = filas;
	this->columnas = columnas;
}
void Matriz::setValue(int value, int fila, int columna) {
	MAT[fila][columna] = value;
}
int Matriz::getValue(int x, int y) {
	return MAT[x][y];
}
//void setFil(int fila);
int Matriz::getFil() {
	return filas;
}
//void setCol(int col);
int Matriz::getCol() {
	return columnas;
}

void Matriz::mostrarmat() {
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++) {
			cout << MAT[i][j] << "\t";
		}
		cout << endl;
	}
}

void Matriz::cargarmat() {
	for (int i = 0; i < filas; i++)
		for (int j = 0; j < columnas; j++) {
			cout << "MAT[" << i << "][" << j << "]= ";
			cin >> MAT[i][j];
		}
}

float Matriz::promedio() {
	float prom, s = 0;
	for (int i = 0; i < filas; i++)
		for (int j = 0; j < columnas; j++)
			s = s + MAT[i][j];
	prom = s / (filas*columnas);
	return prom;
}

int Matriz::mayor() {
	int may = MAT[0][0];
	for (int i = 0; i < filas; i++)
		for (int j = 0; j < columnas; j++)
			if (MAT[i][j] > may)
				may = MAT[i][j];
	return may;
}
