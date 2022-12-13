#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// Caractérisation d'un processus

typedef struct processus processus;
struct processus
{
    char nom[50];
    int duree;
    int priorite;
};

// Caractérisation de l'ordonnanceur : Un ordonnanceur est une file de processus (un processus est un élément de la file).
typedef struct Element Element;     // on définit les éléments de la file comme étant des processus    
struct Element
{
    processus process;
    Element *suivant;
};

typedef struct File File;           // on caractérise l'ordonnanceur comme étant une file de processus
struct File
{
    Element *premier;
};


// Fonctions utilisées
File *initialiser(); // cette fonction permet d'initialiser l'ordonnanceur (la file qu'on va utiliser)
void ajout_activite(File *file,processus activite); // cette fonction permet d'ajouter un processus à la file (ordonnanceur)
void step(File *file); // cette fonction permet de faire un tour d'ordonnanceur, si la file est vide on ne fait rien (0 processus déclaré) sinon on ajoute un processus et on l'exécute en affichant son nom et sa durée
void run(File *file); // cette fonction itère step jusqu'à avoir une file vide c'est à dire un ordonnancement complet

