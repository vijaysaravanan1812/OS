#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>

//Signal event handler
void sigend()
{
	printf("Process is terminated\n");
	exit(0);
}

void main()
{
	int pid = fork();
	if(pid > 0)//Parent Process
	{
		printf("Parent process started\n");
		sleep(10);
		kill(pid,SIGQUIT);
		wait(pid);
		printf("Parent process ends\n");
	}
	else if (pid == 0)//Child Process
	{
		printf("Child Process Started\n");
		signal(SIGQUIT,sigend);
		for(int i=1;;++i)
		{
			printf("Pass %d\n",i);
			sleep(1);
		}
	}
	else
	{
		printf("Fork failed\n");
		exit(1);
	}
	exit(0);
}
