#include<stdio.h>
#include<sys/types.h>//socket
#include<sys/socket.h>//socket
#include<string.h>//memset
#include<stdlib.h>//sizeof
#include<netinet/in.h>//INADDR_ANY
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8000
#define SERVER_IP "127.0.0.1"
#define MAXSZ 100
int main()
{
 int sockfd;

 struct sockaddr_in serverAddress;

 int n;
 char msg1[MAXSZ];
 char msg2[MAXSZ];

 sockfd=socket(AF_INET,SOCK_STREAM,0);
 
 memset(&serverAddress,0,sizeof(serverAddress));
 serverAddress.sin_family=AF_INET;
 serverAddress.sin_addr.s_addr=inet_addr(SERVER_IP);
 serverAddress.sin_port=htons(PORT);

 connect(sockfd,(struct sockaddr *)&serverAddress,sizeof(serverAddress));
 
 while(1) {
  memset(&msg1, 0, sizeof msg1);
  printf("\nEnter message to send to server:\n");
  fgets(msg1,MAXSZ,stdin);
  n = strlen(msg1);
  msg1[n-1] = '\0';
  send(sockfd,msg1,n,0);
  if(msg1[0]=='#') break;
  n = recv(sockfd,msg2,MAXSZ,0);
  printf("Receive message from server:%s\n",msg2);
 }
 close(sockfd);

 return 0;
}
