# Projet Brainfuck

## Description
Ce projet implémente un interpréteur et un analyseur lexical pour le langage Brainfuck. Il inclut des outils pour analyser, interpréter et tester des programmes écrits en Brainfuck, avec prise en charge de différentes syntaxes (ASCII et décimale).

## Structure du projet
- C : Contient les fichiers source pour l'analyse lexicale, syntaxique et l'interprétation du langage Brainfuck.
- src: Fichiers sources
- include: Fichier d'en-tete
## Fichiers principaux
- `lexique.h` : Définit les types et structures pour l'analyse lexicale.
- `Makefile` : Automatisation de la compilation des différents exécutables.

## Compilation
Pour compiler le projet, utilisez la commande suivante :
make

Cela génère les exécutables suivants :
- `brainfuck` : Interpréteur Brainfuck pour la syntaxe ASCII.
- `brainfuckd` : Interpréteur Brainfuck pour la syntaxe décimale.
- `analyse_lexicale` : Analyseur lexical pour Brainfuck.

Pour nettoyer les fichiers compilés :
make clean

## Utilisation
### Analyse lexicale
Pour analyser un fichier Brainfuck :
./analyse_lexicale chemin/vers/fichier.b

### Interprétation
Pour exécuter un programme Brainfuck en syntaxe ASCII :
./brainfuck chemin/vers/fichier.b

Pour exécuter un programme Brainfuck en syntaxe décimale :
./brainfuckd chemin/vers/fichier.b

## Dépendances
- Compilateur C : gcc
- C: C99 ? 
## Auteur
Créé par Chloé Briquet et Marie Aubert.

Watashi no na wa “kirayoshikage” nenrei 33-sai jitaku wa moriōchō hokutō-bu no bessō chitai ni ari…
kekkon wa shite inai… shigoto wa “kameyūchēn-ten” no kaishain de mainichi osokutomo yoru 8-ji made
ni wa kitaku suru tabako wa suwanai sake wa tashinamu teido yoru 11 tokiniha yuka ni tsuki kanarazu
8-jikan wa suimin o toru yō ni shite iru… nerumae ni atatakai miruku o nomi 20-bu hodo no sutoretchi
de karada o hogushite kara yuka ni tsuku to hotondo asamade jukusui-sa… akanbō no yō ni hirō ya 
sutoresu o nokosazu ni asa-me o samaseru nda… kenkōshinda demo ijō nashi to iwa reta yo 
