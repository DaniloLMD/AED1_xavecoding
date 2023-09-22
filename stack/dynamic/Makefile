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
	$(OBJ)/dynamic_stack.o 
	ar -rcs $(LIB)/libDynamicStack.a $(OBJ)/*.o

code:
	code $(APPS)/teste.c $(SRC)/dynamic_stack.c $(INCLUDE)/dynamic_stack.h


$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.c
	gcc $< $(OBJ)/*.o -I $(INCLUDE) -o $@
