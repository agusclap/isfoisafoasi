#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 5

int arrayList[NUM_THREADS]={0};


void *runner(void *param)
{
   int *tid = param;

   printf("Hello World! It's me, thread #%d!\n", *tid);
   for(int t=2;t<NUM_THREADS;t++){
   arrayList[t] = arrayList[t-2] + arrayList[t-1];
   
   }

   sleep(5);

   pthread_exit(0);
}

int main(int argc,char *argv[]){

arrayList[1] = 1;

pthread_t threads[NUM_THREADS];
pthread_attr_t attr;

int rc;
int t;

for(t=0; t<NUM_THREADS ; t++){
printf("In main: creating thread %d\n" , t);
pthread_attr_init(&attr);

rc= pthread_create(&threads[t],&attr , runner,(void*) &t);

if ( rc ) {
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
}
for ( int i = 1; i <= NUM_THREADS; i++ ) {
      printf("Id de thread #%d -> %ld\n", i, threads[i-1]);
   }

printf("Numeros:\n");
   
for(int i=0;i<NUM_THREADS;i++){

     printf("%d\t", arrayList[i]);

}


   /* End main thread */
   pthread_exit(NULL);
}
