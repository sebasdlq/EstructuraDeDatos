#pragma once
#include <iostream>

using namespace std;
#define MAX 50
class Matriz
{
private:
	//Solo funcionan con matrizes rectangulares
	int MAT[MAX][30];
	int filas, columnas;

public:
	Matriz(int filas, int columnas);
	//~Matriz();
	void setValue(int value, int fila, int columna);
	int getValue(int x, int y);
	//void setFil(int fila);
	int getFil();
	//void setCol(int col);
	int getCol();
	void mostrarmat();
	void cargarmat();
	float promedio();
	int mayor();
};

