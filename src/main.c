#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "fila.h"
#include "linked_node.h"
#include "utils.h"

LinkedNode *head = NULL;
Fila fila;

/**
 * @brief Funcao que imprime o menu
 *
 */
void menu() {
    printf("\n\n\n+------------------------------+\n");
    printf("1 - Adicionar pedido\n");
    printf("2 - Remover pedido\n");
    printf("3 - Colocar um pedido na fila de processamento\n");
    printf("4 - Processar fila de pedidos\n");
    printf("5 - Listar pedidos na fila\n");
    printf("6 - Listar pedidos na lista\n");
    printf("7 - Sair\n");
    printf("+------------------------------+\n");
}

/**
 * @brief Funcao que imprime as opcoes do menu em loop
 *
 */
void print_menu_options() {
    while (true) {
        menu();

        int option;

        scanf("%d", &option);
        switch (option) {
            // Adicionar pedido
            case 1:
                LinkedNode *novoPedido = adicionar_pedido(head);
                if (novoPedido != NULL) {
                    head = novoPedido;
                }
                break;
            // Remover pedido
            case 2:
                LinkedNode *headAtualizada1 = remover_pedido(head);
                head = headAtualizada1;
                break;
            // Processar pedido
            case 3:
                int pedidoEscolhido = processar_pedido(head, &fila);
                if (pedidoEscolhido != -100) {
                    LinkedNode *headAtualizada2 = remove_linked_node_by_pedido(head, pedidoEscolhido);
                    if(headAtualizada2 != NULL) {
                        head = headAtualizada2;
                    }
                }
                break;
            // Processar fila
            case 4:
                fila = *processar_fila(&fila);
                break;
            // Listar pedidos da fila
            case 5:
                fila_listar_pedidos(&fila);
                break;
            // Listar pedidos da lista
            case 6:
                listar_pedidos(head);
                break;
            // Sair
            case 7:
                return;
            default:
                return;
                break;
        }
    }
}

/**
 * @brief Funcao de entrada do programa
 *
 * @return int
 */
int main() {
    fila = create_fila();
    fila.tamanho = 0;
    print_menu_options();
    return 0;
}