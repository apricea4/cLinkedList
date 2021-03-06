#include "pipes.h"
#include "../tokenize/makeArgs.h"

int containsPipe(char *s)
{
    char* save;
    char copy[MAX];
    char* res = NULL;
    strcpy(copy,s);
    res = strtok_r(copy,"|",&save);
    if(res == NULL)
    {
        return -1;
    }

    int i = 0;
    while(res != NULL)
    {

        res = strtok_r(NULL,"|",&save);
        ++i;

    }
    printf("contains pipe %d ", i);
    return i;




}
char ** parsePrePipe(char *s, int * preCount)
{


    char* save;
    char copy[MAX];
    strcpy(copy,s);
    char* prePipe = strtok_r(copy,"|",&save);
    strip(prePipe);


    printf("prePipe-> %s\n", prePipe );

    char** pre = NULL;
    *preCount = makeargs(prePipe, &pre);

    return pre;





}
char ** parsePostPipe(char *s, int * postCount)
{
    char* save;
    char copy[MAX];

    strcpy(copy,s);
    char* postPipe = strtok_r(copy,"|",&save);
    postPipe = strtok_r(NULL, "|", &save);
    printf("postPipe-> %s\n", postPipe );



    char** post = NULL;
    *postCount = makeargs(postPipe, &post);

    return post;




}
void pipeIt(char ** prePipe, char ** postPipe)
{

    pid_t pid = fork();
    int status;

    int fd[2];
    pipe(fd);

    if(pid == 0)//if child of a.out
    {
        pid_t pid2 = fork();
        if(pid2 == 0) //grandchild aka ls-l execute first
        {
            close(fd[0]);
            close(1);
            dup(fd[1]);
            close(fd[1]);
            if(execvp(prePipe[0], prePipe) < 0)
            {
                printf("command not found ");
                return;
            }

        }

        else
        {

            waitpid(pid2, &status,0);
            printf("got to inner else ");
            close(fd[1]);
            close(0);
            dup(fd[0]);
            close(fd[0]);
            if(execvp(postPipe[0], postPipe) < 0)
            {
                printf("command not found ");
                return;

            }


        }




    }
    else
    {

        waitpid(pid,&status,0);


    }


}

//gcc -Wall cscd340Lab5.c ./tokenize/makeArgs.c ./utils/myUtils.c ./pipes/pipes.c ./process/process.c
