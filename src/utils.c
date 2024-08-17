#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "pedido.h"
#include "linked_node.h"

/**
 * @brief Fluxo de execucao pra adicionar um pedido
 * 
 * 
 * @param head 
 */
void adicionar_pedido(LinkedNode *head) {

    printf("Digite o prato de entrada: ");
    scanf("%s", pedido.entrada);
    printf("Digite o prato principal: ");
    scanf("%s", pedido.principal);
    printf("Digite a sobremesa: ");
    scanf("%s", pedido.sobremesa);

    LinkedNode *node = create_linked_node(pedido);
    insert_linked_node(node, head);
}

void remover_pedido(LinkedNode *head) {
    int numero;
    printf("Digite o número do pedido: ");
    scanf("%d", &numero);

    LinkedNode *node = head;
    while (node != NULL) {
        if (node->pedido.numero == numero) {
            remove_linked_node(node);
            return;
        }
        node = node->next;
    }
}

void processar_pedido(LinkedNode *head) {
    LinkedNode *node = head;
    while (node != NULL) {
        print_linked_node(node);
        node = node->next;
    }
}

void listar_pedidos(LinkedNode *head) {
    LinkedNode *node = head;
    while (node != NULL) {
        print_linked_node(node);
        node = node->next;
    }
}

void print_pratos(int tipo) {
    
    FILE *file;

    switch (tipo)
    {
    case 1:
        file = fopen("entradas.txt", "r");
        break;
    case 2:
        file = fopen("principais.txt", "r");
        break;
    case 3:
        file = fopen("sobremesas.txt", "r");
        break;
    default:
        printf("Tipo de prato inválido\n");
        break;
    }

    if (file == NULL) {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    char line[100];
    while (fgets(line, 100, file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}