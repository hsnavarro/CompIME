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
  
// Driver code 
int main() { 
    int sockfd; 
    char msg[MAX_SIZE]; 
    struct sockaddr_in servaddr; 
  
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  
    memset(&servaddr, 0, sizeof(servaddr)); 
      
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(PORT); 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
      
    int n, len = sizeof(servaddr);; 
     
    while(1){
      printf("Enter message:\n");
      memset(&msg, 0, sizeof msg);
      fgets(msg, MAX_SIZE, stdin);
      n = strlen(msg);
      msg[n-1] = '\0';
      sendto(sockfd, (char*) msg, MAX_SIZE, MSG_CONFIRM, (struct sockaddr *) &servaddr, len); 
      if(msg[0] == '#') break;
      recvfrom(sockfd, (char*) msg, MAX_SIZE, MSG_WAITALL, (struct sockaddr *) &servaddr, (socklen_t *) &len); 
      printf("Received and sent: %s\n", msg);
    }

    close(sockfd); 
    return 0; 
} 
