#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define CIPHER      1
#define DECIPHER    2

// Função que aplica o ROT13 em um caractere
char rot13(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        // Calcula o deslocamento apropriado para o ROT13
        char base = (c >= 'a' && c <= 'z') ? 'a' : 'A';
        return (c - base + 13) % 26 + base;
    }
    return c;
}

// Função que lê um arquivo, aplica o ROT13 e escreve o resultado em outro arquivo
void cipher_file(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w+");

    // Verifica se os arquivos foram abertos corretamente
    if (input_file == NULL || output_file == NULL) {
        perror("Erro ao abrir os arquivos");
        exit(EXIT_FAILURE);
    }

    int c;
    // Lê cada caractere do arquivo de entrada
    while ((c = fgetc(input_file)) != EOF) {
        // Aplica o ROT13 no caractere e escreve no arquivo de saída
        char encrypted_char = rot13((char)c);
        fputc(encrypted_char, output_file);
    }

    // Fecha os arquivos
    fclose(input_file);
    fclose(output_file);
}

int get_operation() {
    int choice = 0;
    char input[256];

    while (true) {
        printf("Qual operação você deseja realizar?\n"
               "1. Encriptar\n"
               "2. Desencriptar\n");

        // Lê a entrada padrão usando fgets para lidar corretamente com quebras de linhas
        if (fgets(input, sizeof(input), stdin) == NULL) {
            perror("Erro ao ler a entrada");
            exit(EXIT_FAILURE);
        }

        // Use sscanf para extrair o número escolhido da entrada padrão
        if (sscanf(input, "%d", &choice) == 1) {
            if (choice >= CIPHER && choice <= DECIPHER) {
                break;  // Sai do loop se o input for válido
            } else {
                printf("Opção inválida. Por favor, escolha 1 ou 2.\n");
            }
        } else {
            printf("Entrada inválida. Por favor, digite um número.\n");
        }
    }

    return choice;
}

int main(void) {
    char input_filename[256];
    char output_filename[256];
    time_t current_time;
    
    if (get_operation() == CIPHER) {
        printf("Digite o nome do arquivo que deseja encriptar: ");
        scanf("%255s", input_filename);

        time(&current_time);
        sprintf(output_filename, "encriptado-%s-%d", input_filename, (int)current_time);

        // Encripta o arquivo
        printf("Encriptando arquivo...\n");
        cipher_file(input_filename, output_filename);
        printf("Arquivo encriptado com sucesso!\n");
    } else {
        printf("Digite o nome do arquivo que deseja Desencriptar: ");
        scanf("%255s", input_filename);

        time(&current_time);
        sprintf(output_filename, "desencriptado-%s-%d", input_filename, (int)current_time);
        // Desencripta o arquivo
        printf("Desencriptando arquivo...\n");
        cipher_file(input_filename, output_filename);
        printf("Arquivo desencriptado com sucesso!\n");
    }

    return 0;
}
