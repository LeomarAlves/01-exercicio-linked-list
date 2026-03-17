#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
    int conteudo;
    Node* proximo;
};

struct ListaSimplesmenteEncadeada {
    int cardinalidade;
    Node* inicio;
};

ListaSimplesmenteEncadeada* criaLista();
void mostraLista(ListaSimplesmenteEncadeada &lista);
bool listaVazia(ListaSimplesmenteEncadeada &lista);
int numElementos(ListaSimplesmenteEncadeada &lista);
void insere(ListaSimplesmenteEncadeada &lista, int conteudo);
void inserePosicao(ListaSimplesmenteEncadeada &lista, int conteudo, int posicao);
void removeElementoPosicao(ListaSimplesmenteEncadeada &lista, int posicao);
void inverteLista(ListaSimplesmenteEncadeada &lista);
void destroiLista(ListaSimplesmenteEncadeada &lista);
#endif // LINKED_LIST_H
