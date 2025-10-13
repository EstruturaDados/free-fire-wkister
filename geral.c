#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "geral.h"

// Vetor de tipos de itens
char tipoItens[5][TAM_STRING] = {"Arma", "Municao", "Cura", "Equipamento", "Outro"};

// Funções gerais
/**
 * @brief Função para limpar o buffer de entrada
 */
void limparBufferEntrada(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * @brief Função para exibir os tipos de itens
 * @param tipoItens Vetor de tipos de item
 */
void exibirTiposItens(char tipoItens[5][TAM_STRING]){
    printf("Tipos de Itens Disponíveis:\n");
    for (int i = 0; i < 5; i++){
        printf("%d. %s\n", i + 1, tipoItens[i]);
    }
}

/**
 * @brief Função par imprimir o tempo gasto em operações
 * @param inicio Tempo de início
 * @param fim Tempo de fim
 */
void tempoGasto(clock_t inicio, clock_t fim){
    double tempoGasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo gasto: %.6f segundos\n", tempoGasto);
}

/**
 * @brief Função para pausar a execução até o usuário pressionar Enter
 */
void pausa(){
    printf("Pressione Enter para continuar...");
    getchar();
}
