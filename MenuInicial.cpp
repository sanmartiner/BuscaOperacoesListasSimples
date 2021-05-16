#include <iostream>
#include <new>
#include <string>
#include <string>
#include <locale.h>

using namespace std;

struct pessoa{
    string nome;
    int rg;
};

void limpaTela(){
    system("CLS");
}
int main(){

    setlocale(LC_ALL, "");

    //VARIAVEIS
    int funcaoDesejada = 1;

    //Ponteiro para a lista sequencial

    pessoa *ponteiroSequencial;

    //Tamanho da lista
    int tamanhoDaLista = 0;

    //Exemplo

    pessoa *exemploListaSequencial = new pessoa[2];

    //Dois registros de exemplo
    Exempl
    //MENU
    while(funcaoDesejada < 10 && funcaoDesejada > 0){

            //Mostrando o meunu
            cout <<	"Operações \n";
            cout <<	"1 - Inserção de um node no inicio da lista";
            cout <<	"2 - Inserção de um node no fim da lista \n";
            cout <<	"3 - Inserção de um node na posição N \n";
            cout <<	"4 - Retirar um node do inicio da lista \n";
            cout <<	"5 - Retirar um node do fim da lista \n";
            cout <<	"6 - Retirar um node na posicao N \n";
            cout <<	"7 - Procurar um node com o campo RG \n";
            cout <<	"8 - Imprimir a Lista. \n";
            cout <<	"9 - Sair do sistema. \n";
            cout <<	"\nEscolha um numero e pressione ENTER: \n";
            cin >> funcaoDesejada;

    limpaTela();

    switch(funcaoDesejada){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;

    }

    }


return 0;
}
