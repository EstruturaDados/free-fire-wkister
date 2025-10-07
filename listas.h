#ifndef LISTA_H
#define LISTA_H

// Estrutrura para representar um nó na lista encadeada
typedef struct noMochila {
    char nome[TAM_STRING]; // Nome do item
    char tipo[TAM_STRING]; // Tipo do item (Arma, Munição, Cura, Equipamento, Outro)
    int quntidade; // Quantidade do item
    struct No* proximo; // Ponteiro para o próximo nó na lista
} noMochila;

#endif