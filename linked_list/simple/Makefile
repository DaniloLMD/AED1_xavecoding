APPS = ./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src
BIN = ./bin
LIB = ./lib

all: _src clean_apps _apps

teste:
	$(BIN)/teste

clean:
	rm -rf $(BIN)/* $(OBJ)/* $(LIB)/*
clean_apps:
	rm -rf $(BIN)/*

_bin: _apps
_apps: $(BIN)/teste

_obj: _src
_src: \
	$(OBJ)/simple_linked_list.o


	ar -rcs $(LIB)/libSimple_LinkedList.a $(OBJ)/*.o

code:
	code $(APPS)/teste.c $(SRC)/simple_linked_list.c $(INCLUDE)/simple_linked_list.h


$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.c
	gcc $< $(OBJ)/*.o -I $(INCLUDE) -o $@
