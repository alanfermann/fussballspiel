#include <stdio.h>

int readInt(){
	int a;
	scanf("%d", &a);
	return a;
}

int spiel(int punktzahl, int spieltage){
	if(punktzahl>spieltage*3 || punktzahl ==0)
		return 0;


	else{
		int konstellationen =0;
		int gewonnen, unentschieden, verloren;

		for(int i=0; i<=punktzahl/3; i++){
			gewonnen = i;
			unentschieden =punktzahl-3*i;
			verloren = spieltage-gewonnen - unentschieden;

			int spiele=gewonnen+unentschieden+verloren;

			if(spiele==spieltage && verloren >=0){
				printf("Gewonnen: %d, unentschieden: %d, verloren: %d \n", gewonnen, unentschieden, verloren);
				konstellationen++;
			}
		}

		return konstellationen;
	}
}

int main(){
	int punkte, tage;
	printf("Geben Sie die Anzahl der Punkte ein: \n");
	punkte=readInt();
	printf("Geben sie die Anzahl der Spieltage ein:\n");
	tage=readInt();

	int anzKonstellationen=spiel(punkte, tage);
	if(anzKonstellationen ==0)
		printf("Keine sinnvollen Konstellationen möglich.\n");
	else if(anzKonstellationen==1)
		printf("Das ist die einzige mögliche Konstellation");
	else
		printf("Das sind %d unterschiedliche mögliche Konstellationen.\n", anzKonstellationen);

	return 0;
}
