#include <stdio.h>
#include <stdlib.h>   // <-- necessário para abs()

#define TAM 10
#define TAM_HAB 5

int main() {
    // Criando as linhas do tabuleiro
    char linhas[TAM] = { 'A','B','C','D','E','F','G','H','I','J' };

    // Tabuleiro 10x10 inicializado com 0
    int tabuleiro[TAM][TAM] = { 0 };

    // Legenda: 0 = água | 3 = navio | 5 = habilidade

    // ===== POSICIONANDO NAVIOS =====
    tabuleiro[2][2] = 3;
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;

    tabuleiro[0][7] = 3;
    tabuleiro[1][7] = 3;
    tabuleiro[2][7] = 3;

    for (int i = 0; i < 3; i++) {
        tabuleiro[7 + i][6 + i] = 3;
    }

    for (int i = 0; i < 3; i++) {
        tabuleiro[9 - i][0 + i] = 3;
    }

    // ==============================
    // MATRIZES DE HABILIDADES (5x5)
    // ==============================

    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    int centro = TAM_HAB / 2;

    // ----- CONE -----
    // Apice no topo (linha 0) e expande para baixo
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // sem limitar por i <= centro: largura cresce conforme descemos.
            if (j >= (centro - i) && j <= (centro + i))
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // ----- CRUZ -----
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == centro || j == centro)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // ----- OCTAEDRO -----
    // Usa distância de Manhattan para formar um losango centrado
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // ==============================
    // SOBREPOSIÇÃO DAS HABILIDADES
    // ==============================

    int origemCone[2] = { 4, 2 };
    int origemCruz[2] = { 5, 5 };
    int origemOctaedro[2] = { 7, 8 };

    for (int hab = 0; hab < 3; hab++) {
        int (*habilidade)[TAM_HAB];
        int origemLinha, origemColuna;

        if (hab == 0) { habilidade = cone; origemLinha = origemCone[0]; origemColuna = origemCone[1]; }
        else if (hab == 1) { habilidade = cruz; origemLinha = origemCruz[0]; origemColuna = origemCruz[1]; }
        else { habilidade = octaedro; origemLinha = origemOctaedro[0]; origemColuna = origemOctaedro[1]; }

        for (int i = 0; i < TAM_HAB; i++) {
            for (int j = 0; j < TAM_HAB; j++) {
                if (habilidade[i][j] == 1) {
                    int linhaTab = origemLinha - centro + i;
                    int colunaTab = origemColuna - centro + j;

                    // Garante que está dentro do tabuleiro e não sobrescreve navios
                    if (linhaTab >= 0 && linhaTab < TAM && colunaTab >= 0 && colunaTab < TAM) {
                        if (tabuleiro[linhaTab][colunaTab] == 0)
                            tabuleiro[linhaTab][colunaTab] = 5;
                    }
                }
            }
        }
    }

    // ==============================
    // EXIBIÇÃO DO TABULEIRO
    // ==============================
    printf("   ");
    for (int i = 0; i < TAM; i++) printf(" %c", linhas[i]);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // ==============================
    // EXIBIÇÃO DAS MATRIZES DE HABILIDADE
    // ==============================
    printf("\n--- MATRIZ CONE ---\n");
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) printf(" %d", cone[i][j]);
        printf("\n");
    }

    printf("\n--- MATRIZ CRUZ ---\n");
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) printf(" %d", cruz[i][j]);
        printf("\n");
    }

    printf("\n--- MATRIZ OCTAEDRO ---\n");
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) printf(" %d", octaedro[i][j]);
        printf("\n");
    }

    return 0;
}
