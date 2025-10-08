#ifndef LISTA_H
#define LISTA_H

/**
 * @file listas.h
 * @brief Protótipos das funções e constantes para manipulação de listas encadeadas
 * @author Wellington Kister do Nascimento
 */

// Estrutrura para representar um nó na lista encadeada
typedef struct noMochila {
    char nome[TAM_STRING];     // Nome do item
    char tipo[TAM_STRING];     // Tipo do item (Arma, Munição, Cura, Equipamento, Outro)
    int quantidade;            // Quantidade do item
    struct noMochila* proximo; // Ponteiro para o próximo nó na lista
} noMochila;

// Definição da estrutura da mochila usando lista encadeada
struct mochilaLista {
    noMochila* inicio; // Ponteiro para o início da lista
    int numItens;      // Quantidade de itens na mochila
    int ordenado;      // Flag para indicar se a mochila está ordenada (1 - Sim, 0 - Não)
};

// Protótipos das funções de manipulação da mochila usando listas encadeadas
// void liberarMemoriaLista(struct mochilaLista** inicio); // Libera a memória alocada para a lista
void inserirItemLista(struct mochilaLista** inicio, char tipoItens[5][TAM_STRING]); // Insere um item na lista
void removerItemLista(struct mochilaLista** inicio); // Remove um item da lista
void listarItensLista(struct mochilaLista* inicio); // Lista os itens na lista
void buscarItemLista(struct mochilaLista* inicio); // Busca um item na lista sequencialmente
int buscarItemPorNomeLista(struct mochilaLista* inicio, char nome[TAM_STRING]); // Busca um item por nome na lista, retornando sua posição ou -1 se não encontrado

#endif