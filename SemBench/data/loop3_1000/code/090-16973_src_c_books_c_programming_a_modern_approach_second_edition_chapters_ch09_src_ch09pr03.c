#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define OPEN 1
#define BLOCKED 0
void gen_rand_walk(int[10][10]);
void print_array(int[10][10]);
void gen_rand_walk(int board[10][10]) {
    int x = rand() % 10;
    int y = rand() % 10;
    int letter = 'A';
    int move, up, down, left, right;
    for (int i = 0; i < 10; i += 1) {
        for (int j = 0; j < 10; j += 1) {
            board[i][j] = '+';
        }
    }
    while (letter <= 'Z') {
        board[x][y] = letter;
        letter += 1;
        if ((y - 1 >= 0) && (board[x][y - 1] == '+')) {
            up = OPEN;
        } else {
            up = BLOCKED;
        }
        if ((y + 1 <= 9) && (board[x][y + 1] == '+')) {
            down = OPEN;
        } else {
            down = BLOCKED;
        }
        if ((x - 1 >= 0) && (board[x - 1][y] == '+')) {
            left = OPEN;
        } else {
            left = BLOCKED;
        }
        if ((x + 1 >= 0) && (board[x + 1][y] == '+')) {
            right = OPEN;
        } else {
            right = BLOCKED;
        }
        if (up == BLOCKED && down == BLOCKED && left == BLOCKED &&
            right == BLOCKED) {
            break;
        }
        while (up == OPEN || down == OPEN || left == OPEN || right == OPEN) {
            move = rand() % 4;
            if (move == 0 && up == OPEN) {
                y -= 1;
                break;
            } else if (move == 1 && down == OPEN) {
                y += 1;
                break;
            } else if (move == 2 && left == OPEN) {
                x -= 1;
                break;
            } else if (move == 3 && right == OPEN) {
                x += 1;
                break;
            } else {
                continue;
            }
        }
    }
}
void print_array(int board[10][10]) {
    for (int i = 0; i < 10; i += 1) {
        printf("\t");
        for (int j = 0; j < 10; j += 1) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}
int main(void) {
    srand((unsigned)time(NULL));
    int board[10][10];
    gen_rand_walk(board);
    print_array(board);
    return 0;
}