#ifndef PEDIDO_H
#define PEDIDO_H

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
    int ordemDeChegada;
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
Pedido* create_pedido(int numero, char entrada[100], char principal[100], char sobremesa[100]);

/**
 * @brief Funcao que printa um pedido
 * 
 * @return Pedido* 
 */
void print_pedido(Pedido *pedido);

/**
 * @brief Fluxo de execucao pra abrir os arquivos e escolher os pratos
 * 
 */
Pedido* montar_pedido();

#endif