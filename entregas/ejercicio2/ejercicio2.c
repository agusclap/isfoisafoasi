#include <sys/types.h>
 #include <unistd.h>
#include <stdio.h>

int main(){
int pId;
pId=getpid();
int pid = fork();
	if (pid == 0) {
		pId=getpid();
		printf("Soy el proceso hijo my PID es %d\n",pId);
	} else {
	printf("Soy el proceso padre my PID es %d\n",pId);
	}
	return 0;


}
