#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

