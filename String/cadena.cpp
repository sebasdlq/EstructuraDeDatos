/*
Sebastian Fernando De La Quintana
Miguel Angelo Rodriguez Montaño
*/

#include "cadena.h"
#include <iostream>
#include <string>
using namespace std;
cadena::cadena() {}
cadena::~cadena() {}
void cadena::set_str( ) {
	cout << endl << "Ingrese un nombre: ";
	getline(cin, nombre);
}
void cadena::Obtener_longitud( ) {
	int longitud = nombre.length();
	cout << endl << "El string tiene: " << longitud;
}
void cadena::Comparar( ) {
	cout << endl << "Redigite el nombre: ";
	cin.ignore();
	getline(cin, var2);
	if (nombre.compare(var2) == 0)
		cout << endl << "Los datos coinciden" << endl;
	else
		cout << nombre << " es diferente que " << var2 << " :1" << endl;

}
void cadena::Número_vocales( ) {
	int cont = 0;
	int longitud = nombre.length();
	cout << endl << "Ejemplo de uso de elementos individuales: " << endl;
	cout << endl << "Contar vocales" << endl << endl;
	for (int i = 0; i < longitud; i++)
		if (nombre.at(i) == 'a' || nombre.at(i) == 'e' || nombre.at(i) == 'i' || nombre.at(i) == 'o' || nombre.at(i) == 'u')
			cont++;
	cout << "Numero de vocales: " << cont << endl;
}
void cadena::sacar_string( ) {
	int pos;
	int longitud = nombre.length();
	cout << endl << "Ingrese desde donde desea extraer el sbstring: ";
	cin >> pos;
	cout << nombre.substr(pos, longitud - pos);
	cin.ignore();
}
void cadena::intercambiar( ) {
	cin.ignore();
	cout << "Cadena a Intercambiar: ";
	getline(cin, var2);
	cout << endl << "Intercambia variables";
	nombre.swap(var2);
	cout << nombre;
	cout << var2;
}
void cadena::encontrar( ) {
	cout << nombre.find(' ');
	int longitud = nombre.length();
	for (int i = 0; i < longitud; i++)
		if (nombre.at(i) == ' ')
			cout << endl << "Existe un espacio en: " << i;
}
void cadena::invertir( ) {
	var2 = nombre;
	int longitud = nombre.length();
	char aux;
	for (int i = 0; i < longitud / 2; i++)
	{
		aux = nombre[i];
		nombre[i] = nombre[longitud - 1 - i];
		nombre[longitud - 1 - i] = aux;
	}
	cout << "La cadena invertida es: " << nombre << endl;

	if (var2.compare(nombre) == 0)
		cout << "Es un palindromo";

}
void cadena::quitar_aeiou( ) {
	var2 = nombre;
	int cont = 0;
	int longitud = nombre.length();
	for (int i = 0; i < longitud; i++)
		if (nombre[i] != 'a' && nombre[i] != 'e' && nombre[i] != 'i' && nombre[i] != 'o' && nombre[i] != 'u')
		{
			var2[cont] = nombre[i];
			cont++;
		}
	cout << "Sin vocales es: " << var2;

}
string cadena::get_str() {
	return nombre;
}
