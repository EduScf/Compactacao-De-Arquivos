#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa vetop
# Autor		: Wagner Meira Jr. (meira@dcc.ufmg.br)
# Histórico	: 2022-04-02 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/leituraArquivo.o $(OBJ)/tabelaFrequencia.o $(OBJ)/listaOrdenada.o $(OBJ)/dicionario.o $(OBJ)/codificacao.o $(OBJ)/descodificacao.o $(OBJ)/compactacao.o $(OBJ)/descompactacao.o $(OBJ)/main.o
HDRS = $(INC)/leituraArquivo.hpp $(INC)/tabelaFrequencia.hpp $(INC)/listaOrdenada.hpp $(INC)/dicionario.hpp $(INC)/codificacao.hpp $(INC)/descodificacao.hpp $(INC)/compactacao.hpp $(INC)/descompactacao.hpp
CFLAGS = -Wall -c -g3 -I$(INC) -pg

EXE = $(BIN)/main
INPUT_FILE = textoExemplo.txt
INPUT_FILE2 = textoIngles.txt

all:  $(EXE)

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/leituraArquivo.o: $(HDRS) $(SRC)/leituraArquivo.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/leituraArquivo.o $(SRC)/leituraArquivo.cpp

$(OBJ)/tabelaFrequencia.o: $(HDRS) $(SRC)/tabelaFrequencia.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/tabelaFrequencia.o $(SRC)/tabelaFrequencia.cpp

$(OBJ)/listaOrdenada.o: $(HDRS) $(SRC)/listaOrdenada.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/listaOrdenada.o $(SRC)/listaOrdenada.cpp

$(OBJ)/dicionario.o: $(HDRS) $(SRC)/dicionario.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/dicionario.o $(SRC)/dicionario.cpp

$(OBJ)/codificacao.o: $(HDRS) $(SRC)/codificacao.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/codificacao.o $(SRC)/codificacao.cpp

$(OBJ)/descodificacao.o: $(HDRS) $(SRC)/descodificacao.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/descodificacao.o $(SRC)/descodificacao.cpp

$(OBJ)/compactacao.o: $(HDRS) $(SRC)/compactacao.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/compactacao.o $(SRC)/compactacao.cpp

$(OBJ)/descompactacao.o: $(HDRS) $(SRC)/descompactacao.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/descompactacao.o $(SRC)/descompactacao.cpp

run: $(EXE)
	$(EXE) $(INPUT_FILE)
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
