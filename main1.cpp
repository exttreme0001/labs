#include <iostream>
#include <cmath>
using namespace std;

// do reverse to our shar[]
char* reverse(char* arr, int i, int j) {

    while (i < j) {
        char t = arr[i];
        arr[i++] = arr[j];
        arr[j--] = t;
    }

    return arr;

}
// realizing itoa
char* ito(int value, char* string, int radix) {
    if (radix > 36 || radix < 2) { cout << "wrong radix "; return nullptr; }
    int n = abs(value);
    int i(0);

    do {
        int r = n % radix;
        n /= radix;
        if (r < 10) {
            string[i++] = r + '0';
        }
        else {
            string[i++] = r - 10 + 'A';
        }
    } while (n);

    // for value < 0 && numbers in the decimal system
    if (value < 0 && radix == 10) string[i++] = '-';
    string[i] = '\0';

    return reverse(string, 0, i - 1);
}

int main() {
    int value(0), radix(0);
    char result[15];
    cout << "enter value _";
    cin >> value;
    cout << "enter radix _";
    cin >> radix;
    cout << ito(value, result, radix);
    cout << "point 1"<< endl;









}
