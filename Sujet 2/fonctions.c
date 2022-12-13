#include "fonctions.h"
#include <unistd.h>

/* On initialise la file utilisée pour l'ordonnancement */
File *initialiser()
{
    File *file = malloc(sizeof(*file));
    file->premier = NULL;

    return file;
}

/* On ajoute les processus en paramètre à la file de l'ordonnanceur */
void ajout_activite(File *file,processus activite){

    Element *nouveau = malloc(sizeof(*nouveau));
    strcpy(nouveau->process.nom,activite.nom);
    nouveau->process.duree=activite.duree;
    nouveau->process.priorite=activite.priorite;
    nouveau->suivant=NULL;
    if (file->premier != NULL) 
    {
        
        Element *elementActuel = file->premier;
        while (elementActuel->suivant != NULL)
        {
            elementActuel = elementActuel->suivant;
        }
        elementActuel->suivant = nouveau;
    }
    else 
    {
        file->premier = nouveau;
    }
    
}

/* On fait un tour d'ordonnanceur, si la file est vide on ne fait rien et on l'affiche, sinon on ajoute un processus et on l'execute*/
void step(File *file)
{
    processus newprocess;

      if (file->premier==NULL)
    {   
        printf("La file est vide\n");
    }

    if (file->premier != NULL)
    {
        Element *elementDefile = file->premier;

        strcpy(newprocess.nom,elementDefile->process.nom);
        newprocess.duree=elementDefile->process.duree;
        newprocess.priorite=elementDefile->process.priorite;
        file->premier = elementDefile->suivant;
        free(elementDefile);
    }

    printf("Processus %s en cours d'execution. Duree d'execution : %d s\n",newprocess.nom,newprocess.duree);
    sleep(newprocess.duree);
}




/* On itère step jusqu'à avoir une file vide */

void run(File *file){
    if (file->premier==NULL)
    {   
        printf("La file est vide\n");
    }
    while(file->premier!=NULL){
        step(file);
    }
}


