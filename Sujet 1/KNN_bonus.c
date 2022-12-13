#include "logement_bonus.h"

int main(void)
{																	    /* Création et obtention des tailles des tableaux de Logement_tab voulus */
    Logement_tab *tabEntrainement = malloc(10000*sizeof(Logement_tab)); 
	printf("\nPour le tableau airbnbEntrainement.csv :\n");
	char *chemin_entrainement = choix_chemin(); 
    int taille_entrainement = tableau_logement_bonus(tabEntrainement,chemin_entrainement); 
	Logement_tab *tabTest = malloc(10000*sizeof(Logement_tab));
	printf("\nPour le tableau airbnbTest.csv:\n");
	char *chemin_test = choix_chemin();
	int taille_test = tableau_logement_bonus(tabTest,chemin_test);

	Logement_tab x; /* x représente les logements de tabTest */
	Logement* tabEntrainement_dist; /* tabEntrainement_dist représente le tableau des Logements après avoir calculé leur distance euclidienne par rapport à x   */
	double prix_predit; 
	double tabPrediction[taille_test]; /* tableau qui contiendra les prix prédits */
	double mae_min; 
	double mae_test; /* MAE qui sera comparée avec la MAE minimal pour chaque k */
	int k = 1; /* on initialise à 1 le nombre d'éléments pris dans le tableau trié pour calculer le prix */
	int k_min; /* k pour lequel la MAE est minimal */
	int k_max; /* L'utilisateur choisit la valeur de k max pour laquelle on calcule la MAE */
	printf("Choississez une valeur de k (k = 10 par exemple), on calculera pour tous les entiers entre 1 et k, attention pour des valeurs importantes de k l'éxécution du programme est assez longue\n");
	scanf("%d",&k_max);

	
	for (int  i = 0; i < taille_test; i++) /* on calcule les prix prédits pour k = 1*/
	{
		x = tabTest[i];
		tabEntrainement_dist = tableau_distance_all_bonus(tabEntrainement,x,taille_entrainement); /* après avoir choisi un logement x on calcule sa distance euclidienne 
																								  par rapport aux Logements_tab dans tabEntrainement */
		prix_predit = prediction_prix(tabEntrainement_dist,taille_entrainement,k,0); /* puis on calcule le prix prédit pour un x*/
		tabPrediction[i] = prix_predit; 
		free (tabEntrainement_dist);
	}
	mae_min = mae(tabTest,tabPrediction,taille_test); /* on calcule la MAE et on la définit comme étant la MAE minimal */
	k_min = 1;
	printf("Pour k = %d la MAE vaut : %lf\n",k, mae_min);


	for (int k = 2; k <= k_max; k++) /* on refait de même pour k allant de 2 jusqu'à k_max */
	{
		for (int  i = 0; i < taille_test; i++)
		{
		x = tabTest[i];
		tabEntrainement_dist = tableau_distance_all_bonus(tabEntrainement,x,taille_entrainement);
		prix_predit = prediction_prix(tabEntrainement_dist,taille_entrainement,k,0);
		tabPrediction[i] = prix_predit;
		free (tabEntrainement_dist);
		}
		mae_test = mae(tabTest,tabPrediction,taille_test);
		printf("Pour k = %d la MAE vaut : %lf\n",k, mae_test); /* on vérifie si la nouvelle MAE obtenue est plus petite */
		if (mae_test < mae_min)
		{
			mae_min = mae_test;
			k_min = k;
		}

	}
	printf("Pour k = %d on a le MAE minimal : %lf\n",k_min,mae_min);

	return 0;

}