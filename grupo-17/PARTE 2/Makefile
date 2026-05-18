# variables
CXX = g++
CXXFLAGS = -Wall -O0
TARGET = programa

#regla por defecto
all: $(TARGET)

$(TARGET): mediciones.cc
		$(CXX) $(CXXFLAGS) mediciones.cc -o $(TARGET)

#regla para ejecutar
run: all
		./$(TARGET)

#regla para limpiar
clean:
		rm -f $(TARGET)