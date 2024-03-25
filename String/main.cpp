#include <iostream>
#include <conio.h>
#include "cadena.h"
using namespace std;

void WriteMenu(string str="");
void doOption(int, cadena &s);
int main()
{
    cadena cadenosa;
    bool active = true;
    cadenosa.set_str();
    while (active)
    {
        WriteMenu(cadenosa.get_str());
        int opcion;
        cin >> opcion;
        if (opcion == 10) {
            active = false;
            cout << "Gracias por usar\n";
        }
        else {
            system("cls");
            doOption(opcion, cadenosa);
        }
    }
}

void WriteMenu(string str) {
    cout << "Bienvenido: \n";
    cout << "String actual: " << str << endl;
    cout << "1.Longitud\n2.Comparar\n3.Contar Vocales\n4.Sacar Substring\n5.Intercambiar\n6.Encontrar Caracter\n7.Invertir\n8.Es Palindromo\n9.Quitar Vocales\n10.Salir\n";
    cout << "Eliga su opcion: ";
}
void doOption(int o, cadena &s) {
    switch (o)
    {
    case 1:
        s.Obtener_longitud();
        break;
    case 2:
        s.Comparar();
        break;
    case 3:
        s.sacar_string();
        break;
    case 4:
        s.intercambiar();
        break;
    case 5:
        s.intercambiar();
        break;
    case 6:
        s.encontrar();
        break;
    case 7:
        s.invertir();
        break;
    case 8:
        s.invertir();
        break;
    case 9:
        s.quitar_aeiou();
        break;

    default:
        cout << "Ingrese una opcion correcta\n";
        break;
    }
    cout << "\nPresione cualquier tecla para continuar\n";
    char a = _getch();
    system("cls");
}
