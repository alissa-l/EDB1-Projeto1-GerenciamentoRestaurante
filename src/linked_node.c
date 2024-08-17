#include <stdlib.h>
#include "linked_node.h"

/**
 * @brief Cria um novo nó encadeado
 * 
 * @param pedido 
 * @return LinkedNode* 
 */
LinkedNode *create_linked_node(Pedido pedido)
{
    LinkedNode *node = (LinkedNode *)malloc(sizeof(LinkedNode));
    node->pedido = pedido;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

/**
 * @brief Remove um nó encadeado
 * 
 * @param node 
 */
void remove_linked_node(LinkedNode *node) {
    LinkedNode *pastNode = node->prev;
    LinkedNode *nextNode = node->next;

    if (pastNode == NULL)
    {
        return;
    }

    pastNode->next = nextNode;

    
    free(node);
}

/**
 * @brief Insere um nó encadeado na lista
 * 
 * @param node 
 * @param prev 
 */
void insert_linked_node(LinkedNode *node, LinkedNode *prev)
{
    LinkedNode *next = prev->next;
    prev->next = node;
    node->prev = prev;
    node->next = next;
    next->prev = node;
}

void print_linked_node(LinkedNode *node) {
    printf("Pedido: %d\n", node->pedido.numero);
    printf("Entrada: %s\n", node->pedido.entrada);
    printf("Principal: %s\n", node->pedido.principal);
    printf("Sobremesa: %s\n", node->pedido.sobremesa);
    printf("\n");
}

void print_linked_list(LinkedNode *node) {
    LinkedNode *current = node;

    while (current->prev != NULL)
    {
        current = current->prev;
    }
    

    while (current != NULL)
    {
        print_linked_node(current);
        current = current->next;
    }
}