#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

#define MAX_MSG_SIZE 256
#define SHM_KEY 0x1234

struct shmsg {
    char message[MAX_MSG_SIZE];
    int msg_present;
};


struct shmsg* shmsg_st;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* send_message(void* arg)
{
    char msg_s[MAX_MSG_SIZE];
    while (1) {
        // printf("Enter your message: ");
        if (fgets(msg_s, MAX_MSG_SIZE, stdin) != NULL) 
        {
            pthread_mutex_lock(&mutex);
            if (shmsg_st->msg_present == 0) 
            {
                strncpy(shmsg_st->message, msg_s, MAX_MSG_SIZE);
                shmsg_st->msg_present = 1;
            }
            pthread_mutex_unlock(&mutex);
        }
    }
    return NULL;
}

void* receive_message(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        if (shmsg_st->msg_present) 
        {
            printf("%s", shmsg_st->message);
            fflush(stdout);
            shmsg_st->msg_present = 0;
        }
        pthread_mutex_unlock(&mutex);
        sleep(1); // Add a small delay to reduce CPU usage
    }
    return NULL;
}

int main()
{
    int shmid;

    pthread_t send_thread, receive_thread;

    shmid = shmget(SHM_KEY, sizeof(struct shmsg), IPC_CREAT | 0644);

    // attach to shared memory
    shmsg_st = shmat(shmid, NULL, 0);

    // Create threads
    pthread_create(&send_thread, NULL, send_message, NULL);
    pthread_create(&receive_thread, NULL, receive_message, NULL);

    pthread_join(send_thread, NULL);
    pthread_join(receive_thread, NULL);

   // detatch
    if (shmdt(shmsg_st) == -1) {
      perror("shmdt");
      return 1;
   }

   pthread_mutex_destroy(&mutex);

    return 0;
}