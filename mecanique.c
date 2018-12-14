#include "mecanique.h"
#include "initialisation.h"
#include <stdio.h>
//Fichier qui regroupera toute les mecanismes du jeu tels que les battaile etc...

short compteurAjoutDansCartePossible = 0;
short indiceDeRetourPourPaquetBis = -1;

static void sauter (int combien) {//permet de sauter des lignes

    int compteurSauter = 0;

    while (compteurSauter <= combien) {

        printf("\n");
        compteurSauter++;
    }
}
short getCarte (short *tableau, short ou) {

    return tableau [ou];
}

void initialisationNombreJoueur(short *p1, short *p2, short *p3, short *p4) {

    nombreDeJoueur[0] = p1;
    nombreDeJoueur[1]= p2;
    nombreDeJoueur[2] = p3;
    nombreDeJoueur[3]= p4;
}
void initialisationCartePossible (){

    short compteurIni = 0;

    while (compteurIni <= 12) {

        cartePossible[compteurIni] = -1;
        cartePossibleCouleur [compteurIni] = -1;
        compteurIni++;
    }
}
void initialisationOrdreDesJoueur(short premierJoueur) {

    short compteurOrdre = 0;

    while (compteurOrdre <= 3) {

        if (premierJoueur >3)
            premierJoueur = 0;


        ordreDeJeu[compteurOrdre] = premierJoueur;

        compteurOrdre++;
        premierJoueur++;
    }
}
void initialisationPaquetBis (short *paquet) {

    short compteurPaquetBis = 0;

    while (compteurPaquetBis <= 12) {

        paquet[compteurPaquetBis] = -1;

        compteurPaquetBis++;
    }
}
void initialisationNombreDeJoueur () {

    nombreDeJoueur [0] = paquet1;
    nombreDeJoueur [1] = paquet2;
    nombreDeJoueur [2] = paquet3;
    nombreDeJoueur [3] = paquet4;
}
void initialisationNombreDeJoueurCouleur() {

    nombreDeJoueurCouleur [0] = paquet1couleur;
    nombreDeJoueurCouleur [1] = paquet2couleur;
    nombreDeJoueurCouleur [2] = paquet3couleur;
    nombreDeJoueurCouleur [3] = paquet4couleur;
}
void initialisationPaquetBisPointeur () {

    paquetBis[0] = paquetdeCarteJoueurbis1;
    paquetBis[1] = paquetdeCarteJoueurbis2;
    paquetBis[2] = paquetdeCarteJoueurbis3;
    paquetBis[3] = paquetdeCarteJoueurbis4;
}
void initialisationPaquetDeCarteDejaUtiliser () {

    paquetDeCarteDejaJouerPointer [0] = carteDejaJouer1;
    paquetDeCarteDejaJouerPointer [1] = carteDejaJouer2;
    paquetDeCarteDejaJouerPointer [2] = carteDejaJouer3;
    paquetDeCarteDejaJouerPointer [3] = carteDejaJouer4;
}
void initialisationPaquetDeCarteDejaJouer (short *paquetDeCarte) {

    short compteurPaquet = 0;

    while (compteurPaquet <= 12) {

        paquetDeCarte [compteurPaquet] = -1;

        compteurPaquet++;
    }
}
void initialisationPaquetDeCarteDejaJouerPointer() {

    paquetDeCarteDejaJouerPointer[0]= carteDejaJouer1;
    paquetDeCarteDejaJouerPointer[1]= carteDejaJouer2;
    paquetDeCarteDejaJouerPointer[2]= carteDejaJouer3;
    paquetDeCarteDejaJouerPointer[3]= carteDejaJouer4;
}
void afficherCarte (short *paquetDeCarte,short *paquetDeCarteCouleur, int nombreDeCarte,char *nomDesCartes [], char *couleurDesCartes []) {

    int compteurAfficherCarte = 0;

    while (compteurAfficherCarte <= nombreDeCarte) {

        if (paquetDeCarte[compteurAfficherCarte] == -1)
            printf("**********\n");
        else
            printf ("(%d) %s de %s \n", compteurAfficherCarte +1,nomDesCartes[paquetDeCarte[compteurAfficherCarte]],couleurDesCartes[paquetDeCarteCouleur[compteurAfficherCarte]]);

        compteurAfficherCarte++;
    }
}
void afficherCarteChoisit (char* nomCarte [], char* nomCouleurCarte [], short *paquetNom, short *paquetCouleur, short ou) {

    printf("Vous avez Choisi la carte : %s de %s \n", nomCarte[paquetNom[ou]],nomCouleurCarte[paquetCouleur[ou]]);
}

