#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SHM_SIZE 1024
int main(){
key_t key;
int shmid;
char *shared_mem;
key = ftok("progfile", 75);
shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
if (shmid == -1){
perror("shmget failed");
exit(1);
}
shared_mem = (char *)shmat(shmid, NULL, 0);
printf("Enter data to write to shared memory: ");
fgets(shared_mem, SHM_SIZE, stdin);
printf("Writer: Data written -> %s\n", shared_mem);
shmdt(shared_mem);
return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SHM_SIZE 1024
int main(){
key_t key;
int shmid;
char *shared_mem;
key = ftok("progfile", 75);
shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
if (shmid == -1){
perror("shmget failed");
exit(1);
}
shared_mem = (char *)shmat(shmid, NULL, 0);
printf("Reader: Data read -> %s\n", shared_mem);
shmdt(shared_mem);
shmctl(shmid,IPC_RMID,NULL);
return 0;
}