#include "pedido.h"
#include <string.h>
#include <stdio.h>

Pedido* create_pedido(int numero, char entrada[100], char principal[100],
                     char sobremesa[100]) {
    Pedido pedido;
    pedido.numero = numero;
    strcpy(pedido.entrada, entrada);
    strcpy(pedido.principal, principal);
    strcpy(pedido.sobremesa, sobremesa);

    Pedido *pedidoPtr = &pedido;

    return pedidoPtr;
}

void print_pedido(Pedido *pedido) {
    printf("\n");
    printf("Pedido: %d\n", pedido->numero);
    printf("Entrada: %s\n", pedido->entrada);
    printf("Principal: %s\n", pedido->principal);
    printf("Sobremesa: %s\n", pedido->sobremesa);
    printf("\n");
}

/**
 * @brief Fluxo de execucao pra abrir os arquivos e escolher os pratos
 *
 *
 * @return Pedido
 */
Pedido* montar_pedido() {
    FILE *fileEntradas;

    // Abre o arquivo de entradas
    fileEntradas = fopen("cardapio/entradas.txt", "r");

    if (fileEntradas == NULL) {
        printf("Erro ao abrir arquivo\n");
        return NULL;
    }

    // Imprime as entradas
    char lineSobremesa[100];
    while (fgets(lineSobremesa, 100, fileEntradas) != NULL) {
        printf("%s", lineSobremesa);
    }

    // Escolhe a entrada
    printf("\nDigite o número correspondente a entrada: ");
    int entrada;
    scanf("%d", &entrada);
    char entradaStr[100];
    rewind(fileEntradas);
    int i = 0;
    while (fgets(lineSobremesa, 100, fileEntradas) != NULL) {
        if (i == entrada - 1) {
            strcpy(entradaStr, lineSobremesa);
            break;
        }
        i++;
    }

    fclose(fileEntradas);


    // Abre o arquivo de pratos principais
    FILE *filePrincipais = fopen("cardapio/principais.txt", "r");

    if (filePrincipais == NULL) {
        printf("Erro ao abrir arquivo\n");
        return NULL;
    }

    // Imprime os pratos principais
    char linePrincipais[100];
    while (fgets(linePrincipais, 100, filePrincipais) != NULL) {
        printf("%s", linePrincipais);
    }

    // Escolhe o prato principal
    printf("\nDigite o número correspondente ao prato principal: ");
    int principal;
    scanf("%d", &principal);
    char principalStr[100];
    rewind(filePrincipais);
    i = 0;
    while (fgets(linePrincipais, 100, filePrincipais) != NULL) {
        if (i == principal - 1) {
            strcpy(principalStr, linePrincipais);
            break;
        }
        i++;
    }

    fclose(filePrincipais);

    // Abre o arquivo de sobremesas
    FILE *fileSobremesas = fopen("cardapio/sobremesas.txt", "r");

    if (fileSobremesas == NULL) {
        printf("Erro ao abrir arquivo\n");
        return NULL;
    }

    // Imprime as sobremesas
    char lineSobremesas[100];
    while (fgets(lineSobremesas, 100, fileSobremesas) != NULL) {
        printf("%s", lineSobremesas);
    }

    // Escolhe a sobremesa
    printf("\nDigite o número correspondente a sobremesa: ");
    int sobremesa;
    scanf("%d", &sobremesa);
    char sobremesaStr[100];
    rewind(fileSobremesas);
    i = 0;
    while (fgets(lineSobremesas, 100, fileSobremesas) != NULL) {
        if (i == sobremesa - 1) {
            strcpy(sobremesaStr, lineSobremesas);
            break;
        }
        i++;
    }

    fclose(fileSobremesas);

    Pedido *pedido = create_pedido(1, entradaStr, principalStr, sobremesaStr);

    return pedido;


}