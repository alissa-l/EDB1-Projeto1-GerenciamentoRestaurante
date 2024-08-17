#pragma once

#include "pedido.h"

typedef struct Fila
{
    Pedido *pedidos[1000];
    int size;
    int capacity;
    int frente;
    int fundo;
} Fila;

Fila *create_fila();
void destroy_fila(Fila *fila);
void adicionar_pedido(Fila *fila, Pedido *pedido);
void remover_pedido(Fila *fila);