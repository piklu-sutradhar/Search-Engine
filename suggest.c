#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include "engine.h"

#define MAX 600

int main(int argc, char const *argv[])
{
	FILE *dict;
	char input[ MAX ];
    char *similar;
    int counter = 0;
    if (argc < 2){
    printf("One Argument Expected\n");
    return EXIT_FAILURE;
    }
    else if (argc > 2){
    printf("More Than Expected Argument Entered\n");
    return EXIT_FAILURE;
    }
    else{
    //Check if expected command line arguments have been entered
    assert(argc == 2);
	assert( argv[1] != NULL );
    if (argv[1] != NULL ) {

		dict = fopen( argv[1], "r" );

		assert(dict != NULL );
        if(dict != NULL){
		printf("What word should i check? " );
        char ch = fgetc(stdin)
        while(ch != '\n' || ch != EOF){
            if(isalpha(ch)){
                input[counter++] = ch;
            }
            ch = fgetc(stdin);
        }
        input[counter] = '\0';
        buildTable(dict,input,similar);
        printf("\nDid you mean... %s?\n", similar );
		printf("\nThere are %d other similar words, would you like 
        to see them? (y/n) ", size());
        ch = tolower(getc(stdin));
        fgetc(stdin);
        do{
            if (ch == 'y'){
                pager();
            }
            else if (ch == 'n'){
                deleteTable();
             }
            else{
                printf("\nEnter y/n and press \"enter\" ");
                ch = tolower(fgetc(stdin));
                fgetc(stdin);
                }   
            }while(ch != 'y' || ch != 'n');
            fclose(dict);
            }   
        }
    }
    return EXIT_SUCCESS;
}

