#include <iostream>
using namespace std;

const int MAX = 10;

struct Lista {
    int dados[MAX];
    int tamanho;
};

void inicializar(Lista &L) {
    L.tamanho = 0;
}

bool cheia(const Lista &L) {
    return L.tamanho == MAX;
}

bool vazia(const Lista &L) {
    return L.tamanho == 0;
}

void imprimir(const Lista &L) {
    cout << "[ ";
    for (int i = 0; i < L.tamanho; i++) {
        cout << L.dados[i] << " ";
    }
    cout << "]" << endl;
}

bool inserir_final(Lista &L, int valor) { 
    if(L.tamanho<MAX){
        L.dados[L.tamanho] = valor;
        L.tamanho++;
        return true;
    }else{return false;}
}

bool inserir_posicao(Lista &L, int valor, int pos) {
    if(L.tamanho<MAX-1){
        L.tamanho++;
        for(int i=L.tamanho-1; i>=pos; i--){
            L.dados[i+1] = L.dados[i];
        }

        L.dados[pos] = valor;

        return true;
    }else if(L.tamanho == MAX-1){
        inserir_final(L, valor);
        return true;
    }else{return false;}
    
}

bool remover_posicao(Lista &L, int pos) { 
    if(L.tamanho>=0){

        for(int i=pos; i<L.tamanho; i++){
            L.dados[i] = L.dados[i+1];
        }

        L.tamanho--;

    return true;
    }else{return false;}
}

int buscar(const Lista &L, int valor) {

    for(int i=0; i<L.tamanho; i++){
        if(L.dados[i]==valor){
            return i;
        }
    }
  
    return -1;
 
}

bool remover_valor(Lista &L, int valor) {

    bool removed=false;

    for(int i=0; i<L.tamanho; i++){
        if(valor == L.dados[i]){
            remover_posicao(L, i);
            removed = true;
        }
        
        if(removed){
            break;
        }
    }

    if(!removed){
        return false;
    }else{return true;}
}

void mostrar_menu() {
    cout << "\n===== MENU - LISTA LINEAR COM VETOR =====\n";
    cout << "1. Inicializar lista\n";
    cout << "2. Inserir no final\n";
    cout << "3. Inserir em uma posicao\n";
    cout << "4. Remover de uma posicao\n";
    cout << "5. Buscar valor\n";
    cout << "6. Imprimir lista\n";
    cout << "7. Verificar se esta vazia\n";
    cout << "8. Verificar se esta cheia\n";
    cout << "9. Remover por valor\n";
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
                inicializar(L);
                cout << "Lista inicializada com sucesso.\n";
                break;
            }

            case 2: {
                int valor;
                cout << "Digite o valor a inserir no final: ";
                cin >> valor;

                if (inserir_final(L, valor)) {
                    cout << "Valor inserido com sucesso.\n";
                } else {
                    cout << "Erro: lista cheia.\n";
                }
                break;
            }

            case 3: {
                int valor, pos;
                cout << "Digite o valor a inserir: ";
                cin >> valor;
                cout << "Digite a posicao: ";
                cin >> pos;

                if (inserir_posicao(L, valor, pos)) {
                    cout << "Valor inserido com sucesso.\n";
                } else {
                    cout << "Erro: posicao invalida ou lista cheia.\n";
                }
                break;
            }

            case 4: {
                int pos;
                cout << "Digite a posicao a remover: ";
                cin >> pos;

                if (remover_posicao(L, pos)) {
                    cout << "Elemento removido com sucesso.\n";
                } else {
                    cout << "Erro: lista vazia ou posicao invalida.\n";
                }
                break;
            }

            case 5: {
                int valor;
                cout << "Digite o valor a buscar: ";
                cin >> valor;

                int pos = buscar(L, valor);
                if (pos != -1) {
                    cout << "Valor encontrado na posicao " << pos << ".\n";
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
                if (cheia(L)) {
                    cout << "A lista esta cheia.\n";
                } else {
                    cout << "A lista nao esta cheia.\n";
                }
                break;
            }

            case 9: {
                int valor;
                cout << "Digite o valor a remover: ";
                cin >> valor;

                if (remover_valor(L, valor)) {
                    cout << "Primeira ocorrencia removida com sucesso.\n";
                } else {
                    cout << "Valor nao encontrado na lista.\n";
                }
                break;
            }

            case 0: {
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