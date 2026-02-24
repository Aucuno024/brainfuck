//
// Created by jolyne on 22/02/25.
//

#include "syntaxe.h"
#include <stdio.h>
#include <stdlib.h>

#include "lecture.h"
#include "lexique.h"
#include "ast.h"

lexeme_t lexeme_courant;

void suite_expression(ast_t **A);
void suite_expr_boucle(ast_t **A, ast_t **B);
type_ast caract();




type_ast caract()
{
    switch (lexeme_courant.nature)
    {
        case INCR:
            return N_MODIF_P;
        case DECR:
            return N_MODIF_M;
        case DECALAGE_DROIT:
            return N_DEPLACEMENT_P;
        case DECALAGE_GAUCHE:
            return N_DEPLACEMENT_M;
        case ENTREE:
            return N_ENTREE;
        case SORTIE:
            return N_SORTIE;
        default:
            fprintf(stderr, "Erreur syntaxique : Mauvaise interprétation");
            exit(33);
    }
}

void suite_expr_boucle(ast_t **A, ast_t **B)
{
    ast_t *suiv = NULL, *boucle = NULL, *sortie = NULL;
    if (lexeme_courant.nature == L_EOF)
    {
        fprintf(stderr, "Erreur Syntaxique : boucle non fermée\n");
        exit(32);
    }
    if (lexeme_courant.nature == COMMENTAIRE)
    {
        lexeme_courant = reconnaissance();
        return suite_expr_boucle(A, B);
    }


    if (lexeme_courant.nature == DONE)
    {
        *A = creer_operation(NULL, N_F_B_AST);
    } else if (lexeme_courant.nature == DO)
    {
        lexeme_courant = reconnaissance();
        suite_expr_boucle(&boucle, A);
        lexeme_courant = reconnaissance();
        suite_expr_boucle(&suiv, B);
        *A = creer_boucle(suiv, boucle);
        creer_fin(A);
    } else
    {
        type_ast type = caract();
        lexeme_courant = reconnaissance();
        suite_expr_boucle(&suiv, B);
        *A = creer_operation(suiv, type);
    }
}

void suite_expression(ast_t **A)
{
    ast_t *suiv = NULL, *boucle = NULL;
    type_ast type;

    if (lexeme_courant.nature == L_EOF)
    {
        return;
    }
    if (lexeme_courant.nature == COMMENTAIRE)
    {
        lexeme_courant = reconnaissance();
        suite_expression(A);
        return;
    }

    if (lexeme_courant.nature == DO)
    {
        type = N_BOUCLE_AST;
        lexeme_courant = reconnaissance();
        suite_expr_boucle(&boucle, A);
        lexeme_courant = reconnaissance();
        suite_expression(&suiv);
        *A = creer_boucle(suiv, boucle);
        creer_fin(A);

    } else if (lexeme_courant.nature == DONE)
    {
        fprintf(stderr, "Erreur syntaxique : Fin de boucle\n");
        exit(31);
    } else
    {
        type = caract();
        lexeme_courant = reconnaissance();
        suite_expression(&suiv);
        *A = creer_operation(suiv, type);
    }
}

void expr(ast_t **A)
{
    lexeme_courant = reconnaissance();
    suite_expression(A);
}

void analyser(char *filename)
{
    initialiser(filename);
    ast_t *a = NULL;
    expr(&a);
    evaluation(a);
    fin();
}