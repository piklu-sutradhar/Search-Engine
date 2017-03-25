#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "table.h"

static Node *top = NULL;
static int numNodes = 0;
 
// used to track where we are for the list traversal methods
static Node *traverseNode = NULL;

int size( )
{
  assert( 0<= numNodes);
    return numNodes;
}
//Invariant
void checkState(char const * const input){
  assert( input != NULL);
  assert( 0 <= strlen(input));
  assert('\0' == input[strlen(input)]);
  assert( 0 <= numNodes );
}
    
// add an element to the beginning of the linked list
Boolean insert( char const * const new_string )
{
  Boolean rc = true;
  Node *newNode = NULL;
  
  newNode = (Node *)malloc( sizeof( Node ) );
  assert(newNode != NULL);
  if (newNode != NULL){
  newNode->next = top;
  top = newNode;
  
  // note that we need to have space for the string as well!
  newNode->string = (char *)malloc( strlen(new_string) + 1 );
  assert( newNode->string != NULL);
  if( newNode->string != NULL){
  strcpy( newNode->string, new_string );
  numNodes++;
  }
  else{
    free(newNode);
    rc = false;
  }
  }
  return rc;
}


// remove an element with the given string
Boolean delete( char const * const target )
{
  Boolean deleted = false;
  Node *curr = top;
  Node *prev = NULL;
  checkState(target);
  while ( curr != NULL && strcmp( target, curr->string ) != 0 )
  {
    prev = curr;
    curr = curr->next;
  }

  if ( curr != NULL )
  {
    if ( prev != NULL )
      prev->next = curr->next;
    else
      top = curr->next;
    
    free( curr->string );
    curr->string = NULL;
    assert( curr->string == NULL);
    free( curr );
    curr = NULL;
    assert( curr == NULL);
    deleted = true;
    numNodes--;
  }
  
  return deleted;
}

// tells us whether or not the given string is in the list
Boolean search( char const * const target )
{
  Boolean found = false;
  Node *curr = top;
  checkState(target);
  while ( curr != NULL && !found )
  {
    if ( strcmp( target, curr->string ) == 0 )
    {
      assert( 0 == strcmp(target, curr->string));
      found = true;
    }
    
    else
    {
      curr = curr->next;
    }
  }
  
  return found;
}


// starts a list traversal by getting the data at top
char * firstItem()
{
  //assert( top != NULL);
  traverseNode = top->next;
  checkState(top->string);
  return top->string;
}


// gets the data at the current traversal node and increments the traversal
char * nextItem()
{
  char *item = NULL;
  //assert( traverseNode != NULL);
  // no need to go past the end of the list...
  if ( traverseNode != NULL )
  {
    assert( traverseNode != NULL);
    item = traverseNode->string;
    checkState( item );
    traverseNode = traverseNode->next;
  }
  
  return item;
}