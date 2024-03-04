#include <iostream>
#include "Estudiante.h"

int main()
{
    cout << "Ingrese el nombre";
    string nom;
    getline(cin, nom);
    cout << "Edad: ";
    int e;
    cin >> e;
    Estudiante estudiante = Estudiante(nom, e);
    cout << "El estudiante es " + estudiante.get_nombre() + " tiene " << estudiante.get_edad() << " estudia " + estudiante.get_materia() + " y tiene una calificacion de " << estudiante.get_calificacion();

}
