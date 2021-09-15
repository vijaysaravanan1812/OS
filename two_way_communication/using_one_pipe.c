

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc,char *argv[])
{

    int fd[2];
    pipe(fd);
        int pid = fork();
    //open(fd[1]);
    
    
    if (pid == 0)
    {
        int y;
        read(fd[0],&y,sizeof(int));
        printf("recieved from parent y = %d\n",y);
        y *= 4;
        write(fd[1],&y,sizeof(int));
        printf("written to parent y = %d\n",y);
    }
    else
    {
        int x = 3;
        write(fd[1],&x,sizeof(int));
        printf("Written to child x = %d\n",x);
    
        read(fd[0],&x,sizeof(int));
        printf("recieved from child x = %d\n",x);
        wait(NULL);
    }
    close(fd[0]);
    close(fd[1]);
}
