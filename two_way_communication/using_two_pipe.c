

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc,char *argv[])
{

    int fd1[2],fd2[2];
    pipe(fd1); // p => c  
    pipe(fd2); // c => p
    int pid = fork();
    //open(fd[1]);
    
    
    if (pid == 0)
    {
        int y;
        close(fd1[1]);
        close(fd2[0]);
        read(fd1[0],&y,sizeof(int));
        printf("recieved from parent y = %d\n",y);
        y *= 4;
        write(fd2[1],&y,sizeof(int));
        printf("written to parent y = %d\n",y);
    }
    else
    {
        int x = 3;
        close(fd1[0]);
        close(fd2[1]);
        write(fd1[1],&x,sizeof(int));
       printf("Written to child x = %d\n",x);
    
        read(fd2[0],&x,sizeof(int));
        printf("recieved from child x = %d\n",x);
        wait(NULL);
    }

}
