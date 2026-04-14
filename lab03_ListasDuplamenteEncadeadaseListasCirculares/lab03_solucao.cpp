#include <iostream>
using namespace std;

struct No {
    int valor;
    No* prox;
    No* ant;
};

struct Lista {
    No* inicio;
    No* fim;
};

void inicializar(Lista &L) {
    L.inicio = nullptr;
    L.fim = nullptr;
}

bool vazia(const Lista &L) {
    return L.inicio == nullptr;
}

bool eh_circular(const Lista &L) {
    if (L.inicio == nullptr || L.fim == nullptr) {
        return false;
    }

    if(L.fim->prox==L.inicio && L.inicio->ant == L.fim){
        return true;
    }else{return false;}
}

void tornar_circular(Lista &L) {
    if (L.inicio == nullptr) {
        return;
    }
    L.fim->prox=L.inicio;
    L.inicio->ant = L.fim;
}

void desfazer_circular(Lista &L) {
    if (!eh_circular(L)) return;
    L.inicio->ant = nullptr;
    L.fim->prox = nullptr;
}

void inserir_inicio(Lista &L, int valor) {
    No* novo = new No;
    novo->valor = valor;
    novo->ant = nullptr;
    novo->prox = L.inicio;

    if (L.inicio == nullptr) {
         L.inicio = novo;
         L.fim = novo;
    } else {
         L.inicio->ant = novo;
          L.inicio = novo;
    }
}

void inserir_final(Lista &L, int valor) {
    No* novo = new No;
    novo->valor = valor;
    novo->prox = nullptr;

    if (L.fim == nullptr) { 
        novo->ant = nullptr;
            L.inicio = novo;
            L.fim = novo;
        } else {
            novo->ant = L.fim;
            L.fim->prox = novo;
            L.fim = novo;
        }
}

bool remover_valor(Lista &L, int valor) {
    No* atual = L.inicio;

    while (atual != nullptr && atual->valor != valor) {
        atual = atual->prox;
    }

    if (atual == nullptr) {
        return false;
    }

    if (atual->ant != nullptr) {
        atual->ant->prox = atual->prox;
    } else {
        L.inicio = atual->prox;
    }

    if (atual->prox != nullptr) {
        atual->prox->ant = atual->ant;
    } else {
        L.fim = atual->ant;
    }

    delete atual;
    return true;
}

void imprimir_frente(const Lista &L) {
    if (vazia(L)) {
        cout << "[ ]\n";
        return;
    }

    if (eh_circular(L)) {
        cout << "A lista e circular. Use imprimir_circular.\n";
        return;
    }

    No* atual = L.inicio;
    cout << "[ ";
    while (atual != nullptr) {
        cout << atual->valor << " ";
        atual = atual->prox;
    }
    cout << "]\n";
}

void imprimir_reverso(const Lista &L) {
        if (vazia(L)) {
        cout << "[ ]\n";
        return;
    }

        if (eh_circular(L)) {
        cout << "A lista e circular. Use imprimir_circular.\n";
        return;
    }

    No* atual = L.fim;
    cout << "[ ";
        while (atual != nullptr) {
        cout << atual->valor << " ";
        atual = atual->ant;
    }
    cout << "]\n";
}

void imprimir_circular(Lista &L, int n) {
    if (L.inicio == nullptr) {
        cout << "Lista vazia." << endl;
        return;
    }

    if(eh_circular(L)){
        No* atual = L.inicio;
        for(int i = 0; i<n; i++){
            cout << atual->valor << " ";
            atual = atual->prox;
        }
    }else{cout << "ERRO: a lista está no modo linear";}
}

void liberar_lista(Lista &L) {
    if (vazia(L)) return;

    if (eh_circular(L)) {
        desfazer_circular(L);
    }

    No* atual = L.inicio;
    while (atual != nullptr) {
        No* temp = atual;
        atual = atual->prox;
        delete temp;
    }

    L.inicio = nullptr;
    L.fim = nullptr;
}

/* MENU */

void menu() {
    cout << "\n===== MENU =====\n";
    cout << "1. Inserir no inicio\n";
    cout << "2. Inserir no final\n";
    cout << "3. Remover valor\n";
    cout << "4. Tornar circular\n";
    cout << "5. Desfazer circular\n";
    cout << "6. Verificar circular\n";
    cout << "7. Imprimir frente\n";
    cout << "8. Imprimir reverso\n";
    cout << "9. Imprimir circular (n elementos)\n";
    cout << "10. Liberar lista\n";
    cout << "0. Sair\n";
    cout << "Opcao: ";
}

int main() {
    Lista L;
    inicializar(L);

    int op;

    do {
        menu();
        cin >> op;

        switch (op) {
            case 1: {
                int v;
                cout << "Digite o valor a inserir no inicio: ";
                cin >> v;
                inserir_inicio(L, v);
                cout << "Valor inserido com sucesso.\n";
                break;
            }

            case 2: {
                int v;
                cout << "Digite o valor a inserir no final: ";
                cin >> v;
                inserir_final(L, v);
                cout << "Valor inserido com sucesso.\n";
                break;
            }

            case 3: {
                int v;
                cout << "Digite o valor a remover: ";
                cin >> v;
                if (remover_valor(L, v)) {
                    cout << "Valor removido com sucesso.\n";
                } else {
                    cout << "Valor nao encontrado.\n";
                }
                break;
            }

            case 4:
                tornar_circular(L);
                cout << "Lista convertida para circular.\n";
                break;

            case 5:
                desfazer_circular(L);
                cout << "Lista voltou para linear.\n";
                break;

            case 6:
                cout << (eh_circular(L) ? "Sim\n" : "Nao\n");
                break;

            case 7:
                cout << "Imprimindo frente: ";
                imprimir_frente(L);
                break;

            case 8:
                cout << "Imprimindo reverso: ";
                imprimir_reverso(L);
                break;

            case 9: {
                int n;
                cout << "Digite quantos elementos deseja imprimir: ";
                cin >> n;
                cout << "Imprimindo circularmente: ";
                imprimir_circular(L, n);
                break;
            }

            case 10:
                liberar_lista(L);
                cout << "Lista liberada.\n";
                break;

            case 0:
                liberar_lista(L);
                cout << "Encerrando.\n";
                break;

            default:
                cout << "Opcao invalida.\n";
        }

    } while (op != 0);

    return 0;
}