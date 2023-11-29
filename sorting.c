#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

/*	Exemplo de saída com arrays de tamanho 10:
    
    lcn@B450:~$ ./a.out
    Insertion Sort:
    [27, 69, 58, 54, 43, 32, 46, 66, 1, 46]
    [1, 27, 32, 43, 46, 46, 54, 58, 66, 69]
    Selection Sort:
    [27, 69, 58, 54, 43, 32, 46, 66, 1, 46]
    [1, 27, 32, 43, 46, 46, 54, 58, 66, 69]
    Bubble Sort:
    [27, 69, 58, 54, 43, 32, 46, 66, 1, 46]
    [1, 27, 32, 43, 46, 46, 54, 58, 66, 69]
    */

#define TAM 1000

// Função para inicializar um array com números aleatórios entre 0 e 99
void initialize_array(int *arr, int size) {
    srand(69420);
    for(int i = 0; i < size; ++i) {
        arr[i] = rand() % 100;
    }

    return;
}

// Função para imprimir um array
void print_array(int *arr, int size) {
    printf("[");
    for(int i = 0; i < size; ++i) {
        printf("%d%s", arr[i], i == size-1 ? "" : ", ");
    }
    printf("]\n");
    return;
}

// Função para trocar dois elementos de posição em um array
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Implementação do algoritmo de ordenação Insertion Sort
void insertion_sort(int *arr, int size) {
    int i = 1;

    while (i < size) {
        int j = i;

        // Desloca os elementos maiores para a direita
        while(j > 0 && arr[j-1] > arr[j]) {
            swap(&arr[j], &arr[j-1]);
            --j;
        }
        ++i;
    }

    return;
}

// Implementação do algoritmo de ordenação Selection Sort
void selection_sort(int *arr, int size) {
    int index_for_swap = 0; // variável que guarda a posição do array em que o elemento será substituído pelo menor elemento encontrado

    while(index_for_swap < size) {
        int current_min_value = INT_MAX; // INT_MAX = 2147483647   (para inteiros de 32 bits)
        int current_min_index = index_for_swap;
        
        // Encontra o menor elemento no restante do array
        for(int i = index_for_swap; i < size; ++i) {
            if(arr[i] < current_min_value) {
                current_min_value = arr[i];
                current_min_index = i;
            }
        }

        // Troca o elemento atual pelo menor encontrado
        swap(&arr[index_for_swap], &arr[current_min_index]);
        index_for_swap += 1;
    }

    return;
}

// Implementação do algoritmo de ordenação Bubble Sort
void bubble_sort(int *arr, int size) {
    bool should_continue = false;

    // Executa o loop até que nenhum swap seja mais necessário
    do {
        should_continue = false;

        // Percorre o array comparando elementos adjacentes e realizando swaps se necessário
        for(int i = 0; i < size-1; ++i) {
            if(arr[i] > arr[i+1]) {
                swap(&arr[i], &arr[i+1]);
                should_continue = true;
            }
        }
    } while(should_continue);

    return;
}

int main(void) {
    int arr[TAM];

    // Demonstração do Insertion Sort
    printf("Insertion Sort:\n");
    initialize_array(arr, TAM);
    print_array(arr, TAM);
    insertion_sort(arr, TAM);
    print_array(arr, TAM);

    // Demonstração do Selection Sort
    printf("Selection Sort:\n");
    initialize_array(arr, TAM);
    print_array(arr, TAM);
    selection_sort(arr, TAM);
    print_array(arr, TAM);

    // Demonstração do Bubble Sort
    printf("Bubble Sort:\n");
    initialize_array(arr, TAM);
    print_array(arr, TAM);
    bubble_sort(arr, TAM);
    print_array(arr, TAM);
 
    return 0;
}
