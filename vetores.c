#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "geral.h"
#include "vetores.h"

// Funções de manipulação da mochila
/**
 * @brief Função para cadastrar um item na mochila
 * @param m Ponteiro para a mochila
 * @param tipoItens Matriz de strings com os tipos de itens disponíveis
 */
void cadastrarItem(mochila *m, char tipoItens[5][TAM_STRING]){
    printf("\n----------------------------------\n");
    printf("--- Adicionar Itens na Mochila ---\n");
    printf("----------------------------------\n");
    // Variável para armazenar o nome do item
    char item[TAM_STRING];
    // Variável para armazenar a quantidade do item
    int quantidade;
    // Variável contador de operções
    int numOperacoes = 0;

    // Perguntar se quer adicionar os itens de forma aleatória
    char escolha;

    printf("Deseja adicionar itens de forma aleatória? (s/n): ");
    scanf(" %c", &escolha);
    limparBufferEntrada();
    if (escolha == 's' || escolha == 'S'){
        // Adicionar itens aleatórios
        while (m->numItens < MAX_ITENS){
            // Gerar um nome aleatório para o item
            snprintf(item, TAM_STRING, "Item%d", m->numItens + 1);
            // Gerar uma quantidade aleatória entre 1 e 5
            quantidade = (rand() % 5) + 1;
            // Escolher um tipo aleatório
            int tipoAleatorio = rand() % 5;

            // Adicionar item
            strcpy(m->itens[m->numItens].nome, item);
            strcpy(m->itens[m->numItens].tipo, tipoItens[tipoAleatorio]);
            m->itens[m->numItens].quantidade = quantidade;
            m->numItens++; // Incrementar o número de itens na mochila
            numOperacoes++; // Incrementar o contador de operações
            printf("Item '%s' do tipo '%s' adicionado com quantidade %d.\n", item, tipoItens[tipoAleatorio], quantidade);
        }
        printf("Mochila cheia! Não é possível adicionar mais itens.\n");
        printf("----------------------------------\n");
        printf("Total de operações realizadas: %d\n", numOperacoes);
        printf("----------------------------------\n");
        return;
    }


    // Testar se a mochila está cheia
    if (m->numItens >= MAX_ITENS){
        printf("A mochila está cheia. Não é possível adicionar mais itens.\n");
    } else {
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
            // Item 1
            strcpy(m->itens[m->numItens].nome, "Bandagem");
            strcpy(m->itens[m->numItens].tipo, "Cura");
            m->itens[m->numItens].quantidade = 3;
            m->numItens++;
            // Item 2
            strcpy(m->itens[m->numItens].nome, "Pistola");
            strcpy(m->itens[m->numItens].tipo, "Arma");
            m->itens[m->numItens].quantidade = 1;
            m->numItens++;
            // Item 3
            strcpy(m->itens[m->numItens].nome, "Municaoo de Pistola");
            strcpy(m->itens[m->numItens].tipo, "Municao");
            m->itens[m->numItens].quantidade = 50;
            m->numItens++;
            // Item 4
            strcpy(m->itens[m->numItens].nome, "Colete");
            strcpy(m->itens[m->numItens].tipo, "Equipamento");
            m->itens[m->numItens].quantidade = 1;
            m->numItens++;
            // Item 5
            strcpy(m->itens[m->numItens].nome, "Kit Medico");
            strcpy(m->itens[m->numItens].tipo, "Cura");
            m->itens[m->numItens].quantidade = 1;
            m->numItens++;
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
                // if (m->numItens == MAX_ITENS){
                //     printf("A mochila está cheia. Não é possível adicionar mais itens.\n");
                // } else {
                    // Iniciallaizando o item da mochila
                    m->itens[m->numItens].quantidade = 0;
                    // Solicitar o nome do item
                    printf("Digite o nome do item a ser adicionado na mochila (ou pressione Enter para sair): ");
                    fgets(item, TAM_STRING, stdin);
                    // Remover o caractere de nova linha, se presente
                    item[strcspn(item, "\n")] = 0;

                    // Copiar o item para a mochila se o item não estiver vazio
                    if (strlen(item) > 0){
                        // Solicitar a quantidade do item
                        do{
                            printf("Quanatos itens foram encontrados? ");
                            scanf("%d", &quantidade);
                            limparBufferEntrada();
                        } while (quantidade < 1);

                        // Procura pelo item na mochila
                        int indiceItem = buscarItemPorNome(*m, item);
                        if (indiceItem != -1){
                            // Item já existe, incrementar a quantidade
                            m->itens[indiceItem].quantidade += quantidade;
                            printf("Item '%s' já existe na mochila. Quantidade incrementada para %d.\n", item, m->itens[indiceItem].quantidade);
                        } else {
                            // Copiando o nome do item para a mochila
                            strcpy(m->itens[m->numItens].nome, item);
                            // Incrementando o número de itens na mochila
                            m->numItens++;
                            // Solicitar o tipo do item
                            exibirTiposItens(tipoItens);
                            int tipoEscolhido;
                            do {
                                printf("Digite o número correspondente ao tipo do item: ");
                                scanf("%d", &tipoEscolhido);
                                limparBufferEntrada();
                                if (tipoEscolhido < 1 || tipoEscolhido > 5){
                                    printf("Tipo inválido. Tente novamente.\n");
                                }
                            } while (tipoEscolhido < 1 || tipoEscolhido > 5);
                            strcpy(m->itens[m->numItens - 1].tipo, tipoItens[tipoEscolhido - 1]);
                            // Incrementando a quantidade do item
                            m->itens[m->numItens - 1].quantidade = quantidade;
                            // Mensagem de sucesso
                            printf("Item adicionado com sucesso!\n");
                            printf("----------------------------------\n");
                        }
                    }
                // }
            } while (m->numItens < MAX_ITENS && strlen(item) > 0);
        }
    }
}

