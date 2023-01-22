//sablona pro programovani tridicich algoritmu v C
//ALGO1 2022/2023

// pouzivame zakladni knihovny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//nastavte si, jak velke chcete pole (kolik cisel budete tridit)
#define VELIKOST 10             //TADY UPRAVIT
//nastavte si rozsah cisel ke trideni
#define CISLA_OD 0             //TADY UPRAVIT
#define CISLA_DO 1000          //TADY UPRAVIT

//nahodne naplni pole nachystane pro VELIKOST prvku hodnotami v zadanem rozsahu
void napln_pole(int pole[]){
    time_t t;
    srand((unsigned) time(&t));
    for (int i = 0; i < VELIKOST; i++){
      pole[i] = CISLA_OD + rand() % CISLA_DO;  
    }
}

//vypise pole obshaujici VELIKOST prvku
void vypis_pole(int pole[]){
    for (int i  =  0; i < VELIKOST; i++){
        printf("%d, ", pole[i]);
    }
}

//funkce provadejici trideni pomoci algoritmu selection sort
void selection_sort(int pole[]){
  int delka = VELIKOST;
  for(int j = 0; j < delka - 1; j++){
    int iMin  = j;
    for (int i = j + 1; i < delka; i++){
      if (pole[i] < pole[iMin]){
	iMin = i;

      }
    }
    int t = pole[j];
    pole[j] = pole[iMin];
    pole[iMin] = t;
  }
}

void insertion_sort(int pole[]){

     for (int x = 0; x < VELIKOST - 1; x++)
    {
        int aktualni = pole[x];
        int z = x - 1;
        while (z >= 0 && pole[z] > aktualni)
        {
            pole[z+1] = pole[z];
            z = z - 1;
        }
        pole[z + 1] = aktualni;
        
    }

}

void bubble_sort(int pole[]){
    for (int i = 0; i < VELIKOST - 2; i++)
    {
        for (int j = VELIKOST - 1;j > i ; j--)
        {
            if (pole[j] >= pole[j - 1]){
                int menic = 0;
                menic = pole[j];
                pole[j] = pole[j - 1];
                pole[j - 1] = menic;
            }
        }
        
    }
    
}

int main(void){
    //vytvorime, naplnime a vypiseme pole
    int pole[VELIKOST];
    napln_pole(pole);
    vypis_pole(pole);

   
    
    bubble_sort(pole);
    
    
    //<--- dale kod nemente

    //vypiseme pole po vykonani uprav
    printf("\n");
    vypis_pole(pole);
    getchar(); //pockame na "enter" a skoncime
    return 0;
}
