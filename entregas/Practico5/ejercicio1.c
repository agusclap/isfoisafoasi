#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MAX 100
  
int main (int argc, char *argv[])
{
	int file,file1, pid;
	file = open("a_inout.txt", O_CREAT);
	file1 = open("b_inout.tdt", O_CREAT);
	pid = fork();
	if ( pid == 0 ) 
		printf("Proceso hijo\n");
	else
		printf("Proceso padre\n");

	return 0;

	
}
   