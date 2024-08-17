#pragma once

#include <stdio.h>
#include <stdlib.h>


#include "pedido.h"
#include "linked_node.h"

/**
 * @brief Fluxo de execucao pra adicionar um pedido
 * 
 * @param head 
 */
void adicionar_pedido(LinkedNode *head);

/**
 * @brief Fluxo de execucao pra remover um pedido
 * 
 * @param head 
 */
void remover_pedido(LinkedNode *head);

/**
 * @brief Fluxo de execucao pra processar um pedido
 * 
 * @param head 
 */
void processar_pedido(LinkedNode *head);

/**
 * @brief Fluxo de execucao pra listar os pedidos
 * 
 * @param head 
 */
void listar_pedidos(LinkedNode *head);

/**
 * @brief Imprime pratos de arquivo
 * 
 */
void print_pratos(int tipo);