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
 */
void cadastrarItem(mochila *m, char tipoItens[5][TAM_STRING]){
    // Variável para armazenar o nome do item
    char item[TAM_STRING];
    // Variável para armazenar a quantidade do item
    int quantidade;

    // Perguntar se quer adicionar os itens de forma aleatória
    char escolha;

    printf("\n----------------------------------\n");
    printf("--- Adicionar Itens na Mochila ---\n");
    printf("----------------------------------\n");
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
            // Verificar se o item já existe na mochila
            // int indiceItem = buscarItemPorNome(*m, item);
            // if (indiceItem != -1){
            //     // Item já existe, incrementar a quantidade
            //     m->itens[indiceItem].quntidade += quantidade;
            //     printf("Item '%s' já existe na mochila. Quantidade incrementada para %d.\n", item, m->itens[indiceItem].quntidade);
            // } else {
                // Adicionar novo item
                strcpy(m->itens[m->numItens].nome, item);
                strcpy(m->itens[m->numItens].tipo, tipoItens[tipoAleatorio]);
                m->itens[m->numItens].quntidade = quantidade;
                m->numItens++;
                printf("Item '%s' do tipo '%s' adicionado com quantidade %d.\n", item, tipoItens[tipoAleatorio], quantidade);
            // }
        }
        printf("Mochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    // Testar se a mochila está cheia
    if (m->numItens >= MAX_ITENS){
        printf("A mochila está cheia. Não é possível adicionar mais itens.\n");
    } else {
        // Loop para adicionar um item, parando quando entrar um item vazio
        do {
            if (m->numItens == MAX_ITENS){
                printf("A mochila está cheia. Não é possível adicionar mais itens.\n");
            } else {
                // Iniciallaizando o item da mochila
                m->itens[m->numItens].quntidade = 0;
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
                        m->itens[indiceItem].quntidade += quantidade;
                        printf("Item '%s' já existe na mochila. Quantidade incrementada para %d.\n", item, m->itens[indiceItem].quntidade);
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
                        m->itens[m->numItens - 1].quntidade = quantidade;
                        // Mensagem de sucesso
                        printf("Item adicionado com sucesso!\n");
                    }
                }
            }
        } while (m->numItens < MAX_ITENS && strlen(item) > 0);
    }
}

/**
 * @brief Função para remover um item da mochila
 * @param m Ponteiro para a mochila
 * @param item Nome do item a ser removido
 */
void removerItem(mochila *m){
    printf("\n----------------------------------\n");
    printf("--- Remover Itens da Mochila ---\n");
    printf("----------------------------------\n");
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
    for (int i = 0; i < m->numItens; i++){
        if (strcmp(m->itens[i].nome, item) == 0){
            // Item encontrado
            // Perguntando quantos itens deseja remover
            int quantidadeRemover;
            do {
                printf("Quantos '%s' deseja remover? (Quantidade atual: %d): ", item, m->itens[i].quntidade);
                scanf("%d", &quantidadeRemover);
                limparBufferEntrada();
                if (quantidadeRemover < 1 || quantidadeRemover > m->itens[i].quntidade){
                    printf("Quantidade inválida. Tente novamente.\n");
                }
            } while (quantidadeRemover < 1 || quantidadeRemover > m->itens[i].quntidade);
            // Removendo a quantidade especificada
            m->itens[i].quntidade -= quantidadeRemover;
            // Se remover toda a quantidade, eliminar o item da mochila
            if (m->itens[i].quntidade == 0){
                // Deslocar os itens seguintes para preencher a lacuna
                for (int j = i; j < m->numItens - 1; j++){
                    strcpy(m->itens[j].nome, m->itens[j + 1].nome);
                    strcpy(m->itens[j].tipo, m->itens[j + 1].tipo);
                    m->itens[j].quntidade = m->itens[j + 1].quntidade;
                }
                // Apaganado o último item duplicado
                m->itens[m->numItens - 1].nome[0] = '\0';
                m->itens[m->numItens - 1].tipo[0] = '\0';
                m->itens[m->numItens - 1].quntidade = 0;
                // Decrementar o total de itens
                m->numItens--;
            } else {
                printf("Removida '%d' itens de %s.\n", m->itens[i].quntidade, item);
            }
            printf("Item '%s' removido com sucesso!\n", item);
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
            printf("| %-20s | %-15s | %-5d |\n", m.itens[i].nome, m.itens[i].tipo, m.itens[i].quntidade);
        }
        printf("-------------------------------------------------\n");
    }
}

/**
 * @brief Função para buscar um item na mochila
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
            printf("Quantidade: %d\n", m.itens[i].quntidade);
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
