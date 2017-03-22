#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "table.h"

//***********
//Constant
//***********
#define LENGTH 8;
static int testsFailed = 0;
static int tetsExecuted = 0;

//*****************
// Prototypes
//*****************

void testSize(int expectedSize);

void testInsert(char const * const target);

void testDelete(char const * const target);

void testSearch( char const * const target);

void testTraversal();

int main( int argc, char *argv[]){
    int i;deleted=0;
     char *array[LENGTH];
     array = { "Hello" ,"World", "!", "\n", "How", "", "are", "you"};
     assert( 0<= size());
     testSize(0);
     for( i = LENGTH-1; i>=0 ;i--){
         insert( array[i] );
        testInsert( array[i] );
         //testSize(i+1);

     }
      //testInsert( array[5] );
     testSize(LENGTH);
     for( i = 0; i< LENGTH ;i++){
        
         testSearch( array[i] );
        // testSize(i+1);
     }
     testTraversal();
     for( i= 0; i< 5; i++){
         delete( array[i] );
         deleted++;
     }
     for( i= 0; i< 5; i++){
         testDelete( array[i] );
        // deleted++;
     }
     testSize(LENGTH - deleted);
     testTraversal();

    printf("\nTotal number of tests executed: %d\n" , testsExecuted);
	printf("Number of tests passed: %d \n" , (testsExecuted - testsFailed));
	printf("Number of tests failed: %d\n" , testsFailed);
	printf("Program completed normally.\n\n");

	return EXIT_SUCCESS;

}

//************************
//Function implementation
//************************

void testSize(int expectedSize){
if (expectedSize != size()){
    testFailed++;
    printf("Expected size is %d , but the actual size is %d", expectedSize, size());
}
testExecuted++;
}

void testInsert(char const * const target){
    char *topItem = firstItem();
    	if ( strcmp( topData, expected ) != 0 ) {

		printf( "\nFAILURE: Expected %s Found %s\n", expected, topData );
		testsFailed++;
	}

	testsExecuted++;

}

void testDelete(char const * const target){
	Boolean result = delete( target );

	if ( !result ) {
		printf("\nFAILURE: Could not delete \"%s\"\n", target );
		testsFailed++;
	}

	testsExecuted++;
}
void testSearch( char const * const target){
Boolean result = search( target );

	if ( !result ) {

		printf( "\nFAILURE: Could not search \"%s\"\n", target );
		testsFailed++;
	}

	testsExecuted++;

}

void testTraversal(){
	int numNodes = 0;
	char *result = firstItem();
	//printf("%s\n", result );

	while ( result != NULL ) {

		numNodes++;
		result = nextItem();
		
	}

	if ( numNodes != size() ) {
		printf("\n%s %d %d", "Linked list traversal failed, Expected Num: ", size(), numNodes );
		testsFailed++;

	}

	testsExecuted++;
}