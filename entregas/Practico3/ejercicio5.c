#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <linux/fs.h>
#include <linux/kdev_t.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
	printf("Uso: %s <archivo>\n", argv[0]);
	return 1;
    }

    struct stat fileStat;

    if (stat(argv[1], &fileStat) < 0) {
	perror("Error al obtener información del archivo");
	return 1;
    }
    printf("Información del archivo: %s\n", argv[1]);
    printf("------------------------------\n");
    printf("st_ino: %ld\n", fileStat.st_ino);
    printf("st_nlink: %ld\n", fileStat.st_nlink);
    printf("st_uid: %d\n", fileStat.st_uid);
    printf("st_gid: %d\n", fileStat.st_gid);
    printf("st_size: %ld\n", fileStat.st_size);
    printf("st_blksize: %ld\n", fileStat.st_blksize);
    printf("st_blocks: %ld\n", fileStat.st_blocks);

    if (S_ISREG(fileStat.st_mode)) {
	printf("Tipo de archivo: Archivo regular\n");
    } else if (S_ISDIR(fileStat.st_mode)) {
	printf("Tipo de archivo: Directorio\n");
    } else if (S_ISCHR(fileStat.st_mode)) {
	printf("Tipo de archivo: Dispositivo de caracteres\n");
    } else if (S_ISBLK(fileStat.st_mode)) {
	printf("Tipo de archivo: Dispositivo de bloques\n");
    } else if (S_ISFIFO(fileStat.st_mode)) {
	printf("Tipo de archivo: FIFO/pipe\n");
    } else if (S_ISLNK(fileStat.st_mode)) {
	printf("Tipo de archivo: Enlace simbólico\n");
    } else if (S_ISSOCK(fileStat.st_mode)) {
	printf("Tipo de archivo: Socket\n");
    } else {
	printf("Tipo de archivo: Desconocido\n");
    }

    printf("Hora último acceso: %s", ctime(&fileStat.st_atime));
    printf("Hora última modificación: %s", ctime(&fileStat.st_mtime));
    printf("Hora último cambio: %s", ctime(&fileStat.st_ctime));

    dev_t st_dev_major = MAJOR(fileStat.st_dev);
    dev_t st_dev_minor = MINOR(fileStat.st_dev);

    printf("Número mayor del dispositivo: %d\n", st_dev_major);
    printf("Número menor del dispositivo: %d\n", st_dev_minor);

    return 0;
}
