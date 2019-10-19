#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
  
#define PORT 8080 
#define MAX_SIZE 100
  
int main() { 
    int sockfd; 
    char msg[MAX_SIZE]; 
    struct sockaddr_in servaddr, cliaddr; 
      
    sockfd = socket(AF_INET, SOCK_DGRAM, 0); 
      
    memset(&servaddr, 0, sizeof(servaddr)); 
    memset(&cliaddr, 0, sizeof(cliaddr)); 
      
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
    servaddr.sin_port = htons(PORT); 
      
    bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)); 
      
    while(1){
      int len = sizeof(cliaddr); 
      recvfrom(sockfd, (char*) msg, MAX_SIZE,  0, (struct sockaddr *) &cliaddr, (socklen_t *) &len);
      if(msg[0] == '#') break;
      sendto(sockfd, (char*) msg,  strlen(msg), 0, (struct sockaddr *) &cliaddr, len); 
      printf("Received and set: %s\n", msg);
    }
    close(sockfd);

    return 0; 
}
