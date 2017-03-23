#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "table.h"
#include "levenshtein.h"
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

	while ( checker == '\n' && result != NULL ) {

		for (int i = 0; i < 10; i++)

		{
		printf("%s\n", result); 
		result = nextItem();
		
		}

		printf("\n");

		checker = fgetc( stdin );

	}
}

// char * removeDigit(char * const input){
//     int i = 0, j= 0;
//     char * result = malloc(strlen(input) * sizeof(char));
//     if(result != NULL){
//         for(i = 0; *(input + i)!= '\0'; i++){
//            if(isalpha(*(input + i))){
//                (result + 0) = (char) *(input + i);
//            }
//         }
//     }
//     else{
//         free(result);
//         result = NULL;
//     }
//     return result;
// }
void toLower( char * const input){
    int i =0;
    for(i = 0;*(input + i) != '\0';i++){
       *(input + i) = tolower(*(input + i)) 
    }
}
void deleteTable(){
    while(firstItem){
        delete(firstItem);
    }
}