void afficherToutesLesCartes () {

    short compteurInterneAfficherLesCartes = 0;


    printf ("Joueur %d\t\t\tJoueur %d\t\t\tJoueur %d\t\t\tJoueur %d\n", ordreDeJeu[0]+1, ordreDeJeu[1]+1,ordreDeJeu[2]+1,ordreDeJeu[3]+1);

    sauter(2);

    while (compteurInterneAfficherLesCartes < 13) {

        if (getCarte(nombreDeJoueurCouleur[ordreDeJeu[0]], compteurInterneAfficherLesCartes) <= -1)
            printf ("**********      ");
        else
            printf ("%s de %s      ",nomCarte[getCarte(nombreDeJoueur[ordreDeJeu[0]], compteurInterneAfficherLesCartes)],nomCouleurCarte[getCarte(nombreDeJoueurCouleur[ordreDeJeu[0]],compteurInterneAfficherLesCartes)]);

        if (getCarte(nombreDeJoueurCouleur[ordreDeJeu[1]], compteurInterneAfficherLesCartes) <= -1)
            printf ("\t\t**********      ");
        else
            printf ("\t\t%s de %s      ",nomCarte[getCarte(nombreDeJoueur[ordreDeJeu[1]], compteurInterneAfficherLesCartes)],nomCouleurCarte[getCarte(nombreDeJoueurCouleur[ordreDeJeu[1]],compteurInterneAfficherLesCartes)]);

        if (getCarte(nombreDeJoueurCouleur[ordreDeJeu[2]], compteurInterneAfficherLesCartes) <= -1)
            printf ("\t\t**********      ");
        else
            printf ("\t\t%s de %s      ",nomCarte[getCarte(nombreDeJoueur[ordreDeJeu[2]], compteurInterneAfficherLesCartes)],nomCouleurCarte[getCarte(nombreDeJoueurCouleur[ordreDeJeu[2]],compteurInterneAfficherLesCartes)]);

        if (getCarte(nombreDeJoueurCouleur[ordreDeJeu[3]], compteurInterneAfficherLesCartes) <= -1)
            printf ("\t\t**********\n");
        else
            printf ("\t\t%s de %s \n",nomCarte[getCarte(nombreDeJoueur[ordreDeJeu[3]], compteurInterneAfficherLesCartes)],nomCouleurCarte[getCarte(nombreDeJoueurCouleur[ordreDeJeu[3]],compteurInterneAfficherLesCartes)]);

        compteurInterneAfficherLesCartes++;
    }
}

void cartePossibleAjouer (short *paquetDeCarte,short *paquetDeCarteCouleur, short couleur, short combien, short *paquetBis, short pAvecAtout, short pAtout) {

    if (pAvecAtout == 0){

        initialisationCartePossible();//initialise à -1 toutes les cases du tableau.

        short compteurCartePossibleAjouer = 0;
        short compteurCarte = 0;

        while (compteurCartePossibleAjouer <= combien ) {

            if (paquetDeCarteCouleur[compteurCartePossibleAjouer]==couleur) {

                cartePossible[compteurCarte] = paquetDeCarte[compteurCartePossibleAjouer];
                cartePossibleCouleur[compteurCarte] = paquetDeCarteCouleur[compteurCartePossibleAjouer];

                paquetBis[compteurCarte] = compteurCartePossibleAjouer;

                compteurCarte++;
            }

            compteurCartePossibleAjouer++;
        }
    }else{

        initialisationCartePossible();

        short compteurCartePossibleAjouer = 0;
        short compteurCarte = 0;

        while (compteurCartePossibleAjouer <= combien) {

            if (paquetDeCarteCouleur[compteurCartePossibleAjouer] == couleur || paquetDeCarteCouleur [compteurCartePossibleAjouer] == pAtout) {

                cartePossible[compteurCarte] = paquetDeCarte[compteurCartePossibleAjouer];
                cartePossibleCouleur[compteurCarte] = paquetDeCarteCouleur[compteurCartePossibleAjouer];

                paquetBis[compteurCarte] = compteurCartePossibleAjouer;

                compteurCarte++;
            }

            compteurCartePossibleAjouer++;
        }
    }
}

