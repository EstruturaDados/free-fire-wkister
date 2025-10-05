#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "geral.h"    // Protótipos das funções e definições gerais
#include "menu.h"     // Protótipos das funções do menu
#include "vetores.h"  // Protótipos das funções e definições de vetores
#include "listas.h"   // Protótipos das funções e definições de listas

// Código da Ilha – Edição Free Fire
// Nível: Aventureiro
// Autor: Wellington Kister do Nascimento
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
    // Definir e inicializar a mochila
    mochila minhaMochila;
    // Inicializando a mochila
    minhaMochila.numItens = 0;
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
            case 6: {
                buscarItem(minhaMochila);
                break;
            }
            case 0:
                printf("Saindo do programa. Até a próxima!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}


// Struct Item:
// Representa um componente com nome, tipo, quantidade e prioridade (1 a 5).
// A prioridade indica a importância do item na montagem do plano de fuga.

// Enum CriterioOrdenacao:
// Define os critérios possíveis para a ordenação dos itens (nome, tipo ou prioridade).

// Vetor mochila:
// Armazena até 10 itens coletados.
// Variáveis de controle: numItens (quantidade atual), comparacoes (análise de desempenho), ordenadaPorNome (para controle da busca binária).

// limparTela():
// Simula a limpeza da tela imprimindo várias linhas em branco.

// exibirMenu():
// Apresenta o menu principal ao jogador, com destaque para status da ordenação.

// inserirItem():
// Adiciona um novo componente à mochila se houver espaço.
// Solicita nome, tipo, quantidade e prioridade.
// Após inserir, marca a mochila como "não ordenada por nome".

// removerItem():
// Permite remover um componente da mochila pelo nome.
// Se encontrado, reorganiza o vetor para preencher a lacuna.

// listarItens():
// Exibe uma tabela formatada com todos os componentes presentes na mochila.

// menuDeOrdenacao():
// Permite ao jogador escolher como deseja ordenar os itens.
// Utiliza a função insertionSort() com o critério selecionado.
// Exibe a quantidade de comparações feitas (análise de desempenho).

// insertionSort():
// Implementação do algoritmo de ordenação por inserção.
// Funciona com diferentes critérios de ordenação:
// - Por nome (ordem alfabética)
// - Por tipo (ordem alfabética)
// - Por prioridade (da mais alta para a mais baixa)

// buscaBinariaPorNome():
// Realiza busca binária por nome, desde que a mochila esteja ordenada por nome.
// Se encontrar, exibe os dados do item buscado.
// Caso contrário, informa que não encontrou o item.
