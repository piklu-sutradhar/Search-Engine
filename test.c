#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "table.h"
#include "engine.h"
#include "levenshtein.c/levenshtein.h"

typedef enum BOOL { false,
                    true } Boolean;
#define LENGTH 8
static int testsFailed = 0;
static int testsExecuted = 0;

//*****************
// Prototypes
//*****************
static char input[] = "HELLO";
static char *similar;
void testBuildTable();
void testToLower(char *const input);
void testDeleteTable();

int main(int argc, char const *argv[])
{
    testBuildTable();
    testToLower(char *input);
    testDeleteTable();
    return EXIT_SUCCESS;
}
void testBuildTable()
{
    FILE *dict;
    dict = fopen("sample.txt", "r");
    if (dict != NULL)
    {
        buildTable(dict, input, similar);
        printf("Input is %s and The similar word is %s\n", input, similar);
        if (size() <= 0)
        {
            printf("Table built failed");
            testsFailed++;
            testExecuted++;
        }
        else
        {
            int dist;
            char *result = firstItem();
            //printf("%s\n", result );

            while (result != NULL)
            {
                dist = levenshtein(input, result);
                if (dist < 5)
                {
                    printf("Success: The distance is %d\n", dist);
                }
                else
                {
                    printf("Failed: The distance >= 5");
                    testsFailed++;
                }
                result = nextItem();
                testsExecuted++;
            }
        }
        fclose(dict);
    }
    void testToLower(char *input)
    {
        Boolean result = true;
        toLower(input);
        for (i = 0; i < strlen(input) && result; i++)
        {
            if (*(inpput + i) != tolower(*(inpput + i)))
            {
                result = false;
            }
        }
        if (!result)
        {
            printf("Test Failed");
            testsFailed++;
        }
        testsExecuted++;
    }
    void testDeleteTable()
    {
        deleteTable();
        if (size() == 0)
        {
            printf("SUCCESS : Table deleted ");
        }
        else
        {
            printf("FAILED: Table is not deleted entirely");
            testsFailed++;
        }
        testsExcuted++;
    }