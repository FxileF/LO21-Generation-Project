#include <stdio.h>
#include <time.h>
#include "individu.h"
#include "population.h"


//warning
//trouver une solution pour A et B
//donne la qualité d'un individu
float f1(individu i);
float f2(individu i);
int generate_number(int min,int max);


int main() {
    int nGen,TaillePop,tSelect,longIndiv=8;
    float (*qualite_ptr)(individu) = &f2;
    float pCroise=0.5f;

    srand(time(0));

    TaillePop = generate_number(20,200);
    tSelect=(generate_number(10,90)*TaillePop)/100;
    nGen = generate_number(20,200);


    population Pop = init(TaillePop,longIndiv);

    for(int i=0;i < nGen;i++){
        Pop = trier(Pop,qualite_ptr);
        Pop = select(Pop,tSelect);
        Pop = croiser_pop(Pop,pCroise);
    }

    print_pop(Pop,qualite_ptr);

    free_pop(Pop);
    return 0;
}

float f1(individu i){
    float A = -1.0f;
    float B = 1.0f;
    int longdiv = 8;
    float X = (decoder(i)/pow(2,longdiv)) * (B-A) + A;
    return -pow(X,2);
}

float f2(individu i){
    float A = 0.1f;
    float B = 5.0f;
    int longdiv = 16;
    float X = (decoder(i)/pow(2,longdiv)) * (B-A) + A;
    return -log(X);
}

int generate_number(int min,int max){
    return min+rand()%(max-min+1);
}