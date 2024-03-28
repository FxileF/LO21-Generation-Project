//
// Created by leroy on 24/11/2022.
//

#include "individu.h"

void printindiv(individu i,float (*qualite)(individu)){
    if(i!=NULL){
        Gene* p=i;
        printf("individu : [");
        if(p->next!=NULL){
            while(p->next!=NULL){
                printf("%d,",p->value);
                p=p->next;
            }
            printf("%d",p->value);
        }else{
            printf("%d",p->value);
        }
        printf("] valeur : %d, et qualite : %f\n",decoder(i),qualite(i));
    }
}


individu insertion_tete(individu l, Bit b){
    Gene* newel=(Gene*)malloc(sizeof(Gene));
    newel->value = b;
    newel->next=l;

    return newel;
}

individu ajouter_queue(individu l, Bit b){
    Gene* newel=(Gene*)malloc(sizeof(Gene));
    newel->value=b;
    newel->next=NULL;
    if(l != NULL){
        Gene* curseur = l;
        while(curseur->next != NULL){
            curseur = curseur->next;
        }
        curseur->next = newel;
        return l;
    }else{
        return newel;
    }
}

//créé un individu et initiallise son génome:
//version récursive
individu initrec(int size){
    if(size==1){
        Bit b=rand()%2;
        individu i= NULL;
        i=insertion_tete(i,b);
        return i;
    }else{
        individu i=initrec(size-1);
        Bit b=rand()%2;
        i= insertion_tete(i,b);
        return i;
    }
}

//version itérative
individu inititer(int size){
    Bit b;
    individu i=NULL;
    for(int j=0;j<size;j++){
        b=rand()%2;
        i= insertion_tete(i,b);
    }
    return i;
}


//donne la valeur entière du génome
int decoder(individu i){
    Gene* p=i;
    int value=0,j=0;
    while(p!=NULL){
        value+=p->value*pow(2,j);
        p=p->next;
        j++;
    }
    return value;
}


//croise 2 individus
//lexique
void croiser(float pCroise,individu i1,individu i2){

    float random;
    Gene* p1=i1;
    Gene* p2=i2;
    while(p1!=NULL && p2!=NULL){
        random=(float)rand()/(float)RAND_MAX;
        if(random<pCroise){
            Bit temp=p1->value;
            p1->value=p2->value;
            p2->value=temp;
        }
        p1=p1->next;
        p2=p2->next;
    }
}

void free_indiv(individu i){
    Gene* current=i;
    Gene* next;
    while(current!=NULL){
        next=current->next;
        free(current);
        current=next;
    }
}



