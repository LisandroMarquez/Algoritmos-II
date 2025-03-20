#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h> /* assert() */

#define N 3

#define CELL_MAX (N * N - 1)

void print_sep(int length)
{
    printf("\t ");
    for (int i = 0; i < length; i++)
        printf("................");
    printf("\n");
}

void print_board(char board[N][N])
{
    int cell = 0;

    print_sep(N);
    for (int row = 0; row < N; ++row)
    {
        for (int column = 0; column < N; ++column)
        {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(N);
    }
}

int cell_value(char cell) {
    int value;

    switch (cell) {
    case 'X':
        value = 1;
        break;
    case 'O':
        value = -1;
        break;
    default:
        value = 0;
        break;
    }
    return value;
}

char get_winner(char board[N][N])
{
    char winner = '-';
    int row_count, col_count, diag1_count = 0, diag2_count = 0, i = 0;

    while (i < N || row_count == N || col_count == N || row_count == -N || col_count == -N) { //+ i es fila, j es columna
        row_count = 0;
        col_count = 0;

        for (int j = 0; j < N; j++) {
            row_count += cell_value(board[i][j]);
            col_count += cell_value(board[j][i]);
        }
        diag1_count += cell_value(board[i][i]);
        diag2_count += cell_value(board[N-1-i][i]);

        //# Finish if tic tac toe
        if (row_count == N || col_count == N) winner = 'X';
        if (row_count == -N || col_count == -N) winner = 'O';

        i++;
    }
    if (diag1_count == N || diag2_count == N) winner = 'X';
    if (diag1_count == -N || diag2_count == -N) winner = 'O';

    return winner;
}

bool has_free_cell(char board[N][N])
{
    bool flag = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == '-') {
                flag = true;
            }
        }
    }
    return flag;
}

int main(void)
{
    printf("TicTacToe [InCoMpLeTo :'(]\n");

    char board[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = '-';
        }
    };

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board))
    {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0)
        {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX)
        {
            int row = cell / N;
            int colum = cell % N;
            if (board[row][colum] == '-')
            {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            }
            else
            {
                printf("\nCelda ocupada!\n");
            }
        }
        else
        {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-')
    {
        printf("Empate!\n");
    }
    else
    {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
