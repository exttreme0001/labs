#include <iostream>
#include "iomanip"
#include <cmath>//   ввод/вывод
using namespace std;

int main  () {
   double x, answ , a , b , func;
   int k , n ( 1 );
    std:: cout << "Vvedite x "<< endl ;
    std:: cin >> x;
    std:: cout << "Vvedite tochnost  "<< endl ;
    std:: cin >> k;

  func = log (1+x );
    std:: cout << setprecision(k) << func << endl ;

    if ( k < 1 || x>1 || x <= -1|| k>11 ){std:: cout <<"used wrong x or k";return 0;}
    else {
        while ( a != b )  {
              answ = answ + pow (x ,n ) * pow (-1, n - 1) / n ; n++;
              a = int ( answ * pow (10,k)), b = int ( func * pow (10,k ) ); // пока все k цифры не совпадут не заканчивать
            //  std:: cout << answ << endl << a << endl << b << endl; // выводит значение на каждом к, не обязательно
    }
        std:: cout << setprecision(k+1) << answ << endl;
    }

    return 0;
}