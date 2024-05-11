#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>


int main (void) {

	int pid;
	pid = fork();
	int status;
	int child_process;
	if(pid == 0){

		printf("Child process PID: %d executing \n", getpid());

	}else{ // padre


		printf("Father process  PID: %d executing\n", getpid());
		child_process = wait(&status);
		// Salida
		if(child_process == pid){
			
			printf("Child process finishes correctly\n");
	
		} else if(child_process == -1){
			
			printf("Child process doesn't finish correctly\n");
		}

		printf("Father process PID: %d finished wait\n", getpid());

	}




	return 0;
}
