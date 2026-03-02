# 01 - Lista Simplesmente Encadeada (Linked List)

## Descrição
Exercício com Lista Simplesmente Encadeada (Linked List).

## Funcionalidades
- [x] Criação/Inicialização: criar uma lista vazia
- [x] Mostrar lista: imprime os elementos da lista
- [x] Lista Vazia: verifica se lista está vazia
- [x] Número de Elementos: quantidade de elementos na lista
- [x] Inserção: início da lista
- [x] Inserção: posição específica
- [x] Remoção: elemento (node) de posição específica
- [x] Inversão: Inverter os elementos da lista
- [x] Destruição: Liberar a memória da lista

## Pré-requisitos

## Ferramentas de Desenvolvimento
1. **Compilador C++**:
    - Windows: MinGW-w64 (gcc) ou MSVC (Visual Studio)
    - Linux: g++
2. **CMake** para build automatizado

## Instalação

1. **Clone o repositório:**
   `git clone https://github.com/<NOME_REPOSITORIO_CRIADO>`

2. **Build do projeto:**

    * Linux:
        ```bash
        mkdir build && cd build
        cmake ..
        make
        ```

      Ou com Makefile:

        ```bash
        make build
        ```

    * Windows (executando a partir de Windows):
        ```bash
        mkdir build && cd build

        # Gera os arquivos de build (usando MinGW)
        cmake .. -G "MinGW Makefiles"

        # Ou usando MSVC (se tiver Visual Studio instalado)
        cmake .. -G "Visual Studio 17 2022"

        # Compila
        cmake --build .
        ```

# Execução

## Fluxo de Execução

Após o build do projeto, executar via CLI:

```bash
./build/linked_list
```

O CLI irá mostrar algo como:

```bash
Exercício de Linked List
------------------------

-- Lista inicial --
Conteúdo: 35
Conteúdo: 99
Conteúdo: 10
-- Lista invertida --
Conteúdo: 10
Conteúdo: 99
Conteúdo: 35
Cardinalidade da Lista: 3
Posição conteúdo: 2


Impressão da lista após remoção
Conteúdo: 10
Conteúdo: 35
Lista após destruir: cardinalidade = 0
```

## Fluxo de Testes

Para buildar os testes do projeto, executar o comando abaixo:

1. Criar a pasta "build", caso ela não exista:

```
mkdir build
```

2. Executar o comando de build com a flag de testes ativada:

```
cd build
cmake -DBUILD_TESTS=ON ..
```

3. Gerar os executáveis:

```
make
```

4. Executar os testes:

```
./tests
```

A saída deve ser algo como:

```
=========================================
  INICIANDO TESTES DE LINKED LIST
=========================================

Testando criaLista()...
✓ criaLista() passou em todos os testes
Testando insere()...
✓ insere() passou em todos os testes
Testando listaVazia()...
✓ listaVazia() passou em todos os testes
Testando numElementos()...
✓ numElementos() passou em todos os testes
Testando existeElemento()...
✓ existeElemento() passou em todos os testes
Testando posicaoConteudo()...
✓ posicaoConteudo() passou em todos os testes
Testando inserePosicao()...
✓ inserePosicao() passou em todos os testes
Testando removeElementoPosicao()...
✓ removeElementoPosicao() passou em todos os testes
Testando esvaziaLista()...
✓ esvaziaLista() passou em todos os testes
Testando inverteLista()...
✓ inverteLista() passou em todos os testes
Testando destroiLista()...
✓ destroiLista() passou em todos os testes

=========================================
  ✓ TODOS OS TESTES PASSARAM COM SUCESSO!
=========================================
```