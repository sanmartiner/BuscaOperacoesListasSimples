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

void imprimeSequencial(pessoa *ponteiroSequencial, int tamanhoDaLista){
    int cont;
    for(cont = 0; cont < tamanhoDaLista; cont++){
        cout << cont << " - " << ponteiroSequencial[cont].nome << ", " << ponteiroSequencial[cont].rg << "\n";
    }
}

void adcComecoSequencial(pessoa *&ponteiroSequencial, int *tamanhoDaLista, string nome, int rg){

    //Verificar se a lista est� vazia ou n�o.
    if(*tamanhoDaLista == 0){
        pessoa *novaListaSequencial = new pessoa[1];

        //Insere os novos elementos
        novaListaSequencial[0].nome = nome ;
        novaListaSequencial[0].rg = rg;

        //Atualiza o ponteiro para a lista nova.
        ponteiroSequencial = novaListaSequencial;

    } else {
        //Caso a lista j� tenha membros
        pessoa *novaListaSequencial = new pessoa[*tamanhoDaLista + 1];

        //Insere os novos elementos
        novaListaSequencial[0].nome = nome ;
        novaListaSequencial[0].rg = rg;

        //Passar elementos para uma lista nova

        int cont;
        for(cont = 0; cont < *tamanhoDaLista; cont++){
            novaListaSequencial[cont + 1].nome = ponteiroSequencial[cont].nome;
            novaListaSequencial[cont + 1].rg = ponteiroSequencial[cont].rg;
        }


        //Atualiza o ponteiro para a lista nova.

        ponteiroSequencial = novaListaSequencial;
    }
    //Aumenta o tamanho da lista
    *tamanhoDaLista = *tamanhoDaLista + 1;
}

void adcFimSequencial(pessoa *&ponteiroSequencial, int *tamanhoDaLista, string nome, int rg){
    //Cria uma lista com um tamanho maior
    pessoa *novaListaSequencial = new pessoa[*tamanhoDaLista + 1];

    //Passar elementos para uma lista nova

    int cont;
    for(cont = 0; cont < *tamanhoDaLista; cont++){
    novaListaSequencial[cont].nome = ponteiroSequencial[cont].nome;
    novaListaSequencial[cont].rg = ponteiroSequencial[cont].rg;
    }

    //Posiciona o ultimo elemento
    novaListaSequencial[*tamanhoDaLista].nome = nome;
    novaListaSequencial[*tamanhoDaLista].rg = rg;

    //Atualiza o ponteiro para  a lista nova
    ponteiroSequencial = novaListaSequencial;

    //Aumenta o tamanho da lista
    *tamanhoDaLista = *tamanhoDaLista + 1;

}

void adcPosicaoSequencial(pessoa *&ponteiroSequencial, int *tamanhoDaLista, string nome, int rg, int posicao){
    //Cria uma lista com um tamanho maior
    pessoa *novaListaSequencial = new pessoa[*tamanhoDaLista + 1];

    //Passar elementos para uma lista nova

    int cont;
    for(cont = 0; cont < posicao; cont++){
    novaListaSequencial[cont].nome = ponteiroSequencial[cont].nome;
    novaListaSequencial[cont].rg = ponteiroSequencial[cont].rg;
    }

    //Adicionar o novo registro na posicao correta
    novaListaSequencial[posicao].nome = nome;
    novaListaSequencial[posicao].rg = rg;

    //Colocar o resto dos valores antigos.
     for(cont = posicao + 1; cont < *tamanhoDaLista + 1; cont++){
        novaListaSequencial[cont].nome = ponteiroSequencial[cont - 1].nome;
        novaListaSequencial[cont].rg = ponteiroSequencial[cont - 1].rg;
    }

    //Atualiza o ponteiro para a lista nova
    ponteiroSequencial = novaListaSequencial;

    //Aumenta o tamanho da lista
    *tamanhoDaLista = *tamanhoDaLista + 1;
}

