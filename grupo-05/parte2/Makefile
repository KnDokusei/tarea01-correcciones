TARGET=mediciones

CC=gcc
RM=rm -f


CFLAGS=-Wall -I.

DIR_OBJ=objs


SRCS=$(wildcard *.c)
OBJS=$(patsubst %.c,$(DIR_OBJ)/%.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

$(DIR_OBJ)/%.o: %.c
	@mkdir -p $(DIR_OBJ)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	@$(RM) $(TARGET)
	@$(RM) -rf $(DIR_OBJ)

