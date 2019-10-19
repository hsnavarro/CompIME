#include <bits/stdc++.h>
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
using namespace std;
  
#define PORT 8080 
#define MAX_SIZE 100
  
int sockfd;
char msg[MAX_SIZE];
string in;
struct sockaddr_in servaddr; 
int len = sizeof(servaddr);

int main() { 
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  
    memset(&servaddr, 0, sizeof(servaddr)); 
      
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(PORT); 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
      
    while(1){
      cout << "Enter algebric expression:" << endl;
      getline(cin, in);
      strcpy(msg, in.c_str());
      sendto(sockfd, (char*) msg, MAX_SIZE, 0, (struct sockaddr*) &servaddr, len); 
      if(msg[0] == '#') break;
      recvfrom(sockfd, (char*) msg, MAX_SIZE, 0, (struct sockaddr*) &servaddr, (socklen_t *) &len); 
      string aux(msg);
      cout << "Result: " << aux << endl;
    }

    close(sockfd); 
    return 0; 
} 
