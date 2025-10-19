#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo *izq, *der;
    int altura;
};

int altura(Nodo* n) { return n ? n->altura : 0; }

Nodo* nuevoNodo(int valor) {
    Nodo* n = new Nodo{valor, nullptr, nullptr, 1};
    return n;
}

int balance(Nodo* n) {
    return n ? altura(n->izq) - altura(n->der) : 0;
}

Nodo* rotarDerecha(Nodo* y) {
    Nodo* x = y->izq;
    Nodo* T2 = x->der;
    x->der = y;
    y->izq = T2;
    y->altura = max(altura(y->izq), altura(y->der)) + 1;
    x->altura = max(altura(x->izq), altura(x->der)) + 1;
    return x;
}

Nodo* rotarIzquierda(Nodo* x) {
    Nodo* y = x->der;
    Nodo* T2 = y->izq;
    y->izq = x;
    x->der = T2;
    x->altura = max(altura(x->izq), altura(x->der)) + 1;
    y->altura = max(altura(y->izq), altura(y->der)) + 1;
    return y;
}

Nodo* insertar(Nodo* nodo, int valor) {
    if (!nodo) return nuevoNodo(valor);
    if (valor < nodo->valor)
        nodo->izq = insertar(nodo->izq, valor);
    else if (valor > nodo->valor)
        nodo->der = insertar(nodo->der, valor);
    else
        return nodo;

    nodo->altura = 1 + max(altura(nodo->izq), altura(nodo->der));
    int bal = balance(nodo);

    // Casos de rotación
    if (bal > 1 && valor < nodo->izq->valor)
        return rotarDerecha(nodo);
    if (bal < -1 && valor > nodo->der->valor)
        return rotarIzquierda(nodo);
    if (bal > 1 && valor > nodo->izq->valor) {
        nodo->izq = rotarIzquierda(nodo->izq);
        return rotarDerecha(nodo);
    }
    if (bal < -1 && valor < nodo->der->valor) {
        nodo->der = rotarDerecha(nodo->der);
        return rotarIzquierda(nodo);
    }
    return nodo;
}

void preorden(Nodo* raiz) {
    if (raiz) {
        cout << raiz->valor << " ";
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}

int main() {
    Nodo* raiz = nullptr;
    raiz = insertar(raiz, 10);
    raiz = insertar(raiz, 20);
    raiz = insertar(raiz, 30);
    raiz = insertar(raiz, 40);
    raiz = insertar(raiz, 50);
    raiz = insertar(raiz, 25);

    cout << "Preorden del árbol AVL balanceado: ";
    preorden(raiz);
}


