#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MAX 256
int main(int argc, char *argv[])
{
    char salida[MAX];
    sprintf(salida, "%s.bak", argv[1]);
    int fd1, fd2;
    ssize_t r, w;
    char buffer[MAX];
    fd1 = open(argv[1], O_RDONLY);
    if (fd1 == -1) {
	perror("Error");
	exit(0);
    }
    fd2 =
	open(salida, O_RDWR | O_CREAT,
	     S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd2 == -1) {
	perror("Error");
	exit(0);
    }
    while ((r = read(fd1, buffer, MAX)) > 0) {

	w = write(fd2, buffer, r);


    }
    close(fd1);
    close(fd2);
    return 0;
}
