#include "logement_tab.h"

Logement_tab choix_log_tab(void) /* fonction qui renvoie un Logement_tab dont les caractéristiques sont affectés par l'utilisateur */
{
	printf("Entrez les caractéristiques du logement x\n");
	Logement_tab x;
	printf("accomodates :\n");
	scanf("%lf",&x.accomodates);
	printf("bedrooms :\n");
	scanf("%lf",&x.bedrooms);
	printf("bathrooms :\n");
	scanf("%lf",&x.bathrooms);
	printf("beds :\n");
	scanf("%lf",&x.beds);
	printf("minimum_nights :\n");
	scanf("%lf",&x.minimum_nights);
	printf("maximum_nights :\n");
	scanf("%lf",&x.maximum_nights);
	printf("number_of_reviews :\n");
	scanf("%lf",&x.number_of_reviews);
	return x;
}

int tableau_logement_2(Logement_tab *tableau,char chemin[200]) /* fonction qui fait comme tableau_logement mais avec la structure améliorée tableau de Logement_tab */
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

	while ((n = fscanf(fp,"%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",&log.number,&log.accomodates,&log.bedrooms,&log.bathrooms,&log.beds,&log.price,&log.minimum_nights,&log.maximum_nights,&log.number_of_reviews)) > 0)
	{
		tableau[i] = log;
		i = i+1;
	}
	
	fclose(fp);
	return i;
}

Logement transformer(Logement_tab x) /* fonction qui prend en argument un Logement_tab et renvoie sa version logement 
									 en remplaçant son tableau de distance par la distance euclidienne voulue */
{
	Logement log = {x.number,x.accomodates,x.bedrooms,x.bathrooms,x.beds,x.price,x.minimum_nights,x.maximum_nights,x.number_of_reviews,dist_abb(x.distance)};
	return log;
}

Logement* tableau_distance_all(Logement_tab *tab,Logement_tab x, int taille) /* fonction qui affecte pour chaque Logement_tab sa distance par rapport au Logement_tab x
																		     et pour chaque caractéristique et qui renvoie l'adresse du tableau de Logements 
																		     où les distance correspondent à la distance euclidienne souhaité */
{
	Logement *tableau = malloc(taille*sizeof(Logement));
    double carac_acc = x.accomodates; /* toutes les caractéristiques sont converties en double */
	double carac_bedrooms = x.bedrooms;
    double carac_bathrooms = x.bathrooms;
	double carac_beds = x.beds;
	double carac_min_nights = x.minimum_nights;
	double carac_max_nights = x.maximum_nights;
	double carac_nb_reviews = x.number_of_reviews;
	printf("Voulez-vous affichez chaque distance (la distance euclidienne est calculée selon les caractéristiques accomodate, bedrooms, beds)?\n1 : oui, 2: non\n");
	int afficher = choix_afficher(); /* on demande à l'utilisateur s'il veut afficher les distances et distances euclidiennes voulues */

	for (int j = 0; j < taille; j++)
	{
        (tab[j].distance)[0] = dist(carac_acc,tab[j].accomodates);
		(tab[j].distance)[1] = dist(carac_bedrooms,tab[j].bedrooms);
        (tab[j].distance)[2] = dist(carac_bathrooms,tab[j].bathrooms);
		(tab[j].distance)[3] = dist(carac_beds,tab[j].beds);
		(tab[j].distance)[4] = dist(carac_min_nights,tab[j].minimum_nights);
		(tab[j].distance)[5] = dist(carac_max_nights,tab[j].maximum_nights);
		(tab[j].distance)[6] = dist(carac_nb_reviews,tab[j].number_of_reviews);

		tableau[j] = transformer(tab[j]);
		
		if (afficher == 1)
		{
			printf("n° logement : %d | distances [%lf,%lf,%lf,%lf,%lf,%lf,%lf] | distance euclidienne : %lf\n", tab[j].number,tab[j].distance[0],tab[j].distance[1],tab[j].distance[2],tab[j].distance[3],tab[j].distance[4],tab[j].distance[5],tab[j].distance[6],tableau[j].distance);
		}
		
	}
	return tableau;
}

void afficher_carac(Logement_tab x) /* fonction affichant toutes les distances d'un Logement_tab par rapport à x */
{
	printf("dist accomodates : %lf\n",(x.distance)[0]);
	printf("dist bedrooms : %lf\n",(x.distance)[1]);
	printf("dist bathrooms : %lf\n",(x.distance)[2]);
	printf("dist beds : %lf\n",(x.distance)[3]);
	printf("dist price : %lf\n",(x.distance)[4]);
	printf("dist min nights : %lf\n",(x.distance)[5]);
	printf("dist max nights : %lf\n",(x.distance)[6]);
	printf("dist nb reviews : %lf\n",(x.distance)[7]);
}

double dist_abb(double *tab) /* fonction qui prend en argument l'adresse d'un tableau contenant les distances pour chaque caractéristique par rapport à x
							 et renvoie la distance euclidienne selon accomodate, bedrooms et beds */
{
	return sqrt(pow(tab[0],2) + pow(tab[1],2) + pow(tab[3],2));
}





