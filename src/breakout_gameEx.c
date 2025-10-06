#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Platform-specific includes and functions (re-declared for this module)
#ifdef _WIN32
#include <windows.h>
#include <conio.h>
void breakout_sleep_ms(int ms) { Sleep(ms); }
void breakout_clear_screen() { system("cls"); }
#define GETCH _getch
#define KBHIT _kbhit
#else
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
void breakout_sleep_ms(int ms) { usleep(ms * 1000); }
void breakout_clear_screen() { system("clear"); }

int breakout_kbhit(void) {
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

int breakout_getch() { return getchar(); }
#define GETCH breakout_getch
#define KBHIT breakout_kbhit
#endif

#include "breakout_gameEx.h"
#include "hello.h"

// Game settings
#define WIDTH 40
#define HEIGHT 20
#define PADDLE_WIDTH 6
#define BRICK_ROWS 5
#define BRICK_COLS 7

// Game state variables
static bool b_gameOver;
static int score;
static int lives;

static int paddleX;
static int ballX, ballY;
static int ballDirX, ballDirY;

static bool bricks[BRICK_ROWS][BRICK_COLS];

static void ResetBall() {
    ballX = WIDTH / 2;
    ballY = HEIGHT - 3;
    ballDirX = -1;
    ballDirY = -1;
    paddleX = (WIDTH - PADDLE_WIDTH) / 2;
}

static void Setup() {
    b_gameOver = false;
    score = 0;
    lives = 3;
    ResetBall();

    for (int i = 0; i < BRICK_ROWS; i++) {
        for (int j = 0; j < BRICK_COLS; j++) {
            bricks[i][j] = true;
        }
    }
}

static void Draw() {
    breakout_clear_screen();
    printf("Score: %d | Lives: %d\n", score, lives);

    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        printf("#");
        for (int j = 0; j < WIDTH; j++) {
            if (i == ballY && j == ballX) {
                printf("O"); // Ball
            } else if (i == HEIGHT - 2 && j >= paddleX && j < paddleX + PADDLE_WIDTH) {
                printf("="); // Paddle
            } else {
                bool isBrick = false;
                if (i < BRICK_ROWS * 2 && i % 2 == 1) {
                    int brickRow = i / 2;
                    int brickCol = j / (WIDTH / BRICK_COLS);
                    if (brickCol < BRICK_COLS && bricks[brickRow][brickCol]) {
                        printf("#");
                        isBrick = true;
                    }
                }
                if (!isBrick) printf(" ");
            }
        }
        printf("#\n");
    }

    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");
    printf("Controls: A(Left), D(Right), X(Quit)\n");
}

static void Input() {
    if (KBHIT()) {
        switch (GETCH()) {
            case 'a':
            case 'A':
                if (paddleX > 0) paddleX--;
                break;
            case 'd':
            case 'D':
                if (paddleX < WIDTH - PADDLE_WIDTH) paddleX++;
                break;
            case 'x':
            case 'X':
                b_gameOver = true;
                break;
        }
    }
}

static void Logic() {
    // Ball movement
    ballX += ballDirX;
    ballY += ballDirY;

    // Wall collision
    if (ballX <= 0 || ballX >= WIDTH - 1) ballDirX *= -1;
    if (ballY <= 0) ballDirY *= -1;

    // Paddle collision
    if (ballY == HEIGHT - 3 && ballX >= paddleX && ballX < paddleX + PADDLE_WIDTH) {
        ballDirY *= -1;
    }

    // Bottom wall (miss)
    if (ballY >= HEIGHT) {
        lives--;
        if (lives <= 0) {
            b_gameOver = true;
        } else {
            ResetBall();
            breakout_sleep_ms(500);
        }
    }

    // Brick collision
    if (ballY < BRICK_ROWS * 2) {
        int brickRow = ballY / 2;
        int brickCol = ballX / (WIDTH / BRICK_COLS);
        if (brickCol < BRICK_COLS && bricks[brickRow][brickCol]) {
            bricks[brickRow][brickCol] = false;
            score += 10;
            ballDirY *= -1;
        }
    }

    // Check for win
    bool allBricksBroken = true;
    for (int i = 0; i < BRICK_ROWS; i++) {
        for (int j = 0; j < BRICK_COLS; j++) {
            if (bricks[i][j]) {
                allBricksBroken = false;
                break;
            }
        }
        if (!allBricksBroken) break;
    }
    if (allBricksBroken) {
        b_gameOver = true;
    }
}

void breakout_gameEx(void) {
    printLine("Classic Breakout Game");
    printf("Get ready! The game will start in 3 seconds...\n");
    breakout_sleep_ms(3000);

    Setup();
    while (!b_gameOver) {
        Draw();
        Input();
        Logic();
        breakout_sleep_ms(50); // Game speed
    }

    breakout_clear_screen();
    bool won = true;
    for (int i = 0; i < BRICK_ROWS; i++) {
        for (int j = 0; j < BRICK_COLS; j++) {
            if (bricks[i][j]) won = false;
        }
    }

    if (won) {
        printf("\n\n    CONGRATULATIONS! YOU WON!\n");
    } else {
        printf("\n\n    GAME OVER!\n");
    }
    printf("    Your final score: %d\n\n", score);

    // Restore terminal settings on Unix-like systems
    #ifndef _WIN32
        struct termios oldt;
        tcgetattr(STDIN_FILENO, &oldt);
        oldt.c_lflag |= (ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    #endif
}
