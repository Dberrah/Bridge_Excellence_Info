#ifndef MECANIQUE
#define MECANIQUE
//c'est un fichier qui rg=egourpe lesfonction et les variables pour les mécanismes
//du jeu. Par exemple tout ce qui est vérification de cartes, choix de cartes etc...
//Mais aussi le comptage des points etc...
/*utilisé*/short compteurAjoutDansCartePossible;//(peut être à retirer).
/*utilisé*/int indiceDeRetour; //utiliser dans les fonctions
/*utilisé*/short tour; //compteur qui donnera
/*utilisé*/int defaussage; //variable temporaire nul permettant seulement de defausser une carte.
/*Utilisé*/int atoutVoulu;//determine si il y a un atout. (soit  soit  s'il y n'y en a pas )
/*utilisé*/short avecAtout; //utlisé dans la fonction de cartePossibleAjouer

/*utilisé*/short carteDejaJouer1 [13];//va enregistrer les indices des cartes deja choisies par le joueur
/*utilisé*/short carteDejaJouer2 [13];//idem
/*utilisé*/short carteDejaJouer3 [13];//idem
/*utilisé*/short carteDejaJouer4 [13];//idem

/*Initialisé*/short *paquetDeCarteDejaJouerPointer [4];//enregistre les pointeurs des paquets de cartes deja untiliser.

//va enregistrer le nombre de plis gagner par chaque joueur sachant que les joueurs de la même pârité sont dans un même groupe
short plisJoueur [4];

short plisPaquetImpaire;
short plisPaquetPaire;

/*utilisé*/short *nombreDeJoueur [4]; //permet de terminer qui jouera en premier. il stockera les pointeurs des differents joueurs.
/*utilisé*/short *nombreDeJoueurCouleur [4]; // garde les pointers des tableaus contenant les paquet de cartes colorés.

/*utilisé*/short *paquetBis [4];//stock les pointeurs des paquets bis de chaques joueur.

/*utilisé*/short carteSurTableCarte [4]; //les cartes jouer. Garde seulement l'indice de la valeur de la carte. (allant de 0 à 12)
/*utilisé*/short carteSurTableCouleur [4];//idem mais pour les couleurs.

/*utilisé*/short carteSurTableAvantTraitement [4];//Permet d'afficher les cartes présentes sur la table avant le traintement
/*utilisé*/short carteSurTableAvantTraitementCouleur[4];//Permet d'afficher la couleur des cartes présentes sur la table avant le traintement


/*utilisé*/short paquetdeCarteJoueurbis1 [13];//paquet de carte secondaire permettant d'effacer plus tard les cartes jouer par les joueurs
/*utilisé*/short paquetdeCarteJoueurbis2 [13];//idem
/*utilisé*/short paquetdeCarteJoueurbis3 [13];//idem
/*utilisé*/short paquetdeCarteJoueurbis4 [13];//idem

/*utilisé*/short cartePossible [13]; //stockera les cartes qui pourront être jouer selon le tour.
/*utilisé*/short cartePossibleCouleur [13]; //idem mais pour les couleurs des cartes.

/*utilisé*/short ordreDeJeu [4];//enregistre l'ordre des joueur pour le tour.

//fonction

/*fait*/void ajouterCarteDansCartePossible (short combien);//(peut etre a retirer)
/*fait*/void retirerCarteDuPaquet (short *paquetDeCarteNom, short *paquetDeCarteCouleur, short indice);

/*fait*/void afficherCarte (short *paquetDeCarte,short *paquetDeCarteCouleur, int nombreDeCarte,char *nomDesCartes [], char *couleurDesCartes []);//affiche des cartes
/*fait*/void afficherCarteChoisit (char* nomCarte [], char* nomCouleurCarte [], short *paquetNom, short *paquetCouleur, short ou);

/*entrain d'être fait*/void afficherToutesLesCartes ();

/*fait*/void cartePossibleAjouer (short *paquetDeCarte,short *paquetDeCarteCouleur, short couleur, short combien, short *paquetBis,short pAvecAtout, short pAtout);//remplit le paquet de carte possible avec les cartes possibles (il n'y a qu'un seul paquet pour les 4 joueurs)

/*fait*/short carteSurTableMemeCouleur (short *paquetDeCarteSurTableCouleur, short couleur);//renvoie 1 si toute les cartes sont de la même couleur 0 sinon.

/*fait*/short cartePresente (short *paquetDeCarte,short couleur, short nombreCarte);//Pseudo boolean, retourne 1 si la couleur de la carte existe dans le paquet sinon 0.
/*fait*/short atoutPresent (short *paquetCouleur , short atout, short combien);//dit si l'atout est présent
/*fait*/short carteMemeCouleur (short *paquetDeCarte , short couleurDeLaCarte);//retourne 1 si toutes les cartes dans les paquet de cartes sur tables possède la même couleur
/*fait*/short choisirCarte (short *paquetDeCarte);//retourne l'indice de la carte qu'à choisi le joueur.
/*fait*/short choisirCarteCouleur (short *paquetCouleur);//retourne l'indice de la carte.
/*fait*/short choisirAtout (int *pAtout);//fonction qui va permettre à chaque joueur de c
/*fait*/short retourIndicePaquetBis (short *paquetDeCarteBis, short ou);
/*fait*/short verificationIndiceDejaChoisit (short *paquetDeCarte, short input,short nombreDeCarte);// return 1 si l'indice existe deja dans le paquet en question

/*fait*/void initialisationNombreJoueur (short *p1, short *p2, short *p3, short *p4);//initialise le tableau avec les pointeurs des cartes
/*fait*/void initialisationCartePossible ();
/*fait*/void initialisationOrdreDesJoueur (short premierJoueur);
/*fait*/void initialisationPaquetBis (short *paquet);
/*fait*/void initialisationNombreDeJoueur ();
/*fait*/void initialisationNombreDeJoueurCouleur ();
/*fait*/void initialisationPaquetBisPointeur ();//enregistre dans paquetBis les adresses des différents paquet bis des joueurs.
/*fait*/void initialisationPaquetDeCarteDejaJouer (short *paquetDeCarte);
/*fait*/void initialisationPaquetDeCarteDejaJouerPointer();
/*fait*/short getCarte (short *tableau, short ou);//permet de retourner une carte dans un paquet de carte

/*fait*/void ajouterDansPaquetBis (short *paquet, short ou , short quoi);//permet d'enregistrer dans le paquet de carte bis.
/*fait*/short carteLaPlusHaute(short *paquetDeCartes);//retoure l'indice du joueur qui vient de gagner


/*fait*/void champDeBataille (char* nomDesCartes [], char* couleurDesCartes [], short *p1, short *pc1,short *p2, short *pc2,short *p3, short *pc3,short *p4, short *pc4,short *pg, short *pgc, short atoutVoulu);

//stop

#endif
