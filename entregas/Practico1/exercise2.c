#include <unistd.h>
#include <stdio.h>
int main() 
{
	int pid;
	pid = fork();
	if (pid == 0)
	{
		/* hijo */
	printf("Hola soy el proceso hijo\n");
	}
	 else 
	{
		/* padre */
	printf("Hola soy el proceso padre\n");
	}
	return 0;
}
