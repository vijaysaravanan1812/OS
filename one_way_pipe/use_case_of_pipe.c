// in this program we demostrate use case of pipe 
// for given array we find it's sum of element using two process

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size  = sizeof(arr)/sizeof(arr[0]);
    int fd[2]; int start,end,total_sum;
    if (pipe(fd) == -1)
        printf("error has occur while creating pipe\n");
    int id = fork();
   
    if (id == 0)
    {
        start = 0 ; end = size/2;
    }
    else
    {
        start = size/2 + 1;
        end = size  - 1;
    }

    int sum = 0; 
    for (int i = start; i <= end; i++)
    {
        sum += arr[i]; 
    }

    if (id == 0)
    {
        close(fd[0]);
        write(fd[1],&sum,sizeof(sum));
        close(fd[1]);
    }
    else
    {  
        close(fd[1]);
        read(fd[0],&total_sum,sizeof(total_sum));
        close(fd[0]);
        total_sum = sum + total_sum;
        printf("total sum is %d\n",total_sum);
    }
    
    printf("partial sum %d\n",sum);
    wait(NULL);
}