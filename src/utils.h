#ifndef PEDIDOS_H
#define PEDIDOS_H

#include "pedido.h"
#include "linked_node.h"
#include "fila.h"

/**
 * @brief Fluxo de execucao pra adicionar um pedido
 * 
 * @param head 
 */
LinkedNode* adicionar_pedido(LinkedNode *head);

/**
 * @brief Fluxo de execucao pra listar os pedidos
 * 
 * @param head 
 */
void listar_pedidos(LinkedNode *head);

/**
 * @brief Fluxo de execucao pra remover um pedido
 * 
 * @param head 
 */
LinkedNode* remover_pedido(LinkedNode *head);

/**
 * @brief Fluxo de execucao pra processar um pedido - envia para a lista de processamento
 * 
 * @param head 
 */
int processar_pedido(LinkedNode *head, Fila *fila);

/**
 * @brief Processa a fila de processamento
 * 
 */
Fila* processar_fila(Fila *fila);

/**
 * @brief Lista os pedidos da fila
 * 
 * @param fila 
 */
void* fila_listar_pedidos(Fila *fila);


#endif