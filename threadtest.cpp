#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#define PTHREADS_COUNT 10 // Number of threads to create
#define SLEEP_SECONDS 5 // Number of seconds to sleep

	void * pthread_function (void * p_thread_id) { // The tread routine
	printf ("This is thread # %ld\n",(long) p_thread_id); // Print the thread index
	sleep(5); // Sleep
	pthread_exit(NULL); // Exit thread and return NULL to the catching join.
}
int main (int argc,char ** argv) {
pthread_t pthreads[PTHREADS_COUNT]; // Array of threads
char message [1024]; // A buffer to hold messages
memset (message,0,1024); // Initialize buffer
sprintf (message,"This is the common message\n"); // Copy message to buffer
for ( long i = 0 ; i < PTHREADS_COUNT ; i ++ ) { // A loop for creating threads
int return_code = pthread_create(&pthreads[i], NULL, pthread_function, (void *)i);/* Call pthread create to create a
new thread and set the thread routine to the pthread_function defined above. Notice that we pass a pointer to a thread handler
which will initialized with the new thread attributes by the pthread_create function for future references */
if (return_code) { // If return code is not zero then an error occured so we will print and error and exit.
printf ("Error Spawning thread: return code %d\n",return_code);
exit(1);
}}
for ( long i = 0 ; i < PTHREADS_COUNT ; i ++ ) pthread_join(pthreads[i],NULL); /* As all the threads are part of the main
program address space, thus exiting will terminate the threads, and hence the main program need to wait for the threads to finish
their work. This is achieved by calling pthread_join on every thread handler we created. */
}