#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define MSGSIZE 16
char* msg1 = "Hello world";
char* msg2 = "Hi";
char* msg3 = "Welcome";
  
int main()
{
    char inbuf[MSGSIZE];
    int p[2], i;
  
    if (pipe(p) < 0)
        exit(1);
  
    write(p[1], msg1, MSGSIZE);
    write(p[1], msg2, MSGSIZE);
    write(p[1], msg3, MSGSIZE);
  
    for (i = 0; i < 3; i++) 
    {

        read(p[0], inbuf, MSGSIZE);
        printf("line %d : %s\n",i+1,inbuf);
    }
    return 0;
}