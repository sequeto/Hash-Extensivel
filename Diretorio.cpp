#include <string>
#include <math.h>
#include <iostream>
#include <algorithm>

#include "Diretorio.h"
#include "Balde.h"

using namespace std;

Diretorio::Diretorio(int m){
    //teste
    this->teste = 1;

    // Setando profundidade inicial
    this->profundidade = 1;

    // Tamanho do diretorio 2 ^ profundidade global
    this->tamanho = pow(2,this->profundidade);

    // Alocando memória para o diretório
    this->diretorio = new Balde*[tamanho];

    // Alocando Balde
    Balde* balde = new Balde(m, 0);
    // Linha de Teste
    balde->setTeste(this->teste);

    // For atribuindo o endereço de um único balde a todos os ponteiros do diretorio (Verificar com o professor)
    for(int i = 0; i < this->tamanho; i++){
        this->diretorio[i] = balde;
    }
}

Diretorio::~Diretorio(){
    for(int i = 0; i < this->tamanho; i++){
        this->diretorio[i]->destroy();
    }

    delete [] this->diretorio;
}

void Diretorio::destroy(){
    delete [] this->diretorio;
}

void Diretorio::insere(string key){
    // Index de acesso
    int index = this->defineIndex(key);

    //verificando se o balde está cheio
    if(this->diretorio[index]->verificaCheio()){
        if(this->diretorio[index]->getProfundidadeLocal() == this->profundidade){
            this->duplica_diretorio();
            index = this->defineIndex(key);
        }
        this->divide_balde(index);
        this->insere(key);
    }

    else{
        this->diretorio[index]->insere(key);
    }
}

bool Diretorio::busca(string key){
    int index = this->defineIndex(key);
    return this->diretorio[index]->buscaChave(key); // Realizando busca no index definido
}

void Diretorio::divide_balde(int index){
    //Fazer copia do balde
    Balde* baldeCopy = this->diretorio[index]->copy();

    // Guardar ponteiro do balde original
    Balde* pb = this->diretorio[index];
    bool flag = false;

    // Alocar novo balde com profundidade incrementada
    this->teste++;
    Balde* novoBalde = new Balde(this->diretorio[index]->getTamanho(), this->diretorio[index]->getProfundidadeLocal());
    novoBalde->incrementaProfundidadeLocal();
    novoBalde->setTeste(this->teste);

    // Incrementando profundidade do balde dividido
    this->diretorio[index]->incrementaProfundidadeLocal();

    //Limpando o Balde
    this->diretorio[index]->clear();

    //Ajustar o Ponteiro
    for(int i = index; i < this->tamanho; i++){
        if(this->diretorio[i] == pb){
            if(flag){
                this->diretorio[i] = novoBalde;
            }
            flag = !flag;
        }
    }

    flag = false;

    for(int i = index; i >= 0; i--){
        if(this->diretorio[i] == pb){
            if(flag){
                this->diretorio[i] = novoBalde;
            }
            flag = !flag;
        }
    }

    // Percorrer a copia redistribuindo as chaves
    for(int i=0; i < baldeCopy->getTamanho(); i++){
        this->insere(baldeCopy->getPosition(i));
    }

    // Destruindo copia
    baldeCopy->destroy();
}

void Diretorio::duplica_diretorio(){
    // Novo balde duplicado
    Balde** diretorioDuplicado = new Balde*[this->tamanho*2];

    //Variaveis auxiliares
    string bits;
    string strAux;
    Balde* pb;


    // Ajuste de ponteiros
    for(int i = 0; i < this->tamanho; i++){
        bits = this->intToBin(this->profundidade, i);
        pb = this->diretorio[i];

        for(int j = 0; j < this->tamanho*2; j++){
            strAux = this->intToBin(this->profundidade+1, j);
            strAux = strAux.substr(0, this->profundidade);
            if(bits == strAux){
                diretorioDuplicado[j] = pb;
            }
        }
    }

    //Atualizando o tamanho;
    this->tamanho *= 2;

    // Incrementando a profundidade
    this->profundidade++;

    // Desalocando lista inicial
    this->destroy();

    this->diretorio = diretorioDuplicado;
}

int Diretorio::getProfundidade(){
    return this->profundidade;
}

string Diretorio::intToBin(int profundidade, int numero){
    string binario;
    for (int i = 0; i < profundidade; i++){
        // Comparando bit
        if (numero & 1)
            binario += '1';
        else
            binario += '0';
        // deslocando bits para direita
        numero = numero >> 1;
    }
    reverse(binario.begin(), binario.end());
    return binario;
}

int Diretorio::defineIndex(string key){;
    string bits = key.substr(0, this->profundidade); // Retorna os d bits da profundidade
    int index = stoi(bits, nullptr, 2); // Transformando os bits extraidos em indice

    return index;
}

void Diretorio::imprime(){
    for(int i = 0; i < this->tamanho; i++){
        cout << i << " --->";
        this->diretorio[i]->imprime();

        //Linha de teste
        this->diretorio[i]->getTeste();
    }
}
