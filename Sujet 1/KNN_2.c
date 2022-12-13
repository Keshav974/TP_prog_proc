#include "logement_tab.h"


int main(void)
{
    Logement_tab *tab = malloc(10000*sizeof(Logement_tab)); /* on alloue arbitrairement assez de mémoire pour pouvoir rentrer toutes les valeurs dans le taleau*/
    char *chemin = choix_chemin(); /* l'utilisateur choisi le fichier en entrant le chemin ou son nom */
    int taille = tableau_logement_2(tab,chemin); /* création du tableau de Logement_tab + on récupère sa taille*/
    Logement_tab x = choix_log_tab(); /* l'utilisateur rentre les caractéistiques de son Logement */
    Logement *tab_dist_abb;
    tab_dist_abb = tableau_distance_all(tab,x,taille);  /* on affecte les distances et on définit en même temps le même tableau mais dont les distances des Logements
                                                        sont des doubles (la distance euclidienne par rapport à x selon accomodate, bedroom et beds) */

    int afficher;
	int nb_k;
	printf("Combien de k voulez-vous tester ?\n"); /* l'utilisateur choisit le nombre de k qu'il veut tester*/
	scanf("%d", &nb_k);
	int *tab_k = choix_k(nb_k); /* l'utilisateur choisit les k qu'il veut tester */

	for (int *k = tab_k; k < &tab_k[nb_k]; k++) /* pour chaque k on indique le prix estimé et on propose à l'utilisateur d'afficher les k premières valeurs*/
	{
		printf("Voulez-vous afficher les k = %d premières valeurs triées ?\n 1 : oui, 2 : non\n",*k);
		afficher = choix_afficher();
		double rep = prediction_prix(tab_dist_abb,taille,*k,afficher);
		printf("Prix prédit pour %d valeurs : %lf\n\n",*k,rep); 
	} 
	return 0;
}