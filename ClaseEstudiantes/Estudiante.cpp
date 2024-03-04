#include "Estudiante.h"


Estudiante::Estudiante(string no, int ed, string mat, float cal) {
	nombre = no;
	edad = ed;
	materia = mat;
	calificacion = cal;
}

void Estudiante::definir_materia(string mat) {
	materia = mat;
}

void Estudiante::definir_calificacion(float cal) {
	calificacion = cal;
}

string Estudiante::get_nombre() {
	return nombre;
}
string Estudiante::get_materia() {
	return materia;
}
int Estudiante::get_edad() {
	return edad;
}
float Estudiante::get_calificacion() {
	return calificacion;
}
