#include<stdio.h>
#include<stdlib.h>
#include "liste.h"

int main(){
    
    cellule *tete=NULL;
    cellule *miroir=NULL;
    printf("Insérer 4 en tete de la liste et 10 et 24 en queue:\n");
    tete=inserer_tete(tete,4);
    tete=inserer_queue(tete,10);
    tete=inserer_queue(tete,24);
    afficher_liste(tete);
    printf("insérer 45 position 1\n");
    
    tete=insertion(tete, 45, 1);
    afficher_liste(tete);

    printf("supprimer elément position 2 et insérer 45 en queue\n");
    tete=suppression(tete,2);
    tete=inserer_queue(tete,45);
    afficher_liste(tete);

    printf("insérer 45 en tete\n");
    tete=inserer_tete(tete,45);
    afficher_liste(tete);
    //tete=supp_occ(tete,45);

    printf("supprimer tete et queue\n");
    tete=supprimer_tete(tete);
    tete=supprimer_queue(tete);
    afficher_liste(tete);

    printf("Le miroir de la liste est :\n");
    miroir=mirroir(tete);
    afficher_liste(miroir);

    printf("Création liste avec 5 cellules:\n");
    cellule *create=NULL;
    create=n_cellule(5);
    afficher_liste(create);




    return 0;
}