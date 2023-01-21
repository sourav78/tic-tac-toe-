#include <stdio.h>
#include <stdlib.h>

// declaring array and variable as globaly
char a[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; 
int k = 0, j = 0;
int end = 1;

// This function print the whole TIC-TAC-TOE grid
void body()
{
    printf("\n\t%c | %c | %c", a[0], a[1], a[2]);
    printf("\n\t---------       Player 1 = X");
    printf("\n\t%c | %c | %c", a[3], a[4], a[5]);
    printf("\n\t---------       Player 2 = 0");
    printf("\n\t%c | %c | %c \n", a[6], a[7], a[8]);
}

// This function get input from player.
void get_input()
{
    char ch;
    int i;

    if (j == 0)
    {
        printf("\n\tPlayer 1 - Enter position=");
        fflush(stdin);
        scanf("%c", &ch);
        j = 1;
    }
    else
    {
        printf("\n\tPlayer 2 - Enter position=");
        fflush(stdin);
        scanf("%c", &ch);
        j = 0;
    }
    
    if (k == 0)
    {
        for (i = 0; i <= 8; i++)
        {
            if (a[i] == ch)
            {
                a[i] = 'X';
                k = 1;
                break;
            }
        }
    }
    else
    {
        for (i = 0; i <= 8; i++)
        {
            if (a[i] == ch)
            {
                a[i] = '0';
                k = 0;
                break;
            }
        }
    }
}

// This function contain all the condition of game
int game_condition()
{
    //Checking for win with X combinations
    if (a[0] == 'X' && a[1] == 'X' && a[2] == 'X')
        return 1;
    else if (a[0] == 'X' && a[3] == 'X' && a[6] == 'X') 
        return 1;
    else if (a[0] == 'X' && a[4] == 'X' && a[8] == 'X')
        return 1;
    else if (a[1] == 'X' && a[4] == 'X' && a[7] == 'X')
        return 1;
    else if (a[2] == 'X' && a[5] == 'X' && a[8] == 'X')
        return 1;
    else if (a[2] == 'X' && a[4] == 'X' && a[6] == 'X')
        return 1;
    else if (a[3] == 'X' && a[4] == 'X' && a[5] == 'X')
        return 1;
    else if (a[6] == 'X' && a[7] == 'X' && a[8] == 'X')
        return 1;

    // checking for draw with X combinations
    else if (a[1] == 'X' && a[4] == 'X' && a[6] == 'X' && a[8] == 'X') 
        return 3;
    else if (a[0] == 'X' && a[2] == 'X' && a[4] == 'X' && a[7] == 'X')
        return 3;
    else if (a[0] == 'X' && a[4] == 'X' && a[5] == 'X' && a[6] == 'X')
        return 3;
    else if (a[2] == 'X' && a[3] == 'X' && a[4] == 'X' && a[8] == 'X')
        return 3;
    else if (a[1] == 'X' && a[4] == 'X' && a[5] == 'X' && a[6] == 'X') 
        return 3;
    else if (a[0] == 'X' && a[4] == 'X' && a[5] == 'X' && a[7] == 'X')
        return 3;
    else if (a[2] == 'X' && a[3] == 'X' && a[4] == 'X' && a[7] == 'X')
        return 3;
    else if (a[1] == 'X' && a[3] == 'X' && a[4] == 'X' && a[8] == 'X')
        return 3;

    //Checking for win with 0 combinations
    else if (a[0] == '0' && a[1] == '0' && a[2] == '0') 
        return 2;
    else if (a[0] == '0' && a[3] == '0' && a[6] == '0')
        return 2;
    else if (a[0] == '0' && a[4] == '0' && a[8] == '0')
        return 2;
    else if (a[1] == '0' && a[4] == '0' && a[7] == '0')
        return 2;
    else if (a[2] == '0' && a[5] == '0' && a[8] == '0')
        return 2;
    else if (a[2] == '0' && a[4] == '0' && a[6] == '0')
        return 2;
    else if (a[3] == '0' && a[4] == '0' && a[5] == '0')
        return 2;
    else if (a[6] == '0' && a[7] == '0' && a[8] == '0')
        return 2;

    // checking for draw with 0 combinations
    else if (a[1] == '0' && a[4] == '0' && a[6] == '0' && a[8] == '0') 
        return 3;
    else if (a[0] == '0' && a[2] == '0' && a[4] == '0' && a[7] == '0')
        return 3;
    else if (a[0] == '0' && a[4] == '0' && a[5] == '0' && a[6] == '0')
        return 3;
    else if (a[2] == '0' && a[3] == '0' && a[4] == '0' && a[8] == '0')
        return 3;
    else if (a[1] == '0' && a[4] == '0' && a[5] == '0' && a[6] == '0') 
        return 3;
    else if (a[0] == '0' && a[4] == '0' && a[5] == '0' && a[7] == '0')
        return 3;
    else if (a[2] == '0' && a[3] == '0' && a[4] == '0' && a[7] == '0')
        return 3;
    else if (a[1] == '0' && a[3] == '0' && a[4] == '0' && a[8] == '0')
        return 3;

    else
        return 0;
}

// This function will determine our winner.
void game_winner()
{
    int f;
    f = game_condition();
    if (f == 1)
    {
        printf("\n_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^\n");
        printf("\nCongraulation :)");
        printf("\n\t\tplayer 1 WON :)");
        printf("\n\nPlayer 2 better luck next time.\n");
        printf("--------------------------------------");
        end = 0;
    }
    else if (f == 2)
    {
        printf("\n_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^\n");
        printf("\nCongraulation :)");
        printf("\n\t\tplayer 2 WON :)");
        printf("\n\nPlayer 1 better luck next time.\n");
        printf("--------------------------------------");
        end = 0;
    }
    else if (f==3)
    {
        printf("\n_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^\n");
        printf("\n Match draw :|");
        printf("\n\t\t Both player played well :) \n");
        printf("--------------------------------------");
        
        end=0;
    }
    else; 
}

void main()
{
    char q;
turn:
    system("cls");
    body();
    while (end)
    {
        get_input();
        system("cls");
        body();
        game_winner();
    }

    printf("\n\nDo you wnat to play again!");
    printf("\nIf yes then prees 'y'=");
    fflush(stdin);
    scanf("%c", &q);
    if (q == 'y' || q == 'Y')
    {
        a[0] = '1', a[1] = '2', a[2] = '3', a[3] = '4', a[4] = '5', a[5] = '6', a[6] = '7', a[7] = '8', a[8] = '9';
        k = 0;
        j = 0;
        end = 1;
        goto turn;
    }
    printf("\n\nThank you :)");
}