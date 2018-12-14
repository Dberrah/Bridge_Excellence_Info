#ifndef INITIALISATION
#define INITIALISATION

#define JEU_DE_CARTE 52

//compteur
short compteur;//compteur pour un paquet de carte
short compteurInterne;
short boolean;
short indice;
short entreFonction;
short compteurDeCouleursDeCartes;
short compteurGlobal; //utiliser pour la distribution et le melange des cartes
//stop

short nombreDeCarte;
short nombreAleatoire1;
short nombreAleatoire2;
short carteTirer;
short couleurTirer;
short modeDeJeu;
/*Paq totalement utilisé*/ short atout;//determine l'atout

short paquet1 [13]; //paquet de carte du joueur
short paquet1couleur [13];//paquet de couleur des cartes du joueur.

//paquet de carte des intéligeance artificielle
short paquet2 [13];
short paquet2couleur [13];
short paquet3 [13];
short paquet3couleur [13];
short paquet4 [13];
short paquet4couleur [13];
//stop

short paquetDeCarteGlobale [JEU_DE_CARTE];//le jeu de carte en soit
short paquetDeCarteGlobaleCouleur [JEU_DE_CARTE];
short paquetDeCarteDejaUtiliser [JEU_DE_CARTE];//carte déjà utilisé.
short paquetDeCarteDejaUtiliserCouleur [JEU_DE_CARTE]; //Permettera de stocker les couleurs des cartes
short importanceDesCartes [JEU_DE_CARTE];//importance des cartes allant de 1 à 13
short carteSurTable [4];//les cartes qui ont étaient joué. A modifier

//Paquet de carte permettant d'écrire les noms des cartes
extern char* nomCouleurCarte [];//Nom des couleurs allant du plus faible au plus fort
extern char* nomCarte[];//Nom des cartes en sois ex : as, 10 etc...
//stop

//fonctions

short verificationCarteDejaUtiliser (short nom1, short nom2);//fait

short generationNombreAleatoire (short n);//fait
void ajoutCarte (short *paquetNom,short *paquetCouleur,short al1,short al2,short ou);//fait
void ajoutCarteDansPaquetDejaUtiliser (short al1, short al2);
void distributionCarte (short *paquetNom, short *paquetCouleur);//fait
void distributiontoutLesPaquets(short *paq1,short *paq2,short *paq3,short *paq4);

void initialisationPaquetDeCarteGlobale ();//fait
void initialisationPaquetDeCarteUtiliser ();//fait
void initialisationVariable (short carteNombre, short modeJeu);//fait
void initialisationImportanceDesCartes (short *paquet);//fait mais seulement dans un cas spécifique, A REVOIR TRES IMPORTANT
void initialisationCouleurDesCartes (short *paquet);
void initialisationPaquetDeCarteUtiliserCouleur();
#endif
