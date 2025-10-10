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
void inserirItemMochila(struct mochilaLista* mochila, char tipoItens[5][TAM_STRING]){
  printf("\n----------------------------------------------------\n");
  printf("--- Adicionar Itens na Mochila (Lista encadeada) ---\n");
  printf("----------------------------------------------------\n");

  // Verificar se a Mochila está cheia
  if ((*mochila).numItens >= MAX_ITENS){
    printf("A mochila está cheia. Não é possível adicionar mais itens.\n");
  } else {
    char item[TAM_STRING];
    int quantidade = 0;
    char escolha;

    // Inicializando o novo nó
      noMochila* novoNo = (noMochila*) malloc(sizeof(noMochila));
      if (novoNo == NULL){
        printf("Erro na alocação de memória para o novo item.\n");
        free(novoNo);
        return;
      }

      novoNo->proximo = NULL; // Inicializa o próximo como NULL
      novoNo->item.quantidade = 0; // Inicializa a quantidade como 0

    printf("Você deseja adicionar alguns itens automaticamente para teste? (s/n): ");
    scanf(" %c", &escolha);
    limparBufferEntrada();
    if (escolha == 's' || escolha == 'S'){
      /**
       * ------------------------------------------------------
       * MODO DE ADIÇÃO DE ITENMS MANUAL
       * DEVE SER APAGADO EM MODO PRODUÇÃO
       * ------------------------------------------------------
       */
      // Testa se a mochila está vazia
      if (mochila->lista != NULL){
        printf("\n--------------------------\n");
        printf("A mochila já contém itens. Não é possível adicionar itens automaticamente.\n");
        printf("--------------------------\n");
        // free(novoNo); // Liberar a memória alocada para o novo nó, pois não será usado
        return;
      }
      // Item 1
      novoNo->item.quantidade = (rand() % 5) + 1;
      snprintf(novoNo->item.nome, TAM_STRING, "Bandagem", (*mochila).numItens + 1);
      strcpy(novoNo->item.tipo, "Cura");
      // Inserindo o novo nó no início da lista
      novoNo->proximo = (*mochila).lista;
      (*mochila).lista = novoNo;
      (*mochila).numItens++;
      // Item 2
      novoNo->item.quantidade = (rand() % 5) + 1;
      snprintf(novoNo->item.nome, TAM_STRING, "Pistola", (*mochila).numItens + 1);
      strcpy(novoNo->item.tipo, "Arma");
      // Inserindo o novo nó no início da lista
      novoNo->proximo = (*mochila).lista;
      (*mochila).lista = novoNo;
      (*mochila).numItens++;
      // Item 3
      novoNo->item.quantidade = 0; // Inicializa a quantidade como 0
      novoNo->item.quantidade = (rand() % 5) + 1;
      snprintf(novoNo->item.nome, TAM_STRING, "Municaoo de Pistola", (*mochila).numItens + 1);
      strcpy(novoNo->item.tipo, "Municao");
      // Inserindo o novo nó no início da lista
      novoNo->proximo = (*mochila).lista;
      (*mochila).lista = novoNo;
      (*mochila).numItens++;
      // Item 4
      novoNo->item.quantidade = (rand() % 5) + 1;
      snprintf(novoNo->item.nome, TAM_STRING, "Colete", (*mochila).numItens + 1);
      strcpy(novoNo->item.tipo, "Equipamento");
      // Inserindo o novo nó no início da lista
      novoNo->proximo = (*mochila).lista;
      (*mochila).lista = novoNo;
      (*mochila).numItens++;
      // Item 5
      novoNo->item.quantidade = (rand() % 5) + 1;
      snprintf(novoNo->item.nome, TAM_STRING, "Kit Medico", (*mochila).numItens + 1);
      strcpy(novoNo->item.tipo, "Cura");
      // Inserindo o novo nó no início da lista
      novoNo->proximo = (*mochila).lista;
      (*mochila).lista = novoNo;
      (*mochila).numItens++;
      return;
      /**
       * ------------------------------------------------------
       * MODO DE ADIÇÃO DE ITENMS MANUAL
       * DEVE SER APAGADO EM MODO PRODUÇÃO
       * ------------------------------------------------------
       */
    } else {
      // Loop para adicionar um item, parando quando entrar um item vazio
      do {
        // Solicitar o nome do item
        printf("Digite o nome do item a ser adicionado na mochila (ou pressione Enter para sair): ");
        fgets(item, TAM_STRING, stdin);
        item[strcspn(item, "\n")] = 0; // Remover o caractere de nova linha

        // Copiar o item para a mochila se o item não estiver vazio
        if (strlen(item) > 0){
          // Solicitar a quantidade do item
          do{
            printf("Quantos itens foram encontrados? ");
            scanf("%d", &quantidade);
            limparBufferEntrada();
          } while (quantidade < 1);

          // Procurar pelo item na lista
          noMochila* atual = (*mochila).lista;
          while (atual != NULL) {
            if (strcmp(atual->item.nome, item) == 0) {
              atual->item.quantidade += quantidade; // Incrementa a quantidade
              printf("Item '%s' já existe na mochila. Quantidade incrementada para %d.\n", item, atual->item.quantidade);
              break; // Item encontrado, sair do loop
            }
            atual = atual->proximo;
          }

          // Se o item não foi encontrado, adicionar um novo nó
          if (atual == NULL) {
            // Copiando o nome do item para a mochila
            strcpy(novoNo->item.nome, item);
            // Incrementando o número de itens na mochila
            (*mochila).numItens++;
            // Solicitar o tipo do item
            exibirTiposItens(tipoItens);
            int tipoEscolhido;
            do {
              printf("Digit e o número correspondente ao tipo do item: ");
              scanf("%d", &tipoEscolhido);
              limparBufferEntrada();
              if (tipoEscolhido < 1 || tipoEscolhido > 5){
                printf("Tipo inválido. Tente novamente.\n");
              }
            } while (tipoEscolhido < 1 || tipoEscolhido > 5);
            // Copiando o tipo do item para a mochila
            strcpy(novoNo->item.tipo, tipoItens[tipoEscolhido - 1]);
            // Atribuindo a quantidade ao item
            novoNo->item.quantidade = quantidade;
            // Inserindo o novo nó no início da lista
            novoNo->proximo = (*mochila).lista;
            (*mochila).lista = novoNo;
            printf("Item '%s' adicionado à mochila com sucesso!\n", item);
          }
        }
      } while (strlen(item) > 0 && (*mochila).numItens < MAX_ITENS);
      if ((*mochila).numItens >= MAX_ITENS){
        printf("A mochila está cheia. Não é possível adicionar mais itens.\n");
        return;    
      }
      free(novoNo); // Liberar a memória alocada para o novo nó, pois não será usado
    }
    // printf("Qual o nome do item a ser adicionado na mochila (ou pressione Enter para sair)? ");
  }
}

