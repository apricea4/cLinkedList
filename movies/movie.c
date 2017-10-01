//
//
//
#include "movie.h"
#include "actor.h"
#include "../linkedlist/requiredIncludes.h"

/**
 * @brief Cleans up all dynamically allocated memory for the movie
 *
 * Cleans up and frees all the dynamically allocated memory
 * In this case title, actors->first, actors->last and the actors array
 *
 * Each pointer in the specific data type is set to NULL after it has been freed.
 *
 * @param passedIn - The void * passed in representing the specific movie
 *
 * @warning - The passed in void * passedIn is checked - exit(-99) if NULL
 */
void cleanTypeMovie(void * ptr)
{
    if(ptr == NULL)
    {
        exit(-99);
    }

    Movie *m = (Movie *) ptr;
    for(int i = 0; i<m->totalActors; i++)
    {
        free(m->actors[i].first);
        free(m->actors[i].last);

    }
    free(m->actors);
    free(m->title);
    free(m);
    m->actors = NULL;
    m->title = NULL;
    m = NULL;




}


/**
 * @brief Builds and returns a single movie.
 *
 * Reads the initial data from the file and then builds
 * an object of type movie.
 *
 * @note The carriage return will be removed when reading from the file
 *
 * @param fin - The FILE * representing the open file
 * @return void * - Representing a movie object
 *
 * @warning - The passed in FILE * fin is checked - exit(-99) if NULL
 */
void * buildTypeMovie(FILE * fin)
{

    if(fin == NULL)
    {
        exit(-99);
    }

    Movie *m = (Movie *) calloc(1,sizeof(Movie));



    char tmpInput[MAX];
    fgets(tmpInput,MAX,fin);
    strip(tmpInput);
    m->title = (char*)calloc(strlen(tmpInput) + 1,sizeof(char));

    strcpy(m->title, tmpInput);

    fgets(tmpInput,MAX,fin);
    strip(tmpInput);

    m->totalActors = atoi(tmpInput);

    Actor* a = (Actor*)calloc(m->totalActors,sizeof(Actor));

    for(int i = 0; i< m->totalActors; i++)
    {

        fgets(tmpInput,MAX,fin);
        char* tok;
        tok = strtok(tmpInput," ");
        strip(tok);

        a[i].first = (char *)calloc(strlen(tok)+1,sizeof(char));

        strcpy(a[i].first,tok);
        tok = strtok(NULL," ");
        strip(tok);
        a[i].last = (char*)calloc(strlen(tok)+1,sizeof(char));
        strcpy(a[i].last,tok);

    }

    m->actors = a;

    return m;


}



void printTypeMovie(void * passedIn)
{

    if(passedIn == NULL)
    {
        exit(-99);
    }
    Movie *m = (Movie *) passedIn;
    printf("%s \n",m->title);
    printf("Starring: \n");
    for(int i = 0; i< m->totalActors; i++)
    {
        printf("%s %s,\n",m->actors[i].first,m->actors[i].last);
    }


}


/**
 * @brief Builds and returns a single movie.
 *
 * Reads the initial data from the keyboard by prompting the user.
 * A movie object is constructed.
 *
 * @note The carriage return will be removed when reading from the keyboard
 *
 * @param fin - The FILE * representing stdin
 * @return void * - Representing a movie object
 *
 * @warning - The passed in FILE * fin is checked - exit(-99) if NULL
 */
void * buildTypeMovie_Prompt(FILE * fin)
{

    if(fin == NULL)
    {
        exit(-99);
    }


    Movie *m = (Movie *)calloc(1,sizeof(Movie));

    char tmpInput[MAX];
    char *lineIn = (char*)calloc(100,sizeof(char));//free later
    printf("Enter a movie title: ");
    int *nbytes =(int*)calloc(100,sizeof(int));//free later
    getline(&lineIn,&nbytes, stdin);

    strip(lineIn);
    m->title = (char*)calloc(strlen(lineIn)+1,sizeof(char));
    strcpy(m->title,strlen);

    printf("how many actors? ");



    int actorCount;
    scanf("d", &actorCount);
    Actor* a = (Actor*)calloc(actorCount,sizeof(Actor));


    printf("list actors First Last: ");

    getline(&lineIn,&nbytes,stdin);
    strip(lineIn);
    int i = 0;

    char *tok = strtok(lineIn," ");
    char *tok1 = strtok(NULL, " ");




    while( tok != NULL)
    {

        a[i].first = (char*)calloc(strlen(tok)+1,sizeof(char));
        strcpy(a[i].first, tok);

        a[i].last = (char*)calloc(strlen(tok1)+1,sizeof(char));
        strcpy(a[i].last,tok1);

        tok = strtok(NULL, " ");
        tok1 = strtok(NULL, " ");
        ++i;

    }
    free(nbytes);
    free(lineIn);
    lineIn =NULL;
    nbytes = NULL;
    m->totalActors = i;


    m->actors = a;
    return m;



}




/**
 * @brief Compares two objects of type movie.
 *
 * movies are compared based on title and if the title are the same then totalActors
 *
 * @note The passed in items will need to be cast to the appropriate movie type.
 *
 * @param p1 - The void * representing an object of type movie
 * @param p2 - The void * representing an object of type movie
 * @return int - Representing order < 0 indicates p1 is less than p2,
 * > 0 indicates p1 is greater than p2 and == 0 indicates p1 == p2 for contents
 *
 * @warning - The passed in void * p1 is checked - exit(-99) if NULL
 * @warning - The passed in void * p2 is checked - exit(-99) if NULL
 */
int compareMovie(const void * p1, const void * p2)
{

    if(p1 == NULL || p2 == NULL)
    {
        exit(-99);

    }

    Movie* m1 = (Movie*) p1;
    Movie* m2 = (Movie*) p2;

    if(strcmp(m1->title,m1->title) == 0)
    {
        return m1->totalActors - m2->totalActors;
    }
    else
    {
        return strcmp(m1->title,m1->title);
    }


}


