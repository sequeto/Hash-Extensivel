#include "Balde.h"
#include <iostream>
#include <math.h>

using namespace std;


Balde::Balde(int tam, int prof){
    this->profundidadeLocal = prof;
    this->tamanho = tam;
    this->balde = new string[tam];
    this->cheio = false;
    this->quantidadeElementos = 0;

    // inicializando todas as posições com -1 (string)
    for(int i=0; i<this->tamanho; i++){
        this->balde[i] = "-1";
    }
}

Balde::~Balde(){
    this->tamanho = 0;
    delete [] this->balde;
}

void Balde::destroy(){
    this->tamanho = 0;
    delete [] this->balde;
}

void Balde::insere(string key){
    if(!this->buscaChave(key)){
        if(!cheio){
            this->balde[this->quantidadeElementos] = key;
        }

        this->quantidadeElementos++;

        // Insere informação de cheio caso a quantidade de elementos for igual ao tamanho do balde
        if(this->quantidadeElementos == this->tamanho){
            this->cheio = true;
        }
    }

    else{
        cout << "chave ja inserida" << endl;
    }

}

bool Balde::verificaCheio(){
    return this->cheio;
}

int Balde::getQuantidadeElementos(){
    return this->quantidadeElementos;
}

void Balde::imprime(){
    for(int i = 0; i < this->tamanho; i++){
        cout << this->balde[i] << " --- ";
    }
    cout << endl;
}

void Balde::setTeste(int info){
    this->infoTeste = info;
}

void Balde::getTeste(){
    cout << "balde: " << this->infoTeste << endl;
}

bool Balde::buscaChave(string key){

    for(int i = 0; i<this->tamanho; i++){
        if(key == this->balde[i]){
            return true;
        }
    }
    return false;
}

void Balde::incrementaProfundidadeLocal(){
    this->profundidadeLocal++;
}

int Balde::getProfundidadeLocal(){
    return this->profundidadeLocal;
}

int Balde::getTamanho(){
    return this->tamanho;
}

Balde* Balde::copy(){
    Balde* baldeCopy = new Balde(this->tamanho, this->profundidadeLocal);
    for(int i =0; i < this->tamanho; i++){
        baldeCopy->insere(this->balde[i]);
    }
    return baldeCopy;
}

string Balde::getPosition(int index){
    return this->balde[index];
}

void Balde::clear(){
    // inicializando todas as posições com -1 (string)
    for(int i=0; i<this->tamanho; i++){
        this->balde[i] = "-1";
    }
    this->quantidadeElementos=0;
    this->cheio = false;
}