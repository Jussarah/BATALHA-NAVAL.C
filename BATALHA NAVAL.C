#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }

    // Coordenadas dos navios
    int linhaHorizontal = 2;
    int colunaHorizontal = 4;

    int linhaVertical = 5;
    int colunaVertical = 7;

    // Valida e posiciona navio horizontal
    if (colunaHorizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaHorizontal][colunaHorizontal + i] = VALOR_NAVIO;
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites.\n");
        return 1;
    }

    // Valida e posiciona navio vertical com verificação de sobreposição
    if (linhaVertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaVertical + i][colunaVertical] == VALOR_NAVIO) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaVertical + i][colunaVertical] = VALOR_NAVIO;
            }
        } else {
            printf("Erro: Sobreposição de navios.\n");
            return 1;
        }
    } else {
        printf("Erro: Navio vertical fora dos limites.\n");
        return 1;
    }

    // Exibe o tabuleiro com cores
    printf("\n   A B C D E F G H I J\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == VALOR_AGUA) {
                printf("\033[34m0\033[0m "); // Azul
            } else if (tabuleiro[i][j] == VALOR_NAVIO) {
                printf("\033[31m3\033[0m "); // Vermelho
            } else {
                printf("%d ", tabuleiro[i][j]); // Outros valores (caso existam)
            }
        }
        printf("\n");
    }

    return 0;
}
