APPS = ./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src
BIN = ./bin
LIB = ./lib

MULTIPLE_FLAGS= "-Wl,--allow-multiple-definition"

all: _src clean_apps _apps


clean:
	rm -rf $(BIN)/* $(OBJ)/* $(LIB)/*
clean_apps:
	rm -rf $(BIN)/*

_bin: _apps
_apps: $(BIN)/teste

_obj: _src
_src: \
	$(OBJ)/binary_tree.o 
	ar -rcs $(LIB)/libBinaryTree.a $(OBJ)/*.o

code:
	code $(APPS)/teste.c $(SRC)/binary_tree.c $(INCLUDE)/binary_tree.h


$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.c
	gcc $< $(OBJ)/*.o -I $(INCLUDE) -o $@
	
teste:
	$(BIN)/teste
