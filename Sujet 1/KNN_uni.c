#include "logement.h"

int main(void) 
{
	Logement *tab = malloc(10000*sizeof(Logement)); /* on alloue arbitrairement assez de mémoire pour pouvoir rentrer toutes les valeurs dans le taleau*/
	char *chemin = choix_chemin(); /* l'utilisateur choisi le fichier en entrant le chemin ou son nom */
	int taille = tableau_logement(tab,chemin); /* création du tableau + on récupère sa taille*/
	Logement x = choix_log(); /* l'utilisateur rentre les caractéistiques de son Logement */
	int choix = choix_critere(); /* l'utilisateur choisi la caractéristique qui défini la distance */
	tableau_distance(tab,x,taille,choix); /* on affecte les distances de chaque logement par rapport à x */

	int afficher;
	int nb_k;
	printf("Combien de k voulez-vous tester ?\n");  /* l'utilisateur choisit le nombre de k qu'il veut tester*/
	scanf("%d", &nb_k);
	int *tab_k = choix_k(nb_k); /* l'utilisateur choisit les k qu'il veut tester */

	for (int *k = tab_k; k < &tab_k[nb_k]; k++) /* pour chaque k on indique le prix estimé et on propose à l'utilisateur d'afficher les k premières valeurs*/
	{
		printf("Voulez-vous afficher les k = %d premières valeurs triées ?\n 1 : oui, 2 : non\n",*k);
		afficher = choix_afficher();
		double rep = prediction_prix(tab,taille,*k,afficher);
		printf("Prix prédit pour %d valeurs : %lf\n\n",*k,rep); 
	} 
	return 0;
}	