//
// Created by jolyne on 17/04/25.
//
#include "stdio.h"
#include "lexique.h"
int main(int argc, char * argv[])
{
    if (argc !=2)
    {
        fprintf(stderr, "Erreur : le programme %s prend exactement un argument \n", argv[0]);
        return -1;
    }
    analyse_lex(argv[1]);
    printf("\n");
    return 0;
}
