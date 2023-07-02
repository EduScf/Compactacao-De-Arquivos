#include "../include/listaOrdenada.hpp"

No::No(){
    this->caractere = 0;
    this->frequencia = 0;
    this->esq = NULL;
    this->dir = NULL;
    this->proximo = NULL;
}

No::No(char c, int freq){
    this->caractere = c;
    this->frequencia = freq;
    this->esq = NULL;
    this->dir = NULL;
    this->proximo = NULL;
}

lista::lista(){
    this->inicio = NULL;
    this->tamanho = 0;
}

lista::lista(lista *lista){
    this->inicio = lista->inicio;
    this->tamanho = lista->tamanho;
}

void lista::inserirOrdenado(lista *lista, No *no){
    No *aux;
    //A lista está vazia?
    if(lista->inicio == NULL){
        lista->inicio = no;
        //lista->tamanho++;
    }
    //tem frequencia menor que o inicio da lista
    else if(no->frequencia < lista->inicio->frequencia){
        no->proximo = lista->inicio;
        lista->inicio = no;
        //lista->tamanho++;
    }

    else{
        aux = lista->inicio;
        while(aux->proximo != NULL && aux->proximo->frequencia < no->frequencia){
            aux = aux->proximo;
        }
        no->proximo = aux->proximo;
        aux->proximo = no;
        //lista->tamanho++;
    }
    lista->tamanho++;
}

void lista::preencherLista(unsigned int tab[], lista *lista){
    No *novo;
    for(int i = 0; i < TAM; i++){
        if(tab[i] > 0){
            novo = new No;
            if(novo){
                novo->caractere = i;
                novo->frequencia = tab[i];
                novo->esq = NULL;
                novo->dir = NULL;
                novo->proximo = NULL;
                inserirOrdenado(lista, novo);
            }
            else{
                std::cout << "Erro ao alocar memoria em preencher lista" << std::endl;
                break;
            }
        }
    }
}

void lista::imprimirLista(lista *lista){
    No *aux = inicio;
    std::cout << std::endl << "Lista ordenada:" << "Tamanho:" << lista->tamanho << std::endl;
    while(aux){
        std::cout << "Caractere: " << aux->caractere << " = " << "Frequencia: " << aux->frequencia << std::endl;
        aux = aux->proximo;
    }
}

No* removeNoInicio(lista *lista){
    No *aux = NULL;

    if(lista->inicio){
        aux = lista->inicio;
        lista->inicio = aux->proximo;
        aux->proximo = NULL;
        lista->tamanho--;
    }
    return aux;
}

No* montarArvore(lista *lista){
    No *primeiro, *segundo, *novo;
    while(lista->tamanho > 1){
        primeiro = removeNoInicio(lista);
        segundo = removeNoInicio(lista);
        novo = new No;

        if(novo){
            novo->caractere = '+';
            novo->frequencia = primeiro->frequencia + segundo->frequencia;
            novo->esq = primeiro;
            novo->dir = segundo;
            novo->proximo = NULL;

            lista->inserirOrdenado(lista, novo);
        }
        else{
            std::cout << "Erro ao alocar memoria em montar arvore" << std::endl;
            break;
        }
    }
    return lista->inicio;
}

void imprimirArvore(No *raiz, int tam){
    if(raiz->esq == NULL && raiz->dir == NULL){//estamos numa folha
        printf("\tFolha: %c \tAltura: %d\n", raiz->caractere, tam);
    }
    else{
        imprimirArvore(raiz->esq, tam + 1);
        imprimirArvore(raiz->dir, tam + 1);
    }
}