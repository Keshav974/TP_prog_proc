#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

struct Logement /* structure logement qui reprend ses caractéristiques présentes dans le fichier avec les logements 
				mais aussi sa distance par rapport au logement dont on souhaite prédire le prix
				*/
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
	double distance;
};

typedef struct Logement Logement;

Logement choix_log(void);

char* choix_chemin(void);

int tableau_logement(Logement *tab,char chemin[200]);

double dist(double a, double b);

int choix_critere(void);

int choix_afficher(void);

void tableau_distance(Logement *tab,Logement x, int taille, int choix);

void randomiser(Logement *tab,int taille);

void replacer(Logement *tab,int init,int fin);

void trier(Logement *tab,int taille);

void trier_aux(Logement *tab,int deb,int fin);

void permuter(Logement *a, Logement *b) ;

void tri_rapide(Logement *tab, int taille);

void tri_rapide_aux(Logement *tab, int first, int last) ;

int* choix_k(int nb_k);

double prediction_prix(Logement *tab, int taille, int k, int afficher);
