#include <stdio.h>

int main(void) {
    int linha = 6;   // posição inicial do cavalo
    int coluna = 1;  // posição inicial do cavalo
    int movimentos = 3; // total de movimentos

    printf("=== Movimentos do Cavalo ===\n\n");
    printf("Posição inicial: linha %d, coluna %d\n\n", linha, coluna);

    // Loop principal dos movimentos
    for (int m = 1; m <= movimentos; m++) {

        // Loop aninhado com múltiplas variáveis (para mostrar que há dois controles)
        for (int v = 0, h = 0; v < 1 || h < 1; v++, h++) {

            // Movimento 1 e 2: uma casa para cima
            if ((m == 1 || m == 2) && v < 1) {
                linha--;
                printf("Movimento %d: cima (linha %d)\n", m, linha);
            }

            // Movimento 3: uma casa para a direita
            if (m == 3 && h < 1) {
                coluna++;
                printf("Movimento %d: direita (coluna %d)\n", m, coluna);
            }
        }
    }

    printf("\nPosição final do cavalo: linha %d, coluna %d\n", linha, coluna);

    return 0;
}
