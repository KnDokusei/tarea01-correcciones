TARGET=mediciones

CC=gcc
CXX=g++
RM=rm -f

INCLUDES=-I./include 
LDFLAGS=-L/usr/local/lib 
LDLIBS=

CXXFLAGS=-std=c++17 -Wall

DIR_OBJ=objs

SRCS=$(wildcard *.cc)
OBJS=$(patsubst %.cc,$(DIR_OBJ)/%.o,$(SRCS))


all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDLIBS) $(LDFLAGS) 

$(DIR_OBJ)/%.o: %.cc
	@mkdir -p $(DIR_OBJ)
	$(CXX) -c -o $@ $< $(CXXFLAGS) $(INCLUDES)

clean:
	@$(RM) *~ core
	@$(RM) $(TARGET)
	@$(RM) -rf  $(DIR_OBJ)

# Entrada para actualizar el repositorio.
# Primero elimina archivos temporales y ejecutable
push: clean
	git add .
	git commit -m 'update'
	git push

	