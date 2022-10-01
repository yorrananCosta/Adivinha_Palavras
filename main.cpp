#include <iostream>
#include <stack>
#include <string>
#include "header.cpp"

using namespace std;

int main(){
    stack<char> secret;
    stack<char> key;
    string s1 = "Teste"; 
    string word_received;
    mensage();
    // word_received = word_receiver();
    for (int i = 0; i < s1.length(); i++)
    {
        key.push(s1[i]);
    }
    

}