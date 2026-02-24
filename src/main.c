#include "syntaxe.h"
#include <stdio.h>



int main(int argc, char *argv[])
{

    if (argc == 2)
    {
        analyser(argv[1]);
    } else
    {
        analyser("");
    }
    printf("\nFin de l'execution\n");
    return 0;
}