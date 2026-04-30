#include <stdio.h>
// Criando movimentos complexos utilizando recursividade

// Função recursiva para o movimento da torre
void movimentoTorre(int movimentosRestantes) {
    if (movimentosRestantes > 0) {
        printf("Direita\n");
        movimentoTorre(movimentosRestantes - 1);
    }
}

// Função recursiva para o movimento do bispo com loop aninhado
    void movimentoBispo(int movimentosRestantes, int v, int h) {
        if (movimentosRestantes == 0) {
            return;
        }

        // Movimento diagonal: cima + direita
        for (int v = 0; v < 1; v++) { // sobe uma linha
            printf("Cima\n");
        }

        for (int h = 0; h < 1; h++) { // vai uma coluna para a direita
            printf("Direita\n");
        }
        movimentoBispo(movimentosRestantes - 1, v, h);
    }

// Função recursiva para o movimento da rainha
void movimentoRainha(int movimentosRestantes) {
    if (movimentosRestantes > 0) {
        printf("Esquerda\n");
        movimentoRainha(movimentosRestantes - 1);
    }
}

// Loops aninhados com multiplas variáveis para o movimento do cavalo

// Função para o movimento do cavalo
void movimentoCavalo(int movimentos) {
    for (int m = 1; m <= movimentos; m++) {

        // Loop aninhado com múltiplas variáveis (para mostrar que há dois controles)
        for (int v = 0, h = 0; v < 1 || h < 1; v++, h++) {

            // Movimento 1 e 2: uma casa para cima
            if ((m == 1 || m == 2) && v < 1) {
                printf("Cima\n");
            }

            // Movimento 3: uma casa para a direita
            if (m == 3 && h < 1) {
                printf("Direita\n");
                
            }
        }
    }
}
int main() {
    // Variáveis de casas a percorrer
    int casasTorre = 5;   // Torre vai andar 5 casas para a direita
    int casasBispo = 5;   // Bispo vai andar 5 casas na diagonal (cima + direita)
    int casasRainha = 8;  // Rainha vai andar 8 casas para a esquerda
    int casasCavalo = 3; // Cavalo vai andar 3 vezes (2 para cima, 1 para direita)

    printf("Movimentos da Torre:\n"); // Movimentos da Torre
    movimentoTorre(casasTorre);

    printf("\nMovimentos do Bispo:\n"); // Movimentos do Bispo
    movimentoBispo(casasBispo, 0, 0);

    printf("\nMovimentos da Rainha:\n"); // Movimentos da Rainha
    printf("\nMovimentos do Cavalo:\n"); // Movimentos do Cavalo
    int movimentos = 3; // total de movimentos
    movimentoCavalo(movimentos);

    return 0;
}