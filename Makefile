# Makefile para exemplos de Ponteiros - Estrutura de Dados
# Compilador e flags específicas para ponteiros
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -O0 -Wpointer-arith -Wcast-align
LDFLAGS =


# Diretórios
SRCDIR = .
OBJDIR = obj
BINDIR = bin

# Encontra todos os arquivos .c recursivamente
SOURCES = $(shell find $(SRCDIR) -name '*.c')
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES:./%=%))
TARGETS = $(patsubst $(SRCDIR)/%.c,$(BINDIR)/%,$(SOURCES:./%=%))

# Adicione o caminho para menu.c
MENU_SRC = menu.c
MENU_OBJ = $(OBJDIR)/menu.o

# Adicione o caminho para geral.c
GERAL_SRC = geral.c
GERAL_OBJ = $(OBJDIR)/geral.o

# Adicione o caminho para geral.c
VETOR_SRC = vetores.c
VETOR_OBJ = $(OBJDIR)/vetores.o

# Adicione o caminho para geral.c
LISTA_SRC = listas.c
LISTA_OBJ = $(OBJDIR)/listas.o

# Permite compilar um arquivo específico: make file=exemplo.c

ifeq ($(file),)
all: dirs $(TARGETS)
else
# Permite compilar arquivo em subpasta, ex: make file=Tema-2_Listas-e-Ordenacao/MOD1/mod1.c
FILE_PATH = $(file)
FILE_NAME = $(notdir $(FILE_PATH))
FILE_BASE = $(basename $(FILE_NAME))
FILE_OBJ = $(OBJDIR)/$(FILE_BASE).o
FILE_BIN = $(BINDIR)/$(FILE_BASE)
all: dirs $(FILE_BIN)
$(FILE_BIN): $(FILE_PATH) $(MENU_OBJ) $(GERAL_OBJ) $(VETOR_OBJ) $(LISTA_OBJ)
	@mkdir -p $(dir $(FILE_OBJ))
	@mkdir -p $(dir $(FILE_BIN))
	$(CC) $(CFLAGS) -c $(FILE_PATH) -o $(FILE_OBJ)
	$(CC) $(LDFLAGS) $(FILE_OBJ) $(MENU_OBJ) $(GERAL_OBJ) $(VETOR_OBJ) $(LISTA_OBJ) -o $(FILE_BIN)
endif

# Compila funcoes.c em obj/funcoes.o

$(MENU_OBJ): $(MENU_SRC)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(GERAL_OBJ): $(GERAL_SRC)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(VETOR_OBJ): $(VETOR_SRC)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LISTA_OBJ): $(LISTA_SRC)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Cria diretórios necessários
dirs:
	@mkdir -p $(OBJDIR) $(BINDIR)

# Regra para compilar objetos de arquivos em subpastas
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para criar executáveis de objetos em subpastas
$(BINDIR)/%: $(OBJDIR)/%.o
	@mkdir -p $(dir $@)
	$(CC) $(LDFLAGS) $< -o $@

# Limpa arquivos compilados

# Limpa arquivos compilados e temporários
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Limpeza completa: remove objetos, binários e arquivos temporários comuns
cleanall:
	rm -rf $(OBJDIR) $(BINDIR) *.o *~ core a.out *.exe *.out *.obj *.gch

# Executa todos os programas compilados
run: all
	@for exe in $(BINDIR)/*; do \
		if [ -x "$$exe" ]; then \
			echo "=== Executando $$exe ==="; \
			"$$exe"; \
			echo; \
		fi \
	done

# Executa com valgrind para verificar vazamentos de memória
valgrind: all
	@for exe in $(BINDIR)/*; do \
		if [ -x "$$exe" ]; then \
			echo "=== Verificando $$exe com valgrind ==="; \
			valgrind --leak-check=full --show-leak-kinds=all "$$exe"; \
			echo; \
		fi \
	done

# Compila com debugging extra para ponteiros
debug: CFLAGS += -DDEBUG -fsanitize=address -fno-omit-frame-pointer
debug: LDFLAGS += -fsanitize=address
debug: clean all

.PHONY: all dirs clean run valgrind debug