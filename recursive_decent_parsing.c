#include <stdio.h>
#include <string.h>
#include <ctype.h>

// E -> E+T/T
// T -> T*F/F
// F -> (E)/id

// after removing left recursion

// E -> TE'
// E'-> +TE'/∈
// T -> FT'
// T'-> *FT'/∈
// F -> (E)/id
  
char input[100]; // imp
 
int i, error;

void E();

void T();

void Eprime();

void Tprime();

void F();

int main()
{

    i = 0;

    error = 0;

    printf("Enter an arithmetic expression   :  "); // Eg:a+a*a
    gets(input);

    E();  // starting symbol

    if (strlen(input) == i && error == 0)

        printf("\nAccepted..!!!\n");

    else
        printf("\nRejected..!!!\n");
}

void E()
{

    T();

    Eprime();
}


void Eprime()
{

    if (input[i] == '+')

    {

        i++;

        T();

        Eprime();
    }
}

void T()
{

    F();

    Tprime();
}


void Tprime()
{

    if (input[i] == '*')

    {

        i++;

        F();

        Tprime();
    }
}

void F()
{

    if (isalnum(input[i]))
        i++;

    else if (input[i] == '(')

    {

        i++;

        E();

        if (input[i] == ')')

            i++;

        else
            error = 1;
    }

    else
        error = 1; 
}

// a+(a*a)  a+a*a , (a), a , a+a+a*a+a , (a+b*c+(a+b)).... etc are  accepted
// ++a, a***a, +a, a*, ((a . . . etc are rejected.

// also make for 
// grammer
// E->iE'
// E'->+iE/∈    
