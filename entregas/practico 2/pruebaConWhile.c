#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



/*
2) Use 5 hilos para computar los 5 primeros términos de la serie de Fibonacci

0 1 1 2 3 5 8 13 ...
a_n = a_n-1 + a_n-2

Use una expresión no recursiva para la función de la serie.
Declare un arreglo común donde cada hilo debe almacenar el resultado.
Imprima el arreglo al finalizar

Piense de que modo 'sicronizar' al hilo principal, recuerde que las variables
globales son comunes.
*/
#define NUM_THREADS     7
int turno= 2;
int numerosFibonacci[7];

void *runner(void *param)
{
   int *tid = param;
   int aux=(*tid);
   printf("Hello World! It's me, thread #%d!\n", *tid);
   printf("aux=%d\n",aux);
   if((*tid)!=0&&(*tid)!=1)
   while(aux!=turno){}

   	numerosFibonacci[aux]=numerosFibonacci[aux-1]+numerosFibonacci[aux-2];
   	  turno++;
   pthread_exit(0);
}

int main (int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];
   pthread_attr_t attr;
   int rc;
   int t;
   numerosFibonacci[0]=0;
numerosFibonacci[1]=1;
   for ( t = 0; t < NUM_THREADS; t++ ) {
      printf("In main: creating thread %d\n", t);
      pthread_attr_init( &attr );
      
      rc = pthread_create( &threads[t], &attr, runner, (void *) &t );
      
      if ( rc ) {
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
   }


   // Print thread id
 
 	
   for ( int i = 0;i < NUM_THREADS; i++ ) {
   	if(pthread_join(threads[i],NULL)==0)
      printf("%d\n",numerosFibonacci[i]);
   }
      pthread_exit(NULL);
   

   /* End main thread */

}

