#ifndef DICIONARIO_HPP
#define DICIONARIO_HPP

#include "listaOrdenada.hpp"

int alturaArvore(No *raiz);

char** alocaDicionario(int colunas);

void gerarDicionario(char **dicionario, No *raiz, char *caminho, int colunas);

void imprimeDicionario(char **dicionario);

#endif // DICIONARIO_HPP