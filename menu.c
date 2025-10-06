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
    printf("4. Buscar um item por nome (busca sequencial) (Vetor)\n");
    printf("5. Buscar um item por nome (busca binária) (Vetor)\n");
    printf("6. Ordenar os itens da mochila por nome (Vetor)\n");
    printf("7. Teste entre ordenadores (Vetor)\n");
    printf("8. Adicionar um item na mochila (Lista)\n");
    printf("9. Remover um item da mochila (Lista)\n");
    printf("10. Listar todos os itens na mochila (Lista)\n");
    printf("11. Buscar um item por nome (busca sequencial) (Lista)\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
}
