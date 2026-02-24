//
// Created by jolyne on 17/03/25.
//
#include <stdio.h>
#include <unistd.h>
#include "ast.h"
#include "stdlib.h"
#define MAX 16777216



ast_t *creer_boucle(ast_t *apres, ast_t *boucle)
{
    ast_t *A = malloc(sizeof(ast_t));
    A->astd = apres;
    A->astg = boucle;
    A->operation = N_BOUCLE_AST;
    A->p_cond = -1;
    return A;
}



ast_t *creer_operation(ast_t *suiv, type_ast nature)
{
    ast_t *A = malloc(sizeof(ast_t));
    A->astd = suiv;
    A->operation = nature;
    return A;
}

void creer_fin(ast_t **retour)
{
    ast_t *c= *retour;
    c = c->astg;
    while (c->operation != N_F_B_AST && c->astd)
    {
        c = c->astd;
    }
   c->astd = *retour;
}

void afficher_ast(ast_t *A)
{
    printf("(gauche : ");
    if (!A) return;
    if (A->astg) afficher_ast(A->astg);
    printf(",%c, droit :", A->operation);
    if (A->astd && A->operation != N_F_B_AST) afficher_ast(A->astd);
    printf(")");
}


void evaluer_it(ast_t *A, int memoire[])
{
    int i = 0;
    FILE *f = fopen("sortie", "w");
    fclose(f);
    while (A)
    {
        i = i % MAX;
        switch (A->operation)
        {
            case N_ENTREE:
                char salut[100];
                fprintf(stdout, "Caractère attendu : ");
                scanf("%s", salut);
                memoire[i] = (int) salut[0];
                A = A->astd;
                break;
            case N_SORTIE:
                putchar(memoire[i]==10?'\n':memoire[i]); fflush(stdout);
                A = A->astd;
                break;
            case N_MODIF_M:
                A = A->astd;
                memoire[i]--;
                break;
            case N_MODIF_P:
                memoire[i]++;
                A = A->astd;
                break;
            case N_DEPLACEMENT_M:
                i--;
                A = A->astd;
                break;
            case N_DEPLACEMENT_P:
                i++;
                A = A->astd;
                break;
            case N_BOUCLE_AST:
                if (memoire[i])
                {
                    A = A->astg;
                } else
                {
                    A = A->astd;
                }
                break;
            case N_F_B_AST:
                A = A->astd;
                break;
            default:
                break;
        }
    }
}


void evaluation(ast_t *A)
{
    int *memoire = malloc(sizeof(int)*MAX);
    int *t = memoire;
    for (int j = 0; j < MAX; j++)
    {
        memoire++[0] = 0;
    }
    memoire = t;
    evaluer_it(A, memoire);
}