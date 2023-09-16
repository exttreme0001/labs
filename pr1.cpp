#include <iostream>
#include "iomanip"
#include <cmath>//   ввод/вывод
using namespace std;

int main  () {
   double x, answ , a , b , func;
   int k , n ( 1 );
    std:: cin >> x;
    std:: cin >> k;

  func = log (1+x );
    std:: cout << setprecision(k) << func << endl ;

    if ( k < 1 || x>1 || x <= -1 ){std:: cout <<"used wrong x or k";return 0;}
    else
    {

    /*func > 0 && func < pow(10.0,-k)*/
  while ( a != b )  {
        answ = answ + pow (x ,n ) * pow (-1, n - 1) / n ; n++;
         a = int ( answ * pow (10,k)), b = int ( func * pow (10,k ) ); // пока все k цифры не совпадут не заканчивать
        std:: cout << answ << endl << a << endl << b << endl;
    }
        std:: cout <<setprecision(k)<<answ<<endl;



    }

    return 0;
}
/*
 *  for ( int i=0;i<3;i+=1)/*func > 0 && func < pow(10.0,-k)
{
answ=answ +pow(x,n)* pow(-1,n-1) / n ;n++;
int a=int( answ*pow(10,k)), b=int(func*pow(10,k)); // пока все k цифры не совпадут не заканчивать
std:: cout << answ<<endl<<a<<endl<<b<<endl;
}


*/