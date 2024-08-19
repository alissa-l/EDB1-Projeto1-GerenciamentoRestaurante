#ifndef FILA_H
#define FILA_H

#include "pedido.h"

typedef struct Fila
{
    Pedido *pedidos[1000];
    int tamanho;
} Fila;

/**
 * @brief Cria uma fila
 * 
 * @return Fila* 
 */
Fila create_fila();

/**
 * @brief Destroi uma fila
 * 
 * @param fila 
 */
void destroy_fila(Fila *fila);

/**
 * @brief Adiciona um pedido a fila
 * 
 * @param fila 
 * @param pedido 
 */
void fila_adicionar_pedido(Fila *fila, Pedido *pedido);

void sort_pedidos(Pedido *pedidos, int size);

#endif