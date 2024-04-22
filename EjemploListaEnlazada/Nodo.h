#pragma once
#include <iostream>

using namespace std;
class Nodo
{
public:
	string nombre;
	string habitat;
	string estadoDeConservacion;
	Nodo* siquiente;
	Nodo(string, string, string);
};

