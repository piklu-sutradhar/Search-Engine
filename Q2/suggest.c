#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include "engine.h"
#include "table.h"

#define MAX 100
void pager();
int main(int argc, char const *argv[])
{
    FILE *dict;
    char wordsInDict[MAX];
    char input[MAX];
    char similar[MAX];
    if (argc < 2)
    {
        printf("One Argument Expected\n");
        return EXIT_FAILURE;
    }
    else if (argc > 2)
    {
        printf("More Than Expected Argument Entered\n");
        return EXIT_FAILURE;
    }
    else
    {
        //Check if expected command line arguments have been entered
        assert(argc == 2);
        assert(argv[1] != NULL);
        if (argv[1] != NULL)
        {

            dict = fopen(argv[1], "r");

            assert(dict != NULL);
            if (dict != NULL)
            {
                printf("What word should i check? ");
                fgets(input, MAX, stdin);
                input[strlen(input) - 1] = '\0';
                //removeDigit(input);
                //toLower(input);
                while (fgets(wordsInDict, MAX, dict))
                {
                    //checkWords(input);
                    wordsInDict[strlen(wordsInDict) - 1] = '\0';
                    checkWords(wordsInDict);

                    buildTable(wordsInDict, input, similar);
                }
                if (getSize() > 0)
                {
                    printf("\nDid you mean... %s?\n", similar);
                    //int similarWords = size();
                    printf("\nThere are %d other similar words, would you like to see them? (y/n) ", getSize());
                    char ch = tolower(getc(stdin));
                    fgetc(stdin);
                    do
                    {
                        if (ch == 'y')
                        {
                            pager();
                            return EXIT_SUCCESS;
                        }
                        else if (ch == 'n')
                        {
                            deleteTable();
                            return EXIT_SUCCESS;
                        }
                        else
                        {
                            printf("\nEnter y/n and press \"enter\" ");
                            ch = tolower(fgetc(stdin));
                            fgetc(stdin);
                        }
                    }while (ch == 'y' || ch == 'n');
                }
                            else
            {
                printf("There is no similar words in the file provided\n");
            }
                  fclose(dict);
            }
        }
        return EXIT_SUCCESS;
    }
}
void pager()
{
    char *result = firstItem();
    for (int i = 0; i < 10 && result != NULL; i++)
    {
      printf("%s\n", result);
      result = nextItem();
    }
    char checker = fgetc(stdin);
    while(checker != '\0' && result != NULL){
      if(checker == '\n'){
      for (int i = 0; i < 10 && result != NULL; i++)
        {
          printf("%s\n", result);
          result = nextItem();
        }
        checker = fgetc(stdin);
      }
      else{
        deleteTable();
        checker = '\0';
      }
    }
}
