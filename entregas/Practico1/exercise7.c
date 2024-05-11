#include<stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int pid;
void sigmanager(int sig_num)
{
	printf("Enviada señal %d al proceso hijo pid: %d\n",sig_num,pid);
	kill(pid,sig_num);
}

void sonsigmanager(int sig_num)
{
	 if(sig_num == SIGINT)
        {
		printf("Hijo recibio señal %d\n terminado hijo...\n",sig_num);
		exit(0);		
        }
        else
        {
                printf("Hijo recibio señal %d\n",sig_num);
        }

}
int main() {
	int childstatus;
	printf("Ejecutando:\n");
	pid = fork();

	
	if(pid != 0)
	{
		//padre
	 	signal(SIGINT, sigmanager);
        	signal(SIGTSTP,sigmanager);
		if(wait(&childstatus) == pid)
		{
			return 0;
		}
	}
	else
	{
		//codigo hijo
		signal(SIGINT, sonsigmanager);
        	signal(SIGTSTP,sonsigmanager);

	}
       	while(1)
	{
		printf(".\n");

		sleep(1);
	}
        return 0;
}
