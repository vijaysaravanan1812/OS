//program to implement one way

#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int fd[2];
    if (pipe(fd) ==  -1)
        printf("error has occur\n");

    int id = fork();
    if (id == 0)
    {
        close(fd[0]); // closing reading part of pipe
        char x[200];
        printf("input the string\n");
        scanf("%[^~]s",x);

        while ((getchar()) != '\n');



        write(fd[1], x, sizeof(x));
        close(fd[1]);
    }
    else
    {
        wait(NULL);
        close(fd[1]); // closing reading part of pipe
        int y[200];
        printf("Message from children process\n");
        read(fd[0],y,sizeof(y));
        printf("%s \n",y);
        close(fd[0]);
    }
    

    
}