#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    char nome[30];
    int idade;
} Pessoa;

typedef struct {
    Pessoa itens[MAX];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

int estaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

void push(Pilha *p, Pessoa nova) {
    if (estaCheia(p)) {
        printf("Pilha cheia! Não é possível adicionar mais pessoas.\n");
        return;
    }
    p->topo++;
    p->itens[p->topo] = nova;
}

void pop(Pilha *p, Pessoa *removida) {
    if (estaVazia(p)) {
        printf("Pilha vazia! Não é possível remover pessoas.\n");
        return;
    }
    *removida = p->itens[p->topo];
    p->topo--;
}

void peek(Pilha *p, Pessoa *vizualizada) {
    if (estaVazia(p)) {
        printf("Pilha vazia! Não há pessoas para mostrar.\n");
        return;
    }
    *vizualizada = p->itens[p->topo];
}

void mostrarPilha(Pilha *p) {
    if (estaVazia(p)) {
        printf("Pilha vazia!\n");
        return;
    }
    printf("Pilha: ");
    for (int i = p->topo; i >= 0; i--) {
        printf("%s (%d) ", p->itens[i].nome, p->itens[i].idade);
    }
    printf("\n");
}

int main(){
    Pilha p;

    inicializarPilha(&p);
    
    Pessoa a = {"Alice", 30};
    Pessoa b = {"Bob", 25};
    Pessoa c = {"Charlie", 35};
    push(&p, a);
    push(&p, b);
    push(&p, c);

    mostrarPilha(&p);

    Pessoa removida;
    pop(&p, &removida);
    printf("Pessoa removida: %s, %d\n", removida.nome, removida.idade);
    mostrarPilha(&p);

    Pessoa topo;
    peek(&p, &topo);
    printf("Pessoa no topo: %s, %d\n", topo.nome, topo.idade);

    return 0;
}