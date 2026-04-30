#include <stdio.h>

int main() {

    // Variáveis para armazenar os dados da carta
    char estado;
    char codigoCarta[5], cidade[50];
    unsigned long int populacao;
    int opcao, opcao2;
    int pontosTuristicos;
    float area, pib, densidade, pibPerCapita;

    char estado2;
    char codigoCarta2[5], cidade2[50];
    unsigned long int populacao2;
    int pontosTuristicos2;
    float area2, pib2, densidade2, pibPerCapita2;

    float somaCarta1 = 0, somaCarta2 = 0;

    // Solicita os dados da primeira carta
    printf("Insira a letra inicial do estado de A a H: ");
    scanf(" %c", &estado);
    printf("Insira o código da carta de 01 a 04 (ex: A01): ");
    scanf(" %s", codigoCarta);
    printf("Insira o nome da cidade: ");
    scanf("%s", cidade);
    printf("Insira a população do estado: ");
    scanf("%lu", &populacao);
    printf("Insira a área do estado: ");
    scanf("%f", &area);
    printf("Insira o PIB do estado: ");
    scanf("%f", &pib);
    printf("Insira a quantidade de pontos turísticos do estado: ");
    scanf("%d", &pontosTuristicos);
    
    // Solicita os dados da segunda carta
    printf("Insira a letra inicial do estado de A a H: ");
    scanf(" %c", &estado2);
    printf("Insira o código da carta de 01 a 04(ex: A01): ");
    scanf(" %s", codigoCarta2);
    printf("Insira o nome da cidade: ");
    scanf("%s", cidade2);
    printf("Insira a população do estado: ");
    scanf("%lu", &populacao2);
    printf("Insira a área do estado: ");
    scanf("%f", &area2);
    printf("Insira o PIB do estado: ");
    scanf("%f", &pib2);
    printf("Insira a quantidade de pontos turísticos do estado: ");
    scanf("%d", &pontosTuristicos2);

    // Calculando o PIB per capita e a densidade
    pibPerCapita = pib / populacao;
    pibPerCapita2 = pib2 / populacao2;
    densidade = populacao / area;
    densidade2 = populacao2 / area2;

    // Escolha do 1º atributo
    printf("\nEscolha o atributo para comparar:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos turísticos\n");
    printf("5. Densidade populacional\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1: somaCarta1 += populacao; somaCarta2 += populacao2; break;
        case 2: somaCarta1 += area; somaCarta2 += area2; break;
        case 3: somaCarta1 += pib; somaCarta2 += pib2; break;
        case 4: somaCarta1 += pontosTuristicos; somaCarta2 += pontosTuristicos2; break;
        case 5: somaCarta1 += (1/densidade); somaCarta2 += (1/densidade2); break; 
        default: printf("Opção inválida!\n"); break;
    }

    // Escolha do 2º atributo
    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos turísticos\n");
    printf("5. Densidade populacional\n");
    scanf("%d", &opcao2);

    if (opcao2 == opcao) {
        printf("Opção inválida: não pode repetir o atributo!\n");
    } else {
        switch (opcao2) {
            case 1: somaCarta1 += populacao; somaCarta2 += populacao2; break;
            case 2: somaCarta1 += area; somaCarta2 += area2; break;
            case 3: somaCarta1 += pib; somaCarta2 += pib2; break;
            case 4: somaCarta1 += pontosTuristicos; somaCarta2 += pontosTuristicos2; break;
            case 5: somaCarta1 += (1/densidade); somaCarta2 += (1/densidade2); break;
            default: printf("Opção inválida!\n"); break;
        }
    }

    // Resultado final
    printf("\nSoma dos atributos escolhidos:\n");
    printf("Carta 1: %.2f\n", somaCarta1);
    printf("Carta 2: %.2f\n", somaCarta2);

    if (somaCarta1 > somaCarta2) {
        printf("A primeira carta é a vencedora!\n");
    } else if (somaCarta2 > somaCarta1) {
        printf("A segunda carta é a vencedora!\n");
    } else {
        printf("Empate!\n");
    }

    return 0;
}
