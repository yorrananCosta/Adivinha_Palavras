#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include "header.cpp"
#include "Pilha.h"
#define MAX 12

using namespace std;



int main(){
    
    string palavra;
    string chute;
    string aux; 
    string aux2;
    char letraAnt[MAX];
    int letra;
    int pontos = 0;

    cout << "Digite a palavra secreta: ";
    cin >> palavra;
    aux = palavra;
    system("clear");
    
    no *pilha;
    pilha = inicializaPilha(pilha);
    
    for (int i = 0; i < aux.length(); i++) {
        pilha = PUSH(pilha, palavra[i]);
    }

    int choice, conta4 = 0;
    //esconder palavra digitada;
    
    embaralhar(palavra);
    mostrarMenuEscolha();
    cin >> choice;
    do{
        switch(choice){
            case 1:{
                cout << "Chute: " <<endl;
                cin >> chute;
                int count = 0;
                for (int i = 0; i < chute.length(); i++)
                {
                    if(comparar_palavras(chute[i], palavra[i])){
                        cout << "A " << i+1 << "(a) letra esta na posicao certa" << endl;
                        count++;
                    }
                }
                if(count == palavra.length()){
                    cout << "PARABENS, VOCE ACERTOU!" <<endl;
                    exit(0);
                    break;
                }
                else {
                    cout << "PALAVRA INCORRETA!"<<endl;
                }
            }
            break;

            case 2: {
                cout << "REEMBARALHANDO..."<<endl;
                embaralhar(palavra);
            }
            break;

            case 3: {
                cout <<endl;
                pilha = POP(pilha, &letra);
                cout << "LETRA: [" << char(letra) << "]" << endl;
                letraAnt[conta4] = letra;
                aux2.push_back(letraAnt[conta4]);
                conta4++;
                revelarPalavra(palavra, aux2);
                cout <<endl;
            }
            break;
            
            case 4: {
                exit(0);
            }break;

            default: {
                cout << "ERRO - selecao invalida!" << endl;
            }

        }
        mostrarMenuEscolha();
        cin >> choice;
        
        
    }while(choice != 4);
}
