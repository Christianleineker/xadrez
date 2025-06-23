#include <stdio.h>
#include "xadrez.h"

void iniciarTabuleiro(char tab[8][8]) {
    for (int i = 2; i < 6; i++)
        for (int j = 0; j < 8; j++)
            tab[i][j] = ' ';

    char linha1Pretas[] = {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'};
    for (int i = 0; i < 8; i++) {
        tab[0][i] = linha1Pretas[i];
        tab[1][i] = 'P';
    }

    char linha1Brancas[] = {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'};
    for (int i = 0; i < 8; i++) {
        tab[7][i] = linha1Brancas[i];
        tab[6][i] = 'p';
    }
}

void imprimirTabuleiro(char tab[8][8]) {
    printf("\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < 8; j++) {
            printf("|%c", tab[i][j]);
        }
        printf("|\n");
    }
    printf("   a b c d e f g h\n\n");
}

int verificarRei(char tab[8][8], char rei) {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (tab[i][j] == rei)
                return 1;
    return 0;
}

void jogadaComputador(char tab[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (tab[i][j] == 'P') {
                if (i+1 < 8 && j-1 >= 0 && tab[i+1][j-1] >= 'a' && tab[i+1][j-1] <= 'z') {
                    tab[i+1][j-1] = 'P';
                    tab[i][j] = ' ';
                    return;
                }
                if (i+1 < 8 && j+1 < 8 && tab[i+1][j+1] >= 'a' && tab[i+1][j+1] <= 'z') {
                    tab[i+1][j+1] = 'P';
                    tab[i][j] = ' ';
                    return;
                }
            }
        }
    }

    for (int i = 1; i < 7; i++) {
        for (int j = 0; j < 8; j++) {
            if (tab[i][j] == 'P' && tab[i+1][j] == ' ') {
                tab[i+1][j] = 'P';
                tab[i][j] = ' ';
                return;
            }
        }
    }
}

void jogarContraComputador(char tab[8][8]) {
    char move[10];
    while (1) {
        imprimirTabuleiro(tab);

        if (!verificarRei(tab, 'K')) {
            printf("Você venceu! Rei inimigo capturado.\n");
            break;
        }
        if (!verificarRei(tab, 'k')) {
            printf("Xeque-mate! O computador venceu.\n");
            break;
        }

        printf("Sua jogada (ex: e2e3, ou 'sair'): ");
        scanf("%s", move);
        if (move[0] == 's') break;

        int i1 = 8 - (move[1] - '0');
        int j1 = move[0] - 'a';
        int i2 = 8 - (move[3] - '0');
        int j2 = move[2] - 'a';

        if (i1 < 0 || i1 >= 8 || j1 < 0 || j1 >= 8 || i2 < 0 || i2 >= 8 || j2 < 0 || j2 >= 8) {
            printf("Movimento fora dos limites!\n");
            continue;
        }

        if (tab[i1][j1] >= 'a' && tab[i1][j1] <= 'z') {
            tab[i2][j2] = tab[i1][j1];
            tab[i1][j1] = ' ';
        } else {
            printf("Movimento inválido! Escolha uma peça sua.\n");
            continue;
        }

        if (!verificarRei(tab, 'K')) {
            imprimirTabuleiro(tab);
            printf("Você venceu! Rei inimigo capturado.\n");
            break;
        }

        jogadaComputador(tab);

        if (!verificarRei(tab, 'k')) {
            imprimirTabuleiro(tab);
            printf("Xeque-mate! O computador venceu.\n");
            break;
        }
    }
}