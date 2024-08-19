#include "fila.h"

#include <stdio.h>
#include <stdlib.h>

#include "linked_node.h"
#include "pedido.h"
#include <unistd.h>

Fila create_fila() {
    Fila fila;
    fila.tamanho = 0;
    return fila;
}

void destroy_fila(Fila *fila) { free(fila); }

void sort_pedidos(Pedido *pedidos, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (pedidos[i].ordemDeChegada > pedidos[j].ordemDeChegada) {
                Pedido temp = pedidos[i];
                pedidos[i] = pedidos[j];
                pedidos[j] = temp;
            }
        }
    }
}