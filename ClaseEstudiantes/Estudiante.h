#pragma once
#include <iostream>
#include <string>

using namespace std;

class Estudiante
{
private:
	string nombre, materia;
	int edad;
	float calificacion;
public:
	Estudiante(string no, int ed = 18, string mat = "", float cal = 0);
	void definir_materia(string mat);
	void  definir_calificacion(float cal);

	string get_nombre();
	string get_materia();
	int get_edad();
	float get_calificacion();
};

