#ifndef DESCOMPACTACAO_HPP
#define DESCOMPACTACAO_HPP

#include "listaOrdenada.hpp"

unsigned int ehBitUm(unsigned char byte, int posicao);

void descompactar(No *raiz, char *nomeArquivoCompactado, char *nomeArquivoDestino);

#endif