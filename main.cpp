#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include "Pilha.h"
#define MAX 12

using namespace std;

void embaralhar(no *pilhaaux, string palavra1){
    string embaralhada = palavra1;
    random_shuffle( embaralhada.begin(), embaralhada.end());
    cout << "Palavra embaralhada:  " << embaralhada <<endl;
}

void revelarPalavra(string palavra1, string aux1){
    for (int i = 0; i < palavra1.length() - aux1.length(); i++)
        cout << "_ ";
    for (int i = aux1.length(); i >= 0; i--)
        cout << aux1[i] << " ";
    cout <<endl;
}

int main(){
    cout << "Digite a palavra secreta: ";
    char palavra[MAX], letra, letraAnt[MAX];
    cin >> palavra;
    string chute, aux = palavra;
    no *pilha;
    pilha = inicializaPilha(pilha);
    
    for (int i = 0; i < aux.length(); i++)
        pilha = PUSH(pilha, palavra[i]);

    int choice, conta4 = 0;
    //esconder palavra digitada;
    
    embaralhar(pilha, palavra);
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
            embaralhar(pilha,palavra);
            break;

            case 3:
            cout <<endl;
            pilha = POP(pilha, &letra);
            letraAnt[conta4] = letra;
            aux = letraAnt;
            conta4++;
            revelarPalavra(palavra, aux);
            cout <<endl;
            break;
            
            default:
            exit(0);
            break;

        }
        cin >> choice;
    }while(choice != 3);
}
