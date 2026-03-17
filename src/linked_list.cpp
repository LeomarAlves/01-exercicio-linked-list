#include "linked_list.h"
#include <iostream>
#include <cstdlib>

using namespace std;

ListaSimplesmenteEncadeada* criaLista()
{
    ListaSimplesmenteEncadeada* lista = (ListaSimplesmenteEncadeada*) malloc(sizeof(ListaSimplesmenteEncadeada));
    lista->cardinalidade = 0;
    lista->inicio = NULL;
    return lista;
}

void mostraLista(ListaSimplesmenteEncadeada &lista) {
    Node* atual = lista.inicio;
    while (atual != NULL) {
        cout << "Conteúdo: " << atual->conteudo << endl;
        atual = atual->proximo;
    }
}

bool listaVazia(ListaSimplesmenteEncadeada &lista)
{
    return lista.cardinalidade == 0;
}

int numElementos(ListaSimplesmenteEncadeada &lista) {
    return lista.cardinalidade;
}

void insere(ListaSimplesmenteEncadeada &lista, int conteudo)
{
    Node* novoNode = (Node*) malloc(sizeof(Node));
    if (novoNode == NULL) {
        cerr << "Erro na alocação de memória" << endl;
    }

    novoNode->conteudo = conteudo;
    novoNode->proximo = lista.inicio;

    lista.inicio = novoNode;
    lista.cardinalidade++;
}

void inserePosicao(ListaSimplesmenteEncadeada &lista, int conteudo, int posicao)
{
    if (posicao < 0 || posicao > lista.cardinalidade){
        cerr << "Posição inválida" << endl;
        return;
    }

    if (posicao == 0){
        insere(lista, conteudo);
        return;
    }

    Node* novoNode = (Node*) malloc(sizeof(Node));
    if (novoNode == NULL){
        cerr << "Erro de memória" << endl;
        return;
    }
    novoNode->conteudo = conteudo;

    Node* anterior = lista.inicio;
    for(int i = 0; i < posicao -1; i++){
        anterior = anterior->proximo;
    }

    novoNode->proximo = anterior->proximo;
    anterior->proximo = novoNode;

    lista.cardinalidade++;
}

void removeElementoPosicao(ListaSimplesmenteEncadeada &lista, int posicao)
{
    if (listaVazia(lista)) {
        cerr << "Erro: A lista está vazia." << endl;
        return;
    }
    if (posicao < 0 || posicao >= lista.cardinalidade) {
        cerr << "Erro: Posição " << posicao << " inválida!" << endl;
        return;
    }

    Node* alvo = NULL;

    if (posicao == 0) {
        alvo = lista.inicio;
        lista.inicio = alvo->proximo;
    } 
    else {
        Node* anterior = lista.inicio;
        
        for (int i = 0; i < posicao - 1; i++) {
            anterior = anterior->proximo;
        }
        
        alvo = anterior->proximo; 
        anterior->proximo = alvo->proximo;
    }

    free(alvo);
    lista.cardinalidade--;
}

void inverteLista(ListaSimplesmenteEncadeada &lista) {
    if (lista.inicio == NULL || lista.inicio->proximo == NULL) {
        return;
    }

    Node* anterior = NULL;
    Node* atual = lista.inicio;
    Node* proximo = NULL;

    while (atual != NULL) {
        proximo = atual->proximo;
        atual->proximo = anterior;
        anterior = atual;
        atual = proximo;
    }

    lista.inicio = anterior;
}

void destroiLista(ListaSimplesmenteEncadeada &lista)
{
    Node* temp;
    while (lista.inicio != NULL) {
        temp = lista.inicio;
        lista.inicio = lista.inicio->proximo;
        free(temp);
    }
    lista.cardinalidade = 0;
}