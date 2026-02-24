//
// Created by jolyne on 17/03/25.
//

#ifndef AST_H
#define AST_H
#define debug(fmt, ...) \
            do { if (DEBUG) fprintf(stderr, fmt, ##__VA_ARGS__); } while (0)
typedef enum
{
    N_BOUCLE_AST = '[',
    N_F_B_AST = ']',
    N_ENTREE = ',',
    N_SORTIE = '.',
    N_DEPLACEMENT_M = '<',
    N_DEPLACEMENT_P = '>',
    N_MODIF_P = '+',
    N_MODIF_M = '-',
    N_IF,
    N_THEN,
    N_ELSE
} type_ast;
typedef struct ast
{
    type_ast operation;
    struct ast *astg, *astd;
    int p_cond;
}ast_t;

ast_t *creer_boucle(ast_t *apres, ast_t *boucle);
ast_t *creer_operation(ast_t *suiv, type_ast nature);
ast_t *creer_condition(ast_t *si, ast_t* sinon);
void evaluation(ast_t *A);
void creer_fin(ast_t **retour);
//void creer_suite(ast_t **cond, ast_t *suite);
void afficher_ast(ast_t *A);
#endif //AST_H
