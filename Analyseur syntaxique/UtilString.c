#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int calcLength (char *c1) {
	int i, cmp=0;

	for (i=0; c1[i]!='\0'; i++) {
		cmp++;
	}

	return cmp;
}

void aff (char *c1) {
	int i;

	for (i=0; c1[i]!='\0'; i++) {
		printf("%c",c1[i]);
	}

	printf("\n");
}

void verif_et_recup_arg(int nb, char *arguments[], int nb_souhaite, char *chaine) {
	if(nb != nb_souhaite){
		printf("Usage : lignes nom_fichier\n");
		exit(1);
	}

	strcpy(chaine, arguments[1]);
}

/*int main(int argc, char *argv[]) {
	FILE *fic; 
	int nb_lignes;
	char ligne_lue[512];
	char nom_fic[255];
	char *fichier;

	verif_et_recup_arg(argc, argv, 2, nom_fic);
	
	// ouverture du fichier
	fic = fopen(nom_fic, "r"); // ouvrir en lecture
	if(fic == NULL){
			printf("Impossible d'ouvrir le fichier %s\n", nom_fic);
			exit(1);
	}
	printf(".............. Ouverture du fichier %s\n", nom_fic);

	// compter et afficher les lignes du fichier
	nb_lignes = 0;
	while (fgets(ligne_lue, 512, fic) != NULL){
		//printf("\t%s", ligne_lue);
		//fichier+=ligne_lue;
		nb_lignes++;
	}
	printf("le fichier %s comporte %d lignes\n", nom_fic, nb_lignes);

	// fermeture du fichier
	if (fclose(fic) == EOF) {
			printf("Probleme de fermeture du fichier %s", nom_fic);
			exit(1);
	}
	printf (".............. Fermeture du fichier %s\n", nom_fic);

	return 0;
}*/

char *copieFinChaine (char *c1, char *c2, char *c3) { /*c1 = cha�ne 1, c2 = cha�ne 2, cha�ne destinataire.*/
	int i=0, j=0; //j : variable de boucle c2.

	int cmp1=0, cmp2=0;

	for (i=0; c1[i]!='\0'; i++) {
		cmp1++;
	}
	for (i=0; c2[i]!='\0'; i++) {
		cmp2++;
	}

	//printf("\ncmp1 = %d\ncmp2 = %d\ncmp1+cmp2 = %d\n",cmp1,cmp2,cmp1+cmp2);
	
	c3 = malloc((cmp1+cmp2)*sizeof(char));

	//aff(c3);

	j=0;
	for (i=0; i<cmp1; i++) {
		c3[j]=c1[i];

		j++;
	}
	//aff(c3);

	for (i=0; i<cmp2; i++) {
		c3[j]=c2[i];

		j++;
	}
	c3[j] = '\0';
	//aff(c3);

	return c3;
}

char *copieDebutChaine (char *c2, char *c1, char *c3) { /*c2 = cha�ne 1, c1 = cha�ne 2, cha�ne destinataire.*/
	int i=0, j=0; //j : variable de boucle c2.

	int cmp1=0, cmp2=0;

	for (i=0; c1[i]!='\0'; i++) {
		cmp1++;
	}
	for (i=0; c2[i]!='\0'; i++) {
		cmp2++;
	}

	//printf("\ncmp1 = %d\ncmp2 = %d\ncmp1+cmp2 = %d\n",cmp1,cmp2,cmp1+cmp2);
	
	c3 = malloc((cmp1+cmp2)*sizeof(char));

	//aff(c3);

	j=0;
	for (i=0; i<cmp1; i++) {
		c3[j]=c1[i];

		j++;
	}
	//aff(c3);

	for (i=0; i<cmp2; i++) {
		c3[j]=c2[i];

		j++;
	}
	c3[j] = '\0';
	//aff(c3);

	return c3;
}

char *coupeStr (char *c1, char *c2, int x, int y) { /* on coupe le string de x � y inclu.*/
	int i,j, cmp=0, length=0;

	//printf("\ny - x = %d\n",y-x);

	for (i=0; c1[i]!='\0'; i++) {
		cmp++;
	}

	length=cmp;

	//printf("\ncmp = %d\n",cmp);

	j=0;

	for (i=x; i<y; i++) {
		c2[j] = c1[i];

		j++;
	}

	c2[j] = '\0';

	return c2;
}

int main () {
	char c1[] = "abcdefgh";
	char c2[] = "ijklmnop";

	char *c3;
	char *c4;
	char *c5;

	c3 = copieFinChaine(c1,c2,c3);
	//c3 = copieDebutChaine(c1,c2,c3);

	aff(c3);
	
	aff(coupeStr(c1,c4,0,3));
	aff(coupeStr(c2,c5,0,3));

	//printf("\nlength(c3) = %d\n",calcLength(c3));

	return 0;
}
