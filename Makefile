# Makefile para Free Fire
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -O0 -Wpointer-arith -Wcast-align
LDFLAGS =

# Diretórios
OBJDIR = obj
BINDIR = bin

# Nome do programa executável
PROG = freefire

# Arquivos fonte
SOURCES = FreeFire.c menu.c geral.c vetores.c listas.c
OBJECTS = $(patsubst %.c,$(OBJDIR)/%.o,$(SOURCES))
TARGET = $(BINDIR)/$(PROG)

# Regra principal
all: dirs $(TARGET)

# Regra para criar diretórios
dirs:
	@mkdir -p $(OBJDIR) $(BINDIR)

# Regra para o arquivo objeto
$(OBJDIR)/%.o: %.c
	@echo "Compilando $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para o executável
$(TARGET): $(OBJECTS)
	@echo "Linkando $(PROG)..."
	$(CC) $(OBJECTS) $(LDFLAGS) -o $(TARGET)

# Limpa arquivos compilados
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Executa o programa
run: all
	./$(TARGET)

# Executa com valgrind para verificar vazamentos de memória
valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all $(TARGET)

# Compila com debugging extra
debug: CFLAGS += -DDEBUG -fsanitize=address -fno-omit-frame-pointer
debug: LDFLAGS += -fsanitize=address
debug: clean all

# Declara targets que não são arquivos
.PHONY: all dirs clean run valgrind debug