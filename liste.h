typedef struct cellule{
    float valeur;
    struct cellule *suivant;
}cellule;

cellule* allocation_cel();
void afficher_liste(cellule *L_tete);
cellule *creer_element(float X);
cellule* inserer_tete(cellule *L_tete, float X);
cellule *inserer_queue(cellule *L_tete, float X);
cellule *n_cellule(int n);
cellule *insertion(cellule *tete, float X, int k);
cellule *mirroir(cellule *tete);
cellule *supprimer_tete(cellule *tete);
cellule *supprimer_queue(cellule *tete);
cellule *suppression(cellule *tete,int k);
cellule *supp_occ(cellule *tete, float X);