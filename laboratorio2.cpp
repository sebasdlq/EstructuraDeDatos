#include <iostream>

using namespace std;

void write_menu();
void answer(int option);
void ProtocoloPotencia();
void ProtocoloFactorial();
void ProtocoloSerie();

double Potencia(int, int); //Funcion sin referencia
void PotenciaConReferencia(int base, int exponente, double &resultado);
int Factorial(int);
double SumatoriaDeSerie(int, double);

bool executing = true;

int main()
{
    cout << "Bienvenido: \n";
    do{
        write_menu();
        int o;
        cout << "Eliga su opcion:"; cin >> o;
        answer(o);
    }while(executing);
    return 0;
}

void write_menu(){
    cout<< "\n\n*****Menu******";
    cout << "\n0. Salir\n1.Potencia\n2.Factorial\n3.Sumatoria De La Serie((x^2/2!)+(x^4/4!)+(x^6/6!)+....+(x^2n/2n!))\n";
}

void answer(int option){
    //Responde segun la opcion seleccionada por el usuario
    system("clear");
    switch(option){
        case 0:
            executing = false;
            cout << "Gracias por usar \n";
            break;
        case 1:
            ProtocoloPotencia();
            break;
        case 2:
            ProtocoloFactorial();
            break;
        case 3:
            ProtocoloSerie();
            break;
        default:
            cout << "Opcion no identificada, ingrese una opcion correcta\n";
            break;
    }
}

double Potencia(double a, int n){
    //Calcula a^n
    if(a == 0){
        return 0;
    }
    double res = 1; //Respuesta
    if(n > 0){
        //Potencias positivas, son multiplicaciones sucesivas
        for(int i = 0; i<n; i++){
            res *= a;
        }
    }else{
        //Potencias negativas, divisiones sucesivas
        for(int i = 0; i<-n; i++){
            res /= a;
        }
    }
    return res;
    /*
    if(n == 1){
        return a;
    }
    return a * Potencia(a, n - 1);
    *///Con Recursividad pero no me gusta porque no es capaz de hacer potencias negativas ni elevado a 0
}
void PotenciaConReferencia(int base, int exponente, double &resultado){
    //Calcula a^n
    if(base == 0){
        resultado = 0;
    }
    resultado = 1;
    if(exponente > 0){
        //Potencias positivas, son multiplicaciones sucesivas
        for(int i = 0; i<exponente; i++){
            resultado *= base;
        }
    }else{
        //Potencias negativas, divisiones sucesivas
        for(int i = 0; i<-exponente; i++){
            resultado /= base;
        }
    }
}
int Factorial(int n){
    //Calcula factorial de n
    if(n == 1 || n == 0){
        return 1;
    }
    return n * Factorial(n-1);
}
double SumatoriaDeSerie(int terminos, double x){
    //Calcula la Sumatoria de (x^2/2!)+(x^4/4!)+(x^6/6!)+....+(x^2n/2n!)
    /*
    double Sum = 0;
    for(int i = 1; i <= terminos; i++){
        Sum += Potencia(x, i*2)/Factorial(2*i);
    }
    return Sum;*/
    if(terminos == 0){
        return 0;
    }
    if(terminos == 1){
        return Potencia(x, 2) / Factorial(2);
    }
    return Potencia(x, terminos*2)/Factorial(terminos*2) + SumatoriaDeSerie(terminos - 1, x);
}

void ProtocoloPotencia(){
    double base;
    int exponente;
    cout<<"\nIngrese la base: "; cin >> base;
    cout<<"Ingrese el exponente: "; cin >> exponente;
    
    double res;
    
    cout << "La potencia es: " << Potencia(base, exponente) << endl;
    PotenciaConReferencia(base, exponente, res);
    cout << "La potencia usando referencia es: " << res << endl;
}
void ProtocoloFactorial(){
    int num;
    do{
        cout << "Ingrese el numero para sacar el factorial: "; cin >> num;
    }while(!(num >= 0));
    cout << "El factorial de " << num << " es: " << Factorial(num) << endl;
}
void ProtocoloSerie(){
    int numDeTerminos;
    double x;
    cout << "Se calculara la Sumatoria de la serie (x^2/2!)+(x^4/4!)+(x^6/6!)+....+(x^2n/2n!)\n x: numero cualquiera\nn: numero de terminos\n";
    do{
        cout << "Ingrese el numero de terminos(n): "; cin >> numDeTerminos;
    }while(!(numDeTerminos>=0));
    cout << "Ingrese X: "; cin >> x;
    
    cout << "La sumatoria es: " << SumatoriaDeSerie(numDeTerminos, x) << endl;
}

