#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    cout << "De La ecuaciòn ax^2 + bx + c = 0"<< endl;
    float a,b,c, dis;
    cout << "a: "; cin>>a;
    cout << "b: "; cin>>b;
    cout << "c: "; cin>>c;
    
    dis = pow(b, 2) - 4*a*c;
    if(dis > 0){
        float x1, x2;
        x1 = (-b + dis)/(2*a);
        x2 = (-b + dis)/(2*a);
        
        cout << "x1: " << x1 << endl;
        cout << "x2: " << x2;
    }else if(dis == 0){
        float x = -b/(2*a);
        cout << "x: " << x;
    }else{
        float ima = sqrt(-dis)/2*a; //La raiz imaginaria de la ecuacion
        cout << "x1: " << -b/(2*a) << "+" << ima << "i" << endl;
        cout << "x2: " << -b/(2*a) << "-" << ima << "i";
    }

    return 0;
}
