#include "pipes.h"
#include "../tokenize/makeArgs.h"

int containsPipe(char *s)
{
    char* save;
    char* res = strtok_r(s,"|",&save);
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
    return i;




}
char ** parsePrePipe(char *s, int * preCount)
{


    char* save;
    char* prePipe = strtok_r(s,"|",&save);
    strip(prePipe);
    char** pre = NULL;
    *preCount = makeargs(prePipe, &pre);

    return pre;





}
char ** parsePostPipe(char *s, int * postCount)
{
    char* save;
    char* postPipe = strtok_r(s,"|",&save);
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
    if(pid == 0)//if child
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
            printf("got to inner else ");
            waitpid(pid2, &status,0);

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
