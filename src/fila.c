#pragma once

#include "fila.h"
#include "pedido.h"
#include "linked_node.h"

Fila *create_fila()
{
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    fila->size = 0;
    fila->capacity = 1000;
    fila->frente = 0;
    fila->fundo = 0;
    return fila;
}

void destroy_fila(Fila *fila)
{
    free(fila);
}

void adicionar_pedido(Fila *fila, Pedido *pedido)
{
    if (fila->size == fila->capacity)
    {
        printf("Fila cheia\n");
        return;
    }
    int numero = pedido->numero;
    fila->pedidos[numero] = pedido;
    fila->fundo = (fila->fundo + 1) % fila->capacity;
    fila->size++;
}

void remover_pedido(Fila *fila)
{
    if (fila->size == 0)
    {
        printf("Fila vazia\n");
        return;
    }

    fila->frente = (fila->frente + 1) % fila->capacity;
    fila->size--;
}

