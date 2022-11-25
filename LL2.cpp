// grammer
/*
A->aBa
B->bB
B->@
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char prod[3][10] = {"A->aBa", "B->bB", "B->@"};
char first[3][10] = {"a", "b", "@"};
char follow[3][10] = {"$", "a", "a"};
char table[3][4][10];

// char input[10];
// int top = -1;
// char stack[25];
// char curp[20];

// void push(char item)
// {
//     stack[++top] = item;
// }
// void pop()
// {
//     top -= 1;
// }
// void display()
// {
//     for (int i = top; i >= 0; i--)
//     {
//         printf("%c", stack[i]);
//     }
// }
int numr(char c)
{
    switch (c)
    {
    case 'A':
        return 1;
    case 'B':
        return 2;
    case 'a':
        return 1;
    case 'b':
        return 2;
    case '@':
        return 3;
    }
    return 1;
}
int main()
{
    char c;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            strcpy(table[i][j], "");
        }
    }
    printf("\nGrammar\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", prod[i]);
    }
    printf("\nfirst ={%s,%s,%s}", first[0], first[1], first[2]);
    printf("\nfollow ={%s,%s}\n", follow[0], follow[1]);

    printf("predictive parsing table for given grammer");

    strcpy(table[0][0], "");
    strcpy(table[0][1], "a");
    strcpy(table[0][2], "b");
    strcpy(table[0][3], "$");
    strcpy(table[1][0], "A");
    strcpy(table[2][0], "B");
    

    for (int i = 0; i < 3; i++)
    {
        if (first[i][0] != '@')
        {
            strcpy(table[numr(prod[i][0])][numr(first[i][0])], prod[i]);
        }
        else
        {
            strcpy(table[numr(prod[i][0])][numr(follow[i][0])], prod[i]);
        }
    }
    printf("\n----------------------------------------------------------------\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            printf("%-20s",table[i][j]);
            if(j==3){
                printf("\n----------------------------------------------------------------\n");
            }
        }
    }
}