void removeInicioSequencial(pessoa *&ponteiroSequencial, int *tamanhoDaLista){

    //Cria um vetor com uma posi��o a menos
    pessoa *novaListaSequencial = new pessoa[*tamanhoDaLista - 1];

    //Passar elementos para uma lista nova

    int cont;
    for(cont = 1; cont < *tamanhoDaLista; cont++){
    novaListaSequencial[cont - 1].nome = ponteiroSequencial[cont].nome;
    novaListaSequencial[cont - 1].rg = ponteiroSequencial[cont].rg;
    }

    //Atualiza o ponteiro para a lista nova
    ponteiroSequencial = novaListaSequencial;

    //Aumenta o tamanho da lista
    *tamanhoDaLista = *tamanhoDaLista - 1;
}

void removeFimSequencial(pessoa *&ponteiroSequencial, int *tamanhoDaLista){
     //Cria um vetor com uma posi��o a menos
    pessoa *novaListaSequencial = new pessoa[*tamanhoDaLista - 1];

    //Passar elementos para uma lista novo menos o ultimo

    int cont;
    for(cont = 0; cont < *tamanhoDaLista - 1; cont++){
    novaListaSequencial[cont].nome = ponteiroSequencial[cont].nome;
    novaListaSequencial[cont].rg = ponteiroSequencial[cont].rg;
    }

    //Atualiza o ponteiro para a lista nova
    ponteiroSequencial = novaListaSequencial;

    //Aumenta o tamanho da lista
    *tamanhoDaLista = *tamanhoDaLista - 1;
}

void removePosicaoSequencial(pessoa *&ponteiroSequencial, int *tamanhoDaLista, int posicao){

      //Cria um vetor com uma posi��o a menos
    pessoa *novaListaSequencial = new pessoa[*tamanhoDaLista - 1];

    int cont;

    for(cont = 0; cont < *tamanhoDaLista - 1; cont++){
        //Se estiver antes da posi��o passa normalmente
        if(cont < posicao){
            novaListaSequencial[cont].nome = ponteiroSequencial[cont].nome;
            novaListaSequencial[cont].rg = ponteiroSequencial[cont].rg;
        } else {
            novaListaSequencial[cont].nome = ponteiroSequencial[cont+1].nome;
            novaListaSequencial[cont].rg = ponteiroSequencial[cont+1].rg;
        }
    }
}

string retornaNomeSequencial(pessoa *&ponteiroSequencial, int *tamanhoDaLista, int rg){
    string nome = "N�o encontrado";

    //Busca pelo nome digitado
    int cont;
    for(cont = 0; cont < *tamanhoDaLista ; cont++){
        if(ponteiroSequencial[cont].rg == rg){
            nome = ponteiroSequencial[cont].nome;
        }
    }
    return nome;
}
// ---------------------- FUN��O PRINCIPAL ----------------------//

