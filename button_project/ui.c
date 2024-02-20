#include <stdio.h>
#include <stdlib.h>
#include "ui.h"

void selectMode()
{
    int num;
    FILE *fptr;
    // Dosya yolunuza uygun bir konum belirtin
    fptr = fopen("/home/bugrahan/İndirilenler/button_project/modeDurum.txt","w");
    if(fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    printf("Mod Giriniz:(1=mode1, 2=mode2): ");
    scanf("%d", &num);

    fprintf(fptr, "%d", num);
    printf("Mod seçildi.");
    fclose(fptr);
}

void getMode(int *num, FILE**fptr){
   if ((*fptr = fopen("/home/bugrahan/İndirilenler/button_project/modeDurum.txt","r")) == NULL){
       printf("Error! opening file");
       // Program exits if the file pointer returns NULL.
       exit(1);
   }
   fscanf(*fptr,"%d", num);

}  
