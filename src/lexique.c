//
// Created by jolyne on 21/02/25.
//
#include<stdio.h>
#include<stdlib.h>
#include "lecture.h"
#include "lexique.h"


/**
 * Utilise les fonctions de lecture_fichier afin de lire dans le fichier ouvert (si il existe)
 *des lexèmes du langage brainfuck.
 *
 * @return un lexème dont la nature convient à l'interpretation du caracctère lu
 */
lexeme_t reconnaissance()
{
    char c;
    lexeme_t lexeme_courant;
    lecture(&c);
    switch (c)
    {
        case '>':
            lexeme_courant.nature = DECALAGE_DROIT;
            break;
        case '<':
            lexeme_courant.nature = DECALAGE_GAUCHE;
            break;
        case EOF:
            lexeme_courant.nature = L_EOF;
            break;
        case '+':
            lexeme_courant.nature = INCR;
            break;
        case '-':
            lexeme_courant.nature = DECR;
            break;
        case '.':
            lexeme_courant.nature = SORTIE;
            break;
        case ',':
            lexeme_courant.nature = ENTREE;
            break;
        case '[':
            lexeme_courant.nature = DO;
            break;
        case ']':
            lexeme_courant.nature = DONE;
            break;
        default:
            lexeme_courant.nature = COMMENTAIRE;
            break;
    }
    lexeme_courant.chaine[0] = c;
    return lexeme_courant;
}


/**
 * Donne la représentation en tableau de caractère d'un lexeme passé en argument si celui-ci possède une nature.
 * @param lexeme un lexème avec une nature définie
 * @return une représentation en tableau de caractère de la nature de lexeme
 */
char *lexemets(lexeme_t lexeme)
{
    switch (lexeme.nature)
    {
        case DO:
            return "DO";
        case DONE:
            return "DONE";
        case DECALAGE_DROIT:
            return "DECALAGE_DROIT";
        case DECALAGE_GAUCHE:
            return "DECALAGE_GAUCHE";
        case INCR:
            return "INCREMENTE";
        case DECR:
            return "DECREMENTE";
        case ENTREE:
            return "ENTREE";
        case SORTIE:
            return "SORTIE";
        case COMMENTAIRE:
            return "COMMENTAIRE";
        default:
            return "";
    }
}


/**
 * Affiche dans la sortie standard la nature du lexème passé en argument
 * @param lexeme un lexème avec une nature définie.
 **/
void afficher(lexeme_t lexeme)
{
    printf("[Nature : %s, chaine : %s]\n", lexemets(lexeme), lexeme.chaine);
}



void analyse_lex(char *filename)
{
    initialiser(filename);
    lexeme_t lexeme_courant;
    do
    {
        lexeme_courant = reconnaissance();
        if (lexeme_courant.nature != L_EOF) afficher(lexeme_courant);
    }while (lexeme_courant.nature != L_EOF);
    fin();
}