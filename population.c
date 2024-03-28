//
// Created by leroy on 24/11/2022.
//
#include "individu.h"
#include "population.h"
#include <stdio.h>
#include <time.h>






void print_pop(population P,float (*qualite)(individu)){
    if(P!=NULL){
        indiv* pop=P;
        printf("Population : [\n");
        while(pop!=NULL) {
            printindiv(pop->value,qualite);
            pop = pop->next;
        }
    }
}


population insertion_tete_pop(population p, individu i){
    indiv* newel=(indiv*)malloc(sizeof(indiv));
    newel->value = (individu)malloc(sizeof(individu));
    newel->value=i;
    newel->next=p;

    return newel;
}

population ajouter_queue_pop(population P, individu queue){
    indiv* newel=(indiv*)malloc(sizeof(indiv));
    newel->value=queue;
    newel->next=NULL;
    if(P != NULL){
        indiv* curseur = P;
        while(curseur->next != NULL){
            curseur = curseur->next;
        }
        curseur->next = newel;
        return P;
    }else{
        return newel;
    }
}


population init(int size_pop,int size_indiv){
    population p=NULL;
    individu i;
    for(int j=0;j<size_pop;j++){
        i = inititer(size_indiv);
        p = insertion_tete_pop(p,i);
    }
    return p;
}

indiv* queue(population p){
    indiv *current = p;
    while (current != NULL && current->next != NULL)
        current = current->next;
    return current;
}


population trier(population P,float (*qualite)(individu)){
    //printf("entrée dans trier et qualite du premier de POP : %f\n",pf(P->value));
    indiv* pivot=queue(P);
    indiv* current=P;
    population gauche=NULL,droite=NULL;
    if(pivot!=NULL) {
        while (current != pivot) {
            if (qualite(current->value) > qualite(pivot->value)) {
                gauche = insertion_tete_pop(gauche, current->value);
            } else {
                droite = insertion_tete_pop(droite, current->value);
            }
            current = current->next;
        }
        gauche=trier(gauche,qualite);
        droite=trier(droite,qualite);
        if(gauche!=NULL){
            indiv* last=queue(gauche);
            last->next=pivot;
            pivot->next=droite;
            return gauche;
        }else{
            pivot->next=droite;
            return pivot;
        }
    }else{
        return NULL;
    }
}


int taille_pop(population P){
    if(P != NULL){
        return 1 + taille_pop(P->next);
    }else{
        return 0;
    }
}


individu copie_individu(individu i){
    individu i2=NULL;
    Gene* curseur=i;
    while(curseur!=NULL){
        i2= ajouter_queue(i2,curseur->value);
        curseur=curseur->next;
    }
    return i2;
}


population select(population P, int tselect){
    if(taille_pop(P) < tselect){
        printf("Selection size bigger than population\n");
        return NULL;
    }else{
        population Result_Pop=NULL;
        indiv* curseur = P;
        for(int i=0;i<taille_pop(P);i++){
            Result_Pop = ajouter_queue_pop(Result_Pop,copie_individu(curseur->value));
            if((i % tselect) + 1 >= tselect){
                curseur = P;
            }else{
                curseur = curseur->next;
            }
        }
        return Result_Pop;
    }
}



int RNG(float pcroise){
    float n = (rand() % 100) / 100.0;
    if(n > pcroise) {
        return 0;
    }else{
            return 1;
        }
}

individu pop_index_value(population P,int index){
    indiv* result = P;
    if(taille_pop(P) < index){
        printf("Index larger than population size\n");
        return NULL;
    }else{
        for(int i = 0; i < index;i++){
            result = result->next;
        }
        return copie_individu(result->value);
    }
}

population croiser_pop(population P,float pCroise){
    int index_1,index_2,taille,i;
    individu Indiv_1,Indiv_2;
    population P_croise = NULL;
    taille = taille_pop(P);
    i = 0;
    while(i < taille){
        index_1 = rand() % taille;
        index_2 = rand() % taille;

        while(index_2 == index_1){
            index_2 = rand() % taille_pop(P);
        }
        Indiv_1 = pop_index_value(P,index_1);
        Indiv_2 = pop_index_value(P,index_2);
        croiser(pCroise,Indiv_1,Indiv_2);
        P_croise = ajouter_queue_pop(P_croise,Indiv_1);
        i++;
    }
    return P_croise;
}

void free_pop(population P){
    indiv* current=P;
    indiv* next;
    while(current!=NULL){
        next=current->next;
        free_indiv(current->value);
        free(current);
        current=next;
    }
}




