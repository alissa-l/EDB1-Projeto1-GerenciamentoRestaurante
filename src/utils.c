#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "fila.h"
#include "linked_node.h"
#include "pedido.h"

/**
 * @brief Fluxo de execucao pra adicionar um pedido
 *
 *
 * @param head
 */
LinkedNode *adicionar_pedido(LinkedNode *head) {
    Pedido *pedido = montar_pedido();

    if (pedido == NULL) {
        printf("Erro ao montar pedido\n");
        return NULL;
    }

    LinkedNode *node = NULL;

    if (head == NULL) {
        head = create_linked_node(*pedido);
        return head;
    } else {
        pedido->numero = head->pedido.numero + 1;
        print_pedido(pedido);
        node = create_linked_node(*pedido);
        node = insert_linked_node(node, &head);
    }
    return node;
}

/**
 * @brief Fluxo de execucao pra listar os pedidos
 *
 * @param head
 */
void listar_pedidos(LinkedNode *head) {
    printf("Pedidos na lista:\n");
    print_linked_list(head);
}

/**
 * @brief Fluxo de execucao pra remover um pedido
 *
 * @param head
 */
LinkedNode *remover_pedido(LinkedNode *head) {
    int numero;

    if (head == NULL) {
        printf("Lista vazia\n");
        return NULL;
    }

    listar_pedidos(head);

    printf("Digite o número do pedido: ");
    scanf("%d", &numero);

    LinkedNode *node = head;
    while (node != NULL) {
        if (node->pedido.numero == numero) {
            head = remove_linked_node(node, &head);
            printf("Pedido removido\n");
            return head;
        }
        node = node->next;
    }
    return NULL;
}

/**
 * @brief Fluxo de execucao pra processar um pedido
 *
 * @param head
 */
int processar_pedido(LinkedNode *head, Fila *fila) {
    if (head == NULL) {
        printf("Lista vazia\n");
        return -100;
    }

    listar_pedidos(head);

    printf("Digite o número do pedido: ");
    int numero;
    scanf("%d", &numero);

    while (head->prev != NULL) {
        head = head->prev;
    }

    Pedido *pedido = NULL;

    while (head != NULL) {
        if (head->pedido.numero == numero) {
            pedido = &head->pedido;
            break;
        }
        head = head->next;
    }


    if (pedido == NULL) {
        printf("Pedido não encontrado\n");
        return -100;
    }

    if (fila == NULL) {
        printf("Fila nao existe\n");
        return -100;
    }

    if (fila->tamanho == 0) {
        pedido->ordemDeChegada = 1;
        fila->pedidos[0] = pedido;
    } else {
        pedido->ordemDeChegada = fila->tamanho + 1;
        fila->pedidos[fila->tamanho + 1] = pedido;
    }
    fila->tamanho++;

    return numero;
}

/**
 * @brief Processa a fila de processamento
 *
 * @param fila
 * @return Fila*
 */
Fila* processar_fila(Fila *fila) {

    if (fila->tamanho == 0) {
        printf("Fila vazia\n");
        return NULL;
    }

    for (int i = 0; i < fila->tamanho + 1; i++) {
        if(fila->pedidos[i] != NULL) {
            print_pedido(fila->pedidos[i]);
            usleep(100000);
        }

    }

    Fila newFila = create_fila();
    printf("\nFila processada\n");
    Fila *pFila = &newFila;
    return pFila;
}

/**
 * @brief Lista os pedidos da fila
 *
 * @param fila
 */
void* fila_listar_pedidos(Fila *fila) {


    if (fila->tamanho == 0) {
        printf("Fila vazia\n");
        return NULL;
    }

    for (int i = 0; i < fila->tamanho + 1; i++) {
        if(fila->pedidos[i] != NULL) {
            print_pedido(fila->pedidos[i]);
        }
    }

    return NULL;
}
