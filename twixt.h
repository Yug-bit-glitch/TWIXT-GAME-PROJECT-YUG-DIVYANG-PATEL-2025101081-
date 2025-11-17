#ifndef TWIXT_H
#define TWIXT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
    int x, y;
    struct node *next;
} node;

typedef struct {
    char name[100];
    int id;
    char identifier;
    node *moves;
} player;

void printboard(int n, player *pl1, player *pl2);
void place(int n, int x, int y, player *pl, player *pl1, player *pl2);
bool checkvalidity(int n, int x, int y, player *pl1, player *pl2);

#endif
