#include "linked_node.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Cria um novo nó encadeado
 *
 * @param pedido
 * @return LinkedNode*
 */
LinkedNode *create_linked_node(Pedido pedido) {
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
LinkedNode* remove_linked_node(LinkedNode *node, LinkedNode **head) {
    if (*head == NULL || node == NULL) return NULL;

    if (*head == node) *head = node->next;

    if (node->next != NULL) node->next->prev = node->prev;

    if (node->prev != NULL) node->prev->next = node->next;

    return *head;
}

LinkedNode* remove_linked_node_by_pedido(LinkedNode *head, int numero) {
    if (head == NULL) return NULL;

    LinkedNode *current = head;

    while(current->prev != NULL) {
        current = current->prev;
    }

    while (current != NULL) {
        if (current->pedido.numero == numero) {
            return remove_linked_node(current, &head);
        }
        current = current->next;
    }

    return NULL;
}

/**
 * @brief Insere um nó encadeado na lista
 *
 * @param node
 * @param prev
 */
LinkedNode *insert_linked_node(LinkedNode *node, LinkedNode **head) {
    node->prev = *head;
    (*head)->next = node;
    return node;
}

/**
 * @brief Imprime um nó encadeado
 *
 * @param node
 */
void print_linked_node(LinkedNode *node) {
    printf("Pedido: %d\n", node->pedido.numero);
    printf("Entrada: %s\n", node->pedido.entrada);
    printf("Principal: %s\n", node->pedido.principal);
    printf("Sobremesa: %s\n", node->pedido.sobremesa);
    printf("\n");
}

/**
 * @brief Imprime a lista encadeada
 *
 * @param node
 */
void print_linked_list(LinkedNode *node) {
    if (node == NULL) {
        printf("Lista vazia\n");
        return;
    }

    if (node->prev == NULL) {
        print_linked_node(node);
        return;
    }

    LinkedNode *current = node->prev;

    while (current->prev != NULL) {
        current = current->prev;
    }

    while (current != NULL) {
        print_linked_node(current);
        current = current->next;
    }
}