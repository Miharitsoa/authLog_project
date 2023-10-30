#ifndef __MOIS_H_
#define __MOIS_H_

#include<stdio.h>
#include<string.h>

static char Mois[12][15]={"Janoary","Febroary","Martsa","Aprily","May","Jona","Jolay","Aogositra","Septambra","Oktobra","Novambra","Desambra"};

int monthToInteger(char*volana){
    int m;
    if(strstr(volana,"Jan")!=NULL) 
       m=0;
    if(strstr(volana,"Feb")!=NULL)
        m=1;
    if(strstr(volana,"Mar")!=NULL)
        m=2;
    if(strstr(volana,"Apr")!=NULL)
        m=3;
    if(strstr(volana,"May")!=NULL)
        m=4;
    else if(strstr(volana,"Jun")!=NULL)
        m=5;
    else if(strstr(volana,"Jul")!=NULL)
        m=6;
    else if(strstr(volana,"Aug")!=NULL)
        m=7;
    else if(strstr(volana,"Sep")!=NULL)
        m=8;
    else if(strstr(volana,"Oct")!=NULL)
        m=9;    
    else if(strstr(volana,"Nov")!=NULL)
        m=10;
    else if(strstr(volana,"Dec")!=NULL)
        m=11;
    else
        printf("Echec\n");
    
    return m;
}

char*integerToMonths(int m){
    char*volana;
    for(int i=0;i<12;i++){
        if(m==i){
            volana=Mois[i];
        }
    }
    printf("%s\n",volana);
    return volana;
}

#endif