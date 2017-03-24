#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "table.h"
#include "levenshtein.c/levenshtein.h"
#include "engine.h"

#define LENGTH 200
static int minDistance = 5;
//static char wordsInDict[LENGTH];
void checkWords(char const * const input){
  assert( input != NULL);
  assert( 0 <= strlen(input));
  assert('\0' == input[strlen(input)]);
}

void buildTable( char *dictWord, char *input, char * similar){
    int  dist;
    checkWords(input);
    checkWords( dictWord);
        toLower(dictWord);
        dist = levenshtein(dictWord, input);
        assert(dist >= 0);
        removeDigit(input);
        toLower(input);
        dist = levenshtein(dictWord, input);
        if(dist < 5){
          if(dist < minDistance){
            minDistance = dist;
            strcpy(similar, dictWord);
            checkWords(similar);
            }
            insert(dictWord);
            }
        }

void toLower( char * const input){
    checkWords(input);
    int i =0;
    for(i = 0;*(input + i) != '\0';i++){
       *(input + i) = tolower(*(input + i)); 
    }
    checkWords(input);
}
void removeDigit(char * input){
  int i, j =0;
  checkWords(input);
  char newInput[LENGTH];
  for(i = 0;*(input + i) != '\0';i++){
    if(isalpha(*(input + i))){
      newInput[j++] = *(input + i);
      }
  }
  *(newInput + j) = '\0';
  strcpy(input,newInput);
  checkWords(input);
}
void deleteTable(){
assert(size()>=0);
if(size() > 0){
char *item = firstItem();
    while(item){
        delete(item);
        item = nextItem();
      }
    }
}
int getSize(){
return size();
}