/**
 * @brief Função para remover um item da mochila
 * @param m Ponteiro para a mochila
 */
void removerItem(mochila *m){
    printf("\n----------------------------------\n");
    printf("--- Remover Itens da Mochila ---\n");
    printf("----------------------------------\n");
    // Mostrar os itens para a escolha
    listarItens(*m);
    // Variável para armazenar o nome do item a ser removido
    char item[TAM_STRING];
    printf("Digite o nome do item a ser removido: ");
    fgets(item, TAM_STRING, stdin);
    item[strcspn(item, "\n")] = 0; // Remover o caractere de nova linha
    clock_t inicio = clock();
    removerItemPorNome(m, item);
    clock_t fim = clock();
    double tempoGasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo gasto na remoção: %.6f segundos\n", tempoGasto);
    printf("----------------------------------\n");
}

/**
 * @brief Função para remover um item da mochila pelo nome
 * @param m Ponteiro para a mochila
 * @param item Nome do item a ser removido
 */
void removerItemPorNome(mochila *m, char item[TAM_STRING]){
    // Variável contador de operações
    int numOperacoes = 0;
    // Procurar o item na mochila
    for (int i = 0; i < m->numItens; i++){
        if (strcmp(m->itens[i].nome, item) == 0){
            // Item encontrado
            // Perguntando quantos itens deseja remover
            int quantidadeRemover;
            do {
                printf("Quantos '%s' deseja remover? (Quantidade atual: %d): ", item, m->itens[i].quantidade);
                scanf("%d", &quantidadeRemover);
                limparBufferEntrada();
                if (quantidadeRemover < 1 || quantidadeRemover > m->itens[i].quantidade){
                    printf("Quantidade inválida. Tente novamente.\n");
                }
            } while (quantidadeRemover < 1 || quantidadeRemover > m->itens[i].quantidade);
            // Removendo a quantidade especificada
            m->itens[i].quantidade -= quantidadeRemover;
            // Se remover toda a quantidade, eliminar o item da mochila
            if (m->itens[i].quantidade == 0){
                // Deslocar os itens seguintes para preencher a lacuna
                for (int j = i; j < m->numItens - 1; j++){
                    strcpy(m->itens[j].nome, m->itens[j + 1].nome);
                    strcpy(m->itens[j].tipo, m->itens[j + 1].tipo);
                    m->itens[j].quantidade = m->itens[j + 1].quantidade;
                    numOperacoes++; // Incrementar o contador de operações
                }
                // Apaganado o último item duplicado
                m->itens[m->numItens - 1].nome[0] = '\0';
                m->itens[m->numItens - 1].tipo[0] = '\0';
                m->itens[m->numItens - 1].quantidade = 0;
                // Decrementar o total de itens
                m->numItens--;
            } else {
                printf("Removida '%d' itens de %s.\n", m->itens[i].quantidade, item);
            }
            printf("Item '%s' removido com sucesso!\n", item);
            printf("------------------------------\n");
            printf("Total de operações realizadas: %d\n", numOperacoes);
            printf("------------------------------\n");
            return;
        }
    }
    printf("Item '%s' não encontrado na mochila.\n", item);
}

