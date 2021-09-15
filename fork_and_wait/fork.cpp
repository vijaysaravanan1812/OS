// program to demostrate fork()

#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

using namespace std;

int main()
{
    pid_t pid,children_id,parent_id;
    pid = fork();
    if (pid == 0)
    {
        children_id = getpid();
        printf("I am child, my process is %d\n",children_id);
    }
    else
    {
        parent_id = getpid();
        printf("I am parent process, my id is %d\n",parent_id);
        printf("I am parent of %d\n",pid);
        getchar();
    }
     
    

    return 0;
}