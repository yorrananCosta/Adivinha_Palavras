#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include "Pilha.h"
#define MAX 12

using namespace std;

void embaralhar(string palavra1){
    string embaralhada = palavra1;
    random_shuffle( embaralhada.begin(), embaralhada.end());
    cout << "Palavra embaralhada:  " << embaralhada <<endl;
}

void revelarPalavra(string palavra1, string aux1){
    for (int i = 0; i < (palavra1.length() - aux1.length()); i++)
        cout << "_ ";
    for (int i = aux1.length(); i >= 0; i--)
        cout << aux1[i] << " ";
    cout <<endl;
}

void mostrarMenuEscolha(){
    cout << "-----------------------|L E T R O C A|-----------------------"<<endl;
    cout <<endl << "[1] - Chutar palavra" <<endl << "[2] - Reembaralhar palavra" <<endl << "[3] - Revelar letra" <<endl << "[4] - Sair" <<endl <<endl;
}

int main(){
    cout << "Digite a palavra secreta: ";
    string palavra;
    char letra, letraAnt[MAX];
    cin >> palavra;
    string chute, aux = palavra, aux2;
    no *pilha;
    pilha = inicializaPilha(pilha);
    
    for (int i = 0; i < aux.length(); i++)
        pilha = PUSH(pilha, palavra[i]);

    int choice, conta4 = 0;
    //esconder palavra digitada;
    
    embaralhar(palavra);
    mostrarMenuEscolha();
    cin >> choice;
    do{
        switch(choice){
            case 1:
            cout << "Chute: " <<endl;
            cin >> chute;
            if (chute == palavra){
                cout << "PARABENS, VOCE ACERTOU!" <<endl;
                exit(0);
                break;
            }
            else
                cout << "PALAVRA INCORRETA!"<<endl;
            
            break;

            case 2:
            cout << "REEMBARALHANDO..."<<endl;
            embaralhar(palavra);
            break;

            case 3:
            cout <<endl;
            pilha = POP(pilha, &letra);
            cout << "LETRA: " << letra <<endl;
            letraAnt[conta4] = letra;
            aux2.push_back(letraAnt[conta4]);
            conta4++;
            revelarPalavra(palavra, aux2);
            cout <<endl;
            break;
            
            case 4:
            exit(0);
            break;

        }
        mostrarMenuEscolha();
        cin >> choice;
    }while(choice != 4);
}
