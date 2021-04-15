// C program to implement one side of FIFO
// This side writes first, then reads
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
  
int main()
{
    int fd;
  
    // FIFO file path
    char * mypipe = "/tmp/mypipe";
  
  
    mkfifo(mypipe, 0666);
  
    char arr1[80], arr2[80];
    while (1)
    {
         printf("You --> \t");
    
        fd = open(mypipe, O_WRONLY);
  
         fgets(arr2, 80, stdin);
    
        write(fd, arr2, strlen(arr2)+1);
        close(fd);
  
    
        fd = open(mypipe, O_RDONLY);
  
         read(fd, arr1, sizeof(arr1));
  
        printf("User2: %s\n", arr1);
        close(fd);
    }
    return 0;
}