Voici les programmes permettant de répondre aux questions du sujet 1:

KNN_uni.c traite le cas ou l'on souhaite prédire le prix d'un logement à l'aide de distances calculées par 	rapport à UNE caractéristique. Pour cela on a besoin du fichier d'en-tête logement.h qui définit la structure Logement

KNN_2. traite du cas où les distances sont calculées à l'aide de plusieurs caractéristiques et donc on a besoin pour cela de modifier la structure pour qu'elle puisse posséder plus distances. Pour cela il faut le fichier d'en-tête logement_tab.h qui définit la structure Logement_tab et en adaptant à cette structure des fonctions utilisées précédemment pour la structure Logement. La distance ici correspond à la distance euclidienne selon les caractéristiques: accomodates, bedrooms, beds

KNN_bonus traite de la partie bonus et a besoin kdu fichier d'en-tête logement_bonus.h pour adapter les fonctions présentes dans logement_tab.h aux nouveaux tableaux sources qui ont la particularité d'avoir le prix après les autres caractéristiques contrairement au premier tableau. Le promgramme est néanmoins un peu lent et donc tester beaucoup de k différents est un peu long. La distance ici correspond à la distance euclidienne selon toutes les caractéristiques.

Veuillez vous servir de la commande make dans un terminal, pour éxéctuer les différents programmes
