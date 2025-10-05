#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menu.h"

/**
 * @brief Função para exibir o menu principal
 */
void exibirMenu(){
    printf("\n----------------------\n");
    printf("--- MENU PRINCIPAL ---\n");
    printf("----------------------\n");
    printf("1. Adicionar um item na mochila (Vetor)\n");
    printf("2. Remover um item da mochila (Vetor)\n");
    printf("3. Listar todos os itens na mochila (Vetor)\n");
    printf("6. Buscar um item por nome (busca sequencial) (Vetor)\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
}
