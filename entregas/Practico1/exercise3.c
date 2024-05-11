#include <unistd.h>
#include <stdio.h>
int main() 
{
        int pid;
        pid = fork();
        if (pid == 0)
        {
                /* hijo */
        printf("Hola soy el proceso hijo mi PID es: %d y el de mi padre es: %d\n",getpid(),getppid());
        }
         else 
        {
                /* padre */
        printf("Hola soy el proceso padre mi PID es: %d y el de mi padre es:%d\n",getpid(),getppid());
        }
        return 0;
}


