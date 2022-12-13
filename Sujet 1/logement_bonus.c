#include "logement_bonus.h"

int tableau_logement_bonus(Logement_tab *tableau,char chemin[200]) /* même chose que tableau_logement_2 à l'exception que la caractéristique price est la dernière */
{
	char *nom_colonne = malloc(100 * sizeof(char));
	FILE* fp = fopen(chemin,"r");

	if (fp == NULL)
	{
		fprintf(stderr,"Erreur lors de l'ouverture du fichier");
		exit(-1);
	}

	fgets(nom_colonne,100,fp);
	Logement_tab log;
    int i = 0;
	int n;
	

	while ((n = fscanf(fp,"%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",&log.number,&log.accomodates,&log.bedrooms,&log.bathrooms,&log.beds,&log.minimum_nights,&log.maximum_nights,&log.number_of_reviews,&log.price)) > 0)
	{
        {
		tableau[i] = log;
		i = i+1;
		}
	}

    fclose(fp);
    return i;
}

double dist_bonus(double* tab) /* calcule la distance euclidienne selon toutes les distances par rapport à x dans le tableau en paramètre */
{
	return sqrt(pow(tab[0],2) + pow(tab[1],2) + pow(tab[2],2) + pow(tab[3],2) + pow(tab[4],2) + pow(tab[5],2) + pow(tab[6],2));
}

Logement* tableau_distance_all_bonus(Logement_tab *tab,Logement_tab x, int taille) /* meme fonction que tableau_distance_all sauf que la caractéristique price est la dernière et on utilise transformer_bonus*/
{
    Logement *tableau = malloc(taille*sizeof(Logement));
    double carac_acc = x.accomodates;
	double carac_bedrooms = x.bedrooms;
    double carac_bathrooms = x.bathrooms;
	double carac_beds = x.beds;
	double carac_min_nights = x.minimum_nights;
	double carac_max_nights = x.maximum_nights;
	double carac_nb_reviews = x.number_of_reviews;

	for (int j = 0; j < taille; j++)
	{
        (tab[j].distance)[0] = dist(carac_acc,tab[j].accomodates);
		(tab[j].distance)[1] = dist(carac_bedrooms,tab[j].bedrooms);
        (tab[j].distance)[2] = dist(carac_bathrooms,tab[j].bathrooms);
		(tab[j].distance)[3] = dist(carac_beds,tab[j].beds);
		(tab[j].distance)[4] = dist(carac_min_nights,tab[j].minimum_nights);
		(tab[j].distance)[5] = dist(carac_max_nights,tab[j].maximum_nights);
		(tab[j].distance)[6] = dist(carac_nb_reviews,tab[j].number_of_reviews);

        tableau[j] = transformer_bonus(tab[j]);
	}
    return tableau;
}

Logement transformer_bonus(Logement_tab x) /* même fonction que transformer mais celle-ci s'adapte à la distance définie au-dessus */
{
	Logement log = {x.number,x.accomodates,x.bedrooms,x.bathrooms,x.beds,x.price,x.minimum_nights,x.maximum_nights,x.number_of_reviews,dist_bonus(x.distance)};
	return log;
}

double mae(Logement_tab *tabTest, double *tabPrediction, int taille) /* fonction qui calcule la MAE d'un tableau de prix prédits par rapport aux prix réels */
{
    double somme = 0;
    for (int i = 0; i < taille; i++)
    {
        somme = somme + sqrt(pow(tabTest[i].price - tabPrediction[i],2));
    }
    return somme / (double) taille;
}

