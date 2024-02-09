/* Miguel Angelo Rodriguez Montaño
Alexander López
Jorge Ernesto Roca
Sebastian Fernando De La Quintana*/

#include <iostream>

using namespace std;

double potencia(int n, int p);
double factorial(int n);
double SumaGeometrica(int terminoN, double x);
double SumaDeSerie();

int main() {
    int k, n, p;
    double Suma; // Resultado de la Suma en la opcion 3
    do {
        cout << "-----Menu-----" << endl;
        cout << "1.Calcular La potencia " << endl;
        cout << "2.Calcular El Factorial " << endl;
        cout << "3.Resolucion De La Serie" << endl;
        cout << "0.Salir                 " << endl;
        cin >> k;
        
        switch(k) {
            case 0:
                cout << "Gracias por usar mi calculadora" << endl;
                break;
            case 1:
                cout << "Ingrese el valor de n: ";
                cin >> n;
                cout << "Ingrese el valor de la potencia: ";
                cin >> p;
                cout << "El resultado de la potencia es: " << potencia(n, p) << endl;
                break;
            case 2:
                cout << "Ingrese el valor para calcular el factorial: ";
                cin >> n;
                cout << "El factorial de " << n << " es: " << factorial(n) << endl;
                break;
            case 3:
                // Aquí puedes poner la lógica para la opción 3
                Suma = SumaDeSerie();
                cout <<"el resultado de la suma es : "<<Suma<<endl;
                break;
            default:
                cout << "La opción que ingresaste es inválida" << endl;
                break;
        }
    } while(k != 0);
    
    return 0;
}

double potencia(int n, int p) {
    double result = 1.0;
    for(int i = 0; i < p; i++) {
        result *= n;
    }
    return result;
}

double factorial(int n) {
    double result = 1.0;
    for(int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}
double SumaDeSerie(){
    //Calcula la suma de la serie 3 + x +(x^2/2!) + .... + (x^2N/2N!)
    int terminoN;
    double x;
    do{
        cout << "Ingrese el numero de terminos en la Serie: "; cin>>terminoN;
    }while(!(terminoN > 0)); // 
    do{
        cout << "Ingrese x:"; cin>>x;
    }while(!(x>= 0) && !(x < 0)); //Comprueba si x es un numero
    
    double S = 0; // Suma total de la serie
    
    switch(terminoN){
        case 1:
            //Si solo se pide el 1er termino, la suma es de 3
            return 3;
            break;
        case 2:
            //Si se pide la suma de los primeros 2 terminos la suma es de 3 + x
            return 3 + x;
            break;
        default:
            //Si se pide mas alla de dos terminos la suma es 3 + x + SumaGeometricaHastaElTermino(Nterminos - 2)
            // es -2, porque los 1ros dos terminos son 3 y x
            return 3 + x + SumaGeometrica(terminoN - 2, x);
            break;
    }
}

double SumaGeometrica(int terminoN, double x){
    //Calcula la suma de la serie (x^2/2!) + (x^4/4!) + .... + (x^2N/2N!)
    double S = 0; //Suma Total de la serie
    for(int i = 1; i <= terminoN; i++){
        S += potencia(x, i*2) / factorial(i*2); //(x^2N/2N!) en este caso N es i
    }
    return S;
}
