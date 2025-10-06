#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Platform-specific includes and functions
#ifdef _WIN32
#include <windows.h>
#include <conio.h> // For _kbhit() and _getch()
void sleep_ms(int milliseconds) { Sleep(milliseconds); }
void clear_screen_game() { system("cls"); }
#else
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
void sleep_ms(int milliseconds) { usleep(milliseconds * 1000); }
void clear_screen_game() { system("clear"); }

// Non-blocking keyboard input for Unix-like systems
int _kbhit(void) {
    struct termios oldt, newt;
    int ch;
    int oldf;

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

int _getch() {
    return getchar();
}
#endif

#include "snake_gameEx.h"
#include "hello.h"

// Game settings
#define WIDTH 20
#define HEIGHT 20

static bool gameOver;
static int x, y, fruitX, fruitY, score;
static int tailX[100], tailY[100];
static int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
static enum eDirection dir;

// Setup initial game state
static void Setup() {
    srand(time(NULL));
    gameOver = false;
    dir = STOP;
    x = WIDTH / 2;
    y = HEIGHT / 2;
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    score = 0;
    nTail = 0;
}

// Draw the game board, snake, and fruit
static void Draw() {
    clear_screen_game();
    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0) printf("#");

            if (i == y && j == x) {
                printf("O"); // Snake head
            } else if (i == fruitY && j == fruitX) {
                printf("F"); // Fruit
            } else {
                bool printTail = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printf("o"); // Snake tail
                        printTail = true;
                    }
                }
                if (!printTail) printf(" ");
            }

            if (j == WIDTH - 1) printf("#");
        }
        printf("\n");
    }

    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");
    printf("Score: %d\n", score);
    printf("Use W-A-S-D keys to move. Press 'x' to quit.\n");
}

// Handle user input
static void Input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a':
                if (dir != RIGHT) dir = LEFT;
                break;
            case 'd':
                if (dir != LEFT) dir = RIGHT;
                break;
            case 'w':
                if (dir != DOWN) dir = UP;
                break;
            case 's':
                if (dir != UP) dir = DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
        }
    }
}

// Update game logic (move snake, check for collisions, etc.)
static void Logic() {
    // Update tail positions
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    // Update head position based on direction
    switch (dir) {
        case LEFT:  x--; break;
        case RIGHT: x++; break;
        case UP:    y--; break;
        case DOWN:  y++; break;
        default:    break;
    }

    // Check for wall collisions
    if (x >= WIDTH || x < 0 || y >= HEIGHT || y < 0) {
        gameOver = true;
    }

    // Check for tail collisions
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y) {
            gameOver = true;
        }
    }

    // Check for fruit consumption
    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
        nTail++;
    }
}

void snake_gameEx(void) {
    printLine("Classic Snake Game");
    printf("Get ready to play! The game will start in 3 seconds...\n");
    sleep_ms(3000);

    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        // Control game speed
        if (dir != STOP) {
            sleep_ms(150);
        }
    }

    clear_screen_game();
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