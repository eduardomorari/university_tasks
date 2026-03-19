#include <iostream>
using namespace std;

struct No {
    int valor;
    No* prox;
};

struct Lista {
    No* inicio;
};

void inicializar(Lista &L) {
    L.inicio = nullptr;
}

bool vazia(const Lista &L) {
    return L.inicio == nullptr;
}

void imprimir(const Lista &L) {
    No* atual = L.inicio;

    cout << "[ ";
    while (atual != nullptr) {
        cout << atual->valor << " ";
        atual = atual->prox;
    }
    cout << "]" << endl;
}

/* IMPLEMENTAR AS FUNCOES ABAIXO */

void inserir_inicio(Lista &L, int valor) {
    No* novo = new No;     //cria endereço pra outro dado tipo No
    novo->valor = valor;   //insere o valor fornecido da função no novo dado
    novo->prox = L.inicio; //atualiza o endereço do novo dado com o endereço inicio
    L.inicio = novo;       //endereço do inicio agora recebe o endereço "novo"
}

void inserir_final(Lista &L, int valor) {
    // TODO
}

No* buscar(const Lista &L, int valor) {
    // TODO
    return nullptr;
}

bool remover_valor(Lista &L, int valor) {
    // TODO
    return false;
}

void liberar_lista(Lista &L) {
    // TODO
}

void mostrar_menu() {
    cout << "\n===== MENU - LISTA ENCADEADA =====\n";
    cout << "1. Inicializar lista\n";
    cout << "2. Inserir no inicio\n";
    cout << "3. Inserir no final\n";
    cout << "4. Buscar valor\n";
    cout << "5. Remover valor\n";
    cout << "6. Imprimir lista\n";
    cout << "7. Verificar se a lista esta vazia\n";
    cout << "8. Liberar memoria da lista\n";
    cout << "0. Sair\n";
    cout << "Escolha uma opcao: ";
}

int main() {
    Lista L;
    inicializar(L);

    int opcao;

    do {
        mostrar_menu();
        cin >> opcao;

        switch (opcao) {
            case 1: {
                liberar_lista(L);
                inicializar(L);
                cout << "Lista inicializada com sucesso.\n";
                break;
            }

            case 2: {
                int valor;
                cout << "Digite o valor a inserir no inicio: ";
                cin >> valor;
                inserir_inicio(L, valor);
                cout << "Valor inserido com sucesso.\n";
                break;
            }

            case 3: {
                int valor;
                cout << "Digite o valor a inserir no final: ";
                cin >> valor;
                inserir_final(L, valor);
                cout << "Valor inserido com sucesso.\n";
                break;
            }

            case 4: {
                int valor;
                cout << "Digite o valor a buscar: ";
                cin >> valor;

                No* p = buscar(L, valor);
                if (p != nullptr) {
                    cout << "Valor encontrado no no de endereco: " << p << endl;
                } else {
                    cout << "Valor nao encontrado.\n";
                }
                break;
            }

            case 5: {
                int valor;
                cout << "Digite o valor a remover: ";
                cin >> valor;

                if (remover_valor(L, valor)) {
                    cout << "Valor removido com sucesso.\n";
                } else {
                    cout << "Valor nao encontrado.\n";
                }
                break;
            }

            case 6: {
                cout << "Conteudo da lista: ";
                imprimir(L);
                break;
            }

            case 7: {
                if (vazia(L)) {
                    cout << "A lista esta vazia.\n";
                } else {
                    cout << "A lista nao esta vazia.\n";
                }
                break;
            }

            case 8: {
                liberar_lista(L);
                cout << "Memoria da lista liberada com sucesso.\n";
                break;
            }

            case 0: {
                liberar_lista(L);
                cout << "Encerrando o programa.\n";
                break;
            }

            default: {
                cout << "Opcao invalida. Tente novamente.\n";
                break;
            }
        }

    } while (opcao != 0);

    return 0;
}