
// program to implement Kill command 

#include<stdio.h>
#include<unistd.h>
#include <signal.h>

int main()
{
    int id = fork();
    if (id == 0)
    {
        int i = 1;
        for (;;)
        {
            printf("%d Hello \n",i++);
            sleep(1);
        }
    }
    else
    {
        sleep(20);
        kill(id,SIGKILL);
        wait(NULL);

    }
}