#include <string>
#include <math.h>
#include <iostream>
#include <time.h>

#include "Diretorio.h"
#include "Balde.h"

using namespace std;

string geraChavesAleatorias(int n, int modulo){
    string key;
    int random;
    if(modulo == 1){
        for(int i = 0; i<n; i++){
            random = rand() % 1000;
            random = random % 2;
            key.append(to_string(random));
        }
    }

    else{
        key.append("00");
        for(int i = 2; i<n; i++){
            random = rand() % 1000;
            random = random % 2;
            key.append(to_string(random));
        }
    }

    return key;
}

void moduloTeste(int m, int b, int modulo){
    Diretorio dir(m);
    int n;
    string key;
    cout << "Digite um valor para a quantidade de chaves a ser inserida: " << endl;
    cin >> n;

    for(int i = 0; i < n; i ++){
        key = geraChavesAleatorias(b, modulo);
        cout << "Chave: " << key << endl;
        dir.insere(key);
    }

    cout << "Diretorio: " << endl;
    dir.imprime();
}

int main(){
    srand(time(NULL));

    int m, b;
    int opcao;

    cout << "Digite o tamanho M dos baldes: " << endl;
    cin >> m;

    cout << "Digite o numero de bits a ser usado para as pseudochaves: " << endl;
    cin >> b;

    cout << "Selecione uma opcao: " << endl;
    cout << "1 - PseudoChaves aleatorios" << endl;
    cout << "2 - PseudoChaves aleatorias iniciados com 00" << endl;

    cin >> opcao;
    
    if(opcao == 1 || opcao == 2){
        moduloTeste(m, b, opcao);
    }

    else{
        cout << "Opção Invalida" << endl;
    }

    // Teste da aula
    // d.insere("00001");
    // d.insere("01100");
    // d.insere("10000");
    // d.insere("10001");
    // d.insere("11001");
    // d.insere("10101");
    // d.insere("01111");
    // d.insere("00100");
    // d.insere("11111");
}