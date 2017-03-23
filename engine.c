#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "table.h"
#include "levenshtein.c/levenshtein.h"
#include "engine.h"

#define LENGTH 200

static char wordsInDict[LENGTH];

void buildTable( FILE *dict, char *input, char * similar){
    int minDist , dist;
    if(fgets(wordsInDict, LENGTH, dict)){
        wordsInDict[strlen(wordsInDict)-1] = '\0';
        toLower(wordsInDict);
        strcpy(similar, wordsInDict);
        minDist = levenshtein(wordsInDict, input);
        while(fgets(wordsInDict, LENGTH, dict)){
            wordsInDict[strlen(wordsInDict)-1] = '\0';
            toLower(wordsInDict);
            dist = levenshtein(wordsInDict, input);
            if(dist < minDist){
                minDist = dist;
                strcpy(similar, wordsInDict);
            }
            if(dist < 5){
                insert(wordsInDict);
            }
        }
    }
}
void pager() {

	char checker = '\n';
	char *result = firstItem();

	do{
 if(checker == '\n'){
		for (int i = 0; i < 10 && result != NULL ; i++)

		{
		printf("%s\n", result); 
		result = nextItem();
		
		}
   }
   else if (checker == 'q'){
   return;
   }
   else{
printf("To quit enter q");
}
		checker = fgetc( stdin );
   //fgetc(stdin);

	}while ( (checker == '\n' || checker == 'q') && result != NULL) ;
}
void toLower( char * const input){
    int i =0;
    for(i = 0;*(input + i) != '\0';i++){
       *(input + i) = tolower(*(input + i)); 
    }
}
void deleteTable(){
char *item = firstItem();
    while(item){
        delete(item);
        item = nextItem();
    }
    //return ;
}