#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include "engine.h"

#define MAX 600

int main(int argc, char const *argv[])
{
	FILE *fp;
	char string[ MAX ];

    assert( argc > 1 );
	assert( argv[1] != NULL );
