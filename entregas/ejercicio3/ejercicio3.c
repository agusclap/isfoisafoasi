#include <sys/types.h>
 #include <unistd.h>
#include <stdio.h>

int main(){
int pId;int ppid;
pId=getpid();
int pid = fork();
	if (pid == 0) {
		pId=getpid();
		ppid=getppid();
		printf("Soy el proceso hijo my PID es %d, y mi padre %d\n",pId,ppid);
	} else {
	ppid=getppid();
	printf("Soy el proceso padre my PID es %d y mi padre %d\n",pId,ppid);
	}
	return 0;


}
