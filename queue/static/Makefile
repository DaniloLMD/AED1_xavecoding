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
	$(OBJ)/static_queue.o 
	ar -rcs $(LIB)/libStaticQueue.a $(OBJ)/*.o

code:
	code $(APPS)/teste.c $(SRC)/static_queue.c $(INCLUDE)/static_queue.h


$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.c
	gcc $< $(OBJ)/*.o -I $(INCLUDE) -o $@
