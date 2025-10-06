#include <stdio.h>
#include <pthread.h> // The POSIX threads library
#include <unistd.h>  // For sleep()
#include "multithreadingEx.h"
#include "hello.h"   // For printLine

// This is the function that each thread will execute.
// It must have this specific signature: a function that takes a void pointer
// and returns a void pointer.
void *worker_thread_function(void *arg) {
    // Cast the void pointer argument back to its original type (long).
    long thread_id = (long)arg;

    printf("Thread %ld: Starting my work...\n", thread_id);
    sleep(1); // Simulate doing some work
    printf("Thread %ld: ...Finished my work.\n", thread_id);

    // The thread must return a void pointer. NULL is fine if we don't need to return a value.
    return NULL;
}

void multithreadingEx(void) {
    printLine("Demonstrating Multithreading with pthreads");

    // 1. Declare thread identifiers.
    pthread_t thread1, thread2;

    printf("Main Thread: Creating worker threads.\n");

    // 2. Create the threads.
    //    - 1st arg: A pointer to the pthread_t variable that will hold the thread ID.
    //    - 2nd arg: Thread attributes (NULL for default).
    //    - 3rd arg: The function the thread will execute.
    //    - 4th arg: The argument to pass to the thread function.
    if (pthread_create(&thread1, NULL, worker_thread_function, (void *)1) != 0) {
        perror("Failed to create thread 1");
        return;
    }
    if (pthread_create(&thread2, NULL, worker_thread_function, (void *)2) != 0) {
        perror("Failed to create thread 2");
        return;
    }

    // 3. Wait for the threads to finish their execution.
    //    This is called "joining" the threads. The main thread will block here
    //    until thread1 and thread2 have completed.
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Main Thread: Both worker threads have finished. Exiting.\n");
    printf("\nNOTE: To compile this, you must link the pthread library, e.g., 'clang *.c -pthread'\n");
}