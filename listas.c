#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "geral.h"
#include "listas.h"

// -- Funções de manipulação da mochila usando listas encadeadas --

// /**
//  * @brief Função para liberar a memória alocada para a lista
//  * @param mochila Ponteiro para o início da lista
//  */
// void liberarMemoriaLista(struct mochilaLista** mochila){

// }

/**
 * @brief Função para inserir um item na lista
 * @param mochila Ponteiro para o início da lista
 * @param tipoItens Matriz de strings com os tipos de itens disponíveis
 */
void inserirItemLista(struct mochilaLista** mochila, char tipoItens[5][TAM_STRING]){
  printf("\n----------------------------------\n");
  printf("--- Adicionar Itens na Mochila (Lista encadeada) ---\n");
  printf("----------------------------------\n");

  // Verificar se a Mochila está cheia
  if ((*mochila)->numItens >= MAX_ITENS){
    printf("A mochila está cheia. Não é possível adicionar mais itens.\n");
  } else {
    char item[TAM_STRING];
    int quantidade = 0;

    do {
      // Inicializando o novo nó
      noMochila* novoNo = (noMochila*) malloc(sizeof(noMochila));
      if (novoNo == NULL){
        printf("Erro na alocação de memória para o novo item.\n");
        free(novoNo);
        return;
      }

      novoNo->proximo = NULL; // Inicializa o próximo como NULL
      novoNo->quantidade = 0; // Inicializa a quantidade como 0

      // Solicitar o nome do item
      printf("Digite o nome do item a ser adicionado na mochila (ou pressione Enter para sair): ");
      fgets(item, TAM_STRING, stdin);
      item[strcspn(item, "\n")] = 0; // Remover o caractere de nova linha

      // Copiar o item para a mochila se o item não estiver vazio
      if (strlen(item) > 0){
        // Solicitar a quantidade do item
        do{
          printf("Quanatos itens foram encontrados? ");
          scanf("%d", &quantidade);
          limparBufferEntrada();
        } while (quantidade < 1);

        // Procurar pelo item na lista
        int indiceItem = buscarItemPorNomeLista(*mochila, item);
        if (indiceItem != -1){
          // Item já existe, incrementar a quantidade
          noMochila* atual = (*mochila)->mochila;

          // Varrer a lista até o índice do item encontrado
          for (int i = 0; i < indiceItem; i++){
            atual = atual->proximo;
          }

          // Incrementar a quantidade do item existente
          atual->quantidade += quantidade;
          printf("Item '%s' já existe na mochila. Quantidade incrementada para %d.\n", item, atual->quantidade);
          free(novoNo); // Liberar a memória alocada para o novo nó, pois não será usado
        } else {
          // Copiando o nome do item para a mochila
          strcpy(novoNo->nome, item);
          // Incrementando o número de itens na mochila
          (*mochila)->numItens++;
          // Solicitar o tipo do item
          exibirTiposItens(tipoItens);
          int tipoEscolhido;
          do {
            printf("Digite o número correspondente ao tipo do item: ");
            scanf("%d", &tipoEscolhido);
            limparBufferEntrada();
            if (tipoEscolhido < 1 || tipoEscolhido > 5){

    printf("Qual o nome do item a ser adicionado na mochila (ou pressione Enter para sair)? ");
  }
}

/**
 * @brief Função para remover um item da lista
 * @param mochila Ponteiro para o início da lista
 */
// void removerItemLista(struct mochilaLista** mochila){

// }

/**
 * @brief Função para listar os itens na lista
 * @param mochila Ponteiro para o início da lista
 */
// void listarItensLista(struct mochilaLista* mochila){

// }

/**
 * @brief Função para buscar um item na lista sequencialmente
 * @param mochila Ponteiro para o início da lista
 */
// void buscarItemLista(struct mochilaLista* mochila){

// }

/**
 * @brief Função para buscar um item por nome na lista, retornando sua posição ou -1 se não encontrado
 * @param mochila Ponteiro para o início da lista
 * @param nome Nome do item a ser buscado
 * @return Posição do item na lista (0-based) ou -1 se não encontrado
 */
int buscarItemPorNomeLista(struct mochilaLista* mochila, char nome[TAM_STRING]){
    noMochila* atual = mochila->mochila;
    int posicao = 0;
    while (atual != NULL){
        if (strcmp((*atual)->nome, nome) == 0){
            return posicao; // Item encontrado, retornar a posição
        }
        atual = atual->proximo;
        posicao++;
    }
    // Item não encontrado
    return -1;
}