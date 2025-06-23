#ifndef ARVORE_H
#define ARVORE_H

typedef struct No {
    int id;
    char estado[8][8];
    struct No* esquerda;
    struct No* direita;
} No;

No* criarNo(char estado[8][8], int id);
void liberarArvore(No* raiz);
void imprimirArvore(No* raiz, int nivel);
void operacoesArvore(No* raiz);

#endif