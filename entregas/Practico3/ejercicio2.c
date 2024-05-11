#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#define MAX 100

int main(int argc, char *argv[])
{
    int contador;
    int fd;
    char buf[MAX];
    int n = sizeof(buf);
    int n_read;
    fd = open("listadoo.txt", O_RDONLY);
    if(fd == -1){
	perror("Error");
   	exit(0);
    }
    while((n_read = read(fd, buf, MAX)) > 0)
	{
		contador+=n;
		printf("%s\n", buf);
	}
    printf("%d \n", n_read);
    close(fd);





    return 0;
}
