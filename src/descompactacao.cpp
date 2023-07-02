#include "../include/descompactacao.hpp"

unsigned int ehBitUm(unsigned char byte, int posicao){
    unsigned char mascara = 1 << posicao;
    return byte & mascara;
}

void descompactar(No *raiz, char *nomeArquivoCompactado, char *nomeArquivoDestino){
    FILE *arquivoCompactado = fopen(nomeArquivoCompactado, "rb");
    FILE *arquivoDestino = fopen(nomeArquivoDestino, "w");
    No *aux = raiz;
    unsigned char byte;

    if(arquivoCompactado){
        while(fread(&byte, sizeof(unsigned char), 1, arquivoCompactado)){
            for(int i = 7; i >= 0; i--){
                if(ehBitUm(byte, i))
                    aux = aux->dir;
                else
                    aux = aux->esq;
                
                if(aux->esq == NULL && aux->dir == NULL){
                    fprintf(arquivoDestino, "%c", aux->caractere);
                    aux = raiz;
                } 
            }
        }
        fclose(arquivoCompactado);
        fclose(arquivoDestino);
    }
    else   
        printf("Erro ao abrir o arquivo de descompactação\n");
}