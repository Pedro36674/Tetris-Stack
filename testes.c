#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAMANHO 10

void gerarListaOrdenada(int lista[], int n);
void gerarListaInversa(int lista[], int n);
void gerarListaAleatoria(int lista[], int n);

void bubbleSort(int lista[], int n);
void selectionSort(int lista[], int n);
void insertionSort(int lista[], int n);

void imprimirLista(const char *titulo, int lista[], int n);
void copiarLista(int destino[], const int origem[], int n);

int main(){
    srand(time(NULL));

    int listaOrdenada[TAMANHO];
    int listaInversa[TAMANHO];
    int listaAleatoria[TAMANHO];

    printf("---- Gerando listas de entrada ----\n");
    gerarListaOrdenada(listaOrdenada, TAMANHO);
    gerarListaInversa(listaInversa, TAMANHO);
    gerarListaAleatoria(listaAleatoria, TAMANHO);
    printf("--------------------------------------\n");

    int listaTemp[TAMANHO];

    printf("---- Testando Bubble Sort ----\n");
    // Teste com lista ordenada (melhor caso)
    copiarLista(listaTemp, listaOrdenada, TAMANHO);
    bubbleSort(listaTemp, TAMANHO);
    imprimirLista("Bubble Sort - Lista Ordenada", listaTemp, TAMANHO);
    printf("\n");
    printf("----------------------------------\n");
    // Teste com lista inversa (pior caso)
    copiarLista(listaTemp, listaInversa, TAMANHO);
    bubbleSort(listaTemp, TAMANHO);
    imprimirLista("Bubble Sort - Lista Inversa", listaTemp, TAMANHO);
    printf("\n");
    printf("----------------------------------\n");
    // Teste com lista aleatória (caso médio)
    copiarLista(listaTemp, listaAleatoria, TAMANHO);
    bubbleSort(listaTemp, TAMANHO);
    imprimirLista("Bubble Sort - Lista Aleatória", listaTemp, TAMANHO);
    printf("\n");
    printf("----------------------------------\n");


    printf("---- Testando Selection Sort ----\n");
    // Teste com lista ordenada (melhor caso)
    copiarLista(listaTemp, listaOrdenada, TAMANHO);
    selectionSort(listaTemp, TAMANHO);
    imprimirLista("Selection Sort - Lista Ordenada", listaTemp, TAMANHO);
    printf("\n");
    printf("----------------------------------\n");
    // Teste com lista inversa (pior caso)
    copiarLista(listaTemp, listaInversa, TAMANHO);
    selectionSort(listaTemp, TAMANHO);
    imprimirLista("Selection Sort - Lista Inversa", listaTemp, TAMANHO);
    printf("\n");
    printf("----------------------------------\n");
    // Teste com lista aleatória (caso médio)
    copiarLista(listaTemp, listaAleatoria, TAMANHO);
    selectionSort(listaTemp, TAMANHO);
    imprimirLista("Selection Sort - Lista Aleatória", listaTemp, TAMANHO);
    printf("\n");
    printf("----------------------------------\n");


    printf("---- Testando Insertion Sort ----\n");
    // Teste com lista ordenada (melhor caso)
    copiarLista(listaTemp, listaOrdenada, TAMANHO);
    insertionSort(listaTemp, TAMANHO);
    imprimirLista("Insertion Sort - Lista Ordenada", listaTemp, TAMANHO);
    printf("\n");
    printf("----------------------------------\n");
    // Teste com lista inversa (pior caso)
    copiarLista(listaTemp, listaInversa, TAMANHO);
    insertionSort(listaTemp, TAMANHO);
    imprimirLista("Insertion Sort - Lista Inversa", listaTemp, TAMANHO);
    printf("\n");
    printf("----------------------------------\n");
    // Teste com lista aleatória (caso médio)
    copiarLista(listaTemp, listaAleatoria, TAMANHO);
    insertionSort(listaTemp, TAMANHO);
    imprimirLista("Insertion Sort - Lista Aleatória", listaTemp, TAMANHO);
    printf("\n");
    printf("----------------------------------\n");

    return 0; // Fim do programa
}

void bubbleSort(int lista[], int n) {
    int i, j, temp;
    int trocou;

    for (i = 0; i < n - 1; i++) {
        trocou = 0;
        
        for (j = 0; j < n - i - 1; j++) {
        // Se o elemento atual for maior que o próximo...
            if (lista[j] > lista[j + 1]) {
                // Troca os elementos
                temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
                trocou = 1; // Indica que houve troca nesta passagem
            }
        }
        if (!trocou) {
            break; // A lista já está ordenada
        }
    }
}

void insertionSort(int lista[], int n) {
    int i, key, j;

    for (i = 1; i < n; i++) {
        key = lista[i];
        j = i - 1;

        // Move os elementos de lista[0..i-1], que são maiores que key,
        // para uma posição à frente de sua posição atual
        while (j >= 0 && lista[j] > key) {
            lista[j + 1] = lista[j];
            j = j - 1;
        }
        lista[j + 1] = key;
    }
}

void selectionSort(int lista[], int n) {
    int i, j, min_idx, temp;

    for (i = 0; i < n - 1; i++) {
        min_idx = i; // Encontra o menor elemento no array não ordenado

        for (j = i + 1; j < n; j++) {
            if (lista[j] < lista[min_idx]) {
                min_idx = j; // Atualiza o índice do menor elemento
            }
        }
        // Troca o menor elemento encontrado com o primeiro elemento
        if (min_idx != i) {
            temp = lista[i];
            lista[i] = lista[min_idx];
            lista[min_idx] = temp;
        }
    }
}

void gerarListaOrdenada(int lista[], int n) {
    for (int i = 0; i < n; i++) {
        lista[i] = i + 1; // Lista ordenada de 1 a n
    }
    imprimirLista("Original - Lista Ordenada", lista, n);
}

void gerarListaInversa(int lista[], int n) {
    for (int i = 0; i < n; i++) {
        lista[i] = n - i; // Lista inversa de n a 1
    }
    imprimirLista("Original - Lista Inversa", lista, n);
}

void gerarListaAleatoria(int lista[], int n) {
    for (int i = 0; i < n; i++) {
        lista[i] = rand() % 100 + 1; // Números aleatórios entre 1 e 100
    }
    imprimirLista("Original - Lista Aleatória", lista, n);
}

void imprimirLista(const char *titulo, int lista[], int n) {
    printf("%s:\n", titulo);
    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

void copiarLista(int destino[], const int origem[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}