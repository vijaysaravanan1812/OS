#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
void sigHandler (int);

void sigHandler(int sigNum)
{
    printf (" received an interrupt.\n");
    // this is where shutdown code would be inserted
    sleep (1);
    printf ("outta here.\n");
    exit(0);
}
int main()
{
    signal (SIGINT, sigHandler);
    printf ("waiting...\n");
    pause();
    return 0;
}
