#include <iostream>

using namespace std;

struct No {
    int valor;
    No* prox;

    No(int n) {
        valor = n;
        prox = NULL;
    }
};

struct Lista {
    No* inicio;
    No* fim;
    int n;

    Lista(){
        inicio = NULL;
        fim = NULL;
    }

    void inserirInicio(int n) {
        No* novo = new No(n);

        if(inicio == NULL){
            inicio = novo;
            fim = novo;
        }else {
            novo->prox = inicio;
            inicio = novo;
        }
        n++;
    }

    void inserirFinal(int n) {
        No* novo = new No(n);
        if(inicio == NULL){
            inicio = novo;
            fim = novo;
        }else {
            fim->prox = novo;
            fim = novo;
        }
        n++;
    }

    void removerInicio(){
        if(n == 0) return;
        if(n == 1){
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n--;
            return;
        }

        No* aux = inicio;
        inicio = inicio->prox;
        delete(aux);
        n--;
    }

     void removerFinal(){
        if(n == 0) return;
        if(n == 1){
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n--;
            return;
        }
        No* aux = inicio;
        while(aux->prox != fim){
            aux = aux->prox;
        }
        delete(fim);
        fim = aux;
        aux->prox = NULL;
        n--;
    }

    void imprimir() {
            No* aux = inicio;
            //printf("%d %d\n", aux, aux->valor);
            while(aux != NULL) {
                printf("%d\n", aux->valor);
                //printf("%d %d\n", aux->prox, aux->valor);
                aux = aux->prox;
            }

    }
};

int main(){
    //1. Criar um m�todo que recebe um n�mero N e remove os N �ltimos elementos da lista.
    //Caso o tamanho da lista seja menor que N, esvaziar a lista.

    Lista l;

    int a;

    cin >> a;

    while(a--){
        int b;
        cin >> b;
        l.inserirInicio(b);
    }

    int c;

    cin >> c;

    while(c--){
        int d;
        cin >> d;
        l.inserirFinal(d);
    }

    cout << "Lista original:" << endl;
    l.imprimir();

    int n;

    cin >> n;

    while(n--){
        l.removerFinal();
    }

    cout << "Lista apos remocao dos N ultimos elementos da lista:" << endl;
    l.imprimir();

    return 0;
}
