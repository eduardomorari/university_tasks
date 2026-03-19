#include <iostream>
using namespace std;

const int MAX = 100;

struct Lista {
    int dados[MAX];
    int tamanho;
};

void inicializar(Lista &L) {
    L.tamanho = 0;
}

bool cheia(Lista &L) {
    return L.tamanho == MAX;
}

bool vazia(Lista &L) {
    return L.tamanho == 0;
}

void imprimir(Lista &L) {
    cout << "[ ";
    for (int i = 0; i < L.tamanho; i++) {
        cout << L.dados[i] << " ";
    }
    cout << "]" << endl;
}

/* IMPLEMENTAR ABAIXO */

bool inserir_final(Lista &L, int valor) {
    return true;
}

bool inserir_posicao(Lista &L, int valor, int pos) {
    return true;
}

bool remover_posicao(Lista &L, int pos) {
    return true;
}

int buscar(Lista &L, int valor) {
    return -1;
}

int main() {

    Lista L;
    inicializar(L);

    inserir_final(L, 10);
    inserir_final(L, 20);
    inserir_final(L, 30);

    imprimir(L);

    inserir_posicao(L, 15, 1);
    imprimir(L);

    remover_posicao(L, 2);
    imprimir(L);

    cout << "Posicao do 30: " << buscar(L,30) << endl;

}