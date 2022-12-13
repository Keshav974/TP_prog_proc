#include "fonctions.h"


int main(void){

  // initialisation de l'ordonnanceur, c'est à dire une file vide 
  File *maFile= initialiser();
  

  // initialisation du tableau de processus rempli par l'utlisateur et qui sera ensuite trié
  int nombre_processus;
  processus tableau_processus[nombre_processus]; 


  // utilisées dans l'algorithme de tri :
  int i,j;
  processus temp;   


  /* Saisie des caractéristisques des processus dans le terminal par l'utilisateur*/
  printf("******************************************************\nBienvenue dans l'ordonnanceur de Keshav et de Romain !\n******************************************************\n↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓\nEntrez le nombre de processus : ");
  scanf("%d", &nombre_processus);
  printf("%d\n",nombre_processus);
  
  for(int k=0;k<nombre_processus;k++){
    printf("Entrez le nom du processus %d : \n",k+1);
    scanf("%49s",&tableau_processus[k].nom);
    printf("puis sa durée en s :");
    scanf("%d",&tableau_processus[k].duree);
    printf("finalement sa priorité :");
    scanf("%d",&tableau_processus[k].priorite);
  }

  /* Tri des processus par ordre de priorité, utilisation de la méthode de tri par insertion */
  for (i=1 ; i <= nombre_processus-1; i++) {
  j = i;
    while (j > 0 && tableau_processus[j-1].priorite > tableau_processus[j].priorite) {
      temp= tableau_processus[j];
      tableau_processus[j] = tableau_processus[j-1];
      tableau_processus[j-1] = temp;
      j--;
    }
  }

  /* Utilisation de l'ordonnanceur */
  
  for(int k=0;k<nombre_processus;k++){                  // On remplit la file avec les différents processus
    ajout_activite(maFile,tableau_processus[k]);
  }                                                     

  run(maFile);                                          // On défile en exécutant les processus un à un par ordre de priorité                                        
  
  printf("L'éxécution des processus est terminée !\n");

  return 0;
}

