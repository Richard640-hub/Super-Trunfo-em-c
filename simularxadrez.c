#include <stdio.h>

#define TAM 8

// Função para mostrar a posição
void imprimirPosicao(int linha, int coluna) {
    printf("(%d, %d)\n", linha, coluna);
}

/* ================================
   TORRE - usando FOR
   Move horizontal e vertical
================================ */
void moverTorre(int linha, int coluna) {
    printf("\nMovimentos da Torre:\n");

    // Movimento horizontal →
    for (int c = coluna + 1; c < TAM; c++) {
        imprimirPosicao(linha, c);
    }

    // Movimento horizontal ←
    for (int c = coluna - 1; c >= 0; c--) {
        imprimirPosicao(linha, c);
    }

    // Movimento vertical ↓
    for (int l = linha + 1; l < TAM; l++) {
        imprimirPosicao(l, coluna);
    }

    // Movimento vertical ↑
    for (int l = linha - 1; l >= 0; l--) {
        imprimirPosicao(l, coluna);
    }
}


/* ================================
   BISPO - usando WHILE
   Move nas diagonais
================================ */
void moverBispo(int linha, int coluna) {
    printf("\nMovimentos do Bispo:\n");

    int l, c;

    // Diagonal ↘
    l = linha + 1;
    c = coluna + 1;
    while (l < TAM && c < TAM) {
        imprimirPosicao(l, c);
        l++;
        c++;
    }

    // Diagonal ↖
    l = linha - 1;
    c = coluna - 1;
    while (l >= 0 && c >= 0) {
        imprimirPosicao(l, c);
        l--;
        c--;
    }
}


/* ================================
   RAINHA - usando DO-WHILE
   Combina Torre + Bispo
================================ */
void moverRainha(int linha, int coluna) {
    printf("\nMovimentos da Rainha:\n");

    int l = linha;
    int c = coluna;

    // Movimento horizontal →
    do {
        c++;
        if (c < TAM)
            imprimirPosicao(l, c);
    } while (c < TAM);

}


/* ================================
   CAVALO - loops aninhados
   Movimento em L
================================ */
void moverCavalo(int linha, int coluna) {
    printf("\nMovimentos do Cavalo:\n");

    int movimentos[8][2] = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };

    for (int i = 0; i < 8; i++) {
        int novaLinha = linha + movimentos[i][0];
        int novaColuna = coluna + movimentos[i][1];

        if (novaLinha >= 0 && novaLinha < TAM &&
            novaColuna >= 0 && novaColuna < TAM) {

            imprimirPosicao(novaLinha, novaColuna);
        }
    }
}


/* ================================
   RECURSIVIDADE
   Movimento avançado da Torre
================================ */
void moverTorreRecursivo(int linha, int coluna, int direcao) {

    if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM)
        return;

    imprimirPosicao(linha, coluna);

    if (direcao == 0) // direita
        moverTorreRecursivo(linha, coluna + 1, direcao);
    else if (direcao == 1) // esquerda
        moverTorreRecursivo(linha, coluna - 1, direcao);
}


/* ================================
   MAIN
================================ */
int main() {

    int linha = 3;
    int coluna = 3;

    printf("Peça posicionada em (%d, %d)\n", linha, coluna);

    moverTorre(linha, coluna);
    moverBispo(linha, coluna);
    moverRainha(linha, coluna);
    moverCavalo(linha, coluna);

    printf("\nMovimento Recursivo da Torre (direita):\n");
    moverTorreRecursivo(linha, coluna + 1, 0);

    return 0;
}