#include <iostream> //   ввод/вывод
using namespace std;
#include <fstream>
#include <sstream>
#include <string>
bool checkpalin(string str) {
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
void clear() {
    ofstream file("strings.txt", ios::out | ios::trunc);
    file.close();
}
bool odin(string str) {
    int left = 0;
    int right = str.length() - 1;
    
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
       
    }
    return true;
}
void checkNumber2() {
    ofstream file("strings.txt", ios::app);  
    string str;
    cout << "enter strings. Enter 'stop' for continue: "<<endl; 
    while (str != "stop") {
        getline(cin, str);
        file << str << endl; 

    }
    file.close();
}

void checkNumber1(){
    
        ifstream file("strings.txt", ios::in);
        string str;
        while (getline(file, str)) {
            cout << str << endl;
            
        }
        file.close();
    }
int main() {
    int number(0);
    while (number != 3) {
        cout << "if you wanna open read file enter 1 : " << endl
            << "if you wanna enter strings enter 2: " << endl;
        cout << "or enter 3 to continue ..." << endl;
        cin >> number;
        cin.ignore();

        if (number == 1) {
            checkNumber1();
        }
        else if (number == 2) {
            checkNumber2();
        }
    }
  
    ifstream file("strings.txt", ios::in);
    string str;
    while (getline(file, str)) {
        
         if (odin(str)) {
            ofstream samestr("odin.txt",ios::app);
            samestr << str<<endl;
            samestr.close();
        
        }
         else if (checkpalin(str)) {
             ofstream palin("palindromes.txt", ios::app);
             palin << str << endl;
             palin.close();
         }

    }
    file.close();
    number = 0;
    while (number != 3) {
        cout << "if you wanna read palin enter 1" << endl << "if you wanna read simvols enter 2" << endl;
        cout << "if you wanna continue enter 3" << endl;
        cin >> number;
        if (number == 1) {
            ifstream palin("palindromes.txt", ios::in);
            while (palin) {
                string str;
                getline(palin, str);
                cout << str << endl;
            }
            palin.close();
        }
        if (number == 2) {
            ifstream samestr("odin.txt", ios::in);
            while (samestr) {
                string str;
                getline(samestr, str);
                cout << str << endl;
            }
            samestr.close();
        }
    }
    ofstream palin("palindromes.txt", ios::out | ios::trunc);  
    palin.close();
    ofstream samestr("odin.txt", ios::out | ios::trunc);
    samestr.close();
    clear();
}

