#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// #define LOG
#define LENGTH(x) (sizeof(x) / sizeof(x[0]))
#define NEWLINE printf("\n");
#define BOARD_SIZE 9
#define PLAYER1 'X'
#define PLAYER2 'O'

/* Board
+-----+-----+-----+
|  0  |  1  |  2  |
+-----+-----+-----+
|  3  |  4  |  5  |
+-----+-----+-----+
|  6  |  7  |  8  |
+-----+-----+-----+
*/

const int wins[] = {
    0, 1, 2,
    0, 3, 6,
    0, 4, 8,
    1, 4, 7,
    2, 5, 8,
    2, 4, 6,
    3, 4, 5,
    6, 7, 8
};

// Checks if the board still have some unmarked spaces.
int checkForSpace(char* board);

// Checks if there's a win/three-in-a-row.
_Bool checkForWin(char* board);

// Marks the board.
int mark(char* board, char mark);

// Draws the board.
void drawBoard(char* board);

int main(void) {
    // Declares the necessary things.
    int pos = -1;
    _Bool currentPlayer = 0;
    char board[BOARD_SIZE];
    
    printf("         Tic Tac Toe\n");
    printf("Player 1 = X     Player 2 = O\n");
    
    do {
        pos = mark(board, currentPlayer ? PLAYER2 : PLAYER1);
        if (!pos) continue;
        
        printf("\n      Player %d picked %d\n", currentPlayer + 1, pos);
        drawBoard(board);
        
        if (checkForWin(board))
            break;
        
        currentPlayer = !currentPlayer;
    } while(checkForSpace(board));
    
    NEWLINE
    
    if (checkForWin(board))
        printf("   Player %d is the winner!", currentPlayer + 1);
    else printf("         It's a tie!");
    
    return 0;
}

int checkForSpace(char* board) {
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i] != PLAYER1 &&
            board[i] != PLAYER2) count++;
    }
    
    return count;
}

_Bool checkForWin(char* board) {
    int a, b, c;
    for (int i = 0; i < LENGTH(wins); i += 3) {
        a = wins[i];
        b = wins[i + 1];
        c = wins[i + 2];
        
        if (board[a] == PLAYER1 ||
            board[a] == PLAYER2 ) {
            if (board[a] == board[b] &&
                board[b] == board[c]) return 1;
        }
    }
    
    return 0;
}

int mark(char* board, char mark) {
    srand(time(NULL));

    int length = checkForSpace(board);
    if (!length)
        return 0;
    
    int pos[length];
    
    for (int i = 0, j = 0; i < BOARD_SIZE; i++) {
        if (board[i] != PLAYER1 &&
            board[i] != PLAYER2)
            pos[j++] = i;
    }
    
    int rnd = rand() % length;
    int index = pos[rnd];
    board[index] = mark;
    
#ifdef LOG
    printf("\nPos: ");
    for (int i = 0; i < length; i++) {
        printf("%d, ", pos[i]);
    }
    
    printf("\nLENGTH: %d\n", LENGTH(pos));
    printf("Rand: %d\n", rnd);
    printf("Index: %d\n", index);
#endif
    
    return index + 1;
}

void drawBoard(char* board) {
    printf("     +-----+-----+-----+\n");
    
    for (int i = 0; i < BOARD_SIZE; i += 3) {
        printf("     |");
        
        for (int j = 0; j < 3; j++) {
            if (board[i + j] != PLAYER1 &&
                board[i + j] != PLAYER2)
                printf("  %d  |", i + j + 1);
            else printf("  %c  |", board[i + j]);
        }
        
        printf("\n     +-----+-----+-----+\n");
        
    }
}