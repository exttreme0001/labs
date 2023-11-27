#include <iostream>
#include <vector>
using namespace std;

int main() {
    int size;
    cout << "enter size including space ";
    cin >> size;
    cin.ignore();

    if (size > 300 || size <= 0) {
        cout << "entered wrong size";
        return 0;
    }

    cout << " str" << endl;
    char str[300]{};
 
    cin.getline(str,size+1);
    int strL = 0;
    while (str[strL] != '\0') {
        strL++;
    }

    int counter(0);
    char* words = new char[strL+2];
    words[strL ] = '\0';

    for (int i = 0; i < strL; ++i) {
        
            if (str[i] != ' ') {
                words[counter] = str[i];
        }
        else if (i!=0 && str[i-1] != ' ') {
                words[counter] = ',';
        }
        else if (str[i] == ' ') {
                counter--;  }
        counter++;
          }


    cout << "[] of words with ,  :   ";
    for (int i = 0; i <counter; i++) {
        cout  << words[i];
    }
    vector<char>vect;
    int number(0), i(0), max(0), enters(0);
    while (i!=counter+2) {  
        int cou(0);  
        
        
        if (words[i] == ',' ||  words[i] == '\0') {
            enters++;
            if (max <= vect.size()) {
                max = vect.size();
                number=enters;
                if (i + 1 == counter) {; }
            }

            vect.clear();
        }
          
            else {

                for (int j = 0; j < vect.size(); j++) {
                    if (words[i] == vect[j]) { break; }
                    else cou++;
                }
                if (cou == vect.size()) { vect.push_back(words[i]);}




            }
        i++;
        }
    cout <<endl<<"Number of word is : " << endl << number;
    delete[] words;
}