/**
 * @brief Função para listar os itens da mochila
 * @param m Estrutura da mochila
 */
void listarItens(mochila m){
    printf("\nItens na mochila:\n");
    if (m.numItens == 0){
        printf("A mochila está vazia.\n");
    } else {
        printf("-------------------------------------------------\n");
        printf("| %-20s | %-15s | %-5s |\n", "Nome", "Tipo", "Qtd");
        printf("-------------------------------------------------\n");
        for (int i = 0; i < m.numItens; i++){
            printf("| %-20s | %-15s | %-5d |\n", m.itens[i].nome, m.itens[i].tipo, m.itens[i].quantidade);
        }
        printf("-------------------------------------------------\n");
    }
    printf("Pressione Enter para continuar...");
    getchar();
}

/**
 * @brief Função para buscar um item na mochila sequencialmente
 * @param m Estrutura da mochila
 */
void buscarItem(mochila m){
    printf("\n------------------------------\n");
    printf("--- Buscar Item na Mochila ---\n");
    printf("------------------------------\n");
    char nome[TAM_STRING];
    printf("Digite o nome do item a ser buscado: ");
    fgets(nome, TAM_STRING, stdin);
    nome[strcspn(nome, "\n")] = 0; // Remover o caractere de nova linha
    clock_t inicio = clock();
    buscarItemPorNome(m, nome);
    clock_t fim = clock();
    double tempoGasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo gasto na busca: %.6f segundos\n", tempoGasto);
    printf("------------------------------\n");
}

/**
 * @brief Função para buscar um item por nome na mochila, retornando sua posição ou -1 se não encontrado
 * @param m Estrutura da mochila
 * @param nome Nome do item a ser buscado
 * @return Índice do item na mochila ou -1 se não encontrado
 */
int buscarItemPorNome(mochila m, char nome[TAM_STRING]){
    for (int i = 0; i < m.numItens; i++){
        if (strcmp(m.itens[i].nome, nome) == 0){
            // Item encontrado
            printf("\n--------------------------\n");
            printf("--- Resultado da Busca ---\n");
            printf("--------------------------\n");
            printf("Item encontrado na posição %d:\n", i + 1);
            printf("Nome: %s\n", m.itens[i].nome);
            printf("Tipo: %s\n", m.itens[i].tipo);
            printf("Quantidade: %d\n", m.itens[i].quantidade);
            printf("-----------------------------\n");
            return i;
        }
    }
    // Item não encontrado
    printf("\n--------------------------\n");
    printf("Item '%s' não encontrado na mochila.\n", nome);
    printf("--------------------------\n");
    return -1;
}

/**
 * @brief Função para realizar uma busca binária na mochila (deve estar ordenada por nome)
 * @param m Estrutura da mochila
 */
void buscaBinaria(mochila m){
    printf("\n--------------------------------\n");
    printf("--- Busca Binária na Mochila ---\n");
    printf("--------------------------------\n");
    // Não permitir busca se a mochila estiver vazia
    if (m.numItens == 0){
        printf("A mochila está vazia. Não é possível realizar a busca.\n");
        return;
    }
    // Verificar se a mochila está ordenada
    if (!m.ordenado){
        char escolha;
        printf("A mochila não está ordenada por nome. Deseja ordenar? (s/n): ");
        scanf(" %c", &escolha);
        limparBufferEntrada();
        if (escolha == 's' || escolha == 'S'){
            ordenarItensPorNome(&m);
        } else {
            printf("Busca binária requer que a mochila esteja ordenada. Abortando busca.\n");
            return;
        }
    }
    // Listar os itens da mochila
    listarItens(m);
    // Solicitar o nome do item a ser buscado
    char nome[TAM_STRING];
    printf("Digite o nome do item a ser buscado (busca binária): ");
    fgets(nome, TAM_STRING, stdin);
    nome[strcspn(nome, "\n")] = 0; // Remover o caractere de nova linha
    clock_t inicio = clock();
    buscarItemBinariaPorNome(m, nome);
    clock_t fim = clock();
    tempoGasto(inicio, fim);
    printf("------------------------------\n");
}

