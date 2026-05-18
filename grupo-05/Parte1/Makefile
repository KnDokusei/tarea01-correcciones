# Nombre del ejecutable final
TARGET = sensores

# Compilador y banderas
CC = gcc
CFLAGS = -Wall -Iinclude

# Archivos fuente y objetos
SRCS = main.c sensores.c
OBJS = $(SRCS:.c=.o)

# Regla principal: Compilar el proyecto
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Regla para compilar archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar los archivos generados
clean:
	del /f *.o *.exe
run: all
	.\$(TARGET)