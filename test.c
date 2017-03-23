#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "table.h"
#include "engine.h"

typedef enum BOOL { false, true } Boolean;
#define LENGTH 8
static int testsFailed = 0;
static int testsExecuted = 0;

//*****************
// Prototypes
//*****************

void testBuildTable();
void testPager();
void testToLower( char * const input);
void testDeleteTable();

int main(int argc, char const *argv[])
{
    FILE *dict;
	char input[]= "Hello";
    char similar[MAX];
    dict = fopen("sample.txt", "r");
    if(dict != NULL){
        buildTable(dict,input,similar);
        printf("Input is %s and The similar word is %s\n", input, similar);
        if (size() <= 0){

        }
    }

    return EXIT_SUCCESS;
}
void testBuildTable(){

}
void testToLower( char * input){
    Boolean result = true;
    toLower(input);
    for(i = 0; i < strlen(input) && result; i++){
        if(*(inpput + i) != tolower(*(inpput + i))){
            result = false;
        }
    }
    if(!result){
        printf("Test Failed");
        testsFailed++;
    }
    testsExecuted++;
}