#include <stdio.h>

char board[3][3];

// Inicializa o tabuleiro com espaços vazios
void initBoard() {
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            board[i][j] = ' ';
}

// Mostra o tabuleiro na tela
void printBoard() {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n\n", board[2][0], board[2][1], board[2][2]);
}

// Verifica se o jogador venceu
int checkWin(char player) {
    // Linhas
    for (int i=0; i<3; i++) {
        if (board[i][0]==player && board[i][1]==player && board[i][2]==player)
            return 1;
    }
    // Colunas
    for (int j=0; j<3; j++) {
        if (board[0][j]==player && board[1][j]==player && board[2][j]==player)
            return 1;
    }
    // Diagonais
    if (board[0][0]==player && board[1][1]==player && board[2][2]==player)
        return 1;
    if (board[0][2]==player && board[1][1]==player && board[2][0]==player)
        return 1;

    return 0;
}

// Verifica se o tabuleiro está cheio (empate)
int isBoardFull() {
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            if (board[i][j] == ' ')
                return 0;
    return 1;
}

// Lê jogada do jogador (linha e coluna)
void playerMove(char player) {
    int row, col;
    while (1) {
        printf("Jogador %c, entre a linha (1-3) e coluna (1-3): ", player);
        scanf("%d %d", &row, &col);
        // Ajusta índice para 0-2
        row--;
        col--;
        // Verifica validade
        if (row >=0 && row <3 && col >=0 && col <3) {
            if (board[row][col] == ' ') {
                board[row][col] = player;
                break;
            } else {
                printf("Posição já ocupada! Tente novamente.\n");
            }
        } else {
            printf("Posição inválida! Tente novamente.\n");
        }
    }
}

int main() {
    initBoard();

    char currentPlayer = 'X';

    while (1) {
        printBoard();
        playerMove(currentPlayer);

        if (checkWin(currentPlayer)) {
            printBoard();
            printf("Jogador %c venceu! Parabéns!\n", currentPlayer);
            break;
        }

        if (isBoardFull()) {
            printBoard();
            printf("Empate! Ninguém venceu.\n");
            break;
        }

        // Troca jogador
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
