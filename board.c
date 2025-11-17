#include "twixt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define N 24

bool checkvalidity(int n, int x, int y, player *pl1, player *pl2) {

    if(x < 0 || x >= n || y < 0 || y >= n) {
        return false;
    }

    node *temp = pl1->moves;
    while(temp != NULL) {
        if(temp->x == x && temp->y == y) {
            return false;
        }
        temp = temp->next;
    }

    node *temp2 = pl2->moves;
    while(temp2 != NULL) {
        if(temp2->x == x && temp2->y == y) {
            return false;
        }
        temp2 = temp2->next;
    }

    return true;
}

void place(int n, int x, int y, player *pl, player *pl1, player *pl2) {

    if(checkvalidity(n, x, y, pl1, pl2) == false) {
        printf("INVALID MOVE BRO :(\n");
        return;
    }

    node *temp1 = malloc(sizeof(node));
    temp1->x = x;
    temp1->y = y;
    temp1->next = pl->moves;
    pl->moves = temp1;

    node *temp = pl->moves->next;
    while(temp != NULL) {

        if(temp->x == x+2 && temp->y == y+1) {
            printf("joined to (%d,%d)\n", temp->x, temp->y);
        }
        if(temp->x == x+2 && temp->y == y-1) {
            printf("joined to (%d,%d)\n", temp->x, temp->y);
        }
        if(temp->x == x-2 && temp->y == y+1) {
            printf("joined to (%d,%d)\n", temp->x, temp->y);
        }
        if(temp->x == x-2 && temp->y == y-1) {
            printf("joined to (%d,%d)\n", temp->x, temp->y);
        }
        if(temp->x == x+1 && temp->y == y+2) {
            printf("joined to (%d,%d)\n", temp->x, temp->y);
        }
        if(temp->x == x+1 && temp->y == y-2) {
            printf("joined to (%d,%d)\n", temp->x, temp->y);
        }
        if(temp->x == x-1 && temp->y == y+2) {
            printf("joined to (%d,%d)\n", temp->x, temp->y);
        }
        if(temp->x == x-1 && temp->y == y-2) {
            printf("joined to (%d,%d)\n", temp->x, temp->y);
        }

        temp = temp->next;
    }
}

void printboard(int n, player *pl1, player *pl2) {

    char board[N][N];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            board[i][j] = '.';
        }
    }

    node *temp = pl1->moves;
    while(temp != NULL) {
        board[temp->x][temp->y] = pl1->identifier;
        temp = temp->next;
    }

    temp = pl2->moves;
    while(temp != NULL) {
        board[temp->x][temp->y] = pl2->identifier;
        temp = temp->next;
    }

    printf("#");
    for(int j = 0; j < n; j++) {
        printf("--");
    }
    printf("#\n");

    for(int i = 0; i < n; i++) {
        printf("|");
        for(int j = 0; j < n; j++) {
            printf("%c ", board[i][j]);
        }
        printf("|\n");
    }

    printf("#");
    for(int j = 0; j < n; j++) {
        printf("--");
    }
    printf("#\n");
}
