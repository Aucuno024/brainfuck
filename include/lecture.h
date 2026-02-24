//
// Created by jolyne on 21/02/25.
//

#ifndef LECTURE_H
#define LECTURE_H

#endif //LECTURE_H
/**
 *Ouvre le fichier en parametre dans le pointeut global au fichier "f"
 *@param filename le nom du fichier
 ***/
void initialiser(char const *filename);
/**
 *Lit le caractère suivant du fichier f si il est initalisé
 *@param c pointeur vers un caractere pour le retour de lecture
 **/
void lecture(char *c);
/**
 *Ferme le fichier f si il a été ouvert
 **/
void fin();
