#include "logement.h"

struct Logement_tab /* on change la structure d'un logement pour qu'elle puisse contenir cette fois sa distance pour chaque caractéristique du logement qu'on étudie */
{
	int number;
	double accomodates;
	double bedrooms;
	double bathrooms;
	double beds;
	double price;
	double minimum_nights;
	double maximum_nights;
	double number_of_reviews;
	double distance[7];
};

typedef struct Logement_tab Logement_tab;

Logement_tab choix_log_tab(void);

int tableau_logement_2(Logement_tab *tableau,char chemin[200]);

Logement* tableau_distance_all(Logement_tab *tab,Logement_tab x, int taille);

void afficher_carac(Logement_tab x);

double dist_abb(double *tab);

Logement transformer(Logement_tab x);

