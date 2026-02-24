//
// Created by jolyne on 21/02/25.
//

#ifndef LEXIQUE_H
#define LEXIQUE_H
#endif //LEXIQUE_H
typedef enum
{
    DECALAGE_DROIT,
    DECALAGE_GAUCHE,
    INCR,
    DECR,
    DO,
    DONE,
    SORTIE,
    ENTREE,
    COMMENTAIRE,
    L_EOF,
    IF,
    THEN,
    ELSE,
} type_lexeme;


typedef struct lexeme
{
    char chaine[2];
    type_lexeme nature;
} lexeme_t;

/**
 * Effectue l'analyse lexicale du brainfuck sur un fichier
 * @param filename une chaine de caractère représentant le chemin vers un fichier
 **/
void analyse_lex(char *filename);

/**
 * Utilise les fonctions de lecture_fichier afin de lire dans le fichier ouvert (si il existe)
 *des lexèmes du langage brainfuck.
 * @return un lexème dont la nature convient à l'interpretation du caracctère lu
 */
lexeme_t reconnaissance();