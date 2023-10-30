#ifndef __DATE_H_
#define __DATE_H_

#include<stdio.h>

int determineJourSemaine(int jour,int mois,int annee){
    if(mois<3){
        mois+=12;
        annee--;
    }

    int siecle=annee/100;
    int anneeDansSiecle=annee%100;

    int jourSemaine=(jour+2*mois+3*(mois+1)/5+anneeDansSiecle+anneeDansSiecle/4-anneeDansSiecle/100+anneeDansSiecle/400+siecle*5)%7;

    return jourSemaine;
}

void getResult(int jourSemaine){
    switch(jourSemaine){
        case 0:
            printf("Sabotsy\n");
            break;
        case 1:
            printf("Alahady\n");
            break;
        case 2:
            printf("Alatsinainy\n");
            break;
        case 3:
            printf("Talata\n");
            break;
        case 4:
            printf("Alarobia\n");
            break;
        case 5:
            printf("Alakamisy\n");
            break;
        case 6:
            printf("Zoma\n");
            break;
        default:
            printf("Erreur\n");
            break;
    }
}
char*getJourSemaine(int jourSemaine){
    char jours[7][15]={"Sabotsy","Alahady","Alatsinainy","Talata","Alarobia","Alakamisy","Zoma"};
    char*result;
    for(int i=0;i<7;i++){
        if(jourSemaine==i){
            result=jours[i];
        }
    } 
    printf("%s\n",result);
    return result;
}

#endif