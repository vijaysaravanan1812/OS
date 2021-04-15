#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    pid_t id = fork();
    if (id == 0)
    {
        for (int i = 0; i < 50; i++)
        {
            printf("Hello from child\n");
        }
        
    }
    else
    {
        int *ptr,x = 0 ;
        ptr  = &x;
        wait(ptr);
        for (int i = 0; i < 10; i++)
        {
            printf("hello from parend\n");

        }
        
    }

    return 0 ;
}