int main(){

    setlocale(LC_ALL, "");

    //VARIAVEIS
    int funcaoDesejada = 1;

    //Ponteiro para a lista sequencial

    pessoa *ponteiroSequencial;

    //Tamanho da lista
    int tamanhoDaLista = 0;

    //MENU
    while(funcaoDesejada < 9 && funcaoDesejada > 0){

            //Mostrando o meunu
            cout <<	"Opera��es \n";
            cout <<	"1 - Inser��o de um node no inicio da lista \n";
            cout <<	"2 - Inser��o de um node no fim da lista \n";
            cout <<	"3 - Inser��o de um node na posi��o N \n";
            cout <<	"4 - Retirar um node do inicio da lista \n";
            cout <<	"5 - Retirar um node do fim da lista \n";
            cout <<	"6 - Retirar um node na posicao N \n";
            cout <<	"7 - Procurar um node com o campo RG \n";
            cout <<	"8 - Imprimir a Lista. \n";
            cout <<	"9 - Sair do sistema. \n";
            cout <<	"\nEscolha um numero e pressione ENTER: \n";
            cin >> funcaoDesejada;

    limpaTela();

    //VARIAVEIS USADAS NAS OPERA��ES

    string nome;
    int rg, posicao;

    switch(funcaoDesejada){
        case 1:
            cout << "Fun��o escolhida: 1 - Inser��o de um node no inicio da lista \n";
            cout << "Digite um nome: ";
            cin >> nome;
            cout << "Digite um RG: ";
            cin >> rg;

            adcComecoSequencial(ponteiroSequencial, &tamanhoDaLista, nome, rg);

            break;
        case 2:
            cout << "Fun��o escolhida: 2 - Inser��o de um node no fim da lista \n";
            cout << "Digite um nome: ";
            cin >> nome;
            cout << "Digite um RG: ";
            cin >> rg;

            if(tamanhoDaLista == 0){
            //Se a lista for vazia, usamos a fun��o de criar no inicio.
                adcComecoSequencial(ponteiroSequencial, &tamanhoDaLista, nome, rg);
            } else {
                //Adiciona posi��o especifica
                adcFimSequencial(ponteiroSequencial, &tamanhoDaLista, nome, rg);
            }

            break;
        case 3:
            cout << "Fun��o escolhida: 3 - Inser��o de um node na posi��o N\n";
            cout << "\n Digite uma Posicao: ";
            cin >> posicao;
            cout << "Digite um nome: ";
            cin >> nome;
            cout << "\n Digite um RG: ";
            cin >> rg;


            //Se estiver adicionando no come�o.
             if(posicao == 0){
                adcComecoSequencial(ponteiroSequencial, &tamanhoDaLista, nome, rg);
             } else if(posicao == tamanhoDaLista){
                adcFimSequencial(ponteiroSequencial, &tamanhoDaLista, nome, rg);
             } else {
                adcPosicaoSequencial(ponteiroSequencial, &tamanhoDaLista, nome, rg, posicao);
             }
            break;
        case 4:
            cout << "Fun��o escolhida: 4 - Retirar um node do inicio.\n";
            if(tamanhoDaLista == 0 ){
                cout << "\n Lista vazia! \n";
                } else {
                removeInicioSequencial(ponteiroSequencial, &tamanhoDaLista);
               }
            break;
        case 5:
            cout <<	"Fun��o escolhida: 5 - Retirar um node do fim da lista \n";
             if(tamanhoDaLista == 0 ){
                cout << "\n Lista vazia! \n";
                } else {
                removeFimSequencial(ponteiroSequencial, &tamanhoDaLista);
                }
            break;
        case 6:
            cout << "Fun��o escolhida: 6 - Retirar um node na posicao N \n";
             if(tamanhoDaLista == 0 ){
                cout << "\n Lista vazia! \n";
                } else {
                cout << "Digite uma posi��o";
                cin >> posicao;
                if(posicao == 0){
                    removeInicioSequencial(ponteiroSequencial, &tamanhoDaLista);
                } else if(posicao == tamanhoDaLista - 1){
                    removeFimSequencial(ponteiroSequencial, &tamanhoDaLista);
                } else {
                removePosicaoSequencial(ponteiroSequencial, &tamanhoDaLista, posicao);
                }
            break;
        case 7:
            cout <<	"7 - Procurar um node com o campo RG \n";
             if(tamanhoDaLista == 0 ){
                cout << "\n Lista vazia! \n";
                } else {
                cout << "Digite um RG.";
                cin >> rg;
                cout << "Nome: " << retornaNomeSequencial(ponteiroSequencial, &tamanhoDaLista, rg);
                }
            break;
        case 8:
            //Imprime a lista completa
            imprimeSequencial(ponteiroSequencial, tamanhoDaLista);
            break;
        case 9:
            system("s");
            break;



        }
    }
}
    return 0;
}
