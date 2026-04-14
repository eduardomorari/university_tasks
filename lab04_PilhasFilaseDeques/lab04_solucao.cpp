#include <iostream>
using namespace std;
#define MAX 10

/* =========================
   PILHA - VETORES
   ========================= */

struct Pilha {
    int elementos [MAX];
    int tamanho;
};

void inicializar_pilha(Pilha &P) {
    P.tamanho = -1;
}

bool pilha_vazia(const Pilha &P) {
    if(P.tamanho == -1) {return true;}
    return false;
}

bool push(Pilha &P, int valor) {
    if(P.tamanho<(MAX-1)){
        P.tamanho++;
        P.elementos[P.tamanho] = valor;
        return true;
    }
    return false;
}

bool pop(Pilha &P) {
    if(P.tamanho != -1){
        P.tamanho--;
        return true;
    }
    return false;
}

int top(const Pilha &P) {
    if(P.tamanho != -1){
        return P.elementos[P.tamanho];
    }
    return -1;
}

void imprimir_pilha(const Pilha &P) {
    if(pilha_vazia(P)){
        cout << "[ ]";
        return;
    }

    cout << "[ ";
    for(int i=P.tamanho; i>-1; i--){
        cout << P.elementos[i] << " ";
    }
    cout << "]";
    return;
}

void liberar_pilha(Pilha &P) {
    P.tamanho = -1;
}

/* =========================
   FILA - LISTAS ENCADEADAS
   ========================= */

   
struct No {
    int valor;
    No* prox = nullptr;
};

struct Fila {
    No* inicio;
    No* fim;
};

void inicializar_fila(Fila &F) {
    F.fim = nullptr;
    F.inicio = nullptr;
}

bool fila_vazia(const Fila &F) {
    if(F.fim == nullptr && F.inicio == nullptr){
        return true;
    }
    return false;
}

bool enqueue(Fila &F, int valor) {
    No* novo = new No;
    if(fila_vazia(F)){
        novo->valor = valor;
        F.fim = novo;
        F.inicio = novo;
        return true;
    }

    novo->valor = valor;
    F.fim->prox = novo;
    F.fim = novo;
    return true;
}

bool dequeue(Fila &F) {

    if(F.inicio == F.fim && !fila_vazia(F)){
        No* remover;
        remover = F.inicio;
        F.inicio = nullptr;
        F.fim = nullptr;
        delete remover;
        return true;
    }

    if(F.inicio != F.fim){
        No* remover;
        remover = F.inicio;
        F.inicio = F.inicio->prox;
        delete remover;
        return true;
    }
    return false;
}

int front(const Fila &F) {
    if(!fila_vazia(F)){
        No* front;
        front = F.inicio;
        return front->valor;
    }
    return -1;
}

void imprimir_fila(const Fila &F) {
    if(fila_vazia(F)){cout << "[ ]"; return;}
    No* atual;
    atual = F.inicio;
    cout << "[ ";
    while(atual != nullptr){
        cout << atual->valor << " ";
        atual = atual->prox;
    }
    cout << "]";
    return;
}


/* =========================
   MENUS
   ========================= */
void menu_principal() {
    cout << "\n===== LABORATORIO 4 =====\n";
    cout << "1. Testar Pilha\n";
    cout << "2. Testar Fila\n";
    cout << "0. Sair\n";
    cout << "Opcao: ";
}

void menu_pilha() {
    cout << "\n--- PILHA ---\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Top\n";
    cout << "4. Imprimir\n";
    cout << "5. Liberar pilha\n";
    cout << "0. Voltar\n";
    cout << "Opcao: ";
}

void menu_fila() {
    cout << "\n--- FILA ---\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Front\n";
    cout << "4. Imprimir\n";
    cout << "0. Voltar\n";
    cout << "Opcao: ";
}

int main() {
    Pilha P;
    Fila F;

    inicializar_pilha(P);
    inicializar_fila(F);

    int op;

    do {
        menu_principal();
        cin >> op;

        if (op == 1) {
            int op2;
            do {
                menu_pilha();
                cin >> op2;

                switch (op2) {
                    case 1: {
                        int v;
                        cout << "Valor: ";
                        cin >> v;
                        if (push(P, v)) cout << "Inserido.\n";
                        break;
                    }
                    case 2:
                        if (pop(P)) cout << "Removido.\n";
                        else cout << "Pilha vazia.\n";
                        break;
                    case 3:
                        if (!pilha_vazia(P)) cout << "Topo = " << top(P) << endl;
                        else cout << "Pilha vazia.\n";
                        break;
                    case 4:
                        imprimir_pilha(P);
                        break;
                    case 5:
                        liberar_pilha(P);
                        break;
                }
            } while (op2 != 0);
        }

        if (op == 2) {
            int op2;
            do {
                menu_fila();
                cin >> op2;

                switch (op2) {
                    case 1: {
                        int v;
                        cout << "Valor: ";
                        cin >> v;
                        if (enqueue(F, v)) cout << "Inserido.\n";
                        break;
                    }
                    case 2:
                        if (dequeue(F)) cout << "Removido.\n";
                        else cout << "Fila vazia.\n";
                        break;
                    case 3:
                        if (!fila_vazia(F)) cout << "Front = " << front(F) << endl;
                        else cout << "Fila vazia.\n";
                        break;
                    case 4:
                        imprimir_fila(F);
                        break;
                }
            } while (op2 != 0);
        }
    } while (op != 0);

    liberar_pilha(P);

    return 0;
}