void ajouterCarteDansCartePossible (short combien) {

    cartePossible [compteurAjoutDansCartePossible] = combien;
    compteurAjoutDansCartePossible++;
}
void ajouterDansPaquetBis (short *paquet, short ou , short quoi) {

    paquet[ou] = quoi;
}
short retourIndicePaquetBis (short *paquetDeCarteBis, short ou) {

    return paquetDeCarteBis[ou];
}

void retirerCarteDuPaquet (short *paquetDeCarteNom, short *paquetDeCarteCouleur, short indice) {

    paquetDeCarteNom [indice] = -1;
    paquetDeCarteCouleur [indice] = -1;
}

short cartePresente (short *paquetDeCarte,short couleur, short nombreCarte) {

    short compteurCartePresente = 0;

    while (compteurCartePresente <= nombreCarte) {

        if (paquetDeCarte[compteurCartePresente] == couleur)
            return 1;

        compteurCartePresente++;
    }

    return 0;
}
short atoutPresent (short *paquetCouleur , short atout, short combien) {

    if (atout == -1)
        return 0;

    short compteurAtoutPresent = 0;

    while (compteurAtoutPresent <= combien) {

        if (paquetCouleur[compteurAtoutPresent]== atout)
            return 1;

        compteurAtoutPresent++;
    }

    return 0;
}
short carteMemeCouleur (short *paquetDeCarte , short couleurDeLaCarte) {

    short compteurCarteMemeCouleur = 0;

    while (compteurCarteMemeCouleur < 4) {

        if (paquetDeCarte[compteurCarteMemeCouleur]!= couleurDeLaCarte)
            return 0;

        compteurCarteMemeCouleur++;
    }

    return 1;
}
short choisirCarte(short *paquetDeCarte) {

    indiceDeRetour = -1;

    printf ("Veuillez choisir une carte parmis les cartes possibles : ");
    scanf ("%d",&indiceDeRetour);
    indiceDeRetourPourPaquetBis = indiceDeRetour-1;

    return paquetDeCarte [indiceDeRetourPourPaquetBis];
}
short choisirCarteCouleur (short *paquetCouleur) {

    return paquetCouleur [indiceDeRetourPourPaquetBis];
}
short carteSurTableMemeCouleur (short *paquetDeCarteSurTableCouleur, short couleur) {

    short compteurCarteSurTable = 0;

    while (compteurCarteSurTable <=3) {

        if (paquetDeCarteSurTableCouleur [compteurCarteSurTable] != couleur)
            return 0;

        compteurCarteSurTable++;
    }

    return 1;
}
short carteLaPlusHaute(short *paquetDeCartes) {//retrourne la case gagnante

    short gagnant = -1;

    if (paquetDeCartes[0] >= paquetDeCartes[1] && paquetDeCartes[0]>= paquetDeCartes[2] &&paquetDeCartes[0]>=paquetDeCartes[3])
         gagnant = 0;
    else if (paquetDeCartes[1] >= paquetDeCartes[0] && paquetDeCartes[1]>= paquetDeCartes[2] &&paquetDeCartes[1]>= paquetDeCartes[3])
         gagnant =1;
    else if (paquetDeCartes[2] >= paquetDeCartes[0] && paquetDeCartes[2]>=paquetDeCartes[1] &&paquetDeCartes[2]>=paquetDeCartes[3])
         gagnant =2;
     else if (paquetDeCartes[3] >= paquetDeCartes[0] && paquetDeCartes[3]>= paquetDeCartes[1] &&paquetDeCartes[3]>= paquetDeCartes[2])
         gagnant =3;

    return gagnant;
}
short choisirAtout(int *pAtout) {

    short compteurChoisirAtout = -1;

    printf ("(%d) Pas d'atout. \n", compteurChoisirAtout+1);

    compteurChoisirAtout++;

    while (compteurChoisirAtout <=3) {

        printf ("(%d) %s \n",compteurChoisirAtout+1,nomCouleurCarte[compteurChoisirAtout]);
        compteurChoisirAtout++;
    }
    sauter(1);

    printf ("Veuillez choisir un atout : ");
    scanf("%d", pAtout);

    if (*pAtout >=5 || *pAtout <=-1) {

        if (*pAtout >= 5) {

            printf ("ERREUR : Vous avez choisit un nombre superieur aux choix proposés.\n");

        }else if (*pAtout<=-1){

             printf ("ERREUR : Vous avez choisit un nombre inferieur aux choix proposés.\n");
        }
    }

    sauter(1);

    return *pAtout = *pAtout-1;
}
int verificationCarteJouable(short *paquetDeCarte, short ou, short indiceMaxTableau) {

    if (ou < 0 || ou > indiceMaxTableau)
        return 0;

    else if (paquetDeCarte [ou] == -1)
        return 0;

    return 1;
}

