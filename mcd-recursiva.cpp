/******************************************************************************

Maximo comun divisor

*******************************************************************************/
#include <iostream>

using namespace std;

int MCD(int num1, int num2);
int main()
{
    int a,b;
    cout <<"num1: "; cin>> a;
    cout <<"num2: "; cin>> b;
    
    cout << "su mcd es: " << MCD(a, b);

    return 0;
}

int MCD(int num1, int num2){
    if(num2 == 0){
        return num1;
    }
    return MCD(num2, num1%num2);
}
