#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "geral.h"    // Protótipos das funções e definições gerais
#include "menu.h"     // Protótipos das funções do menu
#include "vetores.h"  // Protótipos das funções e definições de vetores
#include "listas.h"   // Protótipos das funções e definições de listas

/**
 * @file FreeFire.c
 * @brief Código da Ilha – Edição Free Fire
 * @note Nível: Aventureiro
 * @author Wellington Kister do Nascimento
 *
 * @section compilation Compilação
 * Para compilar este projeto, você pode usar os seguintes comandos make:
 *
 * - make all       : Compila o projeto
 * - make run      : Compila e executa o programa
 * - make valgrind : Executa com verificação de vazamento de memória
 * - make debug    : Compila com flags de depuração adicionais
 * - make clean    : Remove arquivos compilados
 *
 * Exemplo de uso:
 * @code
 * $ make clean    # Limpa compilações anteriores
 * $ make         # Compila o projeto
 * $ make run     # Executa o programa
 * @endcode
 */
// Este programa simula o gerenciamento avançado de uma mochila com componentes coletados durante a fuga de uma ilha.
// Ele introduz ordenação com critérios e busca binária para otimizar a gestão dos recursos.

// Função principal
int main() {
    // Semente para números aleatórios
    srand((unsigned int)time(NULL));

    // Mensagem de boas-vindas
    printf("+--------------------------------------------------------------------------------+\n");
    printf("| Bem-vindo à simulação de gerenciamento de mochila na Ilha - Free Fire Edition! |\n");
    printf("+--------------------------------------------------------------------------------+\n");
    // Definir e inicializar o vetor de mochila
    mochila minhaMochila;
    // Inicializando o vetor de mochila
    minhaMochila.numItens = 0; // Inicializa o número de itens como 0
    minhaMochila.ordenado = 0; // Inicialmente não está ordenada

    // Definição da variável para lista da lista de Mochila
    struct mochilaLista minhaMochilaLista;

    // Inicializando a lista da mochila
    minhaMochilaLista.lista = NULL; // Inicializa o início da lista como NULL
    minhaMochilaLista.numItens = 0;  // Inicializa o número de itens como 0
    minhaMochilaLista.ordenado = 0;  // Inicializa a flag de ordenação como 0 (não ordenada)

    // Variável para armazenar a opção do menu
    int opcao = 0;
    // Loop do menu
    do {
        exibirMenu();
        scanf("%d", &opcao);
        limparBufferEntrada();
        switch (opcao) {
            case 1:
                cadastrarItem(&minhaMochila, tipoItens);
                break;
            case 2: {
                removerItem(&minhaMochila);
                break;
            }
            case 3:
                listarItens(minhaMochila);
                break;
            case 4: {
                buscarItem(minhaMochila);
                break;
            }
            case 5: {
                buscaBinaria(minhaMochila);
                break;
            }
            case 6:
                ordenarItensPorNome(&minhaMochila);
                break;
            case 8:
                inserirItemMochila(&minhaMochilaLista, tipoItens);
                break;
            case 9:
                removerItemMochila(&minhaMochilaLista);
                break;
            case 10:
                listarItensMochila(minhaMochilaLista);
                break;
            case 11:
                buscarItemLista(minhaMochilaLista.lista);
                break;
            case 0:
                liberarMemoriaLista(&minhaMochilaLista);
                printf("Saindo do programa. Até a próxima!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}