#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

No* criarNo(char estado[8][8], int id) {
    No* novo = (No*)malloc(sizeof(No));
    memcpy(novo->estado, estado, sizeof(char) * 8 * 8);
    novo->id = id;
    novo->esquerda = novo->direita = NULL;
    return novo;
}

void liberarArvore(No* raiz) {
    if (raiz) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

void imprimirArvore(No* raiz, int nivel) {
    if (raiz == NULL) return;
    for (int i = 0; i < nivel; i++) printf("  ");
    printf("No %d\n", raiz->id);
    imprimirArvore(raiz->esquerda, nivel + 1);
    imprimirArvore(raiz->direita, nivel + 1);
}

void operacoesArvore(No* raiz) {
    int opcao;
    do {
        printf("\n== Árvore de Jogadas ==\n");
        printf("1 - Imprimir árvore\n");
        printf("2 - Inserir jogada à esquerda\n");
        printf("3 - Inserir jogada à direita\n");
        printf("0 - Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                imprimirArvore(raiz, 0);
                break;
            case 2:
                if (raiz->esquerda == NULL)
                    raiz->esquerda = criarNo(raiz->estado, raiz->id * 2 + 1);
                printf("Jogada inserida à esquerda.\n");
                break;
            case 3:
                if (raiz->direita == NULL)
                    raiz->direita = criarNo(raiz->estado, raiz->id * 2 + 2);
                printf("Jogada inserida à direita.\n");
                break;
            case 0:
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);
}