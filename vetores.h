#ifndef VETORES_H
#define VETORES_H

/**
 * @file funcoes_vetores.h
 * @brief Protótipos das funções e constantes para manipulação de vetores
 * @author Wellington Kister do Nascimento
 */

// --- Constantes ---
#define MAX_ITENS 100  // Tamanho máximo de itens na mochila
#define MAX_JOGADORES 10 // Número máximo de jogadores

// --- Definição da Estrutura de Dados ---
// Estrutura para representar um item na mochila
struct Item {
    char nome[TAM_STRING]; // Nome do item
    char tipo[TAM_STRING]; // Tipo do item (Arma, Munição, Cura, Equipamento, Outro)
    int quntidade; // Quantidade do item
};

// Estrutra para a mochila
typedef struct mochila{
    struct Item itens[MAX_ITENS]; // Vetor de itens, com no maáximo de MAX_ITENS
    int numItens; // Quantidade de itens na mochila
    int ordenado; // Flag para indicar se a mochila está ordenada (1 - Sim, 0 - Não)
} mochila;

// Protótipos das funções de manipulação da mochila usando vetores
void cadastrarItem(mochila *m, char tipoItens[5][TAM_STRING]);
void removerItem(mochila *m);
void removerItemPorNome(mochila *m, char item[TAM_STRING]);
void listarItens(mochila m);
void buscarItem(mochila m);
int buscarItemPorNome(mochila m, char nome[TAM_STRING]); // Busca sequencial
void buscaBinaria(mochila m); // Busca binária (a mochila deve estar ordenada por nome)
void buscarItemBinariaPorNome(mochila m, char nome[TAM_STRING]);
void buscarItemBinariaRecursivaAux(mochila m, char nome[TAM_STRING], int inicio, int fim, int *numOperacoes);
void ordenarItensPorNome(mochila *m); // Ordenação por nome (Bubble Sort)

#endif