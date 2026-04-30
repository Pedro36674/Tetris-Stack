#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILA_CAPACIDADE 5
#define PILHA_CAPACIDADE 3

typedef struct {
    char tipo; // Tipo da peça: I, O, T, L
    int id;    // Identificador único da peça
} Peca;

typedef struct {
    Peca itens[FILA_CAPACIDADE];
    int inicio;
    int fim;
    int total;
} Fila;

typedef struct {
    Peca itens[PILHA_CAPACIDADE];
    int topo;
} Pilha;

void inicializarFila(Fila *fila) {
    fila->inicio = 0;
    fila->fim = 0;
    fila->total = 0;
}

int filaCheia(const Fila *fila) {
    return fila->total == FILA_CAPACIDADE;
}

int filaVazia(const Fila *fila) {
    return fila->total == 0;
}

void enfileirar(Fila *fila, Peca peca) {
    if (filaCheia(fila)) {
        printf("Erro: fila cheia. Não é possível adicionar nova peça.\n");
        return;
    }
    fila->itens[fila->fim] = peca;
    fila->fim = (fila->fim + 1) % FILA_CAPACIDADE;
    fila->total++;
}

int desenfileirar(Fila *fila, Peca *peca) {
    if (filaVazia(fila)) {
        return 0;
    }
    if (peca != NULL) {
        *peca = fila->itens[fila->inicio];
    }
    fila->inicio = (fila->inicio + 1) % FILA_CAPACIDADE;
    fila->total--;
    return 1;
}

void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1;
}

int pilhaCheia(const Pilha *pilha) {
    return pilha->topo == PILHA_CAPACIDADE - 1;
}

int pilhaVazia(const Pilha *pilha) {
    return pilha->topo == -1;
}

int empilhar(Pilha *pilha, Peca peca) {
    if (pilhaCheia(pilha)) {
        return 0;
    }
    pilha->itens[++pilha->topo] = peca;
    return 1;
}

int desempilhar(Pilha *pilha, Peca *peca) {
    if (pilhaVazia(pilha)) {
        return 0;
    }
    if (peca != NULL) {
        *peca = pilha->itens[pilha->topo];
    }
    pilha->topo--;
    return 1;
}

char gerarTipoAleatorio(void) {
    const char tipos[4] = {'I', 'O', 'T', 'L'};
    return tipos[rand() % 4];
}

Peca gerarPeca(int *contadorId) {
    Peca peca;
    peca.tipo = gerarTipoAleatorio();
    peca.id = (*contadorId)++;
    return peca;
}

void mostrarFila(const Fila *fila) {
    if (filaVazia(fila)) {
        printf("Fila de peças: [vazia]\n");
        return;
    }

    printf("Fila de peças:");
    for (int i = 0; i < fila->total; i++) {
        int indice = (fila->inicio + i) % FILA_CAPACIDADE;
        printf(" [%c %d]", fila->itens[indice].tipo, fila->itens[indice].id);
    }
    printf("\n");
}

void mostrarPilha(const Pilha *pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha de reserva: (Topo -> Base) [vazia]\n");
        return;
    }

    printf("Pilha de reserva: (Topo -> Base):");
    for (int i = pilha->topo; i >= 0; i--) {
        printf(" [%c %d]", pilha->itens[i].tipo, pilha->itens[i].id);
    }
    printf("\n");
}

void mostrarEstado(const Fila *fila, const Pilha *pilha) {
    printf("\n=== Estado atual ===\n");
    mostrarFila(fila);
    mostrarPilha(pilha);
    printf("====================\n");
}

void exibirMenu(void) {
    printf("\nOpções de ação:\n");
    printf("1 - Jogar peça\n");
    printf("2 - Reservar peça\n");
    printf("3 - Usar peça reservada\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
}

int main(void) {
    srand((unsigned int)time(NULL));

    Fila fila;
    Pilha reserva;
    inicializarFila(&fila);
    inicializarPilha(&reserva);

    int proximoId = 0;
    for (int i = 0; i < FILA_CAPACIDADE; i++) {
        enfileirar(&fila, gerarPeca(&proximoId));
    }

    int comando = -1;
    while (comando != 0) {
        mostrarEstado(&fila, &reserva);
        exibirMenu();

        if (scanf("%d", &comando) != 1) {
            printf("Entrada inválida. Digite um número.\n");
            scanf("%*s");
            continue;
        }

        if (comando == 1) {
            Peca pecaJogada;
            if (!desenfileirar(&fila, &pecaJogada)) {
                printf("Não há peças para jogar.\n");
            } else {
                printf("Peça jogada: [%c %d]\n", pecaJogada.tipo, pecaJogada.id);
                enfileirar(&fila, gerarPeca(&proximoId));
            }
        } else if (comando == 2) {
            if (pilhaCheia(&reserva)) {
                printf("Reserva cheia! Não é possível reservar outra peça.\n");
            } else {
                Peca pecaReservada;
                if (!desenfileirar(&fila, &pecaReservada)) {
                    printf("Não há peças na fila para reservar.\n");
                } else {
                    empilhar(&reserva, pecaReservada);
                    printf("Peça reservada: [%c %d]\n", pecaReservada.tipo, pecaReservada.id);
                    enfileirar(&fila, gerarPeca(&proximoId));
                }
            }
        } else if (comando == 3) {
            Peca pecaUsada;
            if (!desempilhar(&reserva, &pecaUsada)) {
                printf("Reserva vazia! Não há peça para usar.\n");
            } else {
                printf("Peça usada da reserva: [%c %d]\n", pecaUsada.tipo, pecaUsada.id);
            }
        } else if (comando == 0) {
            printf("Encerrando o jogo. Obrigado por jogar!\n");
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}