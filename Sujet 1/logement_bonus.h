#include "logement_tab.h"

int tableau_logement_bonus(Logement_tab *tableau,char chemin[200]);

double dist_bonus(double* tab);

Logement* tableau_distance_all_bonus(Logement_tab *tab,Logement_tab x, int taille);

Logement transformer_bonus(Logement_tab x);

double mae(Logement_tab *TabTest, double *tabPrediction, int taille);
