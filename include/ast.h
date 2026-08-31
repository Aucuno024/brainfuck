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

/**
 * @fn ast_t *creer_boucle(ast_t *apres, ast_t *boucle)
 * @brief concactene deux AST pour qu'ils puisse etre interpreté comme une boucle
 * @param apres la suite de l'AST une fois sorti de la boucle
 * @param boucle le corps de la boucle
 * @return un AST pouvant etre interpreté comme une boucle
 */
ast_t *creer_boucle(ast_t *apres, ast_t *boucle);

/**
 * @fn ast_t *creer_operation(ast_t *suiv, type_ast nature)
 * @brief cree une operation d'un certain type et en fait la racine d'un AST
 * @param suiv l'enfant du nouvel AST
 * @param nature le type d'operation qui va etre effectue
 * @return un nouvel AST contenant l'operation et continuant sur son enfant
 */
ast_t *creer_operation(ast_t *suiv, type_ast nature);

/**
 * @fn ast_t *creer_condition(ast_t *si, ast_t* sinon)
 * @brief cree un noeud operation de type condition
 * @param si la branche a suivre si l'evaluation est vrai
 * @param sinon la branche a suivre si l'evaluation est fausse
 * @return un AST de type condition qui choisit sur quel branche continuer
 */
ast_t *creer_condition(ast_t *si, ast_t* sinon);

/**
 * @fn void evaluation(ast_t *A)
 * @brief evalue un AST
 * @param A l'AST a evaluer
 */
void evaluation(ast_t *A);

/**
 * @fn void creer_fin(ast_t **retour)
 * @brief defini un AST de fin
 */
void creer_fin(ast_t **retour);

/**
 * @fn void afficher_ast(ast_t *A)
 * @brief affiche dans la sortie standard un AST
 * @param A un AST
 */
void afficher_ast(ast_t *A);

#endif //AST_H