void champDeBataille (char* nomDesCartes [], char* couleurDesCartes[], short *p1, short *pc1,short *p2, short *pc2,short *p3, short *pc3,short *p4, short *pc4,short *pg, short *pgc, short pAtout) {


        short compteurTour = 0;
        short compteurGlobalChampDeBataille = 0;//compte le nombre de tour.
        short couleurImposer;
        short compteurDefauchage = 0;
        plisPaquetImpaire = 0;
        plisPaquetPaire = 0;

        avecAtout = 0;

        tour = 0;

        initialisationNombreDeJoueur();
        initialisationNombreDeJoueurCouleur();

       /* initialisationPaquetBisPointeur();

        initialisationPaquetDeCarteDejaJouer(carteDejaJouer1);
        initialisationPaquetDeCarteDejaJouer(carteDejaJouer2);
        initialisationPaquetDeCarteDejaJouer(carteDejaJouer3);
        initialisationPaquetDeCarteDejaJouer(carteDejaJouer4);
       */

        while (compteurGlobalChampDeBataille <= 12) {

            compteurTour = 0;

            initialisationCartePossible();//initialise le paquet de carte possible à 0
            initialisationNombreDeJoueur();// initialise le tableau avec les pointeurs des paquet de cartes des joueurs.
            initialisationNombreDeJoueurCouleur();//idem mais pour les paquets de carte couleurs
            initialisationOrdreDesJoueur(tour);//initialise l'ordre des joueurs a partir d'un premier nombre compris entre 0 et 3
            initialisationPaquetBisPointeur();//initialise les pointers dans le tableau des pointeurs du paquets bis
            initialisationPaquetBis(paquetBis[ordreDeJeu[compteurTour]]);//initialise le paquetBis du joueur en question

            printf("**********Tour %d********** \n",compteurGlobalChampDeBataille+1);
            sauter (2);

            afficherToutesLesCartes();

            sauter(2);

            printf ("---Joueur %d--- :\n", ordreDeJeu[compteurTour]+1);
            sauter(1);


            afficherCarte(nombreDeJoueur [ordreDeJeu[compteurTour]],nombreDeJoueurCouleur[ordreDeJeu[compteurTour]],12,nomDesCartes,couleurDesCartes);
            sauter (1);


            do {

                carteSurTable [compteurTour] = choisirCarte(nombreDeJoueur[ordreDeJeu[compteurTour]]);

            }while (verificationCarteJouable(nombreDeJoueur [ordreDeJeu[compteurTour]], indiceDeRetourPourPaquetBis,12) == 0);

            carteSurTableAvantTraitement [compteurTour] = carteSurTable[compteurTour];
            carteSurTableCouleur [compteurTour] = choisirCarteCouleur(nombreDeJoueurCouleur[ordreDeJeu[compteurTour]]);
            carteSurTableAvantTraitementCouleur [compteurTour] = carteSurTableCouleur [compteurTour];

            printf ("Joueur %d : %s de %s \n", ordreDeJeu [compteurTour]+1,nomDesCartes[carteSurTableAvantTraitement[compteurTour]], couleurDesCartes[carteSurTableAvantTraitementCouleur[compteurTour]]);

            retirerCarteDuPaquet(nombreDeJoueur[ordreDeJeu[compteurTour]],nombreDeJoueurCouleur[ordreDeJeu[compteurTour]],indiceDeRetourPourPaquetBis);

            sauter(1);
            couleurImposer = carteSurTableCouleur[compteurTour];
            printf ("Couleur imposée : %s \n",couleurDesCartes[carteSurTableAvantTraitementCouleur[compteurTour]]);

            ajouterDansPaquetBis(paquetBis[ordreDeJeu[compteurTour]],0,indiceDeRetourPourPaquetBis);


            while (compteurTour < 3) {

                compteurTour++;

                initialisationPaquetBis(paquetBis[ordreDeJeu[compteurTour]]);
                initialisationCartePossible();

                sauter(2);
                afficherToutesLesCartes();
                sauter(2);

                printf ("---Joueur %d--- :\n", ordreDeJeu[compteurTour]+1);;


                sauter(2);

                afficherCarte(nombreDeJoueur[ordreDeJeu[compteurTour]], nombreDeJoueurCouleur [ordreDeJeu[compteurTour]],12,nomDesCartes,couleurDesCartes);
                sauter(1);

                if (cartePresente(nombreDeJoueurCouleur[ordreDeJeu[compteurTour]],couleurImposer,12)==1) {

                    avecAtout = 0;

                    cartePossibleAjouer(nombreDeJoueur[ordreDeJeu[compteurTour]], nombreDeJoueurCouleur [ordreDeJeu[compteurTour]],couleurImposer,12,paquetBis [ordreDeJeu[compteurTour]],avecAtout,pAtout);
                    printf ("**Carte Possible à jouer : \n");
                    sauter(1);
                    afficherCarte(cartePossible,cartePossibleCouleur,12,nomDesCartes,couleurDesCartes);
                    sauter(1);
                    //carteSurTableAvantTraitementCouleur [compteurTour] = carteSurTableCouleur [compteurTour];

                    do {

                        carteSurTable [compteurTour] = choisirCarte(cartePossible);//represente un nombre compris entre 0 et 12

                    }while (verificationCarteJouable(cartePossible, indiceDeRetourPourPaquetBis,12) == 0);

                    carteSurTableAvantTraitement [compteurTour] = carteSurTable [compteurTour];
                    carteSurTableCouleur [compteurTour] = choisirCarteCouleur(cartePossibleCouleur);//un nombre compris entre 0 et 3
                    carteSurTableAvantTraitementCouleur [compteurTour] = carteSurTableCouleur[compteurTour];
                    printf ("Joueur %d : %s de %s \n", ordreDeJeu [compteurTour]+1,nomDesCartes[carteSurTableAvantTraitement[compteurTour]], couleurDesCartes[carteSurTableAvantTraitementCouleur[compteurTour]]);
                    sauter (1);
                    retirerCarteDuPaquet(nombreDeJoueur[ordreDeJeu[compteurTour]],nombreDeJoueurCouleur[ordreDeJeu[compteurTour]],retourIndicePaquetBis(paquetBis[ordreDeJeu[compteurTour]],indiceDeRetourPourPaquetBis));

                }else{


                if (pAtout == -1) {

                        carteSurTable [compteurTour] = -1-compteurDefauchage;
                        compteurDefauchage++;
                        sauter(1);
                        printf("Vous êtes obligé de défausser une carte : \n");
                        printf("Veuillez choisir une carte dans votre paquet de carte : \n");

                        do {

                            scanf("%d",&defaussage);

                        }while (verificationCarteJouable(nombreDeJoueur[ordreDeJeu[compteurTour]], defaussage-1, 12) == 0);

                        sauter (1);

                        carteSurTableAvantTraitement [compteurTour] = getCarte(nombreDeJoueur[ordreDeJeu[compteurTour]], defaussage-1);
                        carteSurTableAvantTraitementCouleur[compteurTour] = getCarte(nombreDeJoueurCouleur[ordreDeJeu[compteurTour]], defaussage-1);

                        printf ("Joueur %d : %s de %s \n", ordreDeJeu[compteurTour]+1, nomDesCartes[carteSurTableAvantTraitement[compteurTour]], couleurDesCartes[carteSurTableAvantTraitementCouleur[compteurTour]]);

                        retirerCarteDuPaquet(nombreDeJoueur[ordreDeJeu[compteurTour]],nombreDeJoueurCouleur[ordreDeJeu[compteurTour]],defaussage-1);

                    }else{

                        avecAtout = 1;

                        sauter(1);
                        printf ("Vous avez le choix de défaussé une carte ou jouer l'atout si vous le souhaitez : \n");
                        printf("Veuillez choisir une carte dans votre paquet de carte : ");

                        do {

                            scanf("%d",&defaussage);

                        }while (verificationCarteJouable(nombreDeJoueur[ordreDeJeu[compteurTour]], defaussage-1, 12) == 0);

                        if (getCarte(nombreDeJoueurCouleur[ordreDeJeu[compteurTour]],defaussage-1) == pAtout) {

                            carteSurTableAvantTraitement [compteurTour] = getCarte(nombreDeJoueur[ordreDeJeu[compteurTour]], defaussage-1);
                            carteSurTableAvantTraitementCouleur [compteurTour] = getCarte(nombreDeJoueurCouleur[ordreDeJeu[compteurTour]], defaussage-1);
                            printf ("Vous jouez l'atout : \n");
                            printf ("Joueur %d : %s de %s \n", ordreDeJeu [compteurTour]+1,nomDesCartes[carteSurTableAvantTraitement[compteurTour]], couleurDesCartes[carteSurTableAvantTraitementCouleur[compteurTour]]);
                            carteSurTable[compteurTour] = getCarte(nombreDeJoueur[ordreDeJeu[compteurTour]], defaussage-1)+40;
                            carteSurTableCouleur [compteurTour] = getCarte(nombreDeJoueurCouleur [ordreDeJeu [compteurTour]], defaussage-1);
                            sauter(1);
                            retirerCarteDuPaquet(nombreDeJoueur[ordreDeJeu[compteurTour]],nombreDeJoueurCouleur[ordreDeJeu[compteurTour]],defaussage-1);

                        }else{

                            carteSurTable[compteurTour] = -1-compteurDefauchage;
                            compteurDefauchage++;

                            carteSurTableAvantTraitement[compteurTour] = getCarte(nombreDeJoueur[ordreDeJeu[compteurTour]], defaussage -1);

                            carteSurTableCouleur [compteurTour] = getCarte(nombreDeJoueurCouleur [ordreDeJeu[compteurTour]], defaussage-1);
                            carteSurTableAvantTraitementCouleur [compteurTour] =getCarte(nombreDeJoueurCouleur[ordreDeJeu[compteurTour]], defaussage-1);

                            printf ("Vous venez de défausser une carte. \n");
                            printf ("Joueur %d : %s de %s \n", ordreDeJeu [compteurTour]+1,nomDesCartes[carteSurTableAvantTraitement[compteurTour]], couleurDesCartes[carteSurTableAvantTraitementCouleur[compteurTour]]);
                            sauter (1);

                            retirerCarteDuPaquet(nombreDeJoueur[ordreDeJeu[compteurTour]],nombreDeJoueurCouleur[ordreDeJeu[compteurTour]],defaussage-1);
                        }
                    }
                }
            }


            tour = carteLaPlusHaute(carteSurTable);// l'indice de la case gagnante

            short compteurAffichage = 0;

            sauter (3);

            printf ("Voici les cartes jouer par les joueurs : \n");
            sauter (1);

            while (compteurAffichage <= 3) {

                printf ("Joueur %d : %s de %s \n", ordreDeJeu[compteurAffichage]+1, nomDesCartes[pg[carteSurTableAvantTraitement[compteurAffichage]]],couleurDesCartes[pgc[carteSurTableAvantTraitementCouleur[compteurAffichage]]]);
                compteurAffichage++;
		system ("clear");
            }

            sauter(1);
            printf ("Le Joueur %d a gagné ce tour \n", ordreDeJeu[tour]+1);
            sauter(2);

            if (ordreDeJeu[tour] == 1 || ordreDeJeu[tour] == 3)
                plisPaquetPaire++;
            else if (ordreDeJeu[tour] == 0 || ordreDeJeu [tour] == 2)
                plisPaquetImpaire++;

            printf ("L'equipe  paire possède %d point(s) \n", plisPaquetPaire);
            printf ("L'equipe  Impaire possède %d point(s) \n", plisPaquetImpaire);

            compteurTour = -1;
            sauter(1);
            avecAtout = 0;

            tour = ordreDeJeu[tour]; // nouvelle version de tour

            compteurGlobalChampDeBataille++;
        }
 }
