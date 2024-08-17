#pragma once

#include "pedido.h"
typedef struct linkedNode
{
    Pedido pedido;
    struct linkedNode *next;
    struct linked_node *prev;
} LinkedNode;

LinkedNode *create_linked_node(Pedido pedido);
void remove_linked_node(LinkedNode *node);
void insert_linked_node(LinkedNode *node, LinkedNode *prev);
void print_linked_node(LinkedNode *node);
void print_linked_list(LinkedNode *node);