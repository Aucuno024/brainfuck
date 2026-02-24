//
// Created by jolyne on 21/02/25.
//
#include <stdio.h>
#include <stdlib.h>
#include "lecture.h"


FILE *f;
void initialiser(char const *filename)
{
    f = fopen(filename, "r");
    if (!f)
    {
        fprintf(stderr, "Erreur de lecture : fichier inexistant\n");
        exit(1);
    }
}

void lecture(char *c)
{
    if (!f)
    {
        fprintf(stderr, "Erreur de lecture : fichier non initialisé");
        exit(2);
    }
    fscanf(f, "%c", c);
    if (feof(f)) *c = EOF;
}

void fin()
{
    fclose(f);
}