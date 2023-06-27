#ifndef TABELA_FREQUENCIA_HPP
#define TABELA_FREQUENCIA_HPP

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <clocale>

#define TAM 256

void inicializaTabelaComZero(unsigned int tab[]);

void preencheTabelaFrequencia(unsigned char texto[], unsigned int tab[]);

void imprimeTabelaFrequencia(unsigned int tab[]);

#endif
