#include "client1.h"

#define PORT 8000
#define SERVER_IP "127.0.0.1"
#define MAXSZ 100

struct sockaddr_in serverAddress;

char msg1[MAXSZ], msg2[MAXSZ];

void fill() {
 memset(&serverAddress,0,sizeof(serverAddress));
 serverAddress.sin_family=AF_INET;
 serverAddress.sin_addr.s_addr=inet_addr(SERVER_IP);
 serverAddress.sin_port=htons(PORT);
}

int main() {
 int sockc1 = socket(AF_INET,SOCK_STREAM,0);
 
 fill();

 connect(sockc1,(struct sockaddr*) &serverAddress, sizeof(serverAddress));
 printf("connected 1\n"); 
 close(sockc1);
}
