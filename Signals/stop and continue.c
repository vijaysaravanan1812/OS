

// program to implement stop and continue 
#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main()
{
    int id = fork();
    if (id == 0)
    {
        int i = 1;
        while (1)
        {
            printf("%d Hello \n",i++);
            usleep(1000000);
        }
        
    }
    else
    {
        int time;
        do
        {
             kill(id, SIGSTOP);
            printf("Enter the time for execution \t");
            scanf("%d",&time);
            if (time > 0)
            {
                kill(id,SIGCONT);
                sleep(time);
                getchar();
                system("clear");
            }
            
        } while (time > 0);
        
    }
}