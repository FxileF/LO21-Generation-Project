//
// Created by leroy on 24/11/2022.
//

#ifndef UNTITLED_POPULATION_H
#define UNTITLED_POPULATION_H

#include "individu.h"

typedef struct element{
    individu value;
    struct element *next ;
}indiv;

typedef indiv * population;

void print_pop(population P,float (*pf)(individu));
int taille_pop(population P);
population ajouter_queue_pop(population P,individu indiv);
population insertion_tete_pop(population p, individu i);

population init(int size_pop,int size_indiv);

indiv* queue(population p);

population trier(population P,float (*pf)(individu));

population select(population P, int tselect);

population croiser_pop(population P,float pCroise);

int RNG(float pcroise);

void free_pop(population P);


#endif //UNTITLED_POPULATION_H
