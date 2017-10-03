//
//
//

#include "word.h"
/**
 * @brief Cleans up all dynamically allocated memory for the word
 *
 * Cleans up and frees all the dynamically allocated memory
 * In this case ltrs
 *
 * Each pointer in the specific data type is set to NULL after it has been freed.
 *
 * @param passedIn - The void * passed in representing the specific word
 *
 * @warning - The passed in void * passedIn is checked - exit(-99) if NULL
 */
void cleanTypeWord(void * ptr)
{
    if(ptr == NULL)
    {
        exit(-99);
    }

    Word * tmp = (Word *) ptr;
    free(tmp->ltrs);
    free(tmp);
    tmp = NULL;

}


/**
 * @brief Builds and returns a single word.
 *
 * Reads the initial data from the file and then builds
 * an object of type word.
 *
 * @note The carriage return will be removed when reading from the file
 *
 * @param fin - The FILE * representing the open file
 * @return void * - Representing a word object
 *
 * @warning - The passed in FILE * fin is checked - exit(-99) if NULL
 */
void * buildTypeWord(FILE * fin)
{
    if(fin == NULL)
    {
        exit(-99);
    }

    Word* w = (Word*)calloc(1, sizeof(Word));
    char tmp[MAX];
    fgets(tmp,100,fin);
    strip(tmp);
    w->len = strlen(tmp);
    w->ltrs = (char*)calloc(strlen(tmp)+1,sizeof(char));
    strcpy(w->ltrs,tmp);
    return w;



}


/**
 * @brief Prints the specific word.
 *
 * Format is word - length
 *
 * @param passedIn - The void * passed in representing a specific word
 *
 * @warning - The passed in void * passedIn is checked - exit(-99) if NULL
 */
void printTypeWord(void * passedIn)
{
    if(passedIn == NULL)
    {
        exit(-99);
    }
    Word *tmp = (Word *) passedIn;
    printf("%s - %d\n", tmp->ltrs, tmp->len);



}


/**
 * @brief Builds and returns a single word.
 *
 * Reads the initial data from the keyboard by prompting the user.
 * A word object is constructed.
 *
 * @note The carriage return will be removed when reading from the keyboard
 *
 * @param fin - The FILE * representing stdin
 * @return void * - Representing a word object
 *
 * @warning - The passed in FILE * fin is checked - exit(-99) if NULL
 */
void * buildTypeWord_Prompt(FILE * fin)
{
    if(fin == NULL)
    {
        exit(-99);
    }

    char tmp[MAX];
    Word *w = (Word*) calloc(1,sizeof(Word));
    printf("enter a word to be built: ");
    scanf("%s",tmp);
    strip(tmp);
    while(getchar() != '\n');

    w->len = strlen(tmp);
    w->ltrs = (char*)calloc(strlen(tmp) + 1,sizeof(char));
    strcpy(w->ltrs,tmp);
    return w;

}

/**
 * @brief Compares two objects of type word.
 *
 * Words are compared based on the letters (word)
 *
 * @note The passed in items will need to be cast to the appropriate word type.
 *
 * @param p1 - The void * representing an object of type word
 * @param p2 - The void * representing an object of type word
 * @return int - Representing order < 0 indicates p1 is less than p2,
 * > 0 indicates p1 is greater than p2 and == 0 indicates p1 == p2 for contents
 *
 * @warning - The passed in void * p1 is checked - exit(-99) if NULL
 * @warning - The passed in void * p2 is checked - exit(-99) if NULL
 */
int compareWord(const void * p1, const void * p2)
{
    if(p1 == NULL || p2 == NULL)
    {
        exit(-99);
    }

    Word *tmp = (Word *) p1;
    Word *tmp1 = (Word *) p2;

    return strcmp(tmp->ltrs,tmp1->ltrs);



}