/**
 * @brief Função para buscar um item por nome na mochila usando busca binária recursiva
 * @param m Estrutura da mochila
 * @param nome Nome do item a ser buscado
 */
void buscarItemBinariaPorNome(mochila m, char nome[TAM_STRING]){
    int numOperacoes = 0;
    buscarItemBinariaRecursivaAux(m, nome, 0, m.numItens - 1, &numOperacoes);
    // printf("Total de operações realizadas: %d\n", numOperacoes);
}

/**
 * @brief Função auxiliar para busca binária recursiva
 * @param m Estrutura da mochila
 * @param nome Nome do item a ser buscado
 * @param inicio Índice inicial da busca
 * @param fim Índice final da busca
 * @param numOperacoes Contador de operações realizadas
 */
void buscarItemBinariaRecursivaAux(mochila m, char nome[TAM_STRING], int inicio, int fim, int *numOperacoes){
    if (inicio > fim){
        // Item não encontrado
        printf("\n--------------------------\n");
        printf("Item '%s' não encontrado na mochila.\n", nome);
        printf("--------------------------\n");
        return;
    }
    int meio = (inicio + fim) / 2;
    int cmp = strcmp(m.itens[meio].nome, nome);
    if (cmp == 0){
        // Item encontrado
        printf("\n--------------------------\n");
        printf("--- Resultado da Busca ---\n");
        printf("--------------------------\n");
        printf("Item encontrado na posição %d:\n", meio + 1);
        printf("Nome: %s\n", m.itens[meio].nome);
        printf("Tipo: %s\n", m.itens[meio].tipo);
        printf("Quantidade: %d\n", m.itens[meio].quantidade);
        printf("----------------------------------\n");
        printf("Total de operações realizadas: %d\n", *numOperacoes);
        printf("----------------------------------\n");
    } else if (cmp < 0){
        // Buscar na metade direita
        (*numOperacoes)++;
        buscarItemBinariaRecursivaAux(m, nome, meio + 1, fim, numOperacoes);
    } else {
        // Buscar na metade esquerda
        (*numOperacoes)++;
        buscarItemBinariaRecursivaAux(m, nome, inicio, meio - 1, numOperacoes);
    }
}

/**
 * @brief Função para ordenar os itens da mochila por nome
 * @note usando o algoritmo de bolha (Bubble Sort)
 * @param m Ponteiro para a mochila
 */
void ordenarItensPorNome(mochila *m){
    if (m->numItens < 2){
        printf("A mochila tem menos de 2 itens. Não é necessário ordenar.\n");
        return;
    }
    // Ordenação usando Bubble Sort
    printf("\n------------------------------\n");
    printf("--- Ordenando Itens por nome (Bubble Search) ---\n");
    printf("------------------------------\n");
    // Variável contador de operações
    int numOperacoes = 0;
    // Algoritmo de ordenação Bubble Sort
    for (int i = 0; i < m->numItens - 1; i++){
        for (int j = 0; j < m->numItens - i - 1; j++){
            if (strcmp(m->itens[j].nome, m->itens[j + 1].nome) > 0){
                // Trocar os itens
                struct Item temp = m->itens[j];
                m->itens[j] = m->itens[j + 1];
                m->itens[j + 1] = temp;
                numOperacoes++; // Incrementar o contador de operações
            }
        }
    }
    m->ordenado = 1; // Marca a mochila como ordenada
    printf("Itens ordenados por nome com sucesso!\n");
    printf("----------------------------------\n");
    printf("Total de operações realizadas: %d\n", numOperacoes);
    printf("----------------------------------\n");
}