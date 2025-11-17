#include "twixt.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main()
{

    player *pl1 = malloc(sizeof(player));
    player *pl2 = malloc(sizeof(player));

    pl1->identifier = 'A';
    pl1->moves = NULL;

    pl2->identifier = 'B';
    pl2->moves = NULL;

    int n = 24;
    int x, y; 
    bool play = true;

    printf("WELCOME TO TWIXT(LITE) VERSION\n");
    printf("1:START A NEW GAME\n");
    printf("2:RESTORE PREVIOUS GAME\n");
    printf("DEAR USER IF YOU WISH TO QUIT ENTER 7(DHEERA'S SIR FAV NUMBER)\n");
    printf("7,QUIT GAME\n");

    int a;
    scanf("%d", &a);

    if (a == 1)
    {
        while (1)
        {
            printboard(n, pl1, pl2);

            if (play == true)
            {
                printf("A ,ENTER YOUR COORDINATES IN TERMS OF X AND Y (7 TO QUIT)\n");
            }
            else
            {
                printf("B,ENTER YOUR COORDINATES IN TERMS OF X AND Y (7 TO QUIT)\n");
            }

            if (scanf("%d", &x) != 1)
            {
                break;
            }

            if (x == 7)
            {
                printf("DEAR USER PLEASE DONT QUIT .IT IS OKAY IF YOU LOSE ONE GAME\n");
                break;
            }

            if (scanf("%d", &y) != 1)
            {
                break;
            }

            if (play == true)
            {
                place(n, x, y, pl1, pl1, pl2);
            }
            else
            {
                place(n, x, y, pl2, pl1, pl2);
            }

            play = !play;
        }
    }

    return 0;
}
