#include <stdio.h>
#include <stdlib.h> 

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5

// Função para inicializar o tabuleiro com 0
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0) printf(". ");
            else if (tabuleiro[i][j] == 3) printf("N ");
            else if (tabuleiro[i][j] == 5) printf("* ");
        }
        printf("\n");
    }
}

void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int origemLinha, int origemColuna){
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int posLinha = origemLinha + i - TAMANHO_HABILIDADE / 2;
            int posColuna = origemColuna + j - TAMANHO_HABILIDADE / 2;
            if (posLinha >= 0 && posLinha < TAMANHO_TABULEIRO && posColuna >= 0 && posColuna < TAMANHO_TABULEIRO) {
                if (habilidade[i][j] == 1 && tabuleiro[posLinha][posColuna] == 0)
                    tabuleiro[posLinha][posColuna] = 5;
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais dos navios
    int linha_h = 2, coluna_h = 2; // horizontal
    int linha_v = 5, coluna_v = 4; // vertical
    int linha_d1 = 1, coluna_d1 = 1; // diagonal descendo
    int linha_d2 = 6, coluna_d2 = 2; // diagonal subindo (ajustada)

    int i;

    // Posiciona navio horizontal
    if (coluna_h + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (i = 0; i < TAMANHO_NAVIO; i++)
            tabuleiro[linha_h][coluna_h + i] = 3;
    } else {
        printf("Erro: navio horizontal ultrapassa os limites do tabuleiro!\n");
    }

    // Posiciona navio vertical
    if (linha_v + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (i = 0; i < TAMANHO_NAVIO; i++)
            tabuleiro[linha_v + i][coluna_v] = 3;
    } else {
        printf("Erro: navio vertical ultrapassa os limites do tabuleiro!\n");
    }

    // Posiciona navio diagonal descendo
    if (linha_d1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && coluna_d1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (i = 0; i < TAMANHO_NAVIO; i++)
            tabuleiro[linha_d1 + i][coluna_d1 + i] = 3;
    } else {
        printf("Erro: navio diagonal descendo ultrapassa os limites do tabuleiro!\n");
    }

    // Posiciona navio diagonal subindo
    if (linha_d2 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && coluna_d2 - (TAMANHO_NAVIO - 1) >= 0) {
        for (i = 0; i < TAMANHO_NAVIO; i++)
            tabuleiro[linha_d2 + i][coluna_d2 - i] = 3;
    } else {
        printf("Erro: navio diagonal subindo ultrapassa os limites do tabuleiro!\n");
    }

    // Definindo matriz de habilidade cone
    int habilidadeCone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidadeCone[i][j] = (j >= TAMANHO_HABILIDADE/2 - i && j <= TAMANHO_HABILIDADE/2 + i) ? 1 : 0;
        }
    }

    // Definindo matriz de habilidade cruz
    int habilidadeCruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidadeCruz[i][j] = (i == TAMANHO_HABILIDADE/2 || j == TAMANHO_HABILIDADE/2) ? 1 : 0;
        }
    }

    // Definindo matriz de habilidade octaedro
    int habilidadeOctaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidadeOctaedro[i][j] = (abs(i - TAMANHO_HABILIDADE/2) + abs(j - TAMANHO_HABILIDADE/2) <= TAMANHO_HABILIDADE/2) ? 1 : 0;
        }
    }

    // Definir ponto de origem das habilidades no tabuleiro
    int origemConeLinha = 0, origemConeColuna = 5;
    int origemCruzLinha = 5, origemCruzColuna = 5;
    int origemOctaedroLinha = 8, origemOctaedroColuna = 8;

    // Aplicar habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, habilidadeCone, origemConeLinha, origemConeColuna);
    aplicarHabilidade(tabuleiro, habilidadeCruz, origemCruzLinha, origemCruzColuna);
    aplicarHabilidade(tabuleiro, habilidadeOctaedro, origemOctaedroLinha, origemOctaedroColuna);

    // Exibir tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}