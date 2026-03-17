#include <cassert>
#include <iostream>
#include "../include/linked_list.h"

using namespace std;

// ===== TESTES FORNECIDOS PELO PROFESSOR =====
void teste_criaLista() {
    cout << "Testando criaLista()..." << endl;
    ListaSimplesmenteEncadeada* lista = criaLista();
    assert(lista != NULL);
    assert(lista->cardinalidade == 0);
    assert(lista->inicio == NULL);
    free(lista);
    cout << "✓ criaLista() passou em todos os testes" << endl;
}

void teste_insere() {
    cout << "Testando insere()..." << endl;
    ListaSimplesmenteEncadeada* lista = criaLista();
    insere(*lista, 10);
    assert(lista->cardinalidade == 1);
    assert(lista->inicio != NULL);
    assert(lista->inicio->conteudo == 10);
    assert(lista->inicio->proximo == NULL);

    insere(*lista, 20);
    assert(lista->cardinalidade == 2);
    assert(lista->inicio->conteudo == 20);
    assert(lista->inicio->proximo->conteudo == 10);

    destroiLista(*lista);
    free(lista);
    cout << "✓ insere() passou em todos os testes" << endl;
}

// ===== NOVOS TESTES DAS NOSSAS FUNÇÕES =====

void teste_listaVazia() {
    cout << "Testando listaVazia()..." << endl;
    ListaSimplesmenteEncadeada* lista = criaLista();
    assert(listaVazia(*lista) == true);
    insere(*lista, 5);
    assert(listaVazia(*lista) == false);
    destroiLista(*lista);
    free(lista);
    cout << "✓ listaVazia() passou em todos os testes" << endl;
}

void teste_numElementos() {
    cout << "Testando numElementos()..." << endl;
    ListaSimplesmenteEncadeada* lista = criaLista();
    assert(numElementos(*lista) == 0);
    insere(*lista, 10);
    assert(numElementos(*lista) == 1);
    insere(*lista, 20);
    assert(numElementos(*lista) == 2);
    destroiLista(*lista);
    free(lista);
    cout << "✓ numElementos() passou em todos os testes" << endl;
}

void teste_inserePosicao() {
    cout << "Testando inserePosicao()..." << endl;
    ListaSimplesmenteEncadeada* lista = criaLista();
    inserePosicao(*lista, 10, 0); 
    assert(lista->inicio->conteudo == 10);
    
    inserePosicao(*lista, 30, 1); 
    assert(lista->inicio->proximo->conteudo == 30);
    
    inserePosicao(*lista, 20, 1); 
    assert(lista->inicio->proximo->conteudo == 20);
    assert(lista->cardinalidade == 3);
    
    destroiLista(*lista);
    free(lista);
    cout << "✓ inserePosicao() passou em todos os testes" << endl;
}

void teste_removeElementoPosicao() {
    cout << "Testando removeElementoPosicao()..." << endl;
    ListaSimplesmenteEncadeada* lista = criaLista();
    insere(*lista, 30);
    insere(*lista, 20);
    insere(*lista, 10); 

    removeElementoPosicao(*lista, 1); 
    assert(lista->cardinalidade == 2);
    assert(lista->inicio->conteudo == 10);
    assert(lista->inicio->proximo->conteudo == 30);

    removeElementoPosicao(*lista, 0); 
    assert(lista->cardinalidade == 1);
    assert(lista->inicio->conteudo == 30);

    destroiLista(*lista);
    free(lista);
    cout << "✓ removeElementoPosicao() passou em todos os testes" << endl;
}

void teste_inverteLista() {
    cout << "Testando inverteLista()..." << endl;
    ListaSimplesmenteEncadeada* lista = criaLista();
    insere(*lista, 30);
    insere(*lista, 20);
    insere(*lista, 10); 
    
    inverteLista(*lista); 
    
    assert(lista->inicio->conteudo == 30);
    assert(lista->inicio->proximo->conteudo == 20);
    assert(lista->inicio->proximo->proximo->conteudo == 10);
    
    destroiLista(*lista);
    free(lista);
    cout << "✓ inverteLista() passou em todos os testes" << endl;
}

void teste_destroiLista() {
    cout << "Testando destroiLista()..." << endl;
    ListaSimplesmenteEncadeada* lista = criaLista();
    insere(*lista, 1);
    destroiLista(*lista);
    assert(lista->cardinalidade == 0);
    assert(lista->inicio == NULL);
    free(lista);
    cout << "✓ destroiLista() passou em todos os testes" << endl;
}

// ===== FUNÇÃO PRINCIPAL =====
int main() {
    cout << "\n=========================================" << endl;
    cout << "  INICIANDO TESTES DE LINKED LIST" << endl;
    cout << "=========================================" << endl << endl;

    try {
        teste_criaLista();
        teste_insere();
        teste_listaVazia();
        teste_numElementos();
        teste_inserePosicao();
        teste_removeElementoPosicao();
        teste_inverteLista();
        teste_destroiLista();

        cout << "\n=========================================" << endl;
        cout << "  ✓ TODOS OS TESTES PASSARAM COM SUCESSO!" << endl;
        cout << "=========================================" << endl << endl;

        return 0;
    } catch (const exception& e) {
        cout << "\nErro durante os testes: " << e.what() << endl;
        return 1;
    } catch (const char* e) {
        cout << "\nErro durante os testes: " << e << endl;
        return 1;
    }
}