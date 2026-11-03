#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MSG_SIZE 100
struct message {
long msg_type;
char msg_text[MSG_SIZE];
};
int main() {
key_t key;
int msgid;
struct message msg;
key = ftok("progfile", 65);
msgid = msgget(key, 0666 | IPC_CREAT);
if (msgid == -1) {
perror("msgget failed");
exit(1);
}
msgrcv(msgid, &msg, sizeof(msg.msg_text), 1, 0);
printf("Receiver: Message Received -> %s\n", msg.msg_text);
msgctl(msgid, IPC_RMID, NULL);
return 0;
}