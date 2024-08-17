#include "pedido.h"

Pedido create_pedido(int numero, char entrada[100], char principal[100], char sobremesa[100])
{
    Pedido pedido;
    pedido.numero = numero;
    strcpy(pedido.entrada, entrada);
    strcpy(pedido.principal, principal);
    strcpy(pedido.sobremesa, sobremesa);
    return pedido;
}