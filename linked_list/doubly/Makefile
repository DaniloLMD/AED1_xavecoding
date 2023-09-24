APPS = ./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src
BIN = ./bin
LIB = ./lib

all: _src clean_apps _apps


clean:
	rm -rf $(BIN)/* $(OBJ)/* $(LIB)/*
clean_apps:
	rm -rf $(BIN)/*

_bin: _apps
_apps: $(BIN)/teste $(BIN)/teste2

_obj: _src
_src: \
	$(OBJ)/doubly_linked_list.o 
	ar -rcs $(LIB)/libDoublyLinkedList.a $(OBJ)/*.o

code:
	code $(APPS)/teste.c $(SRC)/doubly_linked_list.c $(INCLUDE)/doubly_linked_list.h


$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.c
	gcc $< $(OBJ)/*.o -I $(INCLUDE) -o $@
	
teste:
	$(BIN)/teste

teste2:
	$(BIN)/teste2
