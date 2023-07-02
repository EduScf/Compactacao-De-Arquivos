#ifndef LEITURA_ARQUIVO_HPP
#define LEITURA_ARQUIVO_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

int descobrirTamanho(char *nomeArquivo);

void lerTexto(char *nomeArquivo, unsigned char *texto);

void copiaTexto(const char *nomeArquivoDestino, unsigned char *texto, int tamanho);

void ExecutaOperacoes(char *nomeArquivo, char *nomeArquivoDestino,int flag);

#endif  // LEITURA_ARQUIVO_HPP