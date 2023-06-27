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
OBJS = $(OBJ)/leituraArquivo.o $(OBJ)/tabelaFrequencia.o $(OBJ)/main.o
HDRS = $(INC)/leituraArquivo.hpp $(INC)/tabelaFrequencia.hpp
CFLAGS = -Wall -c -g3 -I$(INC) -pg

EXE = $(BIN)/main
INPUT_FILE = textoExemplo.txt
INPUT_FILE2 = textoVideo.txt

all:  $(EXE)

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/leituraArquivo.o: $(HDRS) $(SRC)/leituraArquivo.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/leituraArquivo.o $(SRC)/leituraArquivo.cpp

$(OBJ)/tabelaFrequencia.o: $(HDRS) $(SRC)/tabelaFrequencia.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/tabelaFrequencia.o $(SRC)/tabelaFrequencia.cpp

run: $(EXE)
	$(EXE) $(INPUT_FILE2)
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
