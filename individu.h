//
// Created by leroy on 24/11/2022.
//

#ifndef UNTITLED_INDIVIDU_H
#define UNTITLED_INDIVIDU_H
#include <math.h>
#include <stdlib.h>

//pour les printf
#include <stdio.h>

typedef unsigned char Bit;

typedef struct elem {
    Bit value;
    struct elem *next ;
}Gene;

typedef Gene * individu;

void printindiv(individu i,float (*pf)(individu));


individu insertion_tete(individu l, Bit b);

individu ajouter_queue(individu l, Bit b);

//créé un individu et initiallise son génome:
//version récursive
individu initrec(int size);
//version itérative
individu inititer(int size);


//donne la valeur entière du génome
int decoder(individu i);

//croise 2 individus
//lexique
void croiser(float pCroise,individu i1,individu i2);


//warning
//trouver une solution pour A et B
//donne la qualité d'un individu
//inutile car pointeur sur fonctiong
float qualite(individu i);

void free_indiv(individu i);





#endif //UNTITLED_INDIVIDU_H
