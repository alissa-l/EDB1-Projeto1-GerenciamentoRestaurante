#ifndef LINKED_NODE_H
#define LINKED_NODE_H

#include "pedido.h"

/**
 * @brief Struct que representa um nó encadeado
 * 
 */
typedef struct linkedNode
{
    Pedido pedido;
    struct linkedNode *next;
    struct linkedNode *prev;
} LinkedNode;

/**
 * @brief Cria um novo nó encadeado
 * 
 * @param pedido 
 * @return LinkedNode* 
 */
LinkedNode *create_linked_node(Pedido pedido);

/**
 * @brief Remove um nó encadeado
 * 
 * @param node 
 */
LinkedNode* remove_linked_node(LinkedNode *node, LinkedNode **head);

/**
 * @brief Remove um nó encadeado por pedido
 * 
 * @param head 
 * @param numero 
 * @return LinkedNode* 
 */
LinkedNode* remove_linked_node_by_pedido(LinkedNode *head, int numero);


/**
 * @brief Insere um nó encadeado na lista
 * 
 * @param node 
 * @param prev 
 */
LinkedNode* insert_linked_node(LinkedNode *node, LinkedNode **head);

/**
 * @brief Imprime um nó encadeado
 * 
 * @param node 
 */
void print_linked_node(LinkedNode *node);

/**
 * @brief Imprime a lista encadeada
 * 
 * @param node 
 */
void print_linked_list(LinkedNode *node);

#endif