#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char letra[2]; // 1 caractere + terminador nulo
    int id;
} Peca;

#define max 6

typedef struct {
    Peca itens[max];
    int inicio;
    int fim;
    int total;
} Fila;

void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}

int estaCheia(Fila *f) {
    return f->total == max;
}

int estaVazia(Fila *f) {
    return f->total == 0;
}

void inserir(Fila *f, Peca p) {
    if (estaCheia(f)) {
        printf("Fila cheia! Não é possível inserir.\n");
        return;
    }
    f->itens[f->fim] = p;
    f->fim = (f->fim + 1) % max;
    f->total++;
}

void remover(Fila *f, Peca *p) {
    if (estaVazia(f)) {
        printf("Fila vazia! Não é possível remover.\n");
        return;
    }
    if (p != NULL) {
        *p = f->itens[f->inicio];
    }
    f->inicio = (f->inicio + 1) % max;
    f->total--;
}

void mostrarFila(Fila *f) {
    if (estaVazia(f)) {
        printf("Fila vazia!\n");
        return;
    }
    printf("Fila: ");
    for (int i = 0; i < f->total; i++) {
        int idx = (f->inicio + i) % max;
        printf("%s (%d) ", f->itens[idx].letra, f->itens[idx].id);
    }
    printf("\n");
}

int main() {
    Fila f;
    inicializarFila(&f);

    Peca p1 = {"I", 1};
    Peca p2 = {"O", 2};
    Peca p3 = {"T", 3};
    inserir(&f, p1);
    inserir(&f, p2);
    inserir(&f, p3);

    mostrarFila(&f);

    Peca removida;
    remover(&f, &removida);
    printf("Peça removida: %s, %d\n", removida.letra, removida.id);
    mostrarFila(&f);

    printf("\n-------Menu-----\n");
    printf("1. Inserir peça\n");
    printf("2. Mostrar fila\n");
    printf("3. Sair\n");
    
    int opcao;
    int idPeca = 4;
    
    while (1) {
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o '\n' do buffer
        
        switch (opcao) {
            case 1: {
                printf("Letra da peça: ");
                char letra[2];
                scanf("%1s", letra);
                getchar(); // Limpa o '\n' do buffer
                
                Peca novaPeca = {0};
                novaPeca.letra[0] = letra[0];
                novaPeca.id = idPeca++;
                
                inserir(&f, novaPeca);
                printf("Peça '%s' inserida com sucesso!\n", novaPeca.letra);
                
                // Remove a primeira peça da fila
                Peca removida;
                remover(&f, &removida);
                printf("Peça '%s' removida da fila.\n\n", removida.letra);
                break;
            }
            
            case 2:
                mostrarFila(&f);
                printf("\n");
                break;
                
            case 3:
                printf("Saindo do programa...\n");
                return 0;
                
            default:
                printf("Opção inválida! Tente novamente.\n\n");
                break;
        }
        
        printf("-------Menu-----\n");
        printf("1. Inserir peça\n");
        printf("2. Mostrar fila\n");
        printf("3. Sair\n");
    }

    return 0;
}