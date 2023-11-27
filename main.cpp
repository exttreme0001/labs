#include <iostream>//   ввод/вывод
#include <cstdlib>
using namespace std;

int main() {
    int Left, Right, size, perem(0), numZero(0), first(0), second(0), pr(1);
    std::cout << " Vvedite left border " << endl;
    std::cin >> Left;
    std::cout << " Vvedite right border " << endl;
    std::cin >> Right;
    std::cout << " Vvedite size " << endl;
    std::cin >> size;
    int* random_arr = new int[size];
    for (int i = 0; i < size; ++i) {
        random_arr[i] = rand() % (Right - Left + 1) + Left;
        std::cout << random_arr[i] << ' ';


        if (i >= 1) {
            if ((random_arr[i] < 0 && random_arr[i - 1] >= 0)
                || (random_arr[i] >= 0 && random_arr[i - 1] < 0)) {
                perem++;
            }
        }
    }
    std::cout << " kolichestvo peremen znaka " << perem << endl; // пункт 1

    for (int i = 0; i < size; ++i) {
        if (random_arr[i] == 0) {
            if (numZero == 0) { first = i; }
            else
                if (numZero == 1) { second = i; }
            numZero++;
        }
    }
    if (numZero >= 2) {
        while (first < second - 1) {
            pr *= random_arr[first + 1];
            first++;
        }
    }
    else {
        std::cout << " nety 2 nylia " << endl;
        std::cout << " proizvedenie " << 0 << endl;
    }
    // пункт 2
    int* arr1 = new int[size];
    int j(0);
    for (int i = 0; i < size; ++i) {
        if (random_arr[i] % 2 == 0) {
            arr1[j] = random_arr[i]; j++;
        }
    }
    for (int i = 0; i < size; ++i) {
        if (random_arr[i] % 2 != 0) {
            arr1[j] = random_arr[i];
            j++;
        }
        std::cout << arr1[i] << ' ';
    }
}