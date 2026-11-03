#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
msg.msg_type = 1;
printf("Enter message to send: ");
fgets(msg.msg_text, MSG_SIZE, stdin);
msgsnd(msgid, &msg, sizeof(msg.msg_text), 0);
printf("Sender: Message sent -> %s\n", msg.msg_text);
return 0;
}