# Jogo da Velha em C

![C](https://img.shields.io/badge/Linguagem-C-00599C) ![License](https://img.shields.io/badge/License-MIT-green)

## Descrição do Projeto
Este projeto é um **jogo da velha (tic-tac-toe) em C**, que permite partidas entre **jogador e computador**. O jogo possui:

- **Tabuleiro completo**: visualização do estado do jogo no terminal.  
- **Jogadas entre jogador e computador** com IA básica.  
- **Verificação de vitória e empate** após cada jogada.  
- **Sistema de árvore de jogadas** para simular decisões da IA.  

O projeto foi desenvolvido para estudo de lógica de programação, estruturas de dados e conceitos de IA básica.

---

## Funcionalidades

- Jogador humano pode escolher a posição para jogar.  
- Computador realiza jogadas automáticas com estratégia simples.  
- Verificação de vitória, derrota ou empate após cada jogada.  
- Sistema de árvore de jogadas para decisão do computador.  
- Código modularizado usando arquivos `.c` e `.h`.

---

## Estrutura do Projeto

- `main.c` - Ponto de entrada do programa, controla o fluxo do jogo.  
- `xadrez.c` / `xadrez.h` - Lógica principal do jogo (tabuleiro, verificação de vitória, jogadas da IA).  
- `arvore.c` / `arvore.h` - Estrutura de árvore para simular jogadas futuras.  

---

## Como Compilar e Executar

### Pré-requisitos
- [GCC](https://gcc.gnu.org/) ou outro compilador C instalado.

### Passos
1. Abra o terminal na pasta do projeto.  
2. Compile os arquivos `.c`:

```bash
gcc main.c xadrez.c arvore.c -o jogo
```

Execute o programa:

```bash
./jogo   # Linux/Mac
jogo.exe # Windows
```

## Autor

Christian Henrique Leineker

- GitHub: [Christianleineker](https://github.com/Christianleineker)  
- LinkedIn: [Christian Henrique Leineker](https://www.linkedin.com/in/christian-leineker/)
