#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Platform-specific includes and functions (re-declared for this module)
#ifdef _WIN32
#include <windows.h>
#include <conio.h>
void tetris_sleep_ms(int ms) { Sleep(ms); }
void tetris_clear_screen() { system("cls"); }
#else
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
void tetris_sleep_ms(int ms) { usleep(ms * 1000); }
void tetris_clear_screen() { system("clear"); }

int tetris_kbhit(void) {
    struct termios oldt, newt;
    int ch, oldf;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    if(ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

int tetris_getch() { return getchar(); }
#endif

#include "tetris_gameEx.h"
#include "hello.h"

// Game board dimensions
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
#define BLOCK_SIZE 4

// Game state variables
char board[BOARD_HEIGHT][BOARD_WIDTH];
int score = 0;
bool gameOver = false;

// Tetromino shapes (I, O, T, L, J, S, Z)
const char tetrominoes[7][BLOCK_SIZE][BLOCK_SIZE] = {
    {" I  ", " I  ", " I  ", " I  "}, // I
    {"    ", " OO ", " OO ", "    "}, // O
    {" T  ", "TTT ", "    ", "    "}, // T
    {"  L ", "  L ", " LL ", "    "}, // L
    {" J  ", " J  ", "JJ  ", "    "}, // J
    {" SS ", "SS  ", "    ", "    "}, // S
    {"ZZ  ", " ZZ ", "    ", "    "}  // Z
};

typedef struct {
    char shape[BLOCK_SIZE][BLOCK_SIZE];
    int x, y;
    int type;
    int rotation;
} Tetromino;

Tetromino current;

void rotate(Tetromino *t) {
    char temp[BLOCK_SIZE][BLOCK_SIZE];
    for (int i = 0; i < BLOCK_SIZE; i++) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            temp[i][j] = t->shape[i][j];
        }
    }
    for (int i = 0; i < BLOCK_SIZE; i++) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            t->shape[i][j] = temp[BLOCK_SIZE - 1 - j][i];
        }
    }
}

bool checkCollision(const Tetromino *t) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            if (t->shape[i][j] != ' ') {
                int boardX = t->x + j;
                int boardY = t->y + i;
                if (boardX < 0 || boardX >= BOARD_WIDTH || boardY >= BOARD_HEIGHT) {
                    return true; // Collision with walls or bottom
                }
                if (boardY >= 0 && board[boardY][boardX] != ' ') {
                    return true; // Collision with another block
                }
            }
        }
    }
    return false;
}

void newTetromino() {
    current.type = rand() % 7;
    current.x = BOARD_WIDTH / 2 - 2;
    current.y = 0;
    current.rotation = 0;

    for (int i = 0; i < BLOCK_SIZE; i++) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            current.shape[i][j] = tetrominoes[current.type][i][j];
        }
    }

    if (checkCollision(&current)) {
        gameOver = true;
    }
}

void placeTetromino() {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            if (current.shape[i][j] != ' ') {
                int boardX = current.x + j;
                int boardY = current.y + i;
                if (boardY >= 0) {
                    board[boardY][boardX] = current.shape[i][j];
                }
            }
        }
    }
}

void clearLines() {
    int linesCleared = 0;
    for (int i = BOARD_HEIGHT - 1; i >= 0; i--) {
        bool lineFull = true;
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (board[i][j] == ' ') {
                lineFull = false;
                break;
            }
        }

        if (lineFull) {
            linesCleared++;
            for (int k = i; k > 0; k--) {
                for (int j = 0; j < BOARD_WIDTH; j++) {
                    board[k][j] = board[k - 1][j];
                }
            }
            for (int j = 0; j < BOARD_WIDTH; j++) {
                board[0][j] = ' ';
            }
            i++; // Re-check the current line
        }
    }
    score += linesCleared * linesCleared * 100; // Score based on lines cleared
}

void drawBoard() {
    tetris_clear_screen();
    char tempBoard[BOARD_HEIGHT][BOARD_WIDTH];
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            tempBoard[i][j] = board[i][j];
        }
    }

    // Draw current piece onto the temp board
    for (int i = 0; i < BLOCK_SIZE; i++) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            if (current.shape[i][j] != ' ') {
                int boardX = current.x + j;
                int boardY = current.y + i;
                if (boardY >= 0 && boardY < BOARD_HEIGHT && boardX >= 0 && boardX < BOARD_WIDTH) {
                    tempBoard[boardY][boardX] = current.shape[i][j];
                }
            }
        }
    }

    // Print the board
    printf("Score: %d\n", score);
    for (int j = 0; j < BOARD_WIDTH + 2; j++) printf("#");
    printf("\n");

    for (int i = 0; i < BOARD_HEIGHT; i++) {
        printf("#");
        for (int j = 0; j < BOARD_WIDTH; j++) {
            printf("%c", tempBoard[i][j] == ' ' ? '.' : tempBoard[i][j]);
        }
        printf("#\n");
    }

    for (int j = 0; j < BOARD_WIDTH + 2; j++) printf("#");
    printf("\n");
    printf("Controls: A(Left), D(Right), S(Down), W(Rotate), X(Quit)\n");
}

void handleInput() {
    if (tetris_kbhit()) {
        int key = tetris_getch();
        Tetromino temp = current;

        switch (key) {
            case 'a': // Move left
            case 'A':
                temp.x--;
                break;
            case 'd': // Move right
            case 'D':
                temp.x++;
                break;
            case 's': // Move down
            case 'S':
                temp.y++;
                break;
            case 'w': // Rotate
            case 'W':
                rotate(&temp);
                break;
            case 'x': // Quit
            case 'X':
                gameOver = true;
                break;
        }

        if (!checkCollision(&temp)) {
            current = temp;
        }
    }
}

void updateGame() {
    Tetromino temp = current;
    temp.y++;

    if (checkCollision(&temp)) {
        placeTetromino();
        clearLines();
        newTetromino();
    } else {
        current = temp;
    }
}

void tetris_gameEx(void) {
    printLine("Classic Tetris Game");
    printf("Get ready! The game will start in 3 seconds...\n");
    tetris_sleep_ms(3000);

    srand(time(NULL));
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = ' ';
        }
    }
    newTetromino();

    int timer = 0;
    int speed = 40; // Lower is faster

    while (!gameOver) {
        handleInput();

        if (timer >= speed) {
            updateGame();
            timer = 0;
        }

        drawBoard();
        tetris_sleep_ms(20);
        timer++;
    }

    tetris_clear_screen();
    printf("\n\n    GAME OVER!\n");
    printf("    Your final score: %d\n\n", score);

    // Restore terminal settings on Unix-like systems
    #ifndef _WIN32
        struct termios oldt;
        tcgetattr(STDIN_FILENO, &oldt);
        oldt.c_lflag |= (ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    #endif
}
