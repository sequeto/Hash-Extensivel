/*
Profundidade do Diretorio - Número de bits que são usados para identificar
Profunfidade Local - Número de bits que todas as pseudochaves tem em comum
*/

#ifndef DIRETORIO_H_INCLUDED
#define DIRETORIO_H_INCLUDED
#include <string>
#include "Balde.h"

#include <iostream>

using namespace std;

class Diretorio
{
    public:
        Diretorio(int m); // Construtor
        virtual ~Diretorio(); // Destrutor

        void insere(string key);
        bool busca(string key);
        void divide_balde(int index);
        void duplica_diretorio();

        void setProfundidade(int n);
        int getProfundidade();

        void imprime();
        void destroy();
        
    private:
        Balde** diretorio;
        int profundidade;
        int tamanho;
        int teste;
        int defineIndex(string key); // Função para definir index de acesso de acordo com profundidade
        string intToBin(int profundidade, int numero); // Transforma inteiro em binario
};

#endif