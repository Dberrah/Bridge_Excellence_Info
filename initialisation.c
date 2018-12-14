#include <stdlib.h>
#include <time.h>
#include "initialisation.h"
#include <stdio.h>

char* nomCouleurCarte [] = {"Trèfle","Carreau","Coeur","Pique"};//4
char* nomCarte [] = {"2","3","4","5","6","7","8","9","10","Valet","Reine","Roi","As"};//13

short verificationCarteDejaUtiliser(short nom1, short nom2) {

    compteurInterne = 0;

    while (compteurInterne < JEU_DE_CARTE) {

        if (nom1==paquetDeCarteDejaUtiliser[compteurInterne] && nom2==paquetDeCarteDejaUtiliserCouleur[compteurInterne])
            return 1;

        compteurInterne++;
    }

    return 0;
}
short generationNombreAleatoire(short n) {

    return rand()%n;
}
void ajoutCarte (short *paquetNom,short *paquetCouleur,short al1,short al2,short ou) {

    paquetNom[ou] = al1; //nom de la carte.
    paquetCouleur[ou] = al2; //couleur carte
}
void ajoutCarteDansPaquetDejaUtiliser(short al1, short al2) {

    paquetDeCarteDejaUtiliser [indice] = al1; //nom de la carte
    paquetDeCarteDejaUtiliserCouleur [indice] = al2;//couleur de la carte

    indice ++;
}

void initialisationCouleurDesCartes (short *paquet) {

    compteur = 0;
    compteurDeCouleursDeCartes = 0;

    while (compteur < JEU_DE_CARTE) {

        paquet [compteur] = compteurDeCouleursDeCartes;

        compteurDeCouleursDeCartes++;
        compteur++;

        if (compteurDeCouleursDeCartes > 3)
            compteurDeCouleursDeCartes = 0;
    }
}
void initialisationPaquetDeCarteGlobale() {

    compteur = 0;
    compteurInterne = 0;

    while (compteurInterne < JEU_DE_CARTE) {

        if (compteur > 12)
            compteur = 0;

        paquetDeCarteGlobale [compteurInterne] = compteur;

        compteurInterne++;
        compteur++;
    }
}
void initialisationPaquetDeCarteUtiliser() {

    compteur = 0;

    while (compteur < JEU_DE_CARTE) {


        paquetDeCarteDejaUtiliser [compteur] = -1;

        compteur++;
    }
}

void initialisationPaquetDeCarteUtiliserCouleur() {

    compteur = 0;

    while (compteur <JEU_DE_CARTE) {

        paquetDeCarteDejaUtiliserCouleur[compteur] = -1;

        compteur++;
    }
}

void distributionCarte (short *paquetNom, short *paquetCouleur) {

    if (entreFonction == 0) {

        initialisationCouleurDesCartes(paquetDeCarteGlobaleCouleur);
        initialisationPaquetDeCarteGlobale();
        initialisationPaquetDeCarteUtiliser();
        initialisationPaquetDeCarteUtiliserCouleur();

        entreFonction++;
        srand(time(0));
        indice = 0;
    }

    compteur = 0;

    while (compteur <= nombreDeCarte) {


        nombreAleatoire1 = generationNombreAleatoire(51);

        nombreAleatoire2 = generationNombreAleatoire(51);

        carteTirer = paquetDeCarteGlobale[nombreAleatoire1];//varie entre 0 et 12
        couleurTirer = paquetDeCarteGlobaleCouleur [nombreAleatoire2];//varie entre 0 et 3

        if (verificationCarteDejaUtiliser(carteTirer,couleurTirer)==1)
            compteur--;

        else {

            ajoutCarte(paquetNom,paquetCouleur,carteTirer,couleurTirer,compteur);
            ajoutCarteDansPaquetDejaUtiliser(carteTirer,couleurTirer);
        }

        compteur++;
    }
}

void initialisationVariable (short carteNombre, short modeJeu) {

    indice = 0;
    nombreDeCarte = carteNombre;
    modeDeJeu = modeJeu;
    entreFonction = 0;
}
void initialisationImportanceDesCartes (short *paquet) {

    short compteurTab =0;//comptera les cases ira jusqu'à J
    short compteurImp =1;//comptera les importances
    short compteurDe4=1;

    while (compteurTab<4) {

        paquet [compteurTab] = 13;
        compteurTab++;
    }

    while (compteurTab < JEU_DE_CARTE) {


        paquet [compteurTab] = compteurImp;
        compteurDe4++;

        if (compteurDe4>4) {

            compteurImp++;
            compteurDe4 = 1;
        }

        compteurTab ++;
    }
}
