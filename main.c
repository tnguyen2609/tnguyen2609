
/***************************************************
    Name:       Truc Nguyen
    Project:    TIC TAC TOE
    Date:       09/18/2022
****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void table(int player, char input);
void UI(int player);
int check();
void printWinner(int win);

char input;
char arr[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main()
{
    int win = 0;
    int temp = 1;
    int player = 1;
    
    // System prints headline "TIC TAC TOE"
    printf("\t\tTIC TAC TOE\t\t\n");
    printf("-------------------------------------------------\n");
    
    // System prints "Player 1 <X>   -   Player 2 <O>"
    printf("Player 1 <X>\t-\tPlayer 2 <O>\n\n");
    
    // System displays standard Tic Tac Toe table with number labeled 1 to 9.
    table(-1,-1);
    printf("\n\n");
    
    // System ask user 1 and user 2 for input of number, respectively. Repeatedly untill one wins.
    UI(player);
    while(temp != 0)
    {
        win = check();
        if(win != 0){
                temp = 0;
                printWinner(player);
            }
        else
        {
            if(player == 1)
            {
                player = 2;
                UI(player);
            }
            else if(player == 2)
            {
                player = 1;
                UI(player);
            }
        }
    }
    return 0;
}

/***********************************************************************
    void UI(int player);
    This function will ask for user input.
    Take input as an integer for which player is playing. 
**************************************************************************/
void UI(int player)
{
    
    printf("Player %d, please enter a number: ",player);
    scanf(" %c", &input);
    table(player,input);
}

/***********************************************************************
    void printWinner(int win);
    This function will print to the screen who is the winner.
    Take input as an integer for which player wins. 
**************************************************************************/
void printWinner(int win)
{
    if(win == 1)
    {
        printf("Player 1 wins!! Congrats!!\n");
    }
    else if(win == 2)
    {
        printf("Player 2 wins!! Congrats!!\n");
    }
}

/***********************************************************************
    int check() will check for winner of TIC-TAC-TOE. 
    It will check to see if three marks in a row (horizontal, vertical, and diagonal).
    Funtion will return result of winner found or not. 
    temp = 1 -> Done. Winner found.
    temp = 0 -> No winner found yet.
**************************************************************************/
int check()
{
    int temp;
    //HORIZONTAL
    if(arr[0] == arr[1] && arr[1] == arr[2])
    {
       printf("012%c, %c, %c\n", arr[0], arr[1], arr[2]);
       temp = 1;
    }
    else if(arr[3] == arr[4] && arr[4] == arr[5])
    {
        temp = 1;
        printf("345%c, %c, %c\n", arr[3], arr[4], arr[5]);
    }
    else if(arr[6] == arr[7] && arr[7] == arr[8])
    {
        temp = 1;
        printf("678%c, %c, %c\n", arr[6], arr[7], arr[8]);
    }
    
    //VERTICAL
    else if(arr[0] == arr[3] && arr[3] == arr[6])
    {
        temp = 1;
        printf("036%c, %c, %c\n", arr[0], arr[3], arr[6]);
    }
    else if(arr[1] == arr[4] && arr[4] == arr[7])
    {
        temp = 1;
        printf("147%c, %c, %c\n", arr[1], arr[4], arr[7]);
    }
    else if(arr[2] == arr[5] && arr[5] == arr[8])
    {
        temp = 1;
        printf("258%c, %c, %c\n", arr[2], arr[5], arr[8]);
    }
    
    //DIAGONAL
    else if(arr[0] == arr[4] && arr[4] == arr[8])
    {
       temp = 1;
       printf("048%c, %c, %c\n", arr[0], arr[4], arr[8]);
    }
    else if(arr[2] == arr[4] && arr[4] == arr[6])
    {
        temp = 1;
        printf("246%c, %c, %c\n", arr[2], arr[4], arr[6]);
    }
    
    // NO ONE WINS YET
    else
    {
        temp = 0;
    }
    return temp; 
}



/***********************************************************************
    void table(int player, char input);
    Function table(player, input) draws TIC-TAC-TOE table. 
    It takes input as which player is player and the square selection.
************************************************************************/
void table(int player,char input)
{
    char key;
    
    //Check which player is playing
    if(player == 1)
    {
        key = 'X';
    }
    else if(player == 2)
    {
        key = 'O';
    }
    //standard table
    else if(player != -1)
    {
        printf("Wrong input!!");
        exit(EXIT_FAILURE);
    }
    
    //Loop to find the number from user input
    for(int i = 0; i < 9; i++)
    {
        if(input == arr[i])
        {
            int a = i;
            arr[a] = key;
        }
        printf("\t%c\t|",arr[i]);
        if(i == 2 || i == 5 || i == 8)
        {
            printf("\n");
            for(int k = 0; k < 46; k++)
            {
                printf("_");
                if(k == 15 || k == 30 || k == 45)
                {
                    printf("|");
                }
            }
            printf("\n");
        }
    }
}
