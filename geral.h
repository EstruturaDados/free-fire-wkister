#ifndef GERAL_H
#define GERAL_H

// --- Constantes ---
#define TAM_STRING 50 // Tamanho máximo para strings
#define MAX_ITENS 100 // Tamanho máximo de itens na mochila

// Vetor de tipos de itens
extern char tipoItens[5][TAM_STRING];

// Estrutura para representar um item na mochila
struct Item {
    char nome[TAM_STRING]; // Nome do item
    char tipo[TAM_STRING]; // Tipo do item (Arma, Munição, Cura, Equipamento, Outro)
    int quantidade; // Quantidade do item
};

// --- Protótipos das funções gerais ---
// Função para limpar o buffer de entrada
void limparBufferEntrada();

// Mostrar os tipos de item para escolha
void exibirTiposItens(char tipoItens[5][TAM_STRING]);

// Função para imprimir o tempo gasto em operações
void tempoGasto(clock_t inicio, clock_t fim);

#endif