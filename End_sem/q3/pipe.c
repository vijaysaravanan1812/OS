#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
int pipefds1[2], pipefds2[2];
int returnstatus1, returnstatus2;
int pid;

char pipe1writemessage[20] = "Hi";
char pipe2writemessage[20] = "Hello";
char readmessage[20];
returnstatus1 = pipe(pipefds1);

if (returnstatus1 == -1)
{
printf("Unable to create pipe1\n");
return 1;
}
returnstatus2 = pipe(pipefds2);

if (returnstatus2 == -1)
        {
                printf("Unable to create pipe2\n");
                return 1;
        }
pid = fork();

if (pid != 0)
{
close(pipefds1[0]);
close(pipefds2[1]);
printf("In parent: Writing to pipe 1 - Message is %s\n",pipe1writemessage);
write(pipefds1[1], pipe1writemessage, sizeof(pipe1writemessage));
read(pipefds2[0], readmessage, sizeof(readmessage));
printf("In parent: Reading from pipe 2 - Message is %s\n", readmessage);
}

else
{
close(pipefds1[1]);
close(pipefds2[0]);
read(pipefds1[0],readmessage,sizeof(readmessage));
printf("In child: Reading from pipe 1 - Message is %s\n",readmessage);
printf("In child: Writing to pipe 2 - Message is %s\n",pipe2writemessage);
write(pipefds2[1], pipe2writemessage, sizeof(pipe2writemessage));
}
return 0;
}