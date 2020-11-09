#include <stdio.h>
/***********************prototype de fonctions**************************/
int crediter(int,float);
//nouveau solde du compte en sortie en entrée numéro compte et le montant à créditer;
int debiter(int,float);
//nouveau solde du compte en sortie en entrée numéro compte et le montant à debiter;
int virement(int,float,int);
//nouveau solde du compte en sortie en entrée numéro compte source et le montant à debiter
//numero du compte destinataire
void menu(); //pas de données en entrée ni en sortie;
/*********************definition des variables*******************************/
int numerocompte1=1;
int soldecompte1=0;
int numecompte2=2;
int soldecompte2=0;
int main() {
    menu(); //appel de fonction
    return 0;
}
/*********************definition des fonctions*****************************/
int crediter(int numero,float montant)
{
    if(numero==numerocompte1)
    {
        soldecompte1+=montant;
        return soldecompte1;
    }
    else {
        soldecompte2 += montant;
        return soldecompte2;
    }
}

int debiter(int numero,float montant)
{
    if(numero==numerocompte1)
    {
        soldecompte1-=montant;
        return soldecompte1;
    }
    else {
        soldecompte2 -= montant;
        return soldecompte2;
    }
}

int virement(int numeros,float montant,int numerod)
{
    if(numeros==numerocompte1)
    {
        debiter(1,montant); //appel de fonction pour eviter les répetitions
        if(numerod==numecompte2)
        crediter(2,montant);
        return soldecompte2;
    }
    else
    {
        debiter(2,montant);
        if(numerod==numerocompte1)
        crediter(1,montant);
        return soldecompte1;
    }
}

void menu()
{
    int choix=0;
    int numero=0;
    int montant=0;
    int numerod;
    int nouveausolde;
    printf("1-crediter un compte\n");
    printf("2-debiter un compte\n");
    printf("3-Faire un virement\n");
    scanf("%d",&choix);
    switch (choix) {
        case 1:
            printf("Veuillez saisir un numero de compte");
            scanf("%d",&numero);
            printf("Veuillez saisir un montant");
            scanf("%d",&montant);
            nouveausolde=crediter(numero,montant);

            break;
        case 2:
            printf("Veuillez saisir un numero de compte");
            scanf("%d",&numero);
            printf("Veuillez saisir un montant");
            scanf("%d",&montant);
            nouveausolde=debiter(numero,montant);
            break;
        case 3:
            printf("Veuillez saisir un numero de compte source");
            scanf("%d",&numero);
            printf("Veuillez saisir un montant");
            scanf("%d",&montant);
            printf("Veuillez saisir un numero de compte destinataire");
            scanf("%d",&numerod);
            nouveausolde=virement(numero,montant,numerod);
    }
    printf("Le nouveau solde est de %d\n",nouveausolde);
}

