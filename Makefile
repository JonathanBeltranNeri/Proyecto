# Definición de variables
CC := g++
CFLAGS := -Wall -Wextra -pedantic -std=c++11 -g
LDFLAGS := -lcurses
SRC_DIR := src
INC_DIR := include
BIN_DIR := bin

# Lista de archivos fuente
SRCS := $(wildcard $(SRC_DIR)/*.cpp)

# Lista de objetos
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(SRCS))

# Archivo de encabezado adicional
INC_FILES := include/Dibujo.hpp

# Nombre del ejecutable
EXEC := $(BIN_DIR)/Tetris

# Regla para el ejecutable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC) $(LDFLAGS)

# Regla para compilar los archivos fuente
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_FILES)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Regla para limpiar los archivos generados
clean:
	rm -f $(OBJS) $(EXEC)

# Regla para ejecutar el programa
run: $(EXEC)
	$(EXEC)