/**
 * @brief Função para remover um item da lista
 * @param mochila Ponteiro para o início da lista
 */
void removerItemMochila(struct mochilaLista* mochila){
  // Verificar se a mochila está vazia
  if ((*mochila).numItens == 0 || (*mochila).lista == NULL){
    printf("A mochila está vazia. Não é possível remover itens.\n");
    return;
  }

  // Pergunta o nome do item a ser removido
  char item[TAM_STRING];
  printf("Digite o nome do item a ser removido da mochila: ");
  fgets(item, TAM_STRING, stdin);
  item[strcspn(item, "\n")] = 0; // Remover o caractere de nova linha
  // Procurar o item na lista
  noMochila* atual = (*mochila).lista;
  noMochila* anterior = NULL;
  while (atual != NULL && strcmp(atual->item.nome, item) != 0){
    anterior = atual;
    atual = atual->proximo;
  }
}

/**
 * @brief Função para listar os itens na lista
 * @param mochila Ponteiro para o início da lista
 */
void listarItensMochila(struct mochilaLista mochila){
  printf("\n---------------------------\n");
  printf("--- Itens na Mochila (Lista encadeada) ---\n");
  printf("---------------------------\n");
  if (mochila.numItens == 0 || mochila.lista == NULL){
    printf("A mochila está vazia.\n");
  } else {
    noMochila* atual = mochila.lista;
    int indice = 1;
    while (atual != NULL){
      printf("Item %d:\n", indice);
      printf("Nome      : %s\n", atual->item.nome);
      printf("Tipo      : %s\n", atual->item.tipo);
      printf("Quantidade: %d\n", atual->item.quantidade);
      printf("---------------------------\n");
      atual = atual->proximo;
      indice++;
    }
    printf("Total de itens na mochila: %d\n", mochila.numItens);
    printf("---------------------------\n");
  }
}

/**
 * @brief Função para buscar um item na lista sequencialmente
 * @param mochila Ponteiro para o início da lista
 */
void buscarItemLista(noMochila* lista){
  // Verificar se a mochila está vazia
  if (lista == NULL){
    printf("Lista de elementos vazia. Não é possível buscar itens.\n");
    return;
  }

  // Pergunta o nome do item a ser buscado
  char item[TAM_STRING];
  printf("Digite o nome do item a ser buscado na mochila: ");
  fgets(item, TAM_STRING, stdin);
  item[strcspn(item, "\n")] = 0; // Remover o caractere de nova linha

  // Procurar o item na lista
  struct noMochila* resultado = buscarItemPorNomeLista(lista, item);
  if (resultado != NULL){
    // Item encontrado
    printf("\n--------------------------\n");
    printf("--- Resultado da Busca ---\n");
    printf("--------------------------\n");
    printf("Item encontrado:\n");
    printf("Nome: %s\n", resultado->item.nome);
    printf("Tipo: %s\n", resultado->item.tipo);
    printf("Quantidade: %d\n", resultado->item.quantidade);
    printf("-----------------------------\n");
  } else {
    // Item não encontrado
    printf("\n--------------------------\n");
    printf("Item '%s' não encontrado na mochila.\n", item);
    printf("--------------------------\n");
  }
}

/**
 * @brief Função para buscar um item por nome na lista, retornando sua posição ou -1 se não encontrado
 * @param mochila Ponteiro para o início da lista
 * @param nome Nome do item a ser buscado
 * @return Item encontrado, retornar -1 se não encontrado
 */
struct noMochila* buscarItemPorNomeLista(noMochila* lista, char nome[TAM_STRING]){
    noMochila* atual = lista;
    // int posicao = 0;
    while (atual != NULL){
        if (strcmp(atual->item.nome, nome) == 0){
            return atual; // Retornando o nó encontrado
        }
        atual = atual->proximo;
        // posicao++;
    }
    // Item não encontrado
    return NULL;
}