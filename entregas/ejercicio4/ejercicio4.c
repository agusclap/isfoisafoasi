#include <sys/types.h>
 #include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

/*4. Escriba un programa en el cual creamos un proceso y configuramos 
al proceso “padre” para que espere, por medio de la llamada wait() , 
a que termine su hijo antes de proseguir, luego de lo cual debe 
reportar el status de salida del proceso hijo. 
Use la llamada wait() . Se la debe invocar como
*/

int main(){
int pId;int ppid;
pId=getpid();
int pid = fork();
	if (pid == 0) {
		pId=getpid();
		ppid=getppid();
		printf("Soy el proceso hijo my PID es %d, y mi padre %d\n",pId,ppid);
		wait(-1);
		printf("termino che");
	} else {
	ppid=getppid();
	printf("Soy el proceso padre my PID es %d y mi padre %d\n",pId,ppid);
	sleep(3600);
	}
	return 0;


}
