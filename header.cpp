#include <iostream>
#include <stack>
#include <stdio.h>

using namespace std;

void mensage() {
    cout << "ADVINHADOR DE PALAVRAS" << endl;
}

string word_receiver(){
    string word_typed;
    cin >> word_typed;
    return word_typed;
}

bool compare_words(char char_compared, char comparator_char) {
    if(char_compared == comparator_char) {
        return true;
    }
    else {
        return false;
    }
}
