APPS = ./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src
BIN = ./bin
LIB = ./lib

all: _src clean_apps _apps

run:
	$(BIN)/linked_list

clean:
	rm -rf $(BIN)/* $(OBJ)/* $(LIB)/*
clean_apps:
	rm -rf $(BIN)/*

_bin: _apps
_apps: $(BIN)/linked_list

_obj: _src
_src: \
	$(OBJ)/linked_list.o 
	ar -rcs $(LIB)/libLinkedList.a $(OBJ)/*.o


$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.c
	gcc $< $(OBJ)/*.o -I $(INCLUDE) -o $@
