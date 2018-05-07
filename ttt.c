#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define PLAYERX 'X'
#define PLAYERO 'O'
#define EMPTY_CHAR ' '
#define N 3

char board[3][3];

void initialize();

void print_title();

int player_turn();

int comp_turn(char board[N][N], char player);

int enter_grid_turn(char board[N][N], char player, int grid_num);

int enter_coord_turn(char board[N][N], char player, int x, int y);

void print_board();

//
int my_max(char board[N][N], char player);

int my_min(char board[N][N], char player);

// Use the minimax algorithm for the AI
void minimax(char board[N][N], char player);


int main() {
    // Board will be [N][N] and N is defines as 3. So layout will be 3x3
    char board[N][N];
    char choice;
    //print_title();

    // Start game:
    // Since this game will be played in VirtualBox, ask user in command line
    while (TRUE) {
        printf("Play as X? (y/n): ");
        scanf("%c", &choice);
        choice = tolower(choice);
        if (choice == 'y' || choice == 'n') {
            choice = (choice == 'y' ? PLAYERX : PLAYERO);
            break;
        }
        printf("Incorrect, choose again\n");
    }

    // Initialize the board (need to set them as empty chars)

    //testing some functions
    initialize();
    print_board();
    player_turn();
    print_board();

//    while (TRUE) {
//        if (choice == PLAYERX) {
//            if (player_turn(board, PLAYERX) == TRUE)
//                break;
//
//            if (comp_turn(board, PLAYERO) == TRUE)
//                break;
//
//
//        } else {
//            if (comp_turn(board, PLAYERX) == TRUE)
//                break;
//
//            if (player_turn(board, PLAYERO) == TRUE)
//                break;
//        }
//    }

    return 0;
}

int player_turn() {
    int x, y;
    //coordinates start at 1,1
    printf("Enter X,Y coordinates for your move: ");
    scanf("%d%*c%d", &x, &y);
    x--;
    y--;
    if (board[x][y] != ' ') {
        printf("Invalid move, please try again.\n");
        player_turn( board[N][N]);
    } else {
        board[x][y] = 'X';
    }
}

void initialize() {
    int i, j;
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            board[i][j] = EMPTY_CHAR;
        }
    }
}

void print_board() {
    int t;
    printf("\n");
    for (t = 0; t < 3; t++) {
        printf(" %c | %c | %c ", board[t][0],
               board[t][1], board[t][2]);
        if (t != 2) printf("\n---|---|---\n");
    }
    printf("\n\n");
}
