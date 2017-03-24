#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "table.h"

//***********
//Constant
//***********
#define LENGTH 8
static int testsFailed = 0;
static int testsExecuted = 0;

//*****************
// Prototypes
//*****************

void testSize(int expectedSize);

void testInsert(char const * const target);

void testDelete(char const * const target);

void testSearch( char const * const target);

void testTraversal();

int main( int argc, char *argv[]){
    int i,deleted=0;
    char toFail[] = "To Make The function fail";
     char *array[] = { "Hello" ,"World", "!", "706", "How", "", "are", "you"};
     assert( 0<= size());
     testSize(0);
     for( i = 0; i< LENGTH ;i++){
         insert( array[i] );
        testInsert( array[i] );
         testSize(i+1);

     }
      //testInsert( array[5] );
     testSize(LENGTH);
     for( i = 0; i< LENGTH ;i++){
        
         testSearch( array[i] );
        // testSize(i+1);
     }
     testTraversal();
     //delete( array[LENGTH -1] );
     for( i= 1; i< 5; i++){
         testDelete( array[i] );
         deleted++;
     }
     testSize(LENGTH - deleted);
     testTraversal();
     testSearch(array[0]);
     testSearch(toFail);
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
    testsFailed++;
    printf("FAILED: Expected size is %d , but the actual size is %d\n", expectedSize, size());
}
else{
printf("SUCCESS : Size is as expected\n");
}
testsExecuted++;
}

void testInsert(char const * const target){
    char *topItem = firstItem();
    	if ( strcmp( topItem, target ) != 0 ) {

		printf( "\nFAILED: Expected %s Found %s\n", target, topItem );
		testsFailed++;
	}
 else{
 printf("SUCCESS : Inserted \" %s \"\n", target);
 }

	testsExecuted++;

}

void testDelete(char const * const target){
	Boolean result = delete( target );

	if ( !result ) {
		printf("\nFAILED: Could not delete \"%s\"\n", target );
		testsFailed++;
	}
 else{
 printf("SUCCESS : Deleted \" %s \"\n", target);
 }
	testsExecuted++;
}
void testSearch( char const * const target){
Boolean result = search( target );

	if ( !result ) {

		printf( "\nFAILURE: Could not find \"%s\"\n", target );
		testsFailed++;
	}
  else{
 printf("SUCCESS : Found \" %s \"\n", target);
 }

	testsExecuted++;

}

void testTraversal(){
	int numNodes = 0;
	char *result = firstItem();
	//printf("%s\n", result );

	while ( result != NULL ) {
       // printf("%s", result );
		numNodes++;
		result = nextItem();
		
	}

	if ( numNodes != size() ) {
		printf("FAILED: Linked list traversal, Expected Number of Nodes: %d, Travelled : %d\n", size(), numNodes );
		testsFailed++;
	}
  else{
 printf("SUCCESS : Travelled entire table\n");
 }
	testsExecuted++;
}