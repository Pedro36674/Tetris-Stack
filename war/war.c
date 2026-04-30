#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TERRITORIOS 3
#define TAM_NOME 100
#define MAX_JOGADORES 2
#define TOTAL_MISSOES 3

// ================= STRUCTS =================

struct Territorio {
    char nome[TAM_NOME];
    char bandeira[TAM_NOME];
    int numeroTropas;
    int dono;
};

struct Jogador {
    char nome[TAM_NOME];
    char missao[100];
};

// ================= FUNÇÕES =================

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int rolarDado() {
    return rand() % 6 + 1;
}

// remover território (mantido)
void removerTerritorio(struct Territorio *mapa, int *total, int indice) {
    for (int i = indice; i < *total - 1; i++) {
        mapa[i] = mapa[i + 1];
    }
    (*total)--;
}

// sortear missão
void sortearMissao(struct Jogador *jogador, char missoes[TOTAL_MISSOES][100]) {
    int i = rand() % TOTAL_MISSOES;
    strcpy(jogador->missao, missoes[i]);
}

// contar territórios de um jogador
int contarTerritorios(struct Territorio *mapa, int total, int jogador) {
    int count = 0;
    for (int i = 0; i < total; i++) {
        if (mapa[i].dono == jogador)
            count++;
    }
    return count;
}

// verificar vitória
int verificarVitoria(struct Territorio *mapa, int total, struct Jogador *jogador, int id) {

    if (strcmp(jogador->missao, "Conquistar todos") == 0) {
        return contarTerritorios(mapa, total, id) == total;
    }

    if (strcmp(jogador->missao, "Ter 2 territorios") == 0) {
        return contarTerritorios(mapa, total, id) >= 2;
    }

    if (strcmp(jogador->missao, "Eliminar inimigo") == 0) {
        for (int i = 0; i < total; i++) {
            if (mapa[i].dono != id)
                return 0;
        }
        return 1;
    }

    return 0;
}

// combate atualizado
void combate(struct Territorio *mapa, int *total, int atacante, int defensor) {
    int dadoAtacante = rolarDado();
    int dadoDefensor = rolarDado();

    printf("\n--- Combate ---\n");
    printf("%s rolou: %d\n", mapa[atacante].nome, dadoAtacante);
    printf("%s rolou: %d\n", mapa[defensor].nome, dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        printf("Atacante venceu!\n");
        mapa[defensor].numeroTropas--;

        if (mapa[defensor].numeroTropas <= 0) {
            printf("%s foi conquistado!\n", mapa[defensor].nome);

            mapa[defensor].dono = mapa[atacante].dono;
            mapa[defensor].numeroTropas = 1;
            mapa[atacante].numeroTropas--;
        }

    } else {
        printf("Defensor venceu!\n");
        mapa[atacante].numeroTropas--;

        if (mapa[atacante].numeroTropas <= 0) {
            printf("%s foi removido!\n", mapa[atacante].nome);
            removerTerritorio(mapa, total, atacante);
        }
    }
}

// ================= MAIN =================

int main() {
    struct Territorio *mapa;
    struct Jogador jogadores[MAX_JOGADORES];

    int totalTerritorios = 0;
    int turno = 0;

    srand(time(NULL));

    mapa = (struct Territorio *)calloc(MAX_TERRITORIOS, sizeof(struct Territorio));

    char missoes[TOTAL_MISSOES][100] = {
        "Conquistar todos",
        "Ter 2 territorios",
        "Eliminar inimigo"
    };

    // ===== Jogadores =====
    for (int i = 0; i < MAX_JOGADORES; i++) {
        printf("Nome do jogador %d: ", i);
        fgets(jogadores[i].nome, TAM_NOME, stdin);
        jogadores[i].nome[strcspn(jogadores[i].nome, "\n")] = '\0';

        sortearMissao(&jogadores[i], missoes);
    }

    printf("\n--- Missoes ---\n");
    for (int i = 0; i < MAX_JOGADORES; i++) {
        printf("%s -> %s\n", jogadores[i].nome, jogadores[i].missao);
    }

    // ===== Criar territórios =====
    while (totalTerritorios < MAX_TERRITORIOS) {
        printf("\nAdicionar Território\n");

        printf("Nome:\n");
        fgets(mapa[totalTerritorios].nome, TAM_NOME, stdin);

        printf("Bandeira:\n");
        fgets(mapa[totalTerritorios].bandeira, TAM_NOME, stdin);

        mapa[totalTerritorios].nome[strcspn(mapa[totalTerritorios].nome, "\n")] = '\0';
        mapa[totalTerritorios].bandeira[strcspn(mapa[totalTerritorios].bandeira, "\n")] = '\0';

        printf("Número de tropas:\n");
        scanf("%d", &mapa[totalTerritorios].numeroTropas);
        limparBufferEntrada();

        // distribui donos alternando
        mapa[totalTerritorios].dono = totalTerritorios % MAX_JOGADORES;

        totalTerritorios++;
    }

    // ===== LOOP =====
    while (1) {

        printf("\nTurno de: %s\n", jogadores[turno].nome);

        printf("\n--- Territórios ---\n");
        for (int i = 0; i < totalTerritorios; i++) {
            printf("%d. %s | Dono: %s | Tropas: %d\n",
                   i,
                   mapa[i].nome,
                   jogadores[mapa[i].dono].nome,
                   mapa[i].numeroTropas);
        }

        int atacante, defensor;

        printf("\nEscolha atacante (-1 sai): ");
        scanf("%d", &atacante);
        if (atacante == -1) break;

        printf("Escolha defensor: ");
        scanf("%d", &defensor);
        limparBufferEntrada();

        if (atacante >= 0 && atacante < totalTerritorios &&
            defensor >= 0 && defensor < totalTerritorios &&
            atacante != defensor &&
            mapa[atacante].dono == turno &&
            mapa[defensor].dono != turno) {

            combate(mapa, &totalTerritorios, atacante, defensor);

            // vitória
            if (verificarVitoria(mapa, totalTerritorios, &jogadores[turno], turno)) {
                printf("\n %s venceu cumprindo: %s\n",
                       jogadores[turno].nome,
                       jogadores[turno].missao);
                break;
            }

            turno = (turno + 1) % MAX_JOGADORES;

        } else {
            printf("Jogada inválida!\n");
        }
    }

    free(mapa);
    return 0;
}