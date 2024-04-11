#include<stdio.h>
#include<stdlib.h>
#include"liste.h"



cellule* allocation_cel(){

    cellule *P=(cellule *)malloc(sizeof(cellule));

    P->valeur=0;
    P->suivant=NULL;
    
    return P;

}


void afficher_liste(cellule *L_tete){
    cellule *N=L_tete;

    while(N != NULL){
        printf("%.f      \n",N->valeur);
        N=N->suivant;
    }
}

cellule *creer_element(float X){

    cellule *P=allocation_cel();
    P->valeur=X;
    P->suivant=NULL;
    return P;
}


cellule* inserer_tete(cellule *L_tete, float X){

    /*if(L_tete->suivant==NULL){
        L_tete->valeur=X;
        L_tete->suivant=NULL;
        return L_tete;
    }*/

    cellule *P=creer_element(X);
    P->suivant=L_tete;
    L_tete=P; 

    return P;
}

cellule *inserer_queue(cellule *L_tete, float X){

    cellule *element=creer_element(X);

    if(L_tete==NULL){
        return element;
    }

    else{

        cellule *nouvelle=L_tete;
        cellule *intermediaire=L_tete;
        while(nouvelle->suivant != NULL){
             nouvelle=nouvelle->suivant;

        }
        nouvelle->suivant=element;

        return intermediaire;
    }
}

cellule *n_cellule(int n){
    
    cellule *tete=allocation_cel();
   
    for (int i = 1; i < n; i++)
    {
        tete=inserer_queue(tete,i);
    }

    return tete;

}


cellule *insertion(cellule *tete, float X, int k){

    if (tete==NULL || k==0)
    {
        return inserer_tete(tete,X);

    }

    else{

        cellule *current=tete;
        cellule *next=NULL;
        cellule *insert=current;

                for (int i =0; i < k; i++)
                {
                    next=current;
                    current=current->suivant;
                    if (current->suivant==NULL)
                    {
                        printf("Vous n'avez pas assez d'espace dans votre liste\n");
                        return tete;
                    }
                    
                }

                
                cellule *element=creer_element(X);
                element->suivant=current;
                next->suivant=element;
                
        return insert;
       
    }

}


cellule *mirroir(cellule *tete){

    cellule *P=tete;
    cellule *M=NULL;

    while(P!=NULL){
       
        M=inserer_tete(M,P->valeur);
         
        P=P->suivant;
    }

    return M;
}

cellule *supprimer_tete(cellule *tete){
    cellule *P=tete;
    cellule *T=tete;
    if(tete!=NULL){
        P=tete->suivant;
        free(T);
    }

    return P;
}

cellule *supprimer_queue(cellule *tete){

    cellule *intermediaire=tete;
    if (tete==NULL)
    {
        return NULL;
    }

    else if(tete->suivant==NULL){
        free(intermediaire);
        return NULL;
    }

    else{

        cellule *next=tete;
        cellule *current;
        while(next->suivant != NULL){
            current=next;
            next=next->suivant;
        }
        current->suivant=NULL;
        free(next);
        return intermediaire;
    }
}


cellule *suppression(cellule *tete,int k){

    if (tete==NULL || k==0)
    {
        return supprimer_tete(tete);

    }

    else{

        cellule *current=tete;
        cellule *next=NULL;
        cellule *insert=current;

                for (int i =0; i < k; i++)
                {
                    next=current;
                    current=current->suivant;
                    if (current==NULL)
                    {
                        printf("Vous n'avez pas assez d'espace dans votre liste\n");
                        return tete;
                    }
                    
                }

                current=supprimer_tete(current);
                next->suivant=current;
               
        return insert;
       
    }
}



cellule *supp_occ(cellule *tete, float X){

    cellule *N=NULL;
    int i=0;
    N=tete;
    cellule *P=N;

    while(N!=NULL){
        if(N->valeur==X){
            N=suppression(N,i);
            i++;
        }
        else{
        N=N->suivant;
        i++;
    }
    }

    return P;
}
