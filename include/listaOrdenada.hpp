#ifndef LISTA_ORDENADA_HPP
#define LISTA_ORDENADA_HPP

#include <iostream>
#include "tabelaFrequencia.hpp"

class No{
    public:
        int frequencia;
        unsigned char caractere;
        No *esq, *dir, *proximo;
        No();
        No(char c, int freq);
};

class lista{
    public:
        No *inicio;
        int tamanho;
        lista();
        lista(lista *lista);
        void inserirOrdenado(lista *lista, No *no);
        void preencherLista(unsigned int tab[], lista *lista);
        void imprimirLista(lista *lista);
};

No* removeNoInicio(lista *lista);
No* montarArvore(lista *lista);
void imprimirArvore(No *raiz, int tamanho);

#endif  // LISTA_ORDENADA_HPP