#include <stdlib.h>
#include <stdbool.h>

#include "linked_node.h"
#include "utils.h"

LinkedNode *head = NULL;

/**
 * @brief Funcao que imprime o menu
 * 
 */
void menu() {
    printf("+------------------------------+\n");
    printf("1 - Adicionar pedido\n");
    printf("2 - Remover pedido\n");
    printf("3 - Processar pedido\n");
    printf("3 - Listar pedidos pendentes\n");
    printf("4 - Sair\n");
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
            case 1:
                adicionar_pedido(head);
                break;
            case 2:
                remover_pedido(head);
                break;
            case 3:
                processar_pedido(head);
                break;
            case 4:
                listar_pedidos(head);
                return;
            case 5:
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
int main() 
{ 
    print_menu_options(); 
    return 0; 
}