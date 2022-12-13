all : KNN_uni

KNN_uni : logement.o KNN_uni.o
	gcc -o KNN_uni logement.o KNN_uni.o -lm

logement.o : logement.c
	gcc -c logement.c

KNN_uni.o : KNN_uni.c
	gcc -c KNN_uni.c
	
all : KNN_2

KNN_2 : logement_tab.o logement.o KNN_2.o
	gcc -o KNN_2 logement_tab.o logement.o KNN_2.o -lm

logement_tab.o : logement_tab.c 
	gcc -c logement_tab.c

KNN_2.o : KNN_2.c
	gcc -c KNN_2.c
	
all : KNN_bonus

KNN_bonus : logement_bonus.o logement_tab.o logement.o KNN_bonus.o
	gcc -o KNN_bonus logement_bonus.o logement_tab.o logement.o KNN_bonus.o -lm
	
logemnt_bonus.o : logement_bonus.c
	gcc -c logement_bonus.c

KNN_bonus.o : KNN_bonus.c
	gcc -c KNN_bonus.c


