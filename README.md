# Sistema de Gerenciamento de Pedidos de Restaurante

Alissa de Lima Araújo

## Descrição

Este projeto consiste no desenvolvimento de um sistema para gerenciar os pedidos de um restaurante. Os pedidos são armazenados em uma lista ligada e, posteriormente, processados pela cozinha em ordem de chegada utilizando uma fila.

## Funcionalidades

1. **Adicionar Pedido**  
    Permite que a adição de um pedido.

2. **Remover Pedido**  
    Permite a remoção de um pedido.

3. **Processar Pedido**  
    Transfere um pedido para a fila de processamento.

4. **Listar Pedidos Pendentes**  
    Exibe todos os pedidos na lista ligada.

5. **Listar Pedidos em Processamento**  
    Exibe todos os pedidos na fila de processamento.

6. **Processamento da fila de processamento**
    Processa os pedidos na fila de processamento em ordem.

## Estrutura do Projeto

O projeto está dividido nos seguintes arquivos:

- **fila.c / fila.h**  
  Implementa e declara as funções relacionadas à fila.

- **linked_node.c / linked_node.h**  
  Implementa e declara as funções relacionadas aos nós da lista ligada.

- **pedido.c / pedido.h**  
  Implementa e declara as funções específicas para manipulação dos pedidos.

- **utils.c / utils.h**  
  Contém os fluxos das funcionalidades principais.

- **main.c**  
  Contém a função principal e a interface de usuário para interação com as funcionalidades do sistema.

## Estrutura de Dados

- **Lista Ligada**  
  Utilizada para armazenar os pedidos pendentes, permitindo a inserção e remoção de pratos específicos. Cada pedido é representado como um nó na lista.

- **Fila**  
  Utilizada para processar os pedidos em ordem de chegada. A fila opera no modelo FIFO (First In, First Out).

### Compilar e executar:
```console
make
```

