#include <bits/stdc++.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <unistd.h>

#define PORT 8000
#define MAXSZ 100

int main()
{
 int sockfd;
 int newsockfd;

 struct sockaddr_in serverAddress;
 struct sockaddr_in clientAddress;

 int n;
 char msg[MAXSZ];
 unsigned int clientAddressLength;

 sockfd=socket(AF_INET,SOCK_STREAM,0);

 memset(&serverAddress,0,sizeof(serverAddress));
 serverAddress.sin_family=AF_INET;
 serverAddress.sin_addr.s_addr=htonl(INADDR_ANY);
 serverAddress.sin_port=htons(PORT);

 bind(sockfd,(struct sockaddr *)&serverAddress, sizeof(serverAddress));

 listen(sockfd, 5);

 printf("\n*****server waiting for new client connection:*****\n");
 clientAddressLength=sizeof(clientAddress);
 newsockfd=accept(sockfd,(struct sockaddr*)&clientAddress,&clientAddressLength);
 printf("accepted new connection\n");

 while(1){
  memset(&msg, 0, sizeof msg);
  n = recv(newsockfd,msg,MAXSZ,0);
  if(msg[0] == '#') break;
  send(newsockfd,msg,n,0);
  printf("Receive and set:%s\n",msg);
 }

 close(sockfd);
 close(newsockfd);

 return 0;
}
