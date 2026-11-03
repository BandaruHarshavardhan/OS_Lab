//fork():-
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
void forkexample(){
pid_t p = fork();
if(p<0){
perror("Fork failed");
exit(1);
}else if(p==0){
printf("Hello from child");
}else{
printf("Hello from parent");
}
}
int main(){
forkexample();
return 0;
}

// ex1.c
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
printf("PID of ex1.c: %d\n", getpid());
char *args[] = {"hello","everyone",NULL};
execv("./ex2", args);
perror("execv failed");
printf("Back to ex1.c\n");
return 0;
}

//ex2.c
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int args, char *argv[]){
printf("We are in ex2.c\n");
printf("PID of ex2.c: %d\n", getpid());
for(int i=0; i<args; i++)
printf("argv[%d]: %s\n", i, argv[i]);
return 0;
}