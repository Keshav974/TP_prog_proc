#include "logement.h"
#include <time.h>

Logement choix_log(void) /* fonction qui renvoie un Logement dont les caractéristiques sont affectés par l'utilisateur */
{
	printf("Entrez les caractéristiques du logement x\n");
	Logement x;
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

char* choix_chemin() /* fonction qui renvoie un chaine de caractère pour préciser le chemin ou le nom du fichier */
{
	char *chemin = malloc(1000*sizeof(char));
	printf("Chemin du tableau contenant les informations sur les logements (ou le nom du fichier, exemple : airbnb_donnees_propre.csv): \n");
	scanf("%s",chemin);
	return chemin;
}

int tableau_logement(Logement *tableau,char chemin[200]) // fonction qui prend en argument le chemin du fichier contenant les informations ainsi que l'adresse d'un tableau de Logements
											 // qui permet de rentrer toutes les données des logements (sauf les distances) dans le tableau de Logements et qui renvoie la taille du tableau
{
	char *nom_colonne = malloc(100 * sizeof(char));  /* on alloue de la mémoire pour la première ligne ne contenant pas d'infos importantes*/
	FILE* fp = fopen(chemin,"r"); 

	if (fp == NULL)
	{
		fprintf(stderr,"Erreur lors de l'ouverture du fichier\n");
		exit(-1);
	}

	fgets(nom_colonne,100,fp); /* on récupère la première ligne inutile pour ensuite pouvoir s'occuper directement des chiffres après*/
	free(nom_colonne);

	Logement log;
	int i = 0;
	int n;
	while ((n = fscanf(fp,"%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",&log.number,&log.accomodates,&log.bedrooms,&log.bathrooms,&log.beds,&log.price,&log.minimum_nights,&log.maximum_nights,&log.number_of_reviews)) > 0)
	{                      /* n correspond au nombre d'éléments correctements lues donc tant qu'on lit des éléments on les rajoute dans le tableau jusqu'à ce qu'il y en ait plus */
		tableau[i] = log; /* On récupère chaque caractéristique dans un ordre précis et on remplit notre tableau avec */
		i = i+1;
	}
	
	fclose(fp);
	return i;
}


double dist(double a, double b) /* fonction qui prend en argument 2 mêmes caractéristiques entre 2 logement différents et calcule la distance entre les deux */
{
	return sqrt(pow(a-b,2));
}

int choix_critere(void) /* renvoie un nombre qui permet à l'utilisateur de choisir la caractéristique à comparer */
{
	int choix;
	printf("Choisissez la caractéristique qui détermine la distance de similarité :\n1 : accomodates, 2 : bedrooms, 3 : bathrooms, 4 : beds, 5 : minimum_nights, 6 : maximum_nights, 7 : number_of_reviews\n");
	scanf("%d",&choix);
	return choix;
}

int choix_afficher(void) /* renvoie un nombre pris en compte par d'autres fonctions, qui permet ou non à l'utilisateur d'afficher les résultat*/
{
	int choix;
	scanf("%d",&choix);
	return choix;
}

void tableau_distance(Logement *tab,Logement x, int taille, int choix) /* fonction qui prend en argument le tableau de logements, sa taille et un logement x et
																		et qui permet de renseigner la distance de chaque logement du tableau par rapport à x
																		selon la caractéristique choisie par l'utilisateur */
{
	printf("Voulez-vous affichez chaque distance ?\n1 : oui, 2: non\n");
	int afficher = choix_afficher();
	if (choix == 1) /*accomodates*/
	{
		double carac = x.accomodates;
		for (int j = 0; j < taille; j++)
		{
			tab[j].distance = dist(carac,tab[j].accomodates);
			if (afficher == 1)
			{
				printf("n° logement : %d | distance : %lf\n",tab[j].number,tab[j].distance);
			}
		}
	} 
	if (choix == 2) /*bedrooms*/
	{
		double carac = x.bedrooms;
		for (int j = 0; j < taille; j++)
		{
			tab[j].distance = dist(carac,tab[j].bedrooms);
			if (afficher == 1)
			{
				printf("n° logement : %d | distance : %lf\n",tab[j].number,tab[j].distance);
			}
		}
	} 
	if (choix == 3) /*bathrooms*/
	{
		double carac = x.bathrooms;
		for (int j = 0; j < taille; j++)
		{
			tab[j].distance = dist(carac,tab[j].bathrooms);
			if (afficher == 1)
			{
				printf("n° logement : %d | distance : %lf\n",tab[j].number,tab[j].distance);
			}
		}
	} 
	if (choix == 4) /*beds*/
	{
		double carac = x.beds;
		for (int j = 0; j < taille; j++)
		{
			tab[j].distance = dist(carac,tab[j].beds);
			if (afficher == 1)
			{
				printf("n° logement : %d | distance : %lf\n",tab[j].number,tab[j].distance);
			}
		}
	} 
	if (choix == 5) /*minimum_nights*/
	{
		double carac = x.minimum_nights;
		for (int j = 0; j < taille; j++)
		{
			tab[j].distance = dist(carac,tab[j].minimum_nights);
			if (afficher == 1)
			{
				printf("n° logement : %d | distance : %lf\n",tab[j].number,tab[j].distance);
			}
		}
	} 
	if (choix == 6) /*maximum_nights*/
	{
		double carac = x.maximum_nights;
		for (int j = 0; j < taille; j++)
		{
			tab[j].distance = dist(carac,tab[j].maximum_nights);
			if (afficher == 1)
			{
				printf("n° logement : %d | distance : %lf\n",tab[j].number,tab[j].distance);
			}
		}
	} 
	if (choix == 7) /* number_of_reviews */
	{
		double carac = x.number_of_reviews;
		for (int j = 0; j < taille; j++)
		{
			tab[j].distance = dist(carac,tab[j].number_of_reviews);
			if (afficher == 1)
			{
				printf("n° logement : %d | distance : %lf\n",tab[j].number,tab[j].distance);
			}
		}
	} 
}


void randomiser(Logement *tab,int taille) /* fonction qui prend un tableau de logement ainsi que sa taille et le randomise*/
{
	srand(time(NULL)); /* on définit une seed pour la fonction rand, comme cette seed change tout le temps (temps qui avance) la fonction rand n'en renverra jamais les mêmes suites de valeurs*/
	for(int k = 0; k < taille; k++)  /* on échange chaque tab[i] avec un élément du tableau déterminé aléatoirement */
	{	
		int j = rand() % taille ;
		Logement temp = tab[k];
		tab[k]=tab[j];
		tab[j] = temp;
	}
}


void permuter(Logement *a, Logement *b) { /* fonction qui permute 2 logements à partir de leurs adresses*/
    Logement tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void tri_rapide(Logement *tab,int taille) /* fonction tri rapide qui prend en argument un tableau de logement et sa taille*/
{
	tri_rapide_aux(tab,0,taille-1); /* comme on veut trier tout le tableau on prend les indices de la première et de la dernière valeur */
}

void tri_rapide_aux(Logement *tab, int deb, int fin) /* fonction tri rapide qui prend en argument un tableau de logement et 
													l'intervalle et les indices délimitant le sous tableau que l'on souhaite trier
													*/
 {
    if(deb < fin) 
	{
        int ind_pivot = deb;
        int i = deb;
    	int j = fin;
        while (i < j) /* si i<j alors tous les éléments à gauche de l'élément d'indice i sont inférieurs ou égal au pivot
						et tous tous les éléments à droite de l'élément d'indice j sont strictement supérieur au pivot*/
		{
            while(tab[i].distance <= tab[ind_pivot].distance && i < fin) /* cherche l'indice du premier élément qui est strictement supérieur au pivot en partant de la gauche */
                {
					i = i + 1;
				}
            while(tab[j].distance > tab[ind_pivot].distance)  /* cherche l'indice du premier élément qui est inférieur ou égal au pivot en partant de la droite */
                {
					j = j - 1;
				}
            if(i < j) {
                permuter(&tab[i], &tab[j]); /* on permute les deux logements ainsi */
            }
        }
        permuter(&tab[ind_pivot], &tab[j]); /* on place le pivot le plus à droite possible dans les éléments inférieurs ou égaux au pivot pour séparer le tableau en 2*/

        tri_rapide_aux(tab, deb, j - 1); /* on recommence pour les deux sous-tableaux crées */
        tri_rapide_aux(tab, j + 1, fin);
    }
}

int* choix_k(int nb_k) /* fonction qui renvoie l'adresse d'un tableau contenant les nb_k k valeurs choisies par l'utilisateur*/
{
	int *tab_k = malloc(nb_k*sizeof(int));
	for (int i = 0; i < nb_k; i++)
	{
		printf("k n°%d :\n",i + 1);
		scanf("%d", &tab_k[i]);
	}
	return tab_k;
}

double prediction_prix(Logement *tab, int taille, int k, int afficher) /* fonction qui prédit le prix estimé à partir d'un tableau de Logements tab
															dont les distances par rapport à un logement x on déjà été affectés, de sa taille 
															et d'un entier k qui détermine le nombre d'éléments triés de tab que l'on prend en compte pour la moyenne*/
{	int a = 10;
	if (k > taille)
	{ 
		fprintf(stderr, "k trop grand !\n");
		exit(-1);
	}
	randomiser(tab,taille); /* on randomise le tableau pour éviter que le trie classe les logements toujours dans le même ordre*/
	tri_rapide(tab,taille); /* on trie les logements en fonction de leur distance par ordre croissant */
	double somme = 0; 
	for (int i = 0; i<k; i++) /* enfin on calcule la moyenne du prix des k premiers éléments du tableau trié- */
	{
		somme = somme + tab[i].price;
		if (afficher == 1) /* si la variable afficher vaut 1 on afficher les k valeurs triées */
		{
			printf("n° : %d | distance : %lf | price : %lf \n", tab[i].number, tab[i].distance, tab[i].price);
		}
	}
	return somme/(double)k;
}