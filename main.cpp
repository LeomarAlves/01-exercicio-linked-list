#include <iostream>
#include "linked_list.h"

using namespace std;

int main() {
    cout << "Exercício de Linked List" << endl;
    cout << "------------------------\n" << endl;

    ListaSimplesmenteEncadeada* lista = criaLista();
    cout << "--- Teste de Lista Encadeada ---";

    
    insere(*lista, 10);
    insere(*lista, 99);
    insere(*lista, 35);

    cout << "-- Lista inicial --" << endl;
    mostraLista(*lista);

    cout << "-- Lista invertida --" << endl;
    inverteLista(*lista);
    mostraLista(*lista); 

    cout << "Cardinalidade da Lista: " << numElementos(*lista) << endl;

    removeElementoPosicao(*lista, 1);

    cout << "\nImpressão da lista após remoção" << endl;
    mostraLista(*lista);

    destroiLista(*lista);
    cout << "Lista após destruir: cardinalidade = " << lista->cardinalidade << endl;

    free(lista);
    return 0;
}
