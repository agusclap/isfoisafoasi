
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
int main() 
{
        int pid;
        pid = fork();
	int status;
        if (pid == 0)
        {
                // hijo
        	printf("Proceso hijo PID: %d en ejecucion\n",getpid());
		while(1)
		{
			printf(".\n");
			sleep(1);
		}
	}
         else 
        {
		// padre
		printf("Proceso padre PID: %d en ejecucion\n",getpid());
		wait(&status);
		// SALIDA	
		if (WIFEXITED(status)) 
		{
                       printf("Proceso hijo termino normalmente, status=%d\n", WEXITSTATUS(status));
                 }
	       	else if (WIFSIGNALED(status))
	       	{
                       printf("Proceso hijo matado por la signal %d\n", WTERMSIG(status));
		}
		printf("Proceso padre PID: %d finalizo\n",getpid());
	}

        return 0;
}
