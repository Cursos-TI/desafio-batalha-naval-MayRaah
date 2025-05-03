#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int i, j;

    // 1. Inicializa o tabuleiro com 0 (água)
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Define as coordenadas iniciais dos navios
    int linha_h = 2; // linha inicial do navio horizontal
    int coluna_h = 4; // coluna inicial do navio horizontal

    int linha_v = 5; // linha inicial do navio vertical
    int coluna_v = 7; // coluna inicial do navio vertical

    // 3. Validação: verificar se o navio horizontal cabe no tabuleiro
    if (coluna_h + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio horizontal não cabe no tabuleiro!\n");
        return 1; // encerra o programa
    }

    // 4. Validação: verificar se o navio vertical cabe no tabuleiro
    if (linha_v + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio vertical não cabe no tabuleiro!\n");
        return 1; // encerra o programa
    }

    // 5. Verificar se há sobreposição antes de posicionar
    int sobreposicao = 0;
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha_h][coluna_h + i] == 3) {
            sobreposicao = 1;
            break;
        }
        if (tabuleiro[linha_v + i][coluna_v] == 3) {
            sobreposicao = 1;
            break;
        }
    }

    // Verificar interseção específica entre os dois navios
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        for (j = 0; j < TAMANHO_NAVIO; j++) {
            if (linha_h == linha_v + i && coluna_h + j == coluna_v) {
                sobreposicao = 1;
            }
        }
    }

    if (sobreposicao) {
        printf("Erro: Os navios se sobrepõem!\n");
        return 1; // encerra o programa
    }

    // 6. Posiciona o navio horizontal (marca com 3)
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_h][coluna_h + i] = 3;
    }

    // 7. Posiciona o navio vertical (marca com 3)
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_v + i][coluna_v] = 3;
    }

    // 8. Exibe o tabuleiro
    printf("\nTabuleiro:\n");
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}