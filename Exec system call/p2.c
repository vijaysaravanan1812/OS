#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    int id = fork();
    if (id == 0)
    {
        printf("Enter command\t");  
        char a[10];
        scanf("%s",a); 
        execv(a,NULL);
    }
    else
    {
        wait(NULL);
    }
      
    return 0;
}