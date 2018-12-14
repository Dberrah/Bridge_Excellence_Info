#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "initialisation.h"
#include "mecanique.h"


int main() {

    char reponse;

    printf ("Bienvenue dans le mode de jeu ouvert du bridge. \n");
    printf("A chaque tour vous sera présenté votre paquet de cartes, les cartes des autres joueurs,");
    printf(" ainsi que les autres cartes que vous pourrez jouer.\n");
    printf("\n");
    printf("Êtes-vous prêt ? (O/N) \n");


    do {

        scanf("%c", &reponse);

    }while (reponse !='o' && reponse !='O' && reponse != 'n' && reponse != 'N');

    printf("\n\n");

    if (reponse=='o' || reponse == 'O') {

    initialisationVariable(12, 0);
    distributionCarte(paquet1,paquet1couleur);
    distributionCarte(paquet2,paquet2couleur);
    distributionCarte(paquet3,paquet3couleur);
    distributionCarte(paquet4,paquet4couleur);

    do {

        choisirAtout(&atoutVoulu);

    }while (atoutVoulu < -1 || atoutVoulu >=4);

    champDeBataille(nomCarte,nomCouleurCarte,paquet1, paquet1couleur, paquet2,paquet2couleur, paquet3, paquet3couleur,paquet4,paquet4couleur,paquetDeCarteGlobale,paquetDeCarteGlobaleCouleur,atoutVoulu);

    }else{

        printf("Merci à vous !!! \n");
    }


    return 0;
}
