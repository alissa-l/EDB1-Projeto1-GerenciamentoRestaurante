#pragma once

/**
 * @brief Struct que representa um pedido
 * 
 */
typedef struct Pedido
{
    int numero;
    char entrada[100];
    char principal[100];
    char sobremesa[100];
} Pedido;

/**
 * @brief Funcao que cria um pedido
 * 
 * @param numero 
 * @param entrada 
 * @param principal 
 * @param sobremesa 
 * @return Pedido 
 */
Pedido create_pedido(int numero, char entrada[100], char principal[100], char sobremesa[100]);