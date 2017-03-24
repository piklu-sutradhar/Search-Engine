#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include "table.h"
#include "engine.h"
#include "levenshtein.c/levenshtein.h"

#define LENGTH 8
#define WORDLENGTH 100
static int testsFailed = 0;
static int testsExecuted = 0;

//*****************
// Prototypes
//*****************
//static char input[] = "He4l5l6o";
static char *input[] = {"hello", "\n", "567", "a", "HELLO", "hElLo", "\0", "bacbacbacbacbacbacbacbacbac"};
void testBuildTable(char const *const input);
void testToLower(char *input);
void testDeleteTable();
void testRemoveDigit(char *input);

int main(int argc, char const *argv[])
{
    char similar[WORDLENGTH];
    char word[WORDLENGTH];
    char wordsInDict[WORDLENGTH];
    FILE *dict;
    dict = fopen("sample.txt", "r");
    if (dict != NULL)
    {
        int i = 0;
        for (i = 0; i < LENGTH; i++)
        {
            strcpy(word, input[i]);
            removeDigit(word);
            testRemoveDigit(word);
            toLower(word);
            testToLower(word);
            rewind(dict);
            while (fgets(wordsInDict, WORDLENGTH, dict))
            {
                wordsInDict[strlen(wordsInDict) - 1] = '\0';
                checkWords(wordsInDict);
                removeDigit(wordsInDict);
                testRemoveDigit(wordsInDict);
                toLower(wordsInDict);
                testToLower(wordsInDict);
                checkWords(wordsInDict);
                buildTable(wordsInDict, word, similar);
            }
            testBuildTable(word);
            deleteTable();
            testDeleteTable();
        }
        fclose(dict);
    }
    printf("Test Executed: %d\n", testsExecuted);
    printf("Test Failed: %d\n", testsFailed);
    printf("Test passed: %d\n", testsExecuted - testsFailed);
    return EXIT_SUCCESS;
}
void testBuildTable()
{
    if (size() <= 0)
    {
        printf("Table built failed\n");
        testsFailed++;
        //testsExecuted++;
    }
    else
    {
        printf("SUCESS : Table built");
    }
    testsExecuted++;
}
void testToLower(char *input)
{
    int i;
    Boolean result = true;
    toLower(input);
    for (i = 0; i < strlen(input) && result; i++)
    {
        if (input[i] != tolower(input[i]))
        {
            result = false;
        }
    }
    if (!result)
    {
        printf("Failed : There are some upper case\n");
        testsFailed++;
    }
    else
    {
        printf("SUCCESS : All are lower cases.\n");
    }
    testsExecuted++;
}
void testDeleteTable()
{

    if (size() == 0)
    {
        printf("SUCCESS : Table deleted \n");
    }
    else
    {
        printf("FAILED: Table is not deleted entirely\n");
        testsFailed++;
    }
    testsExecuted++;
}
void testRemoveDigit(char *input)
{
    int i;
    Boolean result = true;
    for (i = 0; i < strlen(input) && result; i++)
    {
        if (!isalpha(input[i]))
        {
            result = false;
        }
    }
    if (result)
    {
        printf("SUCCESS : All digit removed\n");
    }
    else
    {
        printf("FAILED : There are still some digit\n");
        testsFailed++;
    }
    testsExecuted++;
}