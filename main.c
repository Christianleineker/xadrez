#include <stdio.h>
#include "xadrez.h"
#include "arvore.h"

void mostrarRegras() {
    printf("\n===== Regras do Jogo (Versão Simplificada) =====\n");
    printf("- As peças seguem seus movimentos tradicionais do xadrez.\n");
    printf("- As peças do jogador são letras minúsculas. Ex: 'p', 'k'\n");
    printf("- As peças do computador são maiúsculas. Ex: 'P', 'K'\n");
    printf("- Jogadas são feitas no formato: e2e4 (sem espaço)\n");
    printf("- O jogo termina quando um rei é capturado.\n");
    printf("==================================================\n\n");
}

int main() {
    char tabuleiro[8][8];
    iniciarTabuleiro(tabuleiro);

    No* raiz = criarNo(tabuleiro, 0);

    int opcao;
    do {
        printf("===== MENU =====\n");
        printf("1 - Imprimir tabuleiro\n");
        printf("2 - Operações com árvore de jogadas\n");
        printf("3 - Jogar contra computador (modo simples)\n");
        printf("4 - Regras do jogo\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                imprimirTabuleiro(tabuleiro);
                break;
            case 2:
                operacoesArvore(raiz);
                break;
            case 3:
                jogarContraComputador(tabuleiro);
                break;
            case 4:
                mostrarRegras();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    liberarArvore(raiz);
    return 0;
}