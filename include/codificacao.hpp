#ifndef CODIFICACAO_HPP
#define CODIFICACAO_HPP

#include "tabelaFrequencia.hpp"

int calculaTamanhoString(char **dicionario, char *texto);

char* codificar(char **dicionario, unsigned char *texto);

#endif // CODIFICACAO_HPP