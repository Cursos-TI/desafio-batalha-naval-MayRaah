#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int i, j;

    // 1. Inicializa o tabuleiro com 0 (aguá)
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ---- COORDENADAS DOS NAVIOS ----
    // Navio horizontal
    int linha_h = 2, coluna_h = 4;
    // Navio vertical
    int linha_v = 5, coluna_v = 7;
    // Navio diagonal descendente (ex: tabuleiro[i][j])
    int linha_d1 = 0, coluna_d1 = 0;
    // Navio diagonal ascendente (ex: tabuleiro[i][j])
    int linha_d2 = 7, coluna_d2 = 2;
    
    int sobreposicao = 0;

    // 2. Validação dos limites dos navios
    if (coluna_h + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio horizontal não cabe no tabuleiro!\n");
        return 1;
    }

    if (linha_v + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio vertical não cabe no tabuleiro!\n");
        return 1;
    }

    if (linha_d1 + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna_d1 + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio diagonal descendente não cabe no tabuleiro!\n");
        return 1;
    }

    if (linha_d2 + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna_d2 + (TAMANHO_NAVIO - 1) < 0) {
        printf("Erro: Navio diagonal ascendente não cabe no tabuleiro!\n");
        return 1;
    }

    // 3. Verificar sobreposição ANTES de posicionar 
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        // verificar horizontal
        if (tabuleiro[linha_h][coluna_h + 1] == 3) sobreposicao = 1;
        // verificar vertical
        if (tabuleiro[linha_v + i][coluna_v] == 3) sobreposicao = 1;
        // verificar diagonal descendente
        if (tabuleiro[linha_d1 + i][coluna_d1 + i] == 3) sobreposicao = 1;
        // verificar diagonal ascendente
        if (tabuleiro[linha_d2 + i][coluna_d2 - i] == 3) sobreposicao = 1;
    }

    if (sobreposicao) {
        printf("Erro: Há sobreposição entre os navios!\n");
        return 1;
    }

    // 4. Posicionar navio horizontal
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_h][coluna_h + i] = 3;
    }

    // 5. Posicionar navio vertical
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_v][coluna_v + i] = 3;
    }

    // 6. Posicionar navio diagonal descendente
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_d1 + i][coluna_d1 + i] = 3;
    }

    // 7. Posicionar navio diagonal ascendente
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_d2 + i][coluna_d2 - i] = 3;
    }

    // 8. Exibir tabuleiro
    printf("\nTabuleiro:\n");
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}