#include <stdio.h>
#include <stdlib.h>
FILE *fichier;

struct Contact
{
    char nom[20];
    char prenom[20];
    char numero[10];
};

int main()
{
    fichier = fopen("annuaire.txt" ,"a+");

    void menu();
    void afficher();
    void nouveau();
    void modifier();
    void supprimer();

    struct Contact tab[50];
    int w = 0;
    int i;

    for(i=0; i<50; i++)
    {
        tab[i].nom[1] = '\0';
        tab[i].prenom[1] = '\0';
        tab[i].numero[1] = '\0';
    }

    while (w != 5)
    {
       menu();
       scanf("%d", &w);

       switch(w)
       {
           case 1 : afficher(tab);
           break;
           case 2 : nouveau(tab);
           break;
           case 3 : modifier(tab);
           break;
           case 4 : supprimer(tab);
           break;
       }
    }
    fclose(fichier);

    return 0;
}

void menu()
{
    printf("---------------MENU---------------\n");
    printf("------ 1- AFFICHER CONTACT -------\n");
    printf("------ 2- NOUVEAU CONTACT --------\n");
    printf("------ 3- MODIFIER CONTACT -------\n");
    printf("------ 4- SUPPRIMER CONTACT ------\n");
    printf("------ 5- QUITTER ----------------\n");
}

void afficher(struct Contact tab1[50])
{
    int i = 0;
    while(i < 50 && tab1[i].nom[1] != '\0' && tab1[i].prenom[1] != '\0' && tab1[i].numero[1] != '\0')
    {
        printf("*******%d********\n", i+1);
        printf("Nom : %s\n", tab1[i].nom);
        printf("Prenom : %s\n", tab1[i].prenom);
        printf("Numero tel : %s\n", tab1[i].numero);
        printf("*****************\n");
        i = i + 1;
    }
}

void nouveau(struct Contact tab2[50])
{
    char stop;
    int i = 0;

    do
    {
        fflush(stdin);
        printf("Entrez le nom : \n");
        scanf("%s", tab2[i].nom);
        printf("Entrez le prenom : \n");
        scanf("%s", tab2[i].prenom);
        printf("Entrez le numero : \n");
        scanf("%s", tab2[i].numero);
        fflush(stdin);

        fprintf(fichier, "%s %s %s \n", tab2[i].nom, tab2[i].prenom, tab2[i].numero);

        printf("Souhaitez vous saisir un nouveau contact ? (o/n)\n");

        fflush(stdin);
        scanf("%c", &stop);
        i = i + 1;
    }
    while(stop != 'n');
}

void modifier(struct Contact tab3[50], FILE *fichier2)
{

}

void supprimer(struct Contact tab4[50], FILE *fichier3)
{

}

void trier(struct Contact tab5[50], FILE *fichier4)
{

}
