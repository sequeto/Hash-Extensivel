#ifndef BALDE_H_INCLUDED
#define BALDE_H_INCLUDED
#include <string>
#include <vector>
#include <bitset>

#include <iostream>

using namespace std;

class Balde
{
    public:
        Balde(int tam, int prof); // Construtor, inicializando todas as posições com menos -1
        virtual ~Balde(); // Destrutor
        void insere(string key); // Insere a chave caso não esteja cheio
        bool buscaChave(string key); // Busca chave no balde
        void destroy(); // Desaloca balde
        void incrementaProfundidadeLocal();
        int getProfundidadeLocal();
        int getTamanho();
        bool verificaCheio(); // Retorna true se o balde estiver cheio
        int getQuantidadeElementos(); // Retorna quantidade de elementos inseridos
        void imprime(); // Imprime os elementos do balde
        string getPosition(int index); // Retorna chave na posição informada
        void clear(); // Seta todas as posiçoes do balde com -1
        Balde* copy(); // Retona uma copia do balde


        void setTeste(int info);
        void getTeste();

    private:
        string* balde;
        int tamanho;
        int profundidadeLocal;
        int quantidadeElementos;
        bool cheio;
        int infoTeste;
};

#endif