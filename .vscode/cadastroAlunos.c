#include <stdio.h>

int main() {
    int idade, matricula;
    float altura;
    char nome[50];

    printf("Digite sua idade: \n");
    scanf("%i", &idade);

    printf("Digite sua matrícula: \n");
    scanf("%i", &matricula);

    printf("Digite sua altura: \n");
    scanf("%f", &altura);

    printf("Digite seu nome: \n");
    scanf("%s", nome);


    printf("Nome do aluno: %s - Matricula: %i\n", nome, matricula);
    printf("Idade do aluno: %i - Altura: %.2f\n", idade, altura);

    return